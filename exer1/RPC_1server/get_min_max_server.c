#include <stdio.h>
#include <stdlib.h>
#include "get_min_max.h"

int get_min(int a, int b){
	return a < b? a : b;
}

int get_max(int a, int b){
	return a > b? a : b;
}

double_pair *
vetor_min_max_100_svc(vetor *argp, struct svc_req *rqstp)
{
	static double_pair  result;

	printf("Realizando a operação de pergar o menor e o maior valor\n");

	double min_val = INT_MAX, max_val = INT_MIN;

	for (int i=0; i<MAX_SIZE; i++) {
		min_val = get_min(min_val, argp->vetor[i]);
		max_val = get_max(max_val, argp->vetor[i]);
	}

	result.a = min_val;
	result.b = max_val;

	printf("Retornando o maior valor como: %lf\n E o menor valor como: %lf", max_val, min_val);

	return &result;
}
