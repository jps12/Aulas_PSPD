# Projeto 1 - Hadoop

## Como rodar

### Instalar as dependencias do python

```shell
pip install snakebite-py3
```

### Instalar o hadoop:

Segue as instruções contidas no seguinte link: [Hadoop_instalação](https://phoenixnap.com/kb/install-hadoop-ubuntu)

### Iniciar o hadoop

```shell
$HADOOP_HOME/sbin/start-all.sh
```

### Rodar o experimento

Gerar o arquivo de input en envia para o HDFS

```shell
python3 setup.py
```

Rode o script start_hadoop.sh para inciar o experimento (em algumas máquina é necessário rodar o comando `chmod +x start_haddop.sh`)
```shell
./start-hadoop.sh
```

### Ler a saída

Apenas rode o arquivo `read-output.py`
```shell
python3 read-output.py
```

Por fim abra o arquivo output.txt, para onde será enviado o output do problema