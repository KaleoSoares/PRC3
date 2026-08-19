#include <stdio.h>
#include <math.h>

typedef enum {
    F24, F12
} Formato;

typedef struct {
    int h;
    int m;
    int s;
    Formato f;
} Relogio;

int clockRelogio(Relogio* r){
    if((r->s)++ >= 59){
        r->s = 0;
        if((r->m)++ >= 59){
            r->m = 0;
            
            if((r->h)++ >= 23){
                r->h = 0;
                return 1;
            }
        }
    }
    return 0;
}

void printRelogio(Relogio* r){
    if(r->f == F24) {
        printf("%02d:%02d:%02d\n", r->h, r->m, r->s);
    } else {
        int h = r->h % 12;
        if(h == 0) h = 12;
        printf("%02d:%02d:%02d %s\n", h, r->m, r->s, (r->h >= 12) ? "PM" : "AM");
    }
}

// Corrigido: altera a estrutura original via ponteiro
void toggleRelogio(Relogio* r){
    if(r->f == F24) {
        r->f = F12;
    } else {
        r->f = F24;
    }
}

void setRelogio(Relogio* r, int vh, int vm, int vs, Formato f){
    if(vs > 59 || vm > 59 || vh > 23){
        vm = vm + vs / 60;
        vs = vs % 60;
        vh = vh + vm / 60;
        vm = vm % 60;
        vh = vh % 24;
    }
    if(vs < 0 || vm < 0 || vh < 0){
        printf("Tu é burro krl?\n"); // Corrigido: \n no lugar de /n
        return;
    }

    r->h = vh;
    r->m = vm;
    r->s = vs;
    r->f = f;
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
    setRelogio(r3, r3->h, r3->m, r3->s, r1->f);
}

int paraSegundos(Relogio* r){
    return r->h * 3600 + r->m * 60 + r->s;
}

float paraMinutos(Relogio* r){
    return r->h * 60 + r->m + r->s / 60.0;
}

float paraHoras(Relogio* r){
    return r->h + r->m / 60.0 + r->s / 3600.0;
}

int main()
{
    Relogio h1, h2;
    setRelogio(&h1, 21, 2, 595, F12);
    setRelogio(&h2, 11, 35, 57, F12);

    printRelogio(&h1);
    toggleRelogio(&h1);
    printRelogio(&h1);

    printRelogio(&h2);
    toggleRelogio(&h2);
    printRelogio(&h2);

    return 0;
}