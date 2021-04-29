#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    int uuid;
    char nome[50];
    char telefone[25];
    char email[50];
    char dataDeNascimento[25];
    char observ[200];
    struct Pessoa *prox;
}Pessoa;

//funcoes
void mostra(Pessoa *contato);
void cadastra(Pessoa *aux);
void listar(Pessoa *pessoa, Pessoa *aux);


main(){
    //Ponteiros necessários 
    Pessoa *pessoa = NULL;
    Pessoa *aux = NULL;
    Pessoa *ultimo = NULL;

    //variaves uteis
    char op;
    
    //MENU
    while(op != '0'){
        //Menu
        system("cls");
        printf(" ______________________________________________________________\n");
        printf("|___________________________ AGENDA ___________________________|\n");
        printf("|                                                              |\n");
        printf("|       1- Cadastrar                                           |\n");
        printf("|       2- Listar                                              |\n");
        printf("|                                                              |\n");
        printf("|       0- SAIR                                                |\n");
        printf("|______________________________________________________________|\n");
        printf(" Opcao: ");    
        fflush(stdin);
        scanf(" %c",&op);

        switch(op){   
            case '0':
                system("cls");
            break;

            //CADASTRAR
            case '1':

                //O malloc deve estar no main?
                aux = malloc(sizeof(Pessoa));
                aux->prox = NULL;
                
                cadastra(aux);

                //se não existe cadastros
                if(pessoa == NULL){
                    pessoa = aux;
                    ultimo = aux;
                
                //se existe algum cadastro
                }else{
                    ultimo->prox = aux;
                    ultimo = aux;
                }

            break;
            
            //LISTAR
            case '2':
                listar(pessoa, aux);
            break;
            
            default:
                system("cls");

                printf(" ______________________________________________________________\n");
                printf("|___________________________ AGENDA ___________________________|\n");
                printf("|                                                              |\n");
                printf("|                  Selecione uma Opcao valida                  |\n");
                printf("|______________________________________________________________|\n"); 
                system("pause");
            break;
        }
    }

}
//--------------------------------------------- FUNÇÕES ----------------------------------------------

//UTIL

//mostra um contato especifico  
void mostra(Pessoa *contato){
    
    printf(" ______________________________________________________________\n");
    printf("\n");
    printf("         Codigo Unico: %i\n",contato->uuid);            
    printf("\n");
    printf("         Nome: %s\n", contato->nome);            
    printf("         Telefone: %s\n", contato->telefone);            
    printf("         Email: %s\n", contato->email);            
    printf("         Data de Nascimento: %s\n", contato->dataDeNascimento);            
    printf("         Observacoes: %s\n", contato->observ);            
    printf(" ______________________________________________________________\n");
}

//FUNÇÕES DA AGENDA

//cadastra os dados no espaço alocado pelo aux
void cadastra(Pessoa *aux){
    //aux = malloc(sizeof(Pessoa));
    //aux->prox = NULL;


    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|                 Digite o id no campo abaixo                  |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Id: ");    
    fflush(stdin);
    scanf("%i",&aux->uuid);

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|                Digite o nome no campo abaixo                 |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Nome: ");    
    fflush(stdin);
    fgets(aux->nome, sizeof aux->nome, stdin);

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|              Digite o telefone no campo abaixo               |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Telefone: ");    
    fflush(stdin);
    fgets(aux->telefone, sizeof aux->telefone, stdin);

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|                Digite a email no campo abaixo                |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Email: ");    
    fflush(stdin);
    fgets(aux->email, sizeof aux->email, stdin);

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|          Digite a data de nascimento no campo abaixo         |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Data: ");    
    fflush(stdin);
    fgets(aux->dataDeNascimento, sizeof aux->dataDeNascimento, stdin);

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|           Digite alguma observacao no campo abaixo           |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Observacao: ");    
    fflush(stdin);
    fgets(aux->observ, sizeof aux->observ, stdin);
    
}

//escreve a lista
void listar(Pessoa *pessoa, Pessoa *aux){
    
    system("cls");
    //se não existe pessoas na agenda
    if(pessoa == NULL){
        system("cls");
        printf(" ______________________________________________________________\n");
        printf("|___________________________ AGENDA ___________________________|\n");
        printf("|                                                              |\n");
        printf("|                         Agenda Vazia                         |\n");
        printf("|______________________________________________________________|\n"); 
        system("pause");        
    }else{

        //exibe a lista
        printf(" ______________________________________________________________\n");
        printf("|_____________________ TODOS OS CONTATOS ______________________|\n");

        //exibe o primeiro
        mostra(pessoa);
        aux = pessoa;

        //percorre o resto da lista        
        while(aux->prox != NULL){
            mostra(aux->prox);
            aux = aux->prox;
        }

        system("pause");
    }
}
