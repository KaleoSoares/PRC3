#ifndef COMPLEXO_H
#define COMPLEXO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    rec,
    pol
} t_formato;

typedef struct {
    double mod;
    double arg;
} t_polar;

typedef struct {
    double real;
    double imag;
} t_retangular;

typedef struct {
    t_formato f;
    union {
        t_polar pol;
        t_retangular rec;
    };
} t_cplx;

t_cplx converte_CPLX(t_cplx a, t_formato f);

t_cplx somar_CPLX(t_cplx a, t_cplx b);

t_cplx subtrair_CPLX(t_cplx a, t_cplx b);

t_cplx cplx_mult_CPLX(t_cplx a, t_cplx b);

t_cplx real_mult_CPLX(t_cplx a, double r);

t_cplx dividir_CPLX(t_cplx a, t_cplx b);

t_cplx conjugado_CPLX(t_cplx a);

double mod_CPLX(t_cplx a);

double arg_CPLX(t_cplx a);

double img_CPLX(t_cplx a);

double re_CPLX(t_cplx a);

t_cplx potencia_CPLX(t_cplx a, double n);

t_cplx exp_CPLX(t_cplx a);

void imprimir_CPLX(t_cplx a);

void raizes_CPLX(t_cplx c, int n, t_cplx resultados[]);

#endif