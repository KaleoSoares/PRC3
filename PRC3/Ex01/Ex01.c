/* =============================================================================
 * DISCIPLINA: PROC3
 * TAREFA: Implementação do Tipo de Dado Abstrato (TDA) para Números Complexos
 *
 * INSTRUÇÕES:
 * 1. Preencha os tipos de dados e os corpos das funções indicadas com '--preencher--'.
 * 2. Respeite as assinaturas e as regras de formato de entrada e saída.
 * 3. Mantenha os ângulos da forma polar normalizados no intervalo (-PI, PI].
 * 4. Dica de Ponto Flutuante: Para evitar que valores nulos sejam impressos como
 *    '-0.00', utilize fabs(val) < 1e-9 ? 0.0 : val antes de exibir com printf.
 * ============================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

/* =============================================================================
 * 1. DEFINIÇÃO DOS TIPOS DE DADOS
 * ============================================================================= */

/* 
 * 1.a) Especifique o enum com os formatos suportados:
 *      - RETANGULAR (representação z = a + bi)
 *      - POLAR       (representação z = r ∠ theta)
 */
typedef enum {
    rec,
    pol
} t_formato;

/* 
 * 1.b) Especifique a estrutura para a representação polar:
 *      - modulo: valor double (r >= 0)
 *      - arg:    argumento/fase double (em radianos)
 */
typedef struct {
    double mod;
    double arg;
} t_polar;

/* 
 * 1.c) Especifique a estrutura para a representação retangular:
 *      - real: parte real double
 *      - imag: parte imaginária double
 */
typedef struct {
    double real;
    double imag;
} t_retangular;

/* 
 * 1.d) Estrutura principal do TAD Complexo utilizando tagged union:
 *      - f: campo discriminador do formato atual (t_formato)
 *      - union anônima contendo pol (t_polar) e rec (t_retangular)
 */
typedef struct {
    t_formato f;
    union {
        t_polar pol;
        t_retangular rec;
    };
} t_cplx;

typedef t_cplx cplx;

cplx converte_CPLX(cplx a, t_formato f);
cplx conjugado_CPLX(cplx a);

/* =============================================================================
 * FUNÇÃO AUXILIAR DE NORMALIZAÇÃO ANGULAR
 * Mantém o argumento estritamente dentro do intervalo (-PI, PI]
 * ============================================================================= */
static double normaliza_angulo(double theta) {
    while (theta <= -M_PI) theta += 2.0 * M_PI;
    while (theta > M_PI)  theta -= 2.0 * M_PI;
    if (fabs(theta) < 1e-9) theta = 0.0;
    return theta;
}

/* =============================================================================
 * 2. FUNÇÕES DE EXTRAÇÃO DE PROPRIEDADES (GETTERS)
 * Devem funcionar corretamente independentemente do formato interno de 'a'.
 * ============================================================================= */

/*
 * 2.a) Dado um complexo 'a', devolva a sua parte real.
 *      - Se estiver em POLAR: real = modulo * cos(arg)
 */
double re_CPLX(cplx a) {
    if(a.f == rec) {
        return a.rec.real;
    } else if(a.f == pol) {
        t_cplx a_rec = converte_CPLX(a, rec);
        return a_rec.rec.real;
    }
}

/*
 * 2.b) Dado um complexo 'a', devolva a sua parte imaginária.
 *      - Se estiver em POLAR: imag = modulo * sin(arg)
 */
double img_CPLX(cplx a) {
    if(a.f == rec) {
        return a.rec.imag;
    } else if(a.f == pol) {
        t_cplx a_rec = converte_CPLX(a, rec);
        return a_rec.rec.imag;
    }
}

/*
 * 2.c) Dado um complexo 'a', devolva o seu módulo (magnitude).
 *      - Se estiver em RETANGULAR: modulo = sqrt(real^2 + imag^2) ou hypot(real, imag)
 */
double mod_CPLX(cplx a) {
    if(a.f == pol) {
        return a.pol.mod;
    } else if(a.f == rec) {
        t_cplx a_pol = converte_CPLX(a, pol);
        return a_pol.pol.mod;
    }
}

/*
 * 2.d) Dado um complexo 'a', devolva o seu argumento em radianos (-PI, PI].
 *      - Se estiver em RETANGULAR: arg = atan2(imag, real)
 */
double arg_CPLX(cplx a) {
    if(a.f == pol) {
        return a.pol.arg;
    } else if(a.f == rec) {
        t_cplx a_pol = converte_CPLX(a, pol);
        return a_pol.pol.arg;
    }
}

/* =============================================================================
 * 3. CONVERSÃO DE FORMATO E DE TIPO
 * ============================================================================= */

