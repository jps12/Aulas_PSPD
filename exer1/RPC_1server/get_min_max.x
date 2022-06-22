struct vetor{
    int vetor[100];
};

struct int_pair{
    int a;
    int b;
};

program MIN_MAX{
    version VERSAO{
        int_pair vetor_min_max(vetor)=1;
    }=100;
}=200;