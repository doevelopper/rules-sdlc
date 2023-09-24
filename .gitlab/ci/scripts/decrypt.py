from cryptography.fernet import Fernet, InvalidToken
import os
import yaml
from envparse import Env
from wcmatch import pathlib

try:
    from yaml import CLoader as Loader, CDumper as Dumper
except ImportError:
    from yaml import Loader, Dumper

env = Env()
if os.path.isfile('.env'):
    env.read_envfile('.env')

reserved_keywords = [
    'stages', 'image', 'services', 'types', 'before_script', 'after_script',
    'variables', 'cache', 'include'
]


def main():
    key = env('FERNET_KEY').encode('UTF-8')

    with open(env('CI_CONFIG_PATH')) as f:
        document = f.read()
    ci_config = yaml.load(document, Loader=Loader)
    stages = ci_config.get('stages', ['test'])
    jobs = {
        x: y
        for x, y in ci_config.items()
        if x not in reserved_keywords and not x.startswith('.')
    }
    current_stage_index = stages.index(env('CI_JOB_STAGE'))
    p = pathlib.Path('.')

    for job, job_def in jobs.items():
        if not isinstance(job_def, dict):
            continue

        artifact_paths = job_def.get('artifacts', {}).get('paths', [])
        job_stage_index = stages.index(job_def.get('stage', 'test'))
        if not artifact_paths:
            continue
        if job_stage_index >= current_stage_index:
            continue

        for artifact in artifact_paths:
            for file_path in list(p.glob(artifact, flags=pathlib.GLOBSTAR)):
                if os.path.isfile(str(file_path)):
                    cipher_suite = Fernet(key)

                    with open(str(file_path), 'rb') as f:
                        try:
                            clear_text = cipher_suite.decrypt(f.read())
                        except InvalidToken:
                            continue

                    with open(str(file_path), 'wb') as f:
                        f.write(clear_text)
                    print('Decrypted file:', file_path)


if __name__ == '__main__':
    main()
