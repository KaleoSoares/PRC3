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
        t_cplx resultado;
        resultado.f = rec;
        resultado.rec.real = a.rec.real;
        resultado.rec.imag = -a.rec.imag;
        return resultado;
    } else if(a.f == pol) {
        t_cplx resultado;
        resultado.f = pol;
        resultado.pol.mod = a.pol.mod;
        resultado.pol.arg = -a.pol.arg;
        return resultado;
    }
}

/*
9 - Preencha a lógica da função
que, dado um CPLX em qualquer formato,
devolva o modulo.
*/
double mod_CPLX(t_cplx a) {
    if(a.f == pol) {
        return a.pol.mod;
    } else if(a.f == rec) {
        t_cplx a_pol = converte_CPLX(a, pol);
        return a_pol.pol.mod;
    }
}

/*
10 - Preencha a lógica da função
que, dado um CPLX em qualquer formato,
devolva o argumento.
*/
double arg_CPLX(t_cplx a) {
    if(a.f == pol) {
        return a.pol.arg;
    } else if(a.f == rec) {
        t_cplx a_pol = converte_CPLX(a, pol);
        return a_pol.pol.arg;
    }
}

/*
11 - Preencha a lógica da função
que, dado um CPLX em qualquer formato,
devolva a parte imaginaria.
*/
double img_CPLX(t_cplx a) {
    if(a.f == rec) {
        return a.rec.imag;
    } else if(a.f == pol) {
        t_cplx a_rec = converte_CPLX(a, rec);
        return a_rec.rec.imag;
    }
}

/*
12 - Preencha a lógica da função
que, dado um CPLX em qualquer formato,
devolva a parte real.
*/
double re_CPLX(t_cplx a) {
    if(a.f == rec) {
        return a.rec.real;
    } else if(a.f == pol) {
        t_cplx a_rec = converte_CPLX(a, rec);
        return a_rec.rec.real;
    }
}

/*
13 - Preencha a lógica da função
que, dado um 'a' CPLX em qualquer formato, 
e um expoente 'n' double, devolva um CPLX
que é o resultado de 'a' elevado a 'n'
*/
t_cplx potencia_CPLX(t_cplx a, double n) {
    t_cplx a_pol = converte_CPLX(a, pol);
    t_cplx resultado;
    resultado.f = pol;
    resultado.pol.mod = pow(a_pol.pol.mod, n);
    resultado.pol.arg = a_pol.pol.arg * n;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/*
14 - Preencha a lógica da função
que, dado um 'a' CPLX em qualquer formato, 
devolva um CPLX que é o resultado de 
e (constante de euler) elevado a 'a'
*/
t_cplx exp_CPLX(t_cplx a) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx resultado;
    resultado.f = pol;
    resultado.pol.mod = exp(a_rec.rec.real);
    resultado.pol.arg = a_rec.rec.imag;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/*
15 - Preencha a lógica da função
que, dado um CPLX, imprima o 
valor dele, de acordo com seu formato.
*/
void imprimir_CPLX(t_cplx a) {
    if(a.f == rec) {
        printf("%.2f + %.2fi\n", a.rec.real, a.rec.imag);
    } else if(a.f == pol) {
        printf("%.2f /_ %.2f rad\n", a.pol.mod, a.pol.arg);
    }
}

/*
Bonus:
16 - Preencha a lógica da função
que, dado um CPLX, calcule 
as enezimas raízes
*/
void raizes_CPLX(t_cplx c, int n, t_cplx resultados[]) {
    t_cplx c_pol = converte_CPLX(c, pol);
    for(int k = 0; k < n; k++) {
        resultados[k].f = pol;
        resultados[k].pol.mod = pow(c_pol.pol.mod, 1.0/n);
        resultados[k].pol.arg = (c_pol.pol.arg + 2.0 * M_PI * k) / n;
        resultados[k] = converte_CPLX(resultados[k], c.f);
    }
}
