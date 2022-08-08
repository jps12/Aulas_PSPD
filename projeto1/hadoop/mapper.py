#!/usr/bin/python3
import sys

def mapper():
    for line in sys.stdin:
        line_words = line.split()
        for word in line_words:
            print(f'{word}\t{1}')

if __name__ == '__main__':
   mapper()
