#include <stdio.h>

struct amogas{
    char nome[20];
    char cor[12];
    int id;
};

int main(){
    FILE *file = NULL;
    file = fopen("amogascrew.bin", "wb");
    fflush(stdin);

    if(file == NULL){
        printf("Erro!");
        return 0;
    }

    struct amogas crew1[10];
    int i = 0;
    
    while(i < 10){
        printf("\n\nNome crewmate %i!\nR: ", i + 1);
        gets(crew1[i].nome);
        fflush(stdin);

        printf("\nCor crewmate %i!\nR: ", i + 1);
        gets(crew1[i].cor);
        fflush(stdin);

        printf("\nID crewmate %i!\nR: ", i + 1);
        scanf("%i", &crew1[i].id);
        fflush(stdin);
        i++;
    }

    int escritos = fwrite(crew1, sizeof(struct amogas), 10, file);


    printf("\nEscritos %i blocos!", escritos);

    fclose(file);

    return 0;
}