#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>

int comtador(int num){
    static int n = 0;
    
    if(n < num){
        //static int n = -1;
        n++;
        printf("%i ", n);
        comtador(num);
        return n;

    }else if(n > num){
        //static int n = 1;
        n--;
        printf("%i ", n);
        comtador(num);
        return n;
    }
    return 0;
}

void main(){
    int num = 0;
    printf("\nAte que numero voce quer contar?\nR: ");
    scanf("%i", &num);
    comtador(num);
}