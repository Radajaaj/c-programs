#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
char nome1[100], nome2[100];
int numnom;

printf("Tell me your first name! NOW!\n");
gets(nome1);
fflush(stdin);

numnom = strlen(nome1);

printf("Your name has %i characters!!\n", numnom);

printf("Tell me your surnames name! NOW!\n");
gets(nome2);
fflush(stdin);

if(strcmp(nome2, nome1)){
    strcat(nome1, " ");
    strcat(nome1, nome2);
    printf("Your full name is %s!!\n", nome1);
}else{
    printf("Your name is equal to your surname!!!!!1!!1!");
}

return 0;
}
