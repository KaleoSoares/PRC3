#include <stdio.h>

/* declaração do nosso relogio*/

int hora[20];
int minuto[20];
int segundo[20];


int hora1;
int minuto1;
int segundo1;

int hora2;
int minuto2;
int segundo2;

/*
* função: clockRelogio
*   Incrementa o relogio em 1 segundo
* e vai ajustar todas as variáveis do relogio
*
* parâmetros:
* h: endereco da variável hora do relógio
* m: endereco da variável minuto do relogio
* s: endereco da variável segundo do relogio
*
* retorno:
* retorna verdade se houve overflow no relogio
*/

int clockRelogio(int* h, int* m, int* s){
    if((*s)++ >= 59){
        *s = 0;
        if((*m)++ >= 59){
            *m = 0;
            //*h = (*h+1) % 24;
            
            if((*h)++>=23){
                *h = 0;
                return 1;
            }
        }
    }

    return 0;
}


/*
* função: printRelogio
* Imprime o valor formatado do relogio na prompt
*
* parâmetros:
* h: endereco da variável hora do relógio
* m: endereco da variável minuto do relogio
* s: endereco da variável segundo do relogio
*
* retorno:
* void
*/

void printRelogio(int* h, int* m, int* s){
    printf("%02d:%02d:%02d\n", *h, *m, *s);
}

/*
* função: setRelogio
* Ajusta o valor do relogio
*
* parâmetros:
* h: endereco da variável hora do relógio
* m: endereco da variável minuto do relogio
* s: endereco da variável segundo do relogio
* vh: valor de ajuste da variável hora do relógio
* vm: valor de ajuste da variável minuto do relogio
* vs: valor de ajuste da variável segundo do relogio
*
* retorno:
* void
*/

void setRelogio(int* h, int* m, int* s, int vh, int vm, int vs ){
    if(vs < 0){
        printf("Tu é burro krl?/n");
        return;
    }
    if(vs > 59){
        vm = vm + vs/60;
        vs = vs % 60;
    }
    if(vm < 0){
        printf("Tu é burro krl?/n");
        return;
    }
    if(vm > 59){
        vh = vh + vm/60;
        vm = vm % 60;
    }
    if(vh < 0){
        printf("Tu é burro krl?/n");
        return;
    }
    if(vh > 23){
        vh = vh % 24;
    }

    *h = vh;
    *m = vm;
    *s = vs;
}

/*
* função: comparaRelogio
* Dado r1 e r2, informa se r1>r2, ou r1<r2, ou r1==r2
*
* parâmetros:
* h1: endereco da variável hora do relógio1
* m1: endereco da variável minuto do relogio1
* s1: endereco da variável segundo do relogio1
*
* h2: endereco da variável hora do relógio2
* m2: endereco da variável minuto do relogio2
* s2: endereco da variável segundo do relogio2
*
* retorno:
* retorna -1 se r1 < r2
* retorna 0 se r1 = r2
* retorna 1 se r1 > r2
*/

int comparaRelogio(int* h1, int* m1, int* s1,int* h2, int* m2, int* s2) {
    if(*h1 < *h2) return -1;
    if(*h1 > *h2) return 1;
    if(*m1 < *m2) return -1;
    if(*m1 > *m2) return 1;
    if(*s1 < *s2) return -1;
    if(*s1 > *s2) return 1;

    return 0;
}

int main()
{
    setRelogio(&hora1, &minuto1, &segundo1, 8, 123, 154);
    setRelogio(&hora2, &minuto2, &segundo2, 1, 352, 6767);
    
    printf("\n");
    printRelogio(&hora1, &minuto1, &segundo1);
    printRelogio(&hora2, &minuto2, &segundo2);

    if(clockRelogio(&hora1, &minuto1, &segundo1)){
        printf("Agora é um novo dia!\n");
    }

    if(clockRelogio(&hora2, &minuto2, &segundo2)){
        printf("Agora é um novo dia!\n");
    }

    switch(comparaRelogio(&hora1, &minuto1, &segundo1, &hora2, &minuto2, &segundo2)){
        case -1:
            printf("r1 < r2\n");
            break;
        case 0:
            printf("r1 == r2\n");
            break;
        case 1:
            printf("r1 > r2\n");
            break;
    }
    
    printRelogio(&hora1, &minuto1, &segundo1);
    printRelogio(&hora2, &minuto2, &segundo2);
    printf("\n");
    
    return 0;
}
