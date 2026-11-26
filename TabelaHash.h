#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#define A (0.618)
#define M 47

typedef struct noLista{
    int ID;
    struct noLista *prox;
}NoLista;

typedef struct lista{
    NoLista *inicio;
}Lista;

typedef struct dadosEqui{
    int CodEqui;
    char NomeEqui[11];
    Lista *IL; //lista de incidentes
}DadosEqui;

typedef struct equipamento{
    DadosEqui dados;
    struct equipamento *prox;
}Equipamento;

//Função Hash - MULTIPLICAÇÃO

//   47*((codEqui * 0,618)%1) -> achar o menor inteiro do valor obtido
int CalculaChave (int nome){

    float outronome = (nome*0.618);
    outronome = fmodf(outronome, 1);
    outronome = outronome * 47;

    return (int)outronome;
}

Lista* CriaLista(){
     Lista *l;
     l=(Lista*)malloc(sizeof(Lista));
     l->inicio = NULL;
   return l;
}

void liberaLista (Lista* l)
{
    NoLista *aux;
    while(l->inicio!=NULL){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
    free(l);
}

void liberaTabela (Equipamento* E[]){ //livera tabela e a lista de incidentes dentro de cada equi
    Equipamento *aux;
    for(int i=0; i<M; i++){
        while(E[i]!=NULL){
            aux = E[i];
            liberaLista(E[i]->dados.IL);
            E[i] = E[i]->prox;
            free(aux);
        }
    }
    //free(l); da função original mas não creio ser necessário pq a tabela em si nao esta alocada
}

void inserir (Lista *L, int num){
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    novo->ID = num;
    novo->prox = NULL;

    NoLista *aux;
    NoLista *aux2=NULL;
    aux = L ->inicio;
    while(aux!=NULL){
        aux2 = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    if(aux2 == NULL){
        L->inicio = novo;
    }
    else{
        aux2->prox = novo;
    }
}


void inserirEqui (Equipamento *tabela[], int chave, DadosEqui infos){
    Equipamento *novo = (Equipamento*)malloc(sizeof(Equipamento));
    novo->dados = infos;
    novo->dados.IL = CriaLista();
    novo->prox = NULL;

    if(tabela[chave] == NULL){ //se a posição estiver tiver vazia vai direto
        tabela[chave] = novo;
    }
    else{ //se nao cria auxiliares para achar lugar correto
        Equipamento *aux = tabela[chave];
        while(aux->prox!= NULL){
            aux = aux->prox;
        }
        aux->prox=novo;
    }
}

int ExisteEqui (Equipamento *E[], int chave, int cod){
    Equipamento *aux = E[chave];
    while(aux != NULL){
        if(aux->dados.CodEqui == cod){
            printf("\nEsse código de equipamento ja está em uso\n");
            return 0;
        }
        aux = aux->prox;
    }
    return 1;
}

void ImprimeLista(Lista *l){
    printf("\n\nImprimir Lista Incidentes\n");
    NoLista* aux;
    aux = l->inicio;
    if (aux==NULL){
        printf("\nA lista está vazia\n");

    }else{
        while(aux != NULL){
            printf("l->id do incidente do equipamento: %d", aux->ID);
            aux = aux->prox;
        }
    }
}

void ImprimePorCod (DadosEqui infos){
 printf("\n\nImprime dados do Equipamento");
 printf("\nCódigo do Equipamento: %d", infos.CodEqui);
 printf("\nNome do Equipamento: %s", infos.NomeEqui);
 ImprimeLista(infos.IL);
}

void ImprimeEqui (Equipamento *E[], int chave, int cod){
    Equipamento *aux = E[chave];
    while(aux != NULL){
        if(aux->dados.CodEqui == cod){
            ImprimePorCod(aux->dados);
        }
        aux = aux->prox;
    }
}

//int RemovEquiHash (equipamento Hash, int numID){
//}
#endif // TABELAHASH_H_INCLUDED
