#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int randomMachine();

int main()
{
    int numeroPlayer, numeroMachine, result = 0;
    char comparacao;
    char txtSelecao[10];

    

    //inicia o jogo
    printf("Bem-vindo ao jogo das comparações!\n");
    printf("Voce deve escolher um numero e o tipo de comparação.\n");
    printf("M. Maior\n");
    printf("N. Menor\n");
    printf("T. Igual\n");

    printf("Escolha a comparacao: ");
    scanf("%c", &comparacao);

    printf("Digite seu numero (entre 1 e 100): ");
    scanf("%d", &numeroPlayer);

    srand(time(0));//inicializa o numero aleatório
    numeroMachine = randomMachine();
    //printf("O numero do computador é %d\n", numeroMachine);

    switch (comparacao)
    {
    case 'M':
    case 'm':
        strcpy(txtSelecao, "Maior");
        result = numeroPlayer > numeroMachine ? 1 : 0;
        break;
    case 'N':
    case 'n':
        strcpy(txtSelecao, "Menor");
        result = numeroPlayer < numeroMachine ? 1: 0;
        break;
    case 'T':
    case 't':
        strcpy(txtSelecao, "Igual");
        result = numeroPlayer == numeroMachine ? 1: 0;
        break;
    
    default:
        printf("Opcao invalida!! Tente novamente...");
        break;
    }

    printf("Voce escolheu a opcao %s\n", txtSelecao);
    printf("Calculando...\n");
    printf("Verificando se: %d eh %s que %d.\n", numeroPlayer,txtSelecao,numeroMachine);

    if(result == 1)
    {
        printf("Voce ganhou!!\n");
    }else 
    {
        printf("Voce perdeu...\n");
    }


}

int randomMachine()
{
    //gerar numero aleatório
    return rand() % 100 +1;//cria o numero (soma 1 para nao coincidir zero)
}