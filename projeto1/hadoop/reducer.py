#!/usr/bin/python3
import sys
from tracemalloc import get_object_traceback

def reducer():
    current_word = ''
    current_ocurrences = 0
    global_ocurrences = 0
    start_letter = {
        's': 0,
        'p': 0,
        'r': 0
    }
    length_repeat = {
        6: 0,
        8: 0,
        11: 0
    }


    for line in sys.stdin:
        global_ocurrences += 1
        word, ocurrences = line.split('\t')
        ocurrences = int(ocurrences)

        if word[0].lower() in start_letter:
            start_letter[word[0].lower()] += 1

        if len(word) in length_repeat:
            length_repeat[len(word)] += 1

        if word == current_word:
            current_ocurrences += ocurrences
            continue

        if current_word:
            print(f'{current_word}\t{current_ocurrences}')
        
        current_word = word
        current_ocurrences = ocurrences
    
    if current_word == word:
        print(f'{current_word}\t{current_ocurrences}')
    print(f'Quantidade total de palavras: {global_ocurrences}')

    for key, value in start_letter.items():
        print(f'Quantidade de palavras que começam com a letra {key.upper()} : {value}')

    for key, value in length_repeat.items():
        print(f'Quantidade de palavras de tamanho {key} : {value}')

if __name__ == '__main__':
   reducer()
