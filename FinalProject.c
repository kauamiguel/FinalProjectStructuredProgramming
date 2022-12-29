#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_NOME 30
#define TAM_CIDADE 16
#define MAX_JOGOS 30
#define MAX_CIDADE 9

typedef struct {
    char nomePresidente[MAX_NOME];
    int idadePresidente;
    char nacionalidadePresidente[30];
}Presidente;

typedef struct {
    int codigoCidade;
    char nomeCidade[TAM_CIDADE];
}Cidade;

typedef struct {
    int valorArrecadado, codgoCidade, identificadorJogo;
}Jogo;

void cadastroPredisdente(Presidente *presidente);
void menu();
void cadastrarCidade(Cidade *cadastrarcidade);
int cadastroJogo(Jogo jogo[]);
int validadorCodigoDoJogo(Jogo jogo[], int codigoDigitado);
void listarJogos(Presidente *presidente, Jogo jogo[], Cidade cidade[], int quantidadeDeJogos);
void exibirJogosPorCidade(Jogo jogo[], Cidade cidade[], int quandidadeDeJogos);

int main(){

    menu();

    return 0;
}

//Funcao para exibir os jogos que foram cadastrados na cidade que o usuario escolher
void exibirJogosPorCidade(Jogo jogo[], Cidade cidade[], int quandidadeDeJogos){
    int codigoDigitadoPeloUsuario, qtdDeJogosNaCidade = 0, i = 0;
    char temp;
    do{
        printf("Informe o codigo da cidade para a consulta do jogo: ");
        scanf("%d", &codigoDigitadoPeloUsuario);
    }while(codigoDigitadoPeloUsuario < 1 || codigoDigitadoPeloUsuario > 10);

    for(i = 0; i < 9; i++){
        if(codigoDigitadoPeloUsuario == cidade[i].codigoCidade)
            break;
    }

    printf("\nJogo na cidade: %s", cidade[i].nomeCidade);
    for(int j = 0; j < quandidadeDeJogos; j++){
        if(jogo[j].codgoCidade == codigoDigitadoPeloUsuario){
            printf("\nJogo com ID: %d", jogo[j].identificadorJogo);
            qtdDeJogosNaCidade++;
        }
    }
    
    if(qtdDeJogosNaCidade == 0){
        printf("\nNao foi encontrado nenhum jogo em %s\n", cidade[i].nomeCidade);
    }

    do{
        printf("\nPressione enter para voltar o menu.");
        scanf("%c", &temp);
    }while(temp != '\n');
}

//Funcao para pegar cadastros do presidente
void cadastroPredisdente(Presidente *presidente){

    char temp;
    printf("\nInforme a nacionalidade do presidente: ");
    scanf("%s", &presidente->nacionalidadePresidente);

    do{
        printf("\nInforme a idade do presidente: ");
        scanf("%d", &presidente->idadePresidente);
    }while(presidente->idadePresidente < 30 || presidente->idadePresidente > 70);

    do{
        scanf("%c", &temp);
        printf("\nInforme o nome do presidente: ");
        fgets(presidente->nomePresidente, MAX_NOME, stdin);
    }while((strcmp(presidente->nomePresidente,"") == 0) || strlen(presidente->nomePresidente) > MAX_NOME);

}

//Funcao para cadastrar cidade e colocar em lestras maiusculas
void cadastrarCidade(Cidade cidade[]){

    int quantidadeDeCidades = 0;
    do{
        printf("Informe a %da cidade: ", quantidadeDeCidades + 1);
        scanf("%s", &cidade[quantidadeDeCidades].nomeCidade);

        while(strlen(cidade[quantidadeDeCidades].nomeCidade) > TAM_CIDADE){
            fflush(stdin);
            printf("\nNome ultrapassa o permitido. Coloque um valido: ");
            scanf("%s", &cidade[quantidadeDeCidades]);
        }

        for(int i = 0; cidade[quantidadeDeCidades].nomeCidade[i] != '\0'; i++){
            cidade[quantidadeDeCidades].nomeCidade[i] = toupper(cidade[quantidadeDeCidades].nomeCidade[i]);
        }

        cidade[quantidadeDeCidades].codigoCidade = quantidadeDeCidades + 1;
        quantidadeDeCidades++;
    }while(quantidadeDeCidades < 9);

}

//Funcao que percorre todo o vetor para analisar se a um valor de identificadorJogo repetido
int validadorCodigoDoJogo(Jogo jogo[], int codigoDigitado){
    int aux;

    for(aux = 0; aux < MAX_JOGOS; aux++){
        if(jogo[aux].identificadorJogo == codigoDigitado){
            return 0;
        }else{
            continue;
        }
    }
    return 1;
}