/*
 * 3.a) Dado um complexo 'a' e um formato destino 'f', devolva o complexo 
 *      equivalente convertido para o formato especificado.
 */
cplx converte_CPLX(cplx a, t_formato f) {
    if(a.f == f) {
        return a;
    } else if(a.f == rec && f == pol) {
        t_cplx resultado;
        resultado.f = pol;
        resultado.pol.mod = sqrt(a.rec.real * a.rec.real + a.rec.imag * a.rec.imag);
        resultado.pol.arg = normaliza_angulo(atan2(a.rec.imag, a.rec.real));
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
 * 3.b) Dado um número real 'r' e um formato 'f', crie e devolva um CPLX
 *      com valor real 'r' (e parte imaginária 0.0) no formato 'f'.
 */
cplx real_para_CPLX(double r, t_formato f) {
    if(f == rec) {
        t_cplx resultado;
        resultado.f = rec;
        resultado.rec.real = r;
        resultado.rec.imag = 0.0;
        return resultado;
    } else if(f == pol) {
        t_cplx resultado;
        resultado.f = pol;
        resultado.pol.mod = r;
        resultado.pol.arg = 0.0;
        return resultado;
    }
}

/* =============================================================================
 * 4. OPERAÇÕES ARITMÉTICAS ENTRE COMPLEXOS
 * Observação: O resultado deve ser devolvido no mesmo formato de 'a'.
 * ============================================================================= */

/*
 * 4.a) Soma entre dois números complexos (a + b).
 *      Dica: Realizar a soma na forma retangular e converter para o formato de 'a'.
 */
cplx somar_CPLX(cplx a, cplx b) {
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
 * 4.b) Subtração entre dois números complexos (a - b).
 *      Dica: Realizar a subtração na forma retangular e converter para o formato de 'a'.
 */
cplx subtrair_CPLX(cplx a, cplx b) {
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
 * 4.c) Multiplicação entre dois números complexos (a * b).
 *      Dica: Na forma polar, modulo = mod(a)*mod(b) e arg = arg(a)+arg(b).
 */
cplx cplx_mult_CPLX(cplx a, cplx b) {
    t_cplx a_pol = converte_CPLX(a, pol);
    t_cplx b_pol = converte_CPLX(b, pol);
    t_cplx resultado;
    resultado.f = pol;
    resultado.pol.mod = a_pol.pol.mod * b_pol.pol.mod;
    resultado.pol.arg = normaliza_angulo(a_pol.pol.arg + b_pol.pol.arg);
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/*
 * 4.d) Divisão entre dois números complexos (a / b).
 *      Dica: Na forma polar, modulo = mod(a)/mod(b) e arg = arg(a)-arg(b).
 */
cplx dividir_CPLX(cplx a, cplx b) {
    t_cplx a_pol = converte_CPLX(a, pol);
    t_cplx b_pol = converte_CPLX(b, pol);
    t_cplx resultado;
    resultado.f = pol;
    resultado.pol.mod = a_pol.pol.mod / b_pol.pol.mod;
    resultado.pol.arg = normaliza_angulo(a_pol.pol.arg - b_pol.pol.arg);
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/* =============================================================================
 * 5. OPERAÇÕES ARITMÉTICAS ENTRE REAL E COMPLEXO
 * O resultado deve ser devolvido no formato do complexo envolvido ('a').
 * ============================================================================= */

/* 5.a) Soma: r + a */
cplx somar_real_CPLX(double r, cplx a) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx resultado;
    resultado.f = rec;
    resultado.rec.real = r + a_rec.rec.real;
    resultado.rec.imag = a_rec.rec.imag;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/* 5.b) Subtração: r - a */
cplx subtrair_real_CPLX(double r, cplx a) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx resultado;
    resultado.f = rec;
    resultado.rec.real = r - a_rec.rec.real;
    resultado.rec.imag = -a_rec.rec.imag;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/* 5.c) Subtração: a - r */
cplx subtrair_CPLX_real(cplx a, double r) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx resultado;
    resultado.f = rec;
    resultado.rec.real = a_rec.rec.real - r;
    resultado.rec.imag = a_rec.rec.imag;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/* 5.d) Multiplicação por escalar real: a * r */
cplx real_mult_CPLX(cplx a, double r) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx resultado;
    resultado.f = rec;
    resultado.rec.real = a_rec.rec.real * r;
    resultado.rec.imag = a_rec.rec.imag * r;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/* 5.e) Divisão: a / r */
cplx dividir_CPLX_real(cplx a, double r) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx resultado;
    resultado.f = rec;
    resultado.rec.real = a_rec.rec.real / r;
    resultado.rec.imag = a_rec.rec.imag / r;
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/* 5.f) Divisão: r / a */
cplx dividir_real_CPLX(double r, cplx a) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx a_rec_conj = conjugado_CPLX(a_rec);
    t_cplx denominador = real_mult_CPLX(a_rec_conj, r);
    double numerador = a_rec.rec.real * a_rec.rec.real + a_rec.rec.imag * a_rec.rec.imag;
    t_cplx resultado = dividir_CPLX_real(denominador, numerador);
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/* =============================================================================
 * 6. FUNÇÕES AVANÇADAS E ESPECIAIS
 * ============================================================================= */

/*
 * 6.a) Devolva o conjugado do número complexo 'a'. Mantenha o formato de 'a'.
 *      - Em RETANGULAR: troca o sinal de imag.
 *      - Em POLAR: troca o sinal de arg.
 */
cplx conjugado_CPLX(cplx a) {
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
        resultado.pol.arg = normaliza_angulo(-a.pol.arg);
        return resultado;
    }
}

/*
 * 6.b) Dado 'a' e um expoente real 'n', devolva o resultado de a^n (Fórmula de De Moivre).
 *      - Modulo resultante: mod(a)^n
 *      - Argumento resultante: arg(a) * n (normalizado)
 *      - Devolva no formato original de 'a'.
 */
cplx potencia_CPLX(cplx a, double n) {
    t_cplx a_pol = converte_CPLX(a, pol);
    t_cplx resultado;
    resultado.f = pol;
    resultado.pol.mod = pow(a_pol.pol.mod, n);
    resultado.pol.arg = normaliza_angulo(a_pol.pol.arg * n);
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/*
 * 6.c) Dado 'a', devolva e^a (Exponencial Complexa).
 *      - e^(x + iy) = e^x * (cos(y) + i*sin(y)) => Modulo = e^re(a), Arg = img(a)
 *      - Devolva no formato original de 'a'.
 */
cplx exp_CPLX(cplx a) {
    t_cplx a_rec = converte_CPLX(a, rec);
    t_cplx resultado;
    resultado.f = pol;
    resultado.pol.mod = exp(a_rec.rec.real);
    resultado.pol.arg = normaliza_angulo(a_rec.rec.imag);
    resultado = converte_CPLX(resultado, a.f);
    return resultado;
}

/*
 * 6.d) Dado 'c' e um inteiro positivo 'n', preencha o vetor 'resultados' 
 *      com as n raízes enézimas de 'c'.
 *      - Modulo de cada raiz: mod(c)^(1/n)
 *      - Argumento da k-ésima raiz (k de 0 a n-1): (arg(c) + 2*PI*k) / n
 *      - Cada raiz no vetor deve estar no formato original de 'c'.
 */
void raizes_CPLX(cplx c, int n, cplx resultados[]) {
    t_cplx c_pol = converte_CPLX(c, pol);
    for(int k = 0; k < n; k++) {
        resultados[k].f = pol;
        resultados[k].pol.mod = pow(c_pol.pol.mod, 1.0/n);
        resultados[k].pol.arg = normaliza_angulo((c_pol.pol.arg + 2.0 * M_PI * k) / n);
        resultados[k] = converte_CPLX(resultados[k], c.f);
    }
}

/* =============================================================================
 * 7. ENTRADA E SAÍDA (I/O)
 * ============================================================================= */

/*
 * 7.a) Imprima o valor de 'a' com 2 casas decimais de acordo com seu formato:
 *      - RETANGULAR: "%.2f + %.2fi\n" ou "%.2f - %.2fi\n"
 *      - POLAR:       "%.2f < %.2f rad\n"
 *      (Trate valores muito próximos de zero com fabs(val) < 1e-9 -> 0.00)
 */
void imprimir_CPLX(cplx a) {
    if (a.f == rec) {
        if (fabs(a.rec.real) < 1e-2) a.rec.real = 0.0;
        if (fabs(a.rec.imag) < 1e-2) a.rec.imag = 0.0;

        if (a.rec.imag >= 0.0) {
            printf("%.2f + %.2fi\n", a.rec.real, a.rec.imag);
        } else {
            printf("%.2f - %.2fi\n", a.rec.real, fabs(a.rec.imag));
        }
    } else if (a.f == pol) {
        if (fabs(a.pol.mod) < 1e-2) a.pol.mod = 0.0;
        if (fabs(a.pol.arg) < 1e-2) a.pol.arg = 0.0;
        printf("%.2f < %.2f rad\n", a.pol.mod, a.pol.arg);
    }
}

/*
 * 7.b) Lê um complexo da entrada padrão:
 *      - Caractere 'R' ou 'r': lê real e imag (dois doubles)
 *      - Caractere 'P' ou 'p': lê modulo e arg (dois doubles)
 */
cplx ler_CPLX() {
    t_cplx c;
    char tipo;
    scanf(" %c", &tipo);
    if(tipo == 'R' || tipo == 'r') {
        c.f = rec;
        scanf("%lf %lf", &c.rec.real, &c.rec.imag);
        return c;
    } else if(tipo == 'P' || tipo == 'p') {
        c.f = pol;
        scanf("%lf %lf", &c.pol.mod, &c.pol.arg);
        c.pol.arg = normaliza_angulo(c.pol.arg);
        return c;
    }
}

/* =============================================================================
 * 8. FUNÇÃO PRINCIPAL (Bateria de Testes)
 * 
 * Ordem de leitura da entrada:
 * 1. n (inteiro): ordem das raízes enézimas (n >= 1)
 * 2. r (double): escalar real / expoente
 * 3. f_out_char (char: 'R'/'r' ou 'P'/'p'): formato desejado de saída
 * 4. Complexo A (usando ler_CPLX)
 * 5. Complexo B (usando ler_CPLX)
 * 
 * Regra de exibição:
 * Todos os resultados complexos impressos devem ser convertidos para o formato f_out.
 * ============================================================================= */
int main() {
    // 1. Declare as variáveis necessárias (n, r, f_out_char, a, b, etc.)
    // --preencher--
    int n;
    double r;
    char f_out_char;
    t_formato f_out;
    t_cplx a, b;
    // 2. Realize a leitura dos dados de entrada (n, r, formato de saída, A e B)
    // --preencher--
    scanf("%d %lf %c", &n, &r, &f_out_char);
    if(f_out_char == 'R' || f_out_char == 'r') {
        f_out = rec;
    } else {
        f_out = pol;
    }
    
    a = ler_CPLX();
    b = ler_CPLX();
    
    a = converte_CPLX(a, f_out);
    b = converte_CPLX(b, f_out);
    // 3. Exibição de A e B no formato de saída definido
    printf("A = ");
    imprimir_CPLX(a);

    printf("B = ");
    imprimir_CPLX(b);

    // 4. Propriedades fundamentais (use fabs para evitar -0.00)
    // --preencher: imprimir partes de A e partes de B no formato especificado--
    
    printf("PARTS A: MOD=%.2f ARG=%.2f RE=%.2f IMG=%.2f\n", converte_CPLX(a, pol).pol.mod, converte_CPLX(a, pol).pol.arg, converte_CPLX(a, rec).rec.real, converte_CPLX(a, rec).rec.imag);
    printf("PARTS B: MOD=%.2f ARG=%.2f RE=%.2f IMG=%.2f\n", converte_CPLX(b, pol).pol.mod, converte_CPLX(b, pol).pol.arg, converte_CPLX(b, rec).rec.real, converte_CPLX(b, rec).rec.imag);

    // 5. Conjugados
    printf("CONJ(A) = ");
    imprimir_CPLX(conjugado_CPLX(a));

    printf("CONJ(B) = ");
    imprimir_CPLX(conjugado_CPLX(b));

    // 6. Operações entre Complexos
    printf("A + B = ");
    imprimir_CPLX(somar_CPLX(a, b));

    printf("A - B = ");
    imprimir_CPLX(subtrair_CPLX(a, b));

    printf("A * B = ");
    imprimir_CPLX(cplx_mult_CPLX(a, b));

    printf("A / B = ");
    imprimir_CPLX(dividir_CPLX(a, b));

    // 7. Operações com o Escalar Real R
    printf("R + A = ");
    imprimir_CPLX(somar_real_CPLX(r, a));

    printf("R - A = ");
    imprimir_CPLX(subtrair_real_CPLX(r, a));

    printf("A - R = ");
    imprimir_CPLX(subtrair_CPLX_real(a, r));

    printf("R * A = ");
    imprimir_CPLX(real_mult_CPLX(a, r));

    printf("A / R = ");
    imprimir_CPLX(dividir_CPLX_real(a, r));

    printf("R / A = ");
    imprimir_CPLX(dividir_real_CPLX(r, a));

    // 8. Potência e Exponencial
    printf("A ^ R = ");
    imprimir_CPLX(potencia_CPLX(a, r));

    printf("exp(A) = ");
    imprimir_CPLX(exp_CPLX(a));

    // 9. Raízes Enézimas
    // --preencher: alocar vetor para n complexos, chamar raizes_CPLX,
    //              imprimir cada raiz no formato "Raiz %d: " e liberar memória--
    t_cplx raizes[n];
    raizes_CPLX(a, n, raizes);
    printf("RAIZES DE A (ordem %d):\n", n);
    for(int k = 0; k < n; k++) {
        printf("Raiz %d: ", k);
        imprimir_CPLX(raizes[k]);
    }

    return 0;
}