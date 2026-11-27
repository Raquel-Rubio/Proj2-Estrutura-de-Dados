#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include<windows.h>
#include<math.h>
//#include "Lista.h"
#include "ArvoreBinaria.h"
#include "TabelaHash.h"
#include "Extra.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int loop = 1, seletor;

    //Lista *L = CriaLista();
    Equipamento *Hash[47] = {NULL};

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
                liberaTabela(Hash);
                loop = 0;
                break;

            case 1:
                printf("\nCadastrar Equipamento\n\n");

                Equipamento *aux = (Equipamento*) malloc (sizeof(Equipamento));
                int extra,chave, i;
                char h;

                do{
                extra = VerificaID();
                chave = CalculaChave(extra);
                }while(!ExisteEqui(Hash, chave, extra));
                aux->dados.CodEqui = extra;

                printf("\nPor favor insira o Nome do Equipamento (LLL000):   ");
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

                aux->dados.IL = CriaLista();

                inserirEqui(Hash, chave, aux->dados);
                ImprimeEqui(Hash, chave, extra);
                free(aux);
                break;

            case 2:
                printf("\nRegistrar Incidentes\n");
                int temporario, temp2, chave2;
                NoArv *aux2 = (NoArv*)malloc(sizeof(NoArv));

                if(HashVazia(Hash)){
                    printf("Não existem Equipamentos registrados nesse sistema");
                    break;
                }
                printf("\nÉ necessário o Código do Equipamento relacionado ao Insidente");
                do{
                temporario = VerificaID();
                chave2 = CalculaChave(extra);
                }while(ExisteEqui(Hash, chave2, extra));
                aux2->info.CodEqui = temporario;

                aux2->info.NumIden = VerificaNumIdem();

                aux2->info.Grave = VerificaPriori();

                //colocar inserir aqui
                //colocar impromir aqui

                free(aux2);

                break;

            case 3:
                printf("\nConsultar um Equipamento");

                int cod, chave3;
                if(HashVazia(Hash)){
                    printf("Não existem Equipamentos registrados nesse sistema");
                    break;
                }
                printf("\nÉ necessário o Código do Equipamento relacionado ao Insidente");
                do{
                cod = VerificaID();
                chave3 = CalculaChave(extra);
                }while(ExisteEqui(Hash, chave3, extra));

                //Arrumar a impressão para consultar a arvore ISSO NAO TA PRONTOOOO
                system("pause");
                break;

            case 4:
               printf("\nImprimir todos os incidentes em ordem crescente");

               system("pause");
               break;

            case 5:
                printf("\nApagar um incidente");
                system("pause");
                break;

            case 6:


                system("pause");
                break;
            }

    }

    return 0;
}
