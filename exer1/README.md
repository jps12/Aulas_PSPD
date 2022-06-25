# Exercício 1 de PSPD

## Introdução

O objeJvo desse experimento é apresentar as caracterísJcas inerentes à construção de aplicações distribuídas, incluindo passagem de parâmetros, envolvendo módulos cliente e servidor usando RPC e Sockets TCP/UDP.

### Apresentação dos alunos:

| Nome | Matrícula |
| ---- | --------- |
| João Pedro Silva de Carvalho | 180033743 |
| Victor Samuel dos Santos Lucas | 180028685 |

## Sobre o exercício
O arquivo PDF que contém as informações para o exercício relatado pode ser encontrado clicando [aqui](PSPD2022_1_Lab1.pdf).

## TCP 

### Funcionamento

### Limitações

### Como Rodar
> Compilar o lado Servidor 

    gcc tcpServer.c -o tcpServer
> Executar o lado Servidor 

    ./tcpServer 127.0.0.1 5000
> Compilar o lado Cliente 

    gcc tcpClient.c -o tcpClient || gcc -o tcpClient tcpClient.c -lm  (Para ambientes que precisam da tag -lm para biblioteca math.h)
> Executar o lado Cliente 

    ./tcpClient 127.0.0.1 5000
> Obs: 
    
    O ip 127.0.0.1 refere-se ao servidor local da máquina e o segundo parâmetro está relacionado a porta nesse servidor, com isso é necessário que ela estaja disponível para uso. 

## Como rodar 

### RPC 

### Socket

### Problema

### RPC (intro sobre esse tipo de protocolo)

### Socket (intro sobre esse tipo de protocolo)


## Solução apresentada

## Detalhes da Entrega

### Entrega 1

### Entrega 2

## Opinião geral (adicionar a nota aqui tbm)

#### Victor Samuel dos Santos Lucas

#### João Pedro Silva de Carvalho
