import os
from snakebite.client import Client

client = Client('localhost', 9000)

def read_output():
    with open('output.txt', 'w') as fp:
        for l in client.text(['/output/part-00000']):
            fp.write(f'{l.decode("utf-8")}')
    
if __name__ == '__main__':
   read_output()