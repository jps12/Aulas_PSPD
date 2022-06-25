const MAX_SIZE = 5000;
struct vetor{
    double vetor[MAX_SIZE];
};

struct double_pair{
    double a;
    double b;
};

program MIN_MAX{
    version VERSAO{
        double_pair vetor_min_max(vetor)=1;
    }=100;
}=200;