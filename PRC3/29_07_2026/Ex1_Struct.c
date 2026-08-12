#include <stdio.h>

typedef struct {
    int h;
    int m;
    int s;
} Relogio;

int clockRelogio(Relogio* r){
    if((r->s)++ >= 59){
        r->s = 0;
        if((r->m)++ >= 59){
            r->m = 0;
            
            if((r->h)++>=23){
                r->h = 0;
                return 1;
            }
        }
    }
    return 0;
}

void printRelogio(Relogio* r){
    printf("%02d:%02d:%02d\n", r->h, r->m, r->s);
}

void setRelogio(Relogio* r, int vh, int vm, int vs ){
    if(vs > 59 || vm > 59 || vh > 23){
        vm = vm + vs/60;
        vs = vs % 60;
        vh = vh + vm/60;
        vm = vm % 60;
        vh = vh % 24;
    }
    if(vs < 0 || vm < 0 || vh < 0){
        printf("Tu é burro krl?/n");
        return;
    }

    r->h = vh;
    r->m = vm;
    r->s = vs;
}

int comparaRelogio(Relogio* r1, Relogio* r2) {
    if(r1->h < r2->h) return -1;
    if(r1->h > r2->h) return 1;
    if(r1->m < r2->m) return -1;
    if(r1->m > r2->m) return 1;
    if(r1->s < r2->s) return -1;
    if(r1->s > r2->s) return 1;

    return 0;
}

void somaRelogio(Relogio* r1, Relogio* r2, Relogio* r3){
    r3->h = r1->h + r2->h;
    r3->m = r1->m + r2->m;
    r3->s = r1->s + r2->s;
    setRelogio(r3, r3->h, r3->m, r3->s);
}

int main()
{
    Relogio h1, h2, h3;
    setRelogio(&h1, 9, 2, 59);
    setRelogio(&h2, 1, 35, 57);

    printf("\n");
    printRelogio(&h1);
    printRelogio(&h2);

    if(clockRelogio(&h1)){
        printf("Agora é um novo dia!\n");
    }

    if(clockRelogio(&h2)){
        printf("Agora é um novo dia!\n");
    }

    switch(comparaRelogio(&h1, &h2)){
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
    
    printRelogio(&h1);
    printRelogio(&h2);
    printf("\n");
    
    somaRelogio(&h1, &h2, &h3);
    printRelogio(&h3);

    return 0;
}
