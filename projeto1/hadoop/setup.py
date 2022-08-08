#!/usr/bin/python3

import os
from snakebite.client import Client
from random import choice
import json
client = Client('localhost', 9000)
words_qtde = 2**20

def setup_hadoop():

    if client.test('/output', exists=True):
        for p in client.delete(['/output'], recurse=True):
            print(p)

    if client.test('/input', exists=True):
        for p in client.delete(['/input'], recurse=True):
            print(p)

    if not client.test('/input', exists=True):
        for f in client.mkdir(['/input']):
            print(f'Created file: {f}')

    

def generate_words():
    with open('words.json', 'r') as jf:
        words = json.load(jf)
    with open('input.txt', 'w') as fp:
        for i in range(words_qtde):
            fp.write(str(choice(words))+'\n')

def send_file_to_hadoop():
    os.system('hdfs dfs -put input.txt /input')

    for f in client.ls(['/input']):
        print(f)

if __name__ == '__main__':
   setup_hadoop()
   generate_words()
   send_file_to_hadoop()