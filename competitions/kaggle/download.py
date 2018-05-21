#!/usr/bin/env python
# -*- coding: utf-8 -*-

import requests
import getpass
import errno
import os


def ensure_dir(path):
    try:
        os.makedirs(path)
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise

def download_and_unzip_data():
    username = input("Enter Kaggle username: ")
    pwd = getpass.getpass("Enter Kaggle password: ")

    # The direct link to the Kaggle data set
    data_urls = [
        'https://www.kaggle.com/c/3971/download/sample_submission.csv',
        'https://www.kaggle.com/c/3971/download/labeledTrainData.tsv.zip',
        'https://www.kaggle.com/c/3971/download/testData.tsv.zip',
        'https://www.kaggle.com/c/3971/download/unlabeledTrainData.tsv.zip',
    ]
    cname = 'c3971-bag-of-words-meets-bags-of-popcorn'
    cfolder = os.path.join(os.path.dirname(__file__), cname)
    cfolder = os.path.join(cfolder, 'data')
    ensure_dir(cfolder)
    
    for data_url in data_urls:
        print('Download %s' % data_url)
        # The local path where the data set is saved.
        local_filename = data_url.split('/')[-1]

        # Kaggle Username and Password
        kaggle_info = {'UserName': username, 'Password': pwd}

        # Attempts to download the CSV file. Gets rejected because we are not logged in.
        r = requests.get(data_url)

        # Login to Kaggle and retrieve the data.
        r = requests.post(r.url, data = kaggle_info, prefetch=False)

        # Writes the data to a local file one chunk at a time.
        cfile = os.path.join(cfolder, local_filename)
        f = open(cfile, 'wb')
        for chunk in r.iter_content(chunk_size = 512 * 1024): # Reads 512KB at a time into memory
            if chunk: # filter out keep-alive new chunks
                f.write(chunk)
        f.close()
        print('Done')


if __name__ == '__main__':
    download_and_unzip_data()
