#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include<windows.h>
#include<math.h>
//#include "Lista.h"
//#include "ArvoreBinaria.h"
#include "TabelaHash.h"
#include "Extra.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);

    printf("\n\nARQUIVO DE TESTES\n\n");

    //limpando_buffer();

    int extra = VerificaID();

    int chave = CalculaChave(extra);

    printf("RESULTADO FINAL: %d", chave);

return 0;
}
