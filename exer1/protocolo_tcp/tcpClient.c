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
#include <math.h>

#define MAX_SIZE 10000

double vet[MAX_SIZE];

void tratasinal(int s){
	if(s == SIGINT){
		printf(" COMAND0 - Digite FIM para encerrar conexão!!!\n>");
	}
}

void iniciaVetor (){
	double aux = 0;
	for (int i = 0; i < MAX_SIZE; i++){
		aux = pow ((i - (rand() % MAX_SIZE)/2), 2);
		vet[i] = sqrt(aux);
	};
};

int main(int argc,char * argv[]) {
	signal(SIGINT,  tratasinal);
	struct  sockaddr_in data_server; 
	int     sd;          	               
	int     n,k;                  
	char    buf_sen[MAX_SIZE];     
	double    buf_rec[MAX_SIZE];     

  	if(argc<3)  {
    	printf("OBS - uso correto: %s <ip_do_servidor> <porta_do_servidor>\n", argv[0]);
    	exit(1);  
	}

	memset((char *)&data_server,0,sizeof(data_server)); 
	memset((int *)&vet,0,sizeof(vet));    
	
	data_server.sin_family      = AF_INET; 
	data_server.sin_addr.s_addr = inet_addr(argv[1]);
	data_server.sin_port        = htons(atoi(argv[2]));

	iniciaVetor();

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd < 0) {
		fprintf(stderr, " ERROR - Criacao do socket!\n");
		exit(1); 
	}

	if (connect(sd, (struct sockaddr *)&data_server, sizeof(data_server)) < 0) {
		fprintf(stderr,"ERROR - Tentativa de conexao!\n");
		exit(1); 
	}

	int count = 0;
	while (count < 1) {
		if (send(sd,&vet,MAX_SIZE * sizeof(double), 0) < 0) {
			puts("ERROR - Envio de dados ao servidor");
			break;
		}
		printf("ENVIO - Pacote de dados -> %d: \n", count);
		for (int i = 0; i < MAX_SIZE; i++){
			printf("%.2f |", vet[i]);
		};
		printf("\n");
		count ++;
	}

	int aux;
	
	if(recv(sd, &buf_rec, sizeof(buf_rec),0) < 0){
		puts("ERROR - Recebimento de dados do servidor");
		exit(1);
	}else{
		printf("MAIOR ->  %.2f\n", buf_rec[0]);
		printf("MENOR -> %.2f\n", buf_rec[1]);
	};


	
	printf("FIM - Conexão com o servidor encerrada\n");
	close (sd); 
	return (0);
} 
