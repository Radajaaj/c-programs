#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int main(){
    char hello [] = "Hello";
    char world [] = "World!";

    if (strcmp (hello, "Hello ")){
        if(strcmp(world, "World! ")){
            printf("%.5s %.6s", hello, world);
        }
    }
    return 0;
}
