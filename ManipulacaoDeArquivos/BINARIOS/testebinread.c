#include <stdio.h>

typedef struct{
    char name[20];
    char cor[12];
    int id;
}newmogas;

int main(){
    FILE *file = NULL;

    file = fopen("amogascrew.bin", "rb");

    if(file == NULL){
        printf("Erro!!!!");
        return 0;
    }

    newmogas copycrewt[10];

    int escritor;

    escritor = fread(copycrewt, sizeof(newmogas), 10, file);

    fclose(file);

    printf("Copiados %i blocos!", escritor);

    for(int i = 0; i < 10; i++){
        printf("Nome: %s, Cor: %s, ID: %i\n", copycrewt[i].name, copycrewt[i].cor, copycrewt[i].id);
    }

    return 0;
}