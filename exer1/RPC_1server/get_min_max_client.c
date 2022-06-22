#include "get_min_max.h"


void set_vetor(vetor *vetor_tmp){
	for (int i=0; i<MAX_SIZE; i++) {
		vetor_tmp->vetor[i] = i;
	}
}

void
min_max_100(char *host)
{
	CLIENT *clnt;
	int_pair  *result_1;
	vetor  vetor_min_max_100_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, MIN_MAX, VERSAO, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	set_vetor(&vetor_min_max_100_arg);
	result_1 = vetor_min_max_100(&vetor_min_max_100_arg, clnt);

	printf("O resultado é do menor valor é %d enquanto o maior valor é %d\n", result_1->a, result_1->b);

	if (result_1 == (int_pair *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	min_max_100 (host);
exit (0);
}
