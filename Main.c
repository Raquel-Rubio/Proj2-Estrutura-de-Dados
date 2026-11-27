#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include<windows.h>
#include<math.h>
#include "ArvoreBinaria.h"
#include "TabelaHash.h"
#include "Extra.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int loop = 1, seletor;

    //Lista *L = CriaLista();
    Equipamento *Hash[47] = {NULL};
    Arv* Arvore = CriaArv();

    while(loop != 0) {
        printf("\n\tSistema de Cadastro de Manutenção\n\n");

        printf("Escolha o procedimento:\n\t");
        printf("1 - Cadastrar equipamento\n\t");
        printf("2 - Registrar incidente\n\t");
        printf("3 - Consultar Equipamento e Incidente\n\t");
        printf("4 - Listar todos os Incidentes\n\t");
        printf("5 - Excluir um Incidente\n\t");
        printf("6 - Excluir um Equipamento\n\t");
        printf("0 - Finalizar\n\n\t");


        seletor = PegarInteiros();
        limpando_buffer();

            switch(seletor){

            case 0:
                printf("\n\n\t\tObrigado por usar nosso sistema\n\n");
                //liberaArv(Arvore);
                liberaTabela(Hash);
                loop = 0;
                break;

            case 1:
                printf("\nCadastrar Equipamento\n\n");

                Equipamento *aux = (Equipamento*)malloc(sizeof(Equipamento));
                int extra,chave, i;
                char h;


                do{
                extra = VerificaID();
                chave = CalculaChave(extra);
                }while(!ExisteEqui(Hash, chave, extra));

                printf("\nPor favor, insira o Nome do Equipamento:   ");
                for(i=0; i<10; ){
                    h = PegarCaracter(1);
                    if(h=='\0'){
                        break;
                    }
                    aux->dados.NomeEqui[i] = h;
                    i++;
                }
                for(; i<11; i++){
                    aux->dados.NomeEqui[i] = '\0';
                }
                printf("\n\tNome do Equipamento informado: %s\n", aux->dados.NomeEqui);
                inserirEqui(Hash, chave, aux->dados);
                ImprimeEqui(Hash, chave, extra);
                free(aux);
                break;

            case 2:
                printf("\nRegistrar Incidentes\n");
                int temporario;

                printf("\nPor favor insira o Código do Equipamento relacionado ao Insidente");
                    temporario = VerificaID();
                    Equipamento *e = BuscaEquipamento(Hash, temporario);
                    if(e == NULL){
                        printf("\nEquipamento não cadastrado\n");

                break;

            case 3:
                // int encon = VerificaSoli();

                // AchaItemNo(L, encon);

                break;

            case 4:

                        
                // int Mprio, Mperi, mudar;
                // printf("\nAlterar Prioridade e/ou Periodo:");
                // printf("\n\t1-Mudar apenas a Prioridade \n\t2-Mudar apenas o Periodo\n\t3-Mudar Prioridade e Periodo\n\n\t");
                // do{
                //     mudar = PegarInteiros();
                // }while(mudar<1 || mudar>3);

                // int altera = VerificaSoli();

                // int Q = AchaPrioPeri(mudar, L, altera);
                // if(Q == 0){
                //     break;
                // }
                // else{
                //     switch(mudar){
                //         case 1:
                //             do{
                //                 Mprio = VerificaPriori();
                //             }while(!VPInterno(Mprio, Q));
                //             Mperi = Q;
                //             break;

                //         case 2:
                //             Mperi = VerificaPeriodo(Q);
                //             Mprio = Q;
                //             break;

                //         case 3:
                //             Mprio = VerificaPriori();
                //             Mperi = VerificaPeriodo(Mprio);
                //             break;
                //     }

                // }

                // Modifica(L, altera, Mprio, Mperi);
                break;

            case 5:
            //     OrdemManutencao(L);
            //     printf("\n");
            //     system("pause");
            //     break;

            // case 6:
            //     ImprimeLista(L);
            //     printf("\n");
            //     system("pause");
                break;
            }

    }

    return 0;
}
