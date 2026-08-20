#include <stdio.h>
#include <stdlib.h>
#include "Complexo.h"

int main()
{
    printf("=== Testes do TAD Números Complexos ===\n\n");

    /*
    // --- TESTE 1: converte_CPLX ---
    printf("--- Teste 1: converte_CPLX ---\n");
    t_cplx z1;
    z1.f = rec;
    z1.rec.real = 3.0;
    z1.rec.imag = 4.0;

    printf("[1] Numero Original (Retangular):\n");
    printf("    Real: %.2f | Imag: %.2f\n\n", z1.rec.real, z1.rec.imag);

    t_cplx z1_pol = converte_CPLX(z1, pol);
    printf("[2] Convertido para POLAR:\n");
    printf("    Formato: %s\n", z1_pol.f == pol ? "POLAR" : "OUTRO");
    printf("    Modulo:  %.2f (Esperado: 5.00)\n", z1_pol.pol.mod);
    printf("    Angulo:  %.4f rad (Esperado: ~0.9273 rad / ~53.13 deg)\n\n", z1_pol.pol.arg);

    t_cplx z1_rec = converte_CPLX(z1_pol, rec);
    printf("[3] Convertido de volta para RETANGULAR:\n");
    printf("    Formato: %s\n", z1_rec.f == rec ? "RETANGULAR" : "OUTRO");
    printf("    Real: %.2f (Esperado: 3.00)\n", z1_rec.rec.real);
    printf("    Imag: %.2f (Esperado: 4.00)\n\n", z1_rec.rec.imag);
    */

    /*
    // --- TESTE 2: somar_CPLX ---
    printf("--- Teste 2: somar_CPLX ---\n");
    t_cplx z1;
    z1.f = rec;
    z1.rec.real = 3.0;
    z1.rec.imag = 4.0;

    t_cplx z2;
    z2.f = rec;
    z2.rec.real = 1.0;
    z2.rec.imag = 2.0;

    t_cplx soma1 = somar_CPLX(z1, z2);
    printf("[1] Soma Retangular + Retangular:\n");
    printf("    (3 + 4i) + (1 + 2i) = %.2f + %.2fi (Esperado: 4.00 + 6.00i)\n", soma1.rec.real, soma1.rec.imag);
    printf("    Formato do resultado: %s\n\n", soma1.f == rec ? "RETANGULAR" : "POLAR");

    t_cplx z_pol = converte_CPLX(z1, pol);
    t_cplx soma2 = somar_CPLX(z_pol, z2);
    printf("[2] Soma Polar + Retangular (a eh POLAR):\n");
    printf("    Formato retornado: %s (Esperado: POLAR)\n", soma2.f == pol ? "POLAR" : "RETANGULAR");
    printf("    Modulo: %.2f (Esperado: 7.21)\n\n", soma2.pol.mod);
    */

    /*
    // --- TESTE 3: subtrair_CPLX ---
    printf("--- Teste 3: subtrair_CPLX ---\n");
    t_cplx s1;
    s1.f = rec;
    s1.rec.real = 5.0;
    s1.rec.imag = 7.0;

    t_cplx s2;
    s2.f = rec;
    s2.rec.real = 2.0;
    s2.rec.imag = 3.0;

    t_cplx sub1 = subtrair_CPLX(s1, s2);
    printf("[1] Subtracao Retangular - Retangular:\n");
    printf("    (5 + 7i) - (2 + 3i) = %.2f + %.2fi (Esperado: 3.00 + 4.00i)\n", sub1.rec.real, sub1.rec.imag);
    printf("    Formato: %s\n\n", sub1.f == rec ? "RETANGULAR" : "POLAR");

    t_cplx s1_pol = converte_CPLX(s1, pol);
    t_cplx sub2 = subtrair_CPLX(s1_pol, s2);
    printf("[2] Subtracao Polar - Retangular (a eh POLAR):\n");
    printf("    Formato: %s (Esperado: POLAR)\n", sub2.f == pol ? "POLAR" : "RETANGULAR");
    printf("    Modulo: %.2f (Esperado: 5.00)\n\n", sub2.pol.mod);
    */

    /*
    // --- TESTE 4: cplx_mult_CPLX ---
    printf("--- Teste 4: cplx_mult_CPLX ---\n");
    t_cplx m1;
    m1.f = rec;
    m1.rec.real = 3.0;
    m1.rec.imag = 2.0;

    t_cplx m2;
    m2.f = rec;
    m2.rec.real = 1.0;
    m2.rec.imag = 4.0;

    t_cplx mult1 = cplx_mult_CPLX(m1, m2);
    printf("[1] Multiplicacao Retangular * Retangular:\n");
    printf("    (3 + 2i) * (1 + 4i) = %.2f + %.2fi (Esperado: -5.00 + 14.00i)\n", mult1.rec.real, mult1.rec.imag);
    printf("    Formato retornado: %s (Esperado: RETANGULAR)\n\n", mult1.f == rec ? "RETANGULAR" : "POLAR");

    t_cplx p1;
    p1.f = pol;
    p1.pol.mod = 2.0;
    p1.pol.arg = M_PI / 6.0;

    t_cplx p2;
    p2.f = pol;
    p2.pol.mod = 3.0;
    p2.pol.arg = M_PI / 3.0;

    t_cplx mult2 = cplx_mult_CPLX(p1, p2);
    printf("[2] Multiplicacao Polar * Polar:\n");
    printf("    Formato: %s (Esperado: POLAR)\n", mult2.f == pol ? "POLAR" : "RETANGULAR");
    printf("    Modulo: %.2f (Esperado: 6.00)\n", mult2.pol.mod);
    printf("    Angulo: %.4f rad (Esperado: %.4f rad [90 deg])\n\n", mult2.pol.arg, M_PI / 2.0);
    */

    /*
    // --- TESTE 5: real_mult_CPLX ---
    printf("--- Teste 5: real_mult_CPLX ---\n");
    t_cplx z1;
    z1.f = rec;
    z1.rec.real = 3.0;
    z1.rec.imag = 4.0;

    t_cplx r_res1 = real_mult_CPLX(z1, 2.0);
    printf("[1] Retangular * Real:\n");
    printf("    (3 + 4i) * 2.0 = %.2f + %.2fi (Esperado: 6.00 + 8.00i)\n", r_res1.rec.real, r_res1.rec.imag);
    printf("    Formato retornado: %s (Esperado: RETANGULAR)\n\n", r_res1.f == rec ? "RETANGULAR" : "POLAR");

    t_cplx z1_pol = converte_CPLX(z1, pol);
    t_cplx r_res2 = real_mult_CPLX(z1_pol, 3.0);
    printf("[2] Polar * Real (a eh POLAR):\n");
    printf("    Formato: %s (Esperado: POLAR)\n", r_res2.f == pol ? "POLAR" : "RETANGULAR");
    printf("    Modulo: %.2f (Esperado: 15.00)\n\n", r_res2.pol.mod);
    */

    /*
    // --- TESTE 6: dividir_CPLX ---
    printf("--- Teste 6: dividir_CPLX ---\n");
    t_cplx d1;
    d1.f = pol;
    d1.pol.mod = 6.0;
    d1.pol.arg = M_PI / 2.0;

    t_cplx d2;
    d2.f = pol;
    d2.pol.mod = 2.0;
    d2.pol.arg = M_PI / 6.0;

    t_cplx div1 = dividir_CPLX(d1, d2);
    printf("[1] Divisao Polar / Polar:\n");
    printf("    Formato: %s (Esperado: POLAR)\n", div1.f == pol ? "POLAR" : "RETANGULAR");
    printf("    Modulo: %.2f (Esperado: 3.00)\n", div1.pol.mod);
    printf("    Angulo: %.4f rad (Esperado: %.4f rad [60 deg])\n\n", div1.pol.arg, M_PI / 3.0);

    t_cplx m1;
    m1.f = rec;
    m1.rec.real = -5.0;
    m1.rec.imag = 14.0;

    t_cplx m2;
    m2.f = rec;
    m2.rec.real = 1.0;
    m2.rec.imag = 4.0;

    t_cplx div2 = dividir_CPLX(m1, m2);
    printf("[2] Divisao Retangular / Retangular:\n");
    printf("    (-5 + 14i) / (1 + 4i) = %.2f + %.2fi (Esperado: 3.00 + 2.00i)\n\n", div2.rec.real, div2.rec.imag);
    */

    /*
    // --- TESTE 7: conjugado_CPLX ---
    printf("--- Teste 7: conjugado_CPLX ---\n");
    t_cplx z1;
    z1.f = rec;
    z1.rec.real = 3.0;
    z1.rec.imag = 4.0;

    t_cplx conj1 = conjugado_CPLX(z1);
    printf("[1] Conjugado de Retangular (3 + 4i):\n");
    printf("    Resultado: %.2f + (%.2fi) (Esperado: 3.00 - 4.00i)\n", conj1.rec.real, conj1.rec.imag);
    printf("    Formato: %s\n\n", conj1.f == rec ? "RETANGULAR" : "POLAR");

    t_cplx p1 = converte_CPLX(z1, pol);
    t_cplx conj2 = conjugado_CPLX(p1);
    printf("[2] Conjugado de Polar (Mod 5.00, Arg 0.9273 rad):\n");
    printf("    Modulo: %.2f (Esperado: 5.00)\n", conj2.pol.mod);
    printf("    Angulo: %.4f rad (Esperado: -0.9273 rad)\n", conj2.pol.arg);
    printf("    Formato: %s\n\n", conj2.f == pol ? "POLAR" : "RETANGULAR");
    */

    /*
    // --- TESTES 8 a 12: Acessores (mod, arg, img, re) ---
    printf("--- Testes 8 a 12: Acessores ---\n");
    t_cplx z1;
    z1.f = rec;
    z1.rec.real = 3.0;
    z1.rec.imag = 4.0;

    printf("[8]  mod_CPLX(3 + 4i): %.2f (Esperado: 5.00)\n", mod_CPLX(z1));
    printf("[10] arg_CPLX(3 + 4i): %.4f rad (Esperado: 0.9273 rad)\n", arg_CPLX(z1));
    printf("[11] img_CPLX(3 + 4i): %.2f (Esperado: 4.00)\n", img_CPLX(z1));
    printf("[12] re_CPLX(3 + 4i):  %.2f (Esperado: 3.00)\n\n", re_CPLX(z1));
    */

    /*
    // --- TESTE 13: potencia_CPLX ---
    printf("--- Teste 13: potencia_CPLX ---\n");
    t_cplx z_base;
    z_base.f = rec;
    z_base.rec.real = 1.0;
    z_base.rec.imag = 1.0;

    t_cplx pot1 = potencia_CPLX(z_base, 2.0);
    printf("[1] (1 + 1i)^2 = %.2f + %.2fi (Esperado: 0.00 + 2.00i)\n", pot1.rec.real, pot1.rec.imag);
    printf("    Formato: %s\n\n", pot1.f == rec ? "RETANGULAR" : "POLAR");

    t_cplx p_base;
    p_base.f = pol;
    p_base.pol.mod = 2.0;
    p_base.pol.arg = M_PI / 6.0;

    t_cplx pot2 = potencia_CPLX(p_base, 3.0);
    printf("[2] (2 < 30 deg)^3 em Polar:\n");
    printf("    Modulo: %.2f (Esperado: 8.00)\n", pot2.pol.mod);
    printf("    Angulo: %.4f rad (Esperado: %.4f rad [90 deg])\n", pot2.pol.arg, M_PI / 2.0);
    printf("    Formato: %s\n\n", pot2.f == pol ? "POLAR" : "RETANGULAR");
    */

    /*
    // --- TESTE 14: exp_CPLX ---
    printf("--- Teste 14: exp_CPLX ---\n");
    t_cplx z_euler;
    z_euler.f = rec;
    z_euler.rec.real = 0.0;
    z_euler.rec.imag = M_PI;

    t_cplx res_euler = exp_CPLX(z_euler);
    printf("[1] e^(0 + pi*i) = %.2f + %.2fi (Esperado: -1.00 + 0.00i)\n", res_euler.rec.real, res_euler.rec.imag);
    printf("    Formato: %s\n\n", res_euler.f == rec ? "RETANGULAR" : "POLAR");
    */

    /*
    // --- TESTE 15: imprimir_CPLX ---
    printf("--- Teste 15: imprimir_CPLX ---\n");
    t_cplx z_rec;
    z_rec.f = rec;
    z_rec.rec.real = 3.0;
    z_rec.rec.imag = 4.0;
    printf("[1] Retangular: ");
    imprimir_CPLX(z_rec);

    t_cplx z_pol;
    z_pol.f = pol;
    z_pol.pol.mod = 5.0;
    z_pol.pol.arg = 0.9273;
    printf("[2] Polar: ");
    imprimir_CPLX(z_pol);
    printf("\n");
    */

    /*
    // --- TESTE 16: raizes_CPLX ---
    printf("--- Teste 16: raizes_CPLX ---\n");
    t_cplx c_polar;
    c_polar.f = pol;
    c_polar.pol.mod = 16.0;
    c_polar.pol.arg = 0.0;

    int n = 4;
    t_cplx raizes[4];
    raizes_CPLX(c_polar, n, raizes);

    printf("As 4 raizes de (16 < 0 rad) sao:\n");
    for(int k = 0; k < n; k++) {
        printf("  Raiz %d: ", k);
        imprimir_CPLX(raizes[k]);
    }
    printf("\n");
    */

    return 0;
}
