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
    printf("    z1 = 3.00 + 4.00i\n");
    printf("    z2 = 1.00 + 2.00i\n");
    printf("    Resultado (Soma): %.2f + %.2fi (Esperado: 4.00 + 6.00i)\n", soma1.rec.real, soma1.rec.imag);
    printf("    Formato do resultado: %s\n\n", soma1.f == rec ? "RETANGULAR" : "POLAR");

    t_cplx z_pol = converte_CPLX(z1, pol);
    t_cplx soma2 = somar_CPLX(z_pol, z2);
    printf("[2] Soma Polar + Retangular (a eh POLAR):\n");
    printf("    z_pol (3+4i em polar) + z2 (1+2i)\n");
    printf("    Formato retornado: %s (Esperado: POLAR)\n", soma2.f == pol ? "POLAR" : "RETANGULAR");
    printf("    Modulo retornado:  %.2f (Esperado: 7.21)\n", soma2.pol.mod);
    printf("    Angulo retornado:  %.4f rad\n", soma2.pol.arg);

    t_cplx soma2_rec = converte_CPLX(soma2, rec);
    printf("    Conferindo em retangular: %.2f + %.2fi (Esperado: 4.00 + 6.00i)\n\n", soma2_rec.rec.real, soma2_rec.rec.imag);
    */

    return 0;
}
