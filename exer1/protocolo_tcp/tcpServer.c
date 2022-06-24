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
#include <float.h>

#define QLEN 10          
#define MAX_SIZE 10000	

double compara_maior(double *array){
	double maior = DBL_MIN;
	double menor = DBL_MAX;
	for(int i = 0;i<MAX_SIZE;i++){
		if(array[i] < menor) menor = array[i];
		if(array[i] > maior) maior = array[i];
	}
	return maior;
};

double compara_menor(double *array){
	double maior = DBL_MIN;
	double menor = DBL_MAX;
	for(int i = 0;i<MAX_SIZE;i++){
		if(array[i] < menor) menor = array[i];
		if(array[i] > maior) maior = array[i];
	}
	return menor;
};

void recebe_cliente(int descritor, struct sockaddr_in endereco_cliente)  {

	double buf_rec[MAX_SIZE]; 
	int  n; 
	double res[2];

	int count = 0;
	while (count < 1) {
		memset(&buf_rec, 0x0, MAX_SIZE * sizeof(double));
		n = recv(descritor, &buf_rec, sizeof(buf_rec),0); 
		printf("Client - Pactote %d -> ", count);
		for(int i = 0; i < MAX_SIZE; i++){
			printf ("%.2f |", buf_rec[i]);
		}
		printf("\n");
		count++;
  	} 

	res[0] = compara_maior(buf_rec);
    res[1] = compara_menor(buf_rec);

	write(descritor, &res, 2 * sizeof(double));
	fprintf(stdout, "Encerrando conexao com: %u ...\n\n", ntohs(endereco_cliente.sin_port));
	close (descritor);
 }

int main(int argc, char *argv[]){

   	struct sockaddr_in endereco_servidor;     
   	struct sockaddr_in endereco_cliente;    
   	int    sd, novo_sd;      
	int    pid,n; 

    socklen_t alen;

	if (argc < 3) {
		printf("Digite IP e Porta para este servidor\n");
		exit(1); 
	}


   memset((char *)&endereco_servidor,0,sizeof(endereco_servidor));     
   endereco_servidor.sin_family 		= AF_INET;           
   endereco_servidor.sin_addr.s_addr 	= inet_addr(argv[1]); 	
   endereco_servidor.sin_port 		= htons(atoi(argv[2])); 	    

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd < 0) {
		fprintf(stderr, "ERROR - Criacao do socket!\n");
		exit(1); 
	}

	if (bind(sd, (struct sockaddr *)&endereco_servidor, sizeof(endereco_servidor)) < 0) {
		fprintf(stderr,"ERROR - Ligacao Falhou!\n");
		exit(1); 
	}

	if (listen(sd, QLEN) < 0) {	
		fprintf(stderr,"ERROR - Escuta da porta!\n");
		exit(1); 
	}
	printf("Conexão - Servidor ouvindo no IP -> %s | Porta -> %s ...\n\n", argv[1], argv[2]);

	alen = sizeof(endereco_cliente);
	for ( ; ; ){
		if ( (novo_sd=accept(sd, (struct sockaddr *)&endereco_cliente, &alen)) < 0) {
			fprintf(stdout, "ERROR - Falha na conexao\n");
			exit(1); 
		}
		if(fork() == 0){
			fprintf(stdout, "Conexão - %u conectado. PID: %d\n\n", ntohs(endereco_cliente.sin_port), getpid()); 
			recebe_cliente(novo_sd, endereco_cliente); 
			exit(0); 
		}
	} 
	close(novo_sd);
	return 0;
} 


