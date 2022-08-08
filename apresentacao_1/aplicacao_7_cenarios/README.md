# Node.js code for RabbitMQ tutorials

Tenha o RabbitMQ instalado em sua máquina acessando [aqui](https://www.rabbitmq.com/download.html)

Acesse [RabbitMQ](https://www.rabbitmq.com/getstarted.html) para visualizar os tutoriais.

## Tecnologias

### Node.js

- [Node.js](https://nodejs.org/en/download/) 
- [Amqp.node](https://github.com/squaremo/amqp.node)

## Como rodar
``` shell
    npm install 
    npm install amqplib -g
```
 


### Cenários

[Tutorial um: "Hello World!"](https://www.rabbitmq.com/tutorials/tutorial-one-javascript.html):

``` shell
node src/send.js
node src/receive.js
```

[Tutorial dois: Work Queues](https://www.rabbitmq.com/tutorials/tutorial-two-javascript.html):

``` shell
node src/new_task.js "A very hard task which takes two seconds.."
node src/worker.js
```

[Tutorial três: Publish/Subscribe](https://www.rabbitmq.com/tutorials/tutorial-three-javascript.html)

``` shell
node src/receive_logs.js
node src/emit_log.js "info: This is the log message"
```

[Tutorial quatro: Routing](https://www.rabbitmq.com/tutorials/tutorial-four-javascript.html):

``` shell
node src/receive_logs_direct.js info
node src/emit_log_direct.js info "The message"
```


[Tutorial cinco: Topics](https://www.rabbitmq.com/tutorials/tutorial-five-javascript.html):

``` shell
node src/receive_logs_topic.js "*.rabbit"
node src/emit_log_topic.js red.rabbit Hello
```

[Tutorial seis: RPC](https://www.rabbitmq.com/tutorials/tutorial-six-javascript.html):

``` shell
node src/rpc_server.js
node src/rpc_client.js 30
```