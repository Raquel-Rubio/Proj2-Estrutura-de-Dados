#ifndef EXTRA_H_INCLUDED
#define EXTRA_H_INCLUDED

void limpando_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int PegarInteiros(){
    int PI, voltaInteiros=0;
    while(voltaInteiros==0){
        if(scanf(" %d", &PI)==0){
                limpando_buffer();
                printf("\nPor favor insira um valor válido:   ");
        }
        else{
            voltaInteiros=1;
            return PI;
        }
    }
}


char PegarCaracter(){ //aceita letras e numeros, na teoria
    int voltaChar=0;
    char c;
        while(voltaChar == 0){
            if(c==13){
                return '\0'; //lembrar de colocar na main o "if(_=='\0')" tem que sair
            }
            else{
            c = getch();
            printf("%c", c);
            voltaChar = 1;
            return c;
            }
        }
    }

char PegarUMInteiro(){
    int voltaUMInt=0;
    char c;
    while(voltaUMInt == 0){
        c = getch();
        if(isdigit(c)!= 0){
            voltaUMInt = 1;
            printf("%c", c);
            return c;
        }
        printf("\nÉ necessário que seja um número:   ");
    }

}

char PegarLetra(){ //nao aceita espaço
    int voltaChar=0;
    char c;
    while(voltaChar == 0){
        c = getch();
        if(isalpha(c)!= 0){
            printf("%c", c);
            voltaChar = 1;
            return c;
        }
        if(c==13){
            return '\0';
        }
        printf("\nÉ necessário que seja uma letra:   ");
    }
}

int VerificaID(){
    int verif;
    do{
        printf("\nInsira o Código de Identificação do Equipamento:   ");
        verif = PegarInteiros();
        limpando_buffer();
    }while(verif<1000 || verif>9999);
    return verif;
}


int VerificaNumIdem(){
    int verif;
    do{
        printf("\nInsira o Número Único de Indentificação do Equipamento (00): ");
        verif = PegarInteiros();
        limpando_buffer();
    }while(verif<10 || verif >99);
    return verif;
}

int VerificaPriori(){
    int verif;
    do{
        printf("\n\nPor favor insira o nível de Prioridade (1 a 3):   ");
        verif = PegarInteiros();
        limpando_buffer();
    }while(verif<1 || verif>3);
    return verif;
}
#endif // EXTRA_H_INCLUDED
