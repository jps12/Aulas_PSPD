#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(void){
    char *str;

    assert((str = getenv("ENV_TESTE")) != NULL);
    printf("Value of \"HOME Envoronment variable\" : %s\n", str);
    return 0;
}