int cadastroJogo(Jogo jogo[]){
    int quantidadeDeJogosCadstrar, i = 0, codigoDigitado;

    do{
        printf("Informe a quantidade de jogos que deseja cadastrar: ");
        scanf("%d", &quantidadeDeJogosCadstrar);
    }while(quantidadeDeJogosCadstrar < 0 || quantidadeDeJogosCadstrar > MAX_JOGOS); 

    while(i < quantidadeDeJogosCadstrar){
        
        do{
            printf("\nInforme o codigo do jogo(300 a 900): ");
            scanf("%d", &codigoDigitado);       
        }while(codigoDigitado < 300 || codigoDigitado > 999);

        while(validadorCodigoDoJogo(jogo, codigoDigitado) == 0){
            do{
                printf("\nInforme o codigo do jogo valido, esse ja existe: ");
                scanf("%d", &codigoDigitado);       
            }while(codigoDigitado < 300 || codigoDigitado > 999);
        }
        
        jogo[i].identificadorJogo = codigoDigitado;

        do{
            printf("\nInforme o valor arrecadado com este jogo: ");
            scanf("%d", &jogo[i].valorArrecadado);
        }while(jogo[i].valorArrecadado < 1001 || jogo[i].valorArrecadado > 1000000);

        do{
            printf("\nInforme o codigo da cidade: ");
            scanf("%d", &jogo[i].codgoCidade);
        }while(jogo[i].codgoCidade < 0 || jogo[i].codgoCidade > 9);

        i++;
    }
    return quantidadeDeJogosCadstrar;
}

//Listar jogo de acordo com o padrao pedido nas linhas comentadas no cabeçalho
void listarJogos(Presidente *presidente, Jogo jogo[], Cidade cidade[],int quantidadeDeJogos){
    float somaTotal = 0;
    char temp;
    printf("FIFA - Relatorio de Arrecadacao \n");
    printf("Presidente: %s\n", presidente->nomePresidente);
    printf("\n---------------------------------------------------\n");
    for(int i = 0; i < quantidadeDeJogos; i++){
        printf("%d\t%s\t%d\t%d\n", cidade[i].codigoCidade, cidade[i].nomeCidade,jogo[i].identificadorJogo, jogo[i].valorArrecadado);
    }
    printf("---------------------------------------------------\n");
    for(int i = 0; i < quantidadeDeJogos; i++){
        somaTotal += jogo[i].valorArrecadado;
    }
    printf("TOTAL: $%.2f\n", somaTotal);

    do{
        printf("\nPressione enter para voltar o menu.");
        scanf("%c", &temp);
    }while(temp != '\n');
}

// Funçao que mostra o menu e chama as respectivas funções relacionadas as ações que o user deseja
void menu(){

    char opcaoDoMenu = 'g';
    Presidente variavelPresidente;
    Cidade cidadesCadastradas[MAX_CIDADE];
    Jogo joogosCadastrados[MAX_JOGOS];
    int quantidadeDeJogosCadastrar;
    char temp; // Variavel necessaria para ler o enter(\n) do buffer ao cadastrar dados quando chama funções

    cadastroPredisdente(&variavelPresidente);
    while(opcaoDoMenu != 'f'){

        printf("---------------------------------------------------------------------------------\n");
        printf("\t\tBEM-VINDO AO MENU\n");
        printf("---------------------------------------------------------------------------------\n");
        printf("(a) PRESIDENTE\n");
        printf("(b) CADASTRAR CIDADE\n");
        printf("(c) CADASTRAR JOGO\n");
        printf("(d) LISTAR JOGOS\n");
        printf("(e) EXIBIR JOGOS POR CIDADE\n");
        printf("(f) ENCERRAR\n");
        printf("\n\n\nEscolha a opcao: ");
        scanf("%c", &opcaoDoMenu);

        switch (opcaoDoMenu)
        {
        case 'a':
            cadastroPredisdente(&variavelPresidente);
            break;

        case 'b':
            cadastrarCidade(cidadesCadastradas);
            scanf("%c",&temp);
            break;

        case 'c':
             quantidadeDeJogosCadastrar = cadastroJogo(joogosCadastrados);
             scanf("%c",&temp);
            break;

        case 'd':
            listarJogos(&variavelPresidente, joogosCadastrados, cidadesCadastradas, quantidadeDeJogosCadastrar);
            scanf("%c",&temp);
            break;

        case 'e':
            exibirJogosPorCidade(joogosCadastrados, cidadesCadastradas, quantidadeDeJogosCadastrar);
            scanf("%c", &temp);
        default:
            break;
        }
   }
}
