#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

#define QLEN 10      // tamanho da fila de clientes  
#define MAX_SIZE 10	// tamanho do buffer 

void recebe_cliente(int descritor, struct sockaddr_in endereco_cliente)  {

	int buf_rec[MAX_SIZE]; // buffer de dados recebidos
	int  n; // número de caracteres lidos do cliente

	int count = 0;
	while (count < 5) {
		memset(&buf_rec, 0x0, MAX_SIZE * sizeof(int));
		n = recv(descritor, &buf_rec, sizeof(buf_rec),0); // recebendo dados da função send do cliente
		printf("Client - Pactote %d -> ", count);
		for(int i = 0; i < MAX_SIZE; i++){
			printf ("%d | ", buf_rec[i]);
		}
		printf("\n");
	count++;
   } 
	fprintf(stdout, "Encerrando conexao com: %u ...\n\n", ntohs(endereco_cliente.sin_port));
	close (descritor); // fecha socket
 }

int main(int argc, char *argv[]){

   	struct sockaddr_in endereco_servidor;  // endereco do servidor   
   	struct sockaddr_in endereco_cliente;   // endereco do cliente    
   	int    sd, novo_sd;          // socket descriptors 
	int    pid,n; 

    socklen_t alen;

	if (argc < 3) { // Verifica a quantidade de argumentos passados no terminal
		printf("Digite IP e Porta para este servidor\n");
		exit(1); 
	}


   memset((char *)&endereco_servidor,0,sizeof(endereco_servidor)); // limpa variavel endereco_servidor    
   endereco_servidor.sin_family 		= AF_INET;           	// familia TCP/IP   
   endereco_servidor.sin_addr.s_addr 	= inet_addr(argv[1]); 	// endereco IP      
   endereco_servidor.sin_port 		= htons(atoi(argv[2])); // PORTA	    

   // Cria o socket 
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd < 0) {
		fprintf(stderr, "Falha ao criar socket!\n");
		exit(1); 
	}

   // liga o socket a porta e ip 
	if (bind(sd, (struct sockaddr *)&endereco_servidor, sizeof(endereco_servidor)) < 0) {
		fprintf(stderr,"Ligacao Falhou!\n");
		exit(1); 
	}

   // Ouve a porta 
	if (listen(sd, QLEN) < 0) {	
		fprintf(stderr,"Falhou ouvindo porta!\n");
		exit(1); 
	}
	printf("Servidor ouvindo no IP %s, na porta %s ...\n\n", argv[1], argv[2]);

   	// Aceita conexoes 
	alen = sizeof(endereco_cliente);
	for ( ; ; ){
		 // espera nova conexao de um processo cliente ... 	
		if ( (novo_sd=accept(sd, (struct sockaddr *)&endereco_cliente, &alen)) < 0) {
			fprintf(stdout, "Falha na conexao\n");
			exit(1); 
		}
		if(fork() == 0){ // Cria processos filho para os clientes
			fprintf(stdout, "%u conectado. PID: %d\n\n", ntohs(endereco_cliente.sin_port), getpid()); 
			recebe_cliente(novo_sd, endereco_cliente); // Função do comportamento do cliente
			exit(0); 
		}
	} 
	close(novo_sd);
	return 0;
} 


