import json
import os
import sys
from zipfile import BadZipFile, ZipFile

import requests
from envparse import Env

env = Env()
if os.path.isfile('.env'):
    env.read_envfile('.env')


def download_file(v4_origin, project_id, headers, *, job_id=None, commit_ref=None, job_name=None):
    url = None
    if job_id and 'PRIVATE-TOKEN' in headers:
        url = f'{v4_origin}/projects/{project_id}/jobs/{job_id}/artifacts/'
    elif commit_ref and job_name and ('JOB-TOKEN' in headers or 'PRIVATE-TOKEN' in headers):
        url = f'{v4_origin}/projects/{project_id}/jobs/artifacts/{commit_ref}/download?job={job_name}'
    else:
        sys.stderr.write('Must provide either Job ID or both Commit Ref and Job Name\n')
        exit(1)
    # sys.stdout.write('Downloading artifacts for child job at: ' + str(url) + '\n')
    # sys.stdout.flush()
    downloaded = requests.get(
        url,
        headers=headers,
        allow_redirects=True
    )
    if not downloaded.ok:
        sys.stderr.write("Failed to download a file. " + '\n')
        return

    path_to_zip = os.path.join(f'artifacts.zip')
    with open(path_to_zip, 'wb') as f:
        f.write(downloaded.content)
    try:
        with ZipFile(path_to_zip, 'r') as zip_ref:
            zip_ref.extractall('.')
        os.remove(path_to_zip)
    except BadZipFile:
        sys.stderr.write('Cannot find file at:' + str(path_to_zip) + '\n')
        sys.stderr.flush()


def main():
    """
    Run through all scenarios where you would want to use
    a CI_JOB_TOKEN
    """
    v4_origin = 'https://gitlab.com/api/v4'
    project_id = env('CI_PROJECT_ID')
    job_token = env('CI_JOB_TOKEN')
    commit_sha = env('CI_COMMIT_SHA')
    download_disabled = env('DOWNLOAD_DISABLED', default=False, cast=bool)

    url = f'https://gitlab.com/api/v4/projects/{project_id}/repository/commits/{commit_sha}'

    pipeline_url = f'https://gitlab.com/api/v4/projects/{project_id}/pipelines/'

    headers = {
        'JOB-TOKEN': job_token
    }

    r = requests.get(url, headers=headers)

    if not r.ok:
        print('Had an issue:', r.content)
        exit(1)

    response = r.json()

    if 'parent_ids' not in response:
        sys.stderr.write('Unable to find parent IDs')
        exit(2)

    parent_ids = response['parent_ids']

    if len(parent_ids) != 1:
        print('WARNING: Coming from multiple parents')
        # exit(510)

    for commit_sha in parent_ids:
        url = f'https://gitlab.com/api/v4/projects/{project_id}/repository/commits/{commit_sha}'
        print('Looking into commit:', url)
        r = requests.get(url, headers=headers)

        if not r.ok:
            print('Had an issue:', r.content)
            exit(1)

        response = r.json()

        try:
            response['last_pipeline']['ref']
        except TypeError:
            continue

        commit_ref = response['last_pipeline']['ref']
        pipeline_id = response['last_pipeline']['id']
        jobs_url = f'{v4_origin}/projects/{project_id}/pipelines/{pipeline_id}/jobs/'

        jobs_artifact_url = f'{v4_origin}/projects/{project_id}/jobs/artifacts/{commit_ref}/download?job=test'
        download_file(v4_origin, project_id, headers, commit_ref=commit_ref, job_name='test')


if __name__ == '__main__':
    main()
