#include "Complexo.h"

/*
2 - Desenvolva a lógica que, dado um formato e um complexo
devolva o valor cplx no formato especificado
*/
t_cplx converte_CPLX(t_cplx a, t_formato f) {
    if(a.f == f) {
        return a;
    } else if(a.f == rec && f == pol) {
        t_cplx resultado;
        resultado.f = pol;
        resultado.pol.mod = sqrt(a.rec.real * a.rec.real + a.rec.imag * a.rec.imag);
        resultado.pol.arg = atan2(a.rec.imag, a.rec.real);
        return resultado;
    } else if(a.f == pol && f == rec) {
        t_cplx resultado;
        resultado.f = rec;
        resultado.rec.real = a.pol.mod * cos(a.pol.arg);
        resultado.rec.imag = a.pol.mod * sin(a.pol.arg);
        return resultado;
    }
}

/*
3 - Preencha a lógica da função
que, dado dois CPLX em qualquer formato, 
devolva o resultado da soma.
Devolva o resultado no formato de 'a'.
*/
t_cplx somar_CPLX(t_cplx a, t_cplx b) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx b_rec = converte_CPLX(b, rec);
    t_cplx resultado;
    resultado.f = rec;
    resultado.rec.real = a_rec.rec.real + b_rec.rec.real;
    resultado.rec.imag = a_rec.rec.imag + b_rec.rec.imag;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/*
4 - Preencha a lógica da função
que, dado dois CPLX em qualquer formato, 
devolva o resultado da diferença.
Devolva o resultado no formato de 'a'.
*/
t_cplx subtrair_CPLX(t_cplx a, t_cplx b) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx b_rec = converte_CPLX(b, rec);
    t_cplx resultado;
    resultado.f = rec;
    resultado.rec.real = a_rec.rec.real - b_rec.rec.real;
    resultado.rec.imag = a_rec.rec.imag - b_rec.rec.imag;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/*
5 - Preencha a lógica da função
que, dado dois CPLX em qualquer formato,
devolva o resultado do produto.
Devolva o resultado no formato de 'a'.
*/
t_cplx cplx_mult_CPLX(t_cplx a, t_cplx b) {
    t_cplx a_pol = converte_CPLX(a, pol);
    t_cplx b_pol = converte_CPLX(b, pol);
    t_cplx resultado;
    resultado.f = pol;
    resultado.pol.mod = a_pol.pol.mod * b_pol.pol.mod;
    resultado.pol.arg = a_pol.pol.arg + b_pol.pol.arg;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/*
6 - Preencha a lógica da função
que, dado um CPLX em qualquer formato,
e um número real, devolva a multiplicação
entre eles.
*/
t_cplx real_mult_CPLX(t_cplx a, double r) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx resultado;
    resultado.f = rec;
    resultado.rec.real = a_rec.rec.real * r;
    resultado.rec.imag = a_rec.rec.imag * r;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/*
7 - Preencha a lógica da função
que, dado dois CPLX em qualquer formato,
devolva o resultado da divisão.
Devolva o resultado no formato de 'a'.
*/
t_cplx dividir_CPLX(t_cplx a, t_cplx b) {
    t_cplx a_pol = converte_CPLX(a, pol);
    t_cplx b_pol = converte_CPLX(b, pol);
    t_cplx resultado;
    resultado.f = pol;
    resultado.pol.mod = a_pol.pol.mod / b_pol.pol.mod;
    resultado.pol.arg = a_pol.pol.arg - b_pol.pol.arg;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/*
8 - Preencha a lógica da função
que, dado um CPLX em qualquer formato,
devolva o resultado do conjugado.
Mantenha o formato de a.
*/
t_cplx conjugado_CPLX(t_cplx a) {
    if(a.f == rec) {
        
    }
}

/*
9 - Preencha a lógica da função
que, dado um CPLX em qualquer formato,
devolva o modulo.
*/
double mod_CPLX(t_cplx a) {
    // TODO: --preencher lógica da função--
    (void)a;
    return 0.0;
}

/*
10 - Preencha a lógica da função
que, dado um CPLX em qualquer formato,
devolva o argumento.
*/
double arg_CPLX(t_cplx a) {
    // TODO: --preencher lógica da função--
    (void)a;
    return 0.0;
}

/*
11 - Preencha a lógica da função
que, dado um CPLX em qualquer formato,
devolva a parte imaginaria.
*/
double img_CPLX(t_cplx a) {
    // TODO: --preencher lógica da função--
    (void)a;
    return 0.0;
}

/*
12 - Preencha a lógica da função
que, dado um CPLX em qualquer formato,
devolva a parte real.
*/
double re_CPLX(t_cplx a) {
    // TODO: --preencher lógica da função--
    (void)a;
    return 0.0;
}

/*
13 - Preencha a lógica da função
que, dado um 'a' CPLX em qualquer formato, 
e um expoente 'n' double, devolva um CPLX
que é o resultado de 'a' elevado a 'n'
*/
t_cplx potencia_CPLX(t_cplx a, double n) {
    // TODO: --preencher lógica da função--
    (void)n;
    return a;
}

/*
14 - Preencha a lógica da função
que, dado um 'a' CPLX em qualquer formato, 
devolva um CPLX que é o resultado de 
e (constante de euler) elevado a 'a'
*/
t_cplx exp_CPLX(t_cplx a) {
    // TODO: --preencher lógica da função--
    return a;
}

/*
15 - Preencha a lógica da função
que, dado um CPLX, imprima o 
valor dele, de acordo com seu formato.
*/
void imprimir_CPLX(t_cplx a) {
    // TODO: --preencher lógica da função--
    (void)a;
}

/*
Bonus:
16 - Preencha a lógica da função
que, dado um CPLX, calcule 
as enezimas raízes
*/
void raizes_CPLX(t_cplx c, int n, t_cplx resultados[]) {
    // TODO: --preencher lógica da função--
    (void)c;
    (void)n;
    (void)resultados;
}
