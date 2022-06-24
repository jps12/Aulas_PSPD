# Exercício 1 de PSPD

## Introdução

O objetivo desse experimento é apresentar as caracterísJcas inerentes à construção de aplicações distribuídas, incluindo passagem de parâmetros, envolvendo módulos cliente e servidor usando RPC e Sockets TCP/UDP.

### Apresentação dos alunos:

| Nome | Matrícula |
| ---- | --------- |
| João Pedro Silva de Carvalho | 180033743 |
| Victor Samuel dos Santos Lucas | 180028685 |

## Sobre o exercício
O arquivo PDF que contém as informações para o exercício relatado pode ser encontrado clicando [aqui](PSPD2022_1_Lab1.pdf).

## 🚀 TCP 

### O protocolo
A aplicação funciona com base no protocolo de comunicação TCP (Transmission Control Protocol), ou seja, realiza a transmissão de um pacote de dados entre duas máquinas. Durante uma comunicação através do protocolo TCP, as duas máquinas devem estabelecer uma conexão. A máquina emissora (que pede a conexão) chama-se cliente enquanto a máquina receptora é o servidor. Dizemos então que estamos em um ambiente cliente-servidor. As máquinas em tal ambiente se comunicam em modo conectado, ou seja, a comunicação é feita nos dois sentidos.

### Funcionamento
Com base na introdução abordada anteriormente, a aplicação funciona da seguinte maneira: 
 - O Cliente envia ao servidor um vetor de 10 mil possições contendo números aleatórios;
 - O Servidor recebe o pacote de dados enviado pelo cliente e calcula o maior e menor número do vetor;
 - O Servidor retorna ao cliente o maior e menor número;
 - O Cliente recebe e visualiza os dados.

### Limitações
O lado servidor não está aceitando o vetor de 500 mil posições. Para caso de teste foi usado um vetor de 10 mil. 

### Dificuldades
A principal dificuldade foi fazer a comunicação enviando um pacote contendo um vetor de 500 mil posições. A idéia para essa solução consistiu em dividir o vetor em um número x de pacotes e realizar o envio de cada pacote separadamente, com isso o problema de sobrecarga seria corrigido, porém, essa solução não foi implementada por problemas técnicos de implementação. 

### 💻 Como Rodar
> Compilar o lado Servidor 

    gcc tcpServer.c -o tcpServer
> Executar o lado Servidor 

    ./tcpServer 127.0.0.1 5000
> Compilar o lado Cliente 

    gcc tcpClient.c -o tcpClient
> Executar o lado Cliente 

    ./tcpClient 127.0.0.1 5000
> Obs: 
    
    O ip 127.0.0.1 refere-se ao servidor local da máquina e o segundo parâmetro está relacionado a porta nesse servidor, com isso é necessário que ela estaja disponível para uso. 


## 🚀 RPC 

### Socket

### Problema

### RPC (intro sobre esse tipo de protocolo)

### Socket (intro sobre esse tipo de protocolo)

### Solução apresentada

### 💻 Como Rodar

## 🔖 Opinião geral (adicionar a nota aqui tbm)

#### Victor Samuel dos Santos Lucas

#### João Pedro Silva de Carvalho
