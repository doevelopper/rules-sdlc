import binascii
import os

import yaml
from cryptography.fernet import Fernet
from envparse import Env
from wcmatch import pathlib

try:
    from yaml import CDumper as Dumper
    from yaml import CLoader as Loader
except ImportError:
    from yaml import Dumper, Loader

env = Env()
if os.path.isfile('.env'):
    env.read_envfile('.env')

reserved_keywords = [
    'stages', 'image', 'services', 'types', 'before_script', 'after_script',
    'variables', 'cache', 'include'
]


def main():
    with open(env('CI_CONFIG_PATH')) as f:
        document = f.read()
    ci_config = yaml.load(document, Loader=Loader)

    job_def = ci_config.get(env('CI_JOB_NAME'), {})
    artifact_paths = job_def.get('artifacts', {}).get('paths', [])

    if not artifact_paths:  # No artifacts to encrypt
        return
    elif not env('ARTIFACTS_ENCRYPTED', cast=bool, default=False):
        return
    elif not env('FERNET_KEY', default=None):
        print('Missing Fernet Key stored at: FERNET_KEY')
        exit(1)
        return

    cipher_suite = None
    try:
        key = env('FERNET_KEY').encode('UTF-8')
        cipher_suite = Fernet(key)
    except (binascii.Error, ):
        print('Invalid Fernet Key stored at: FERNET_KEY')
        exit(2)

    p = pathlib.Path('.')
    for artifact in artifact_paths:
        for file_path in list(p.glob(artifact, flags=pathlib.GLOBSTAR)):

            with open(str(file_path), 'rb') as f:
                cipher_text = cipher_suite.encrypt(f.read())

            with open(str(file_path), 'wb') as f:
                f.write(cipher_text)
            print('Encrypted file:', file_path)


if __name__ == '__main__':
    main()
