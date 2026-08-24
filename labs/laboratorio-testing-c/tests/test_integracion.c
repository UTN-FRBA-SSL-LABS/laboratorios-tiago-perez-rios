#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Leche", 350, 2};  /* 350 x 2 = 700 */
    Producto p2 = {"Pan", 150, 3};    /* 150 x 3 = 450 */
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    ASSERT_IGUAL(1150, carrito_total(&c));  /* 700 + 450 = 1150 */
    int total_con_descuento = carrito_descuento(carrito_total(&c), 10);
    ASSERT_IGUAL(1035, total_con_descuento);  /* 1150 - 10% = 1035 */

}
    

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */

void test_agregar_hasta_llenar(void)
{
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    for (int i = 0; i < 4; i++) {
    carrito_agregar(&c, p);  /* se puede agregar */
    }
    ASSERT_IGUAL(0, carrito_agregar(&c, p));  /* no se puede agregar más */
    ASSERT_IGUAL(4, carrito_contar(&c));  /* cantidad de productos en el carrito */
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar(); 
    RESUMEN();
    return EXIT_CODE();
}
