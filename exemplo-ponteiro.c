#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    int uuid;
    char nome[50];
    char telefone[25];
    char email[50];
    char dataDeNascimento[25];
    char observ[200];
    struct Pessoa *prox;
}Pessoa;


main(){

    //Ponteiros criados
    Pessoa *pessoa = NULL;
    Pessoa *aux = NULL;
    Pessoa *ultimo = NULL;

    //CADASTRO
    //aux aloca um espaço na memória e cadastra
    aux = malloc(sizeof(Pessoa));
    aux->prox = NULL;

    printf("Digite o nome: ");
    scanf("%s", aux->nome);

    //se não existe cadastros
    //o ponteiro pessoa recebe o aux, indicando o start da lista
    //o ponteiro ultimo recebe aux, indicando um atalho para o ultimo contato
    if(pessoa == NULL){
        pessoa = aux;
        ultimo = aux;
    
    //se existe algum cadastro
    //ultimo leva para o ultimo contato, permitindo-o apontar para um novo contato (aux)
    //ultimo muda para o novo contato 
    }else{
        ultimo->prox = aux;
        ultimo = aux;
    }

    // -- EXIBIÇÃO
    //exibe o primeiro
    mostra(pessoa);
    aux = pessoa;

    //percorre o resto da lista        
    while(aux->prox != NULL){
        mostra(aux->prox);
        aux = aux->prox;
    }

}
