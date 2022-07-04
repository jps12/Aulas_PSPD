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

## 🚀 RPC 

### Problema

O problema proposto a ser resolvido com a programação RPC é que o lado cliente cria um vetor de 500000 posições e manda para o servidor que retorna com o maior e o menor número que estavam naquele vetor. 

### RPC (intro sobre esse tipo de protocolo)

Esse protocolo é um sigla em inglês que significa *Remote Procedure Call* e é um dos principais programas de programação distribuida atualmente. Com ele é possível que partes de um mesmo programa rode em diferentes máquinas. Por exemplo, uma função pode ser programada para rodar em um host A enquanto o resto do programa rode no host B

### 💻 Como rodar 

#### Localmente:

Na pasta RPC_1server compile o código rodando o seguinte comando:

```shell
make
```

*Opcional:* Você pode rodar um comando para limpar todos os arquivos que são gerados na build, rodando:

```shell
make clean
```

Após isso será gerado dois executáveis (ede acordo com o seu sistema operacional), execute eles paralelamente (será mostrado como rodar em sistemas Unix):

O Cliente:
```shell
./client
```

O servidor:
```shell
./server
```

#### Usando docker-compose

É possível rodar os arquivos do RPC usando também o docker-compose, mas esse método apresenta algumas falhas que não apresenta-se localmente. Essas falhas são a não impressão de alguns printf, mas de modo geral o programa é executado corretamente.

Rode: 
```shell
sudo docker-compose up --build
```

## Solução apresentada

A solução apresentada é um arquivo de configuração do RPC com a extensão .x. A partir dele são gerados os demais aquivos, eximindo assim boa parte do trabalho com a configuração de comunicação de rede. com isso foi necessário apenas gerar a lógica dos algoritmos que envolvem a escolha dos dois menores números e a geração dos valores do vetor inicializado no cliente.

## Detalhes da Entrega

### Entrega 1

Conseguimos realizar a entrega dos programas executando como foram propostos, com um porem de que a comunicação TCP não suportou mais que 100000 números no vetor. 

### Entrega 2

Não conseguimos realizar a entrega dois visto a complexidade de dividir essa tarefa além de configurar.

## Opinião geral

### Victor Samuel dos Santos Lucas

Acredito que a proposta do exercício foi uma boa maneira de fixar os conteúdos iniciais sobre distribuição de processos, além de ser uma boa forma de relembrar os protocolos de comunicação TCP/UDP. Nota 8

### João Pedro Silva de Carvalho

Acho que foi uma boa atividade para entender o funcionamento geral do RPC na prática. O complicado dela é que quase não há referências sobre como programar os arquivos de configuração. Nota: 8
