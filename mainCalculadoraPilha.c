#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Nome: Fernanda de Castro Fernandes
  Matricula: 202004672
  Estrutura de dados 1 
  Engenharia de Computacao UFG
*/


typedef struct no{
    float valor;
    struct no *prox;
}No;

No* empilhar(No *pilha, float num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->prox = pilha;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->prox;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

float operacao(float a, float b, char x){
    switch(x){
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    default:
        return 0.0;
    }
}

float resolver_expressao(char x[]){
    char *pt;
    float num;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(x, " ");
    while(pt){
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            n1 = desempilhar(&pilha);
            n2 = desempilhar(&pilha);
            num = operacao(n2->val, n1->val, pt[0]);
            pilha = empilhar(pilha, num);
            free(n1);
            free(n2);
        }
        else{
            num = strtol(pt, NULL, 10);
            pilha = empilhar(pilha, num);
        }
        pt = strtok(NULL, " ");
    }
    n1 = desempilhar(&pilha);
    num = n1->val;
    free(n1);
    return num;
}

int main(){
    char exp[50] = {"5 3 2 4 6 7 1 + * + * + *"};
    char calc[50];
    printf("Digite a expressao a ser calculada em notacao posfixa: %s\n",calc);
    scanf("%[^\n]s",calc);
    printf("Resultado de %s:\t", exp);
    printf("%f\n", resolver_expressao(exp));
    printf("Resultado de %s:\t", calc);
    printf("%f\n", resolver_expressao(calc));
}