#!/usr/bin/python3

import os
import json
from tqdm import tqdm
from random import choice
from snakebite.client import Client

client = Client('localhost', 9000)
words_qtde = 2**26

def setup_hadoop():

    if client.test('/output', exists=True):
        for p in client.delete(['/output'], recurse=True):
            print(f'\tDiretório deletado: {p}')

    if client.test('/input', exists=True):
        for p in client.delete(['/input'], recurse=True):
            print(f'\tDiretório deletado: {p}')

    if not client.test('/input', exists=True):
        for f in client.mkdir(['/input']):
            print(f'\tDiretório criado: {p}')

    

def generate_words():
    with open('words.json', 'r') as jf:
        words = json.load(jf)
    with open('input.txt', 'w') as fp:
        for i in tqdm(range(words_qtde)):
            fp.write(str(choice(words))+'\n')

def send_file_to_hadoop():
    os.system('hdfs dfs -put input.txt /input')

    for f in client.ls(['/input']):
        print(f'\tArquivos no diretório HDFS /input: {f}')

if __name__ == '__main__':
    print("Configurando os diretórios no hdfs")
    setup_hadoop()
    print("Gerando o arquivo de input")
    generate_words()
    print("Enviando o arquivo para o direório do hdfs")
    send_file_to_hadoop()