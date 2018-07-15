#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

struct Pilha {
    float valor[MAX];
    int topo;
};

typedef struct Pilha p;

void Empilha(p *p, float valor) {
    if(p->topo < MAX) {
        p->valor[p->topo] = valor;
        p->topo++;
    }
}

float Desempilha (p *p) {
    if(p->topo > 0){
        int dado = 0;
        p->topo--;
        dado = p->valor[p->topo];
        return dado;
    }
    return -1;
}

float Operacao(char *aux, float dado1, float dado2) {
    switch(*aux) {
        case '+':
            return dado2 + dado1;
            break;
        case '-':
            return dado2 - dado1;
            break;
        case '*':
            return dado2 * dado1;
            break;
        case '/':
            return dado2 / dado1;
            break;
    }
    return -1;
}

void Ler_Expressao (p *p, char expressao[MAX]) {
    printf("-------------------------");
    printf("\nOPERACOES COM NOTACAO RPN\n");
    printf("-------------------------");
    printf("\n\nSOMENTE SAO ACEITOS DIGITOS E OPERACOES\n");
    printf("Digitos 0 a 9\nOperadores + / - *");

    printf("\n\nDigite a expressao: ");
    gets(expressao);
    int i;
    char aux[2];
    for(i = 0; i < strlen(expressao); i++) {
        aux[0] = expressao[i];
        if(isdigit(expressao[i]) == 1){
            float valor = atof(aux);
            Empilha(p, valor);
        }
        else{
            float dado1, dado2;
            dado1 = Desempilha(p);
            dado2 = Desempilha(p);
            if(dado1 != -1 && dado2 != -1) {
                float res = Operacao(aux, dado1, dado2);
                Empilha(p, res);
            }
        }
    }
}

int main()
{
    p pilha;
    pilha.topo = 0;

    char expressao[MAX];
    char resp;

    do {
        Ler_Expressao(&pilha, expressao);
        float res = Desempilha(&pilha);
        printf("\nO resultado da expressao: %.1f\n\n", res);
        printf("Digite S/s para continuar calculando novas expressoes: ");
        scanf("%c", &resp);
        fflush(stdin);
        printf("\n");
    }while(resp != 'S' || resp != 's');

    return 0;
}
