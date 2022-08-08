from random import choice
import json

words_qtde=2**26

def generate_words():
    with open('words.json', 'r') as jf:
        words = json.load(jf)
    with open('input.txt', 'w') as fp:
        for i in range(words_qtde):
            fp.write(str(choice(words))+'\n')

generate_words()