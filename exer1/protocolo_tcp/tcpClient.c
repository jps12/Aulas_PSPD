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

#define MAX_SIZE 10

int vet[MAX_SIZE];

void tratasinal(int s){
	if(s == SIGINT){
		printf(" --> Digite FIM para encerrar conexão!!!\n>");
	}
}

void creatingVector (){
	for (int i = 0; i < MAX_SIZE; i++){
		vet[i] = i;
	};
};

int main(int argc,char * argv[]) {
	signal(SIGINT,  tratasinal); // Trata o signal ctrl+c
	struct  sockaddr_in data_server; // contem os dados do server	 	
	int     sd;          	      // descritor              
	int     n,k;                  // caracteres lidos do server 
	char    buf_sen[MAX_SIZE];     // buffer de dados enviados  
	char    buf_rec[MAX_SIZE];     // buffer de dados recebidos  
	
	//confere o numero de argumentos passados para o programa 
  	if(argc<3)  {
    	printf("uso correto: %s <ip_do_servidor> <porta_do_servidor>\n", argv[0]);
    	exit(1);  
	}

	memset((char *)&data_server,0,sizeof(data_server)); // limpa estrutura 
	memset((int *)&vet,0,sizeof(vet));     // limpa o buffer 
	
	data_server.sin_family      = AF_INET; // configura o socket a internet
	data_server.sin_addr.s_addr = inet_addr(argv[1]);
	data_server.sin_port        = htons(atoi(argv[2]));

	creatingVector();

	// Cria o socket 
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd < 0) {
		fprintf(stderr, "Criacao do socket falhou!\n");
		exit(1); 
	}

	// Conecta o socket ao servidor 	
	if (connect(sd, (struct sockaddr *)&data_server, sizeof(data_server)) < 0) {
		fprintf(stderr,"Tentativa de conexao falhou!\n");
		exit(1); 
	}

	int count = 0;
	while (count < 5) {
		send(sd,&vet,MAX_SIZE * sizeof(int),0); 
		printf("ENVIANDO PACOTE DE DADOS > %d", count);
		printf("\n");
		count ++;
	}
	
	printf("------- conexão com o servidor encerrada -----\n");
	close (sd); 
	return (0);
} 
