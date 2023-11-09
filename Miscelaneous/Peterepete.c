#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char petursivo(){
    char pet[100];
    printf("\nEu tinha dois cachorros, o Pete e o Repete. O Pete morreu, qual sobrou?\nR: ");
    gets(pet);
    fflush(stdin);

    if(strncmp(pet, "Repete", 6) == 0){
        petursivo();

    }else{
        printf("\nSeu burro!\n");
    }
    return "0";
}

int main(){
    petursivo();
}