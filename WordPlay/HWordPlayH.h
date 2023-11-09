int errol = 0, errop = 0, tentatival = 0, tentativap = 0;

void mensagemvitoria(){

    limpatela();
    printf("===============================================================================\n");
    printf("===================PARABENS!! Voce Ganhou o SUPER WORD PLAY!!==================\n");
    printf("--------------------- Voce teve %i acerto(s) e %i erro(s)! --------------------\n\n", (tentatival + tentativap) - (errol + errop), errol + errop);
    while(1 == 1){

    }
}

void mensagemderrota(){

    limpatela();

    printf("================================================================================\n");
    printf("==================Que triste! Voce Perdeu o SUPER WORD PLAY :(==================\n");
    printf("--------------------- Voce teve %i acerto(s) e %i erro(s)! ---------------------\n\n", (tentatival + tentativap) - (errol + errop), errol + errop);
}

char cores[5][20] = //Essa matriz possui as respostas do quiz cores
    {"azul",
     "verde",
     "vermelho",
     "roxo",
     "amarelo"};

char coresd[5][100] = //Essa matriz possui as dicas do quiz cores
    {"A cor do ceu",
     "Clorofila",
     "A cor mais quente",
     "Mistura de azul e vermelho",
     "A cor mais valiosa"};

char futebol[5][20] = //Essa matriz possui as respostas do quiz futebol
    {"internacional",
     "internacional",
     "internacional",
     "internacional",
     "internacional"};

char futebold[5][100] = //Essa matriz possui as dicas do quiz futebol
    {"Vencedor da mundial de clubes de 2006?",
     "Melhor time do mundo?",
     "Torcedores deste time sao chamados de colorados",
     "Maior campeao do campeonato gaucho?",
     "Time criado em Porto Alegre, com a missao de acolher pessoas de qualquer nacionalidade?"};

char animais[5][20] = //Essa matriz possui as respostas do quiz animais
    {"capivara",
     "morcego",
     "guepardo",
     "baleia azul",
     "mosquito"};

char animaisd[5][100] = //Essa matriz possui as dicas do quiz animais
    {"Maior roedor do mundo",
     "O unico mamifero capaz de voar",
     "Animal mais rapido do mundo",
     "Maior animal que ja viveu na terra",
     "Animal que mata mais humanos todo ano"};

char trivia[5][20]; //O tema selecionado será copiados nessa matriz
char dicas[5][100]; //As dicas do tema selecionado serão copiados nessa matriz
char display[5][20]; //É nessa matriz que será mostrado o seu progresso no quiz

void limpatela(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("cls");
    //Não tenho certeza se essa função "system("cls")" de limpar o terminal vai funcionar fora do windows 10.
    //Por isso, antes dela eu também coloquei a função "limpatela()", para simular uma limpeza de tela.
    //Se o system("cls"); der erro na sua máquina, apenas transforme-o em comentário (adicionando // antes dele)
}

void preparacao(){//Essa função preparar a matriz de display, trabsformando as letras em espaços (" ") e os finais em "* * *"
    int i, j, k;

    for(i = 0; i < 5; i++){
        k = strlen(trivia[i]);
        //debug printf("\nLinha %i", i);

        for(j = 0; j < 20; j++){
            if(j < k){
                display[i][j] = ' ';
                //strcat(display, " "); //strcat tambem funciona, a função de cima é mais segura
                //debug printf("%c e ", display[i][j]);
            }else{
                display[i][j] = '*';
                //strcat(display, "*");
                //debug printf("%c e ", display[i][j]);
            }
        }
        //debug printf("\n cabolinha\n");
    }
}

void desenhadisplay(){
    int p, q;
    printf("\n\n");
    for(p = 0; p < 5; p++){
        printf("%i |", (p + 1));
        for(q = 0; q < 14; q++){
            printf("%c |", display[p][q]);
        }
        printf("\n");
    }
    for(p = 0; p < 5; p++){
        printf("\n%i - ", (p + 1));
        printf("%s", dicas[p]);
    }
}

void desenhaplacar(){
    printf("------------- Palavras erradas: %i / 2 ----- Letras erradas: %i / 8 -------------", errop, errol);
}

int opcionador(){
    int resp;
    printf("\n\nO que voce deseja fazer?\n1) Escolher uma letra\n2) Completar uma palavra\nR: ");
    scanf("%i", &resp);
    fflush(stdin);
    return resp;
}

void letrador(char letra){//Função para processar as letras inseridas
    int l = 0, c = 0, cont = 0;

    for(l = 0; l < 5; l++){
        for(c = 0; c < 20; c++){
            if(letra == trivia[l][c] && letra != display[l][c]){
                cont = cont + 1;
                display[l][c] = letra;
            }else{
            //printf("nao"); debug
            }
            //printf("cont %i", cont);
            //Sleep(25); debug
            }
        }
        if(cont == 0){
            errol = errol + 1;
        }
    }

void palavrador(char palavra[20]){
    int l = 0, h = 0, c = 0, cont = 0;
    c = strlen(palavra);


    for(l = 0; l < 5; l++){

        if(strcmp(palavra, trivia[l]) == 0 && strncmp(palavra, display[l], c) != 0){
            cont = cont + 1;
            for(h = 0; h < c; h++){
                display[l][h] = palavra[h];
            }
        }
    }
    if(cont == 0){
        errop = errop + 1;
    }
}

void comparador(){
    int l, tam, cont, fim = 0;

    for(l = 0; l < 5; l++){
        tam = strlen(trivia[l]);
        cont = strncmp(display[l], trivia[l], tam);
        if(cont == 0){
            fim = fim + 1;
        }
    }
    if(fim == 5){
        mensagemvitoria();

    }
}
