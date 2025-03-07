#include <stdbool.h>
#include <stdio.h>
#include "cnf.h"

//
// LOGIN: xpasekj00
//

/** Funkce demonstrující vytvoření nové (arbitrárně vybrané) klauzule
* ve tvaru "h_{0,1} || -v_{0,1}" do výrokové formule
* @param formula výroková formule, do níž bude klauzule přidána
*/
void conditions_example(CNF* formula) {
    assert(formula != NULL);

    // vytvoření nové klauzule
    Clause* cl = create_new_clause(formula);

    // přidání proměnné h_{0,1} do klauzule
    // proměnná říká, že v regionu 0 je produkován produkt 1 jako hlavní
    // cl - klauzule, do níž přidáváme literál
    // true - značí, že přidaný literál je pozitivní proměnná
    // MAIN_PRODUCT - značí, že pracujeme s hlavním produktem
    // 0 - značí region s indexem 0
    // 1 - značí produkt s indexem 1
    add_literal_to_clause(cl, true, MAIN_PRODUCT, 0, 1);

    // přidání proměnné -v_{0,1} do klauzule
    // proměnná říká, že v regionu 0 není produkován produkt 1 jako vedlejší
    // cl - klauzule, do níž přidáváme literál
    // false - značí, že přidaný literál je negativní proměnná
    // SIDE_PRODUCT - značí, že pracujeme s vedlejším produktem
    // 0 - značí region s indexem 0
    // 1 - značí produkt s indexem 1
    add_literal_to_clause(cl, false, SIDE_PRODUCT, 0, 1);
}

/** Funkce vytvářející klauzule ošetřující podmínku, že v každém regionu
* je produkován alespoň jeden hlavní produkt.
* @param formula výroková formule, do níž bude klauzule přidána
* @param num_of_regions počet regionů
* @param num_of_products počet produktů
*/
void all_regions_min_one_main_product(CNF* formula, unsigned num_of_regions, unsigned num_of_products) {
    assert(formula != NULL);
    assert(num_of_regions > 0);

    for (unsigned k = 0; k < num_of_regions; ++k) {
        Clause* cl = create_new_clause(formula);
        for (unsigned p = 0; p < num_of_products; ++p) {
            add_literal_to_clause(cl, true, MAIN_PRODUCT, k, p);
        }
    }
}

/** Funkce vytvářející klauzule ošetřující podmínku, že v každém regionu
* je produkován nejvýše jeden hlavní produkt.
* @param formula výroková formule, do níž bude klauzule přidána
* @param num_of_regions počet regionů
* @param num_of_products počet produktů
*/
void all_regions_max_one_main_product(CNF* formula, unsigned num_of_regions, unsigned num_of_products) {
   assert(formula != NULL);
    assert(num_of_regions > 0);

    for (unsigned k = 0; k < num_of_regions; ++k) {
        for (unsigned p_1 = 0; p_1 < num_of_products; ++p_1) {
            for (unsigned p_2 = 0; p_2 < num_of_products; ++p_2) {
                if (p_1 >= p_2) { continue; }
                Clause* cl = create_new_clause(formula);
                add_literal_to_clause(cl, false, MAIN_PRODUCT, k, p_1);
                add_literal_to_clause(cl, false, MAIN_PRODUCT, k, p_2);
            }
        }

  }

}

/** Funkce vytvářející klauzule ošetřující podmínku, že v každém regionu
* je produkován nejvýše jeden vedlejší produkt.
* @param formula výroková formule, do níž bude klauzule přidána
* @param num_of_regions počet regionů
* @param num_of_products počet produktů
*/

void all_regions_max_one_side_product(CNF* formula, unsigned num_of_regions, unsigned num_of_products) {
    assert(formula != NULL);
    assert(num_of_regions > 0);
    for (unsigned k = 0; k < num_of_regions; ++k) {
        for (unsigned p_1 = 0; p_1 < num_of_products; ++p_1) {
            for (unsigned p_2 = 0; p_2 < num_of_products; ++p_2) {
                if (p_1 >= p_2) { continue; }
                Clause* cl = create_new_clause(formula);
                add_literal_to_clause(cl, false, SIDE_PRODUCT, k, p_1);
                add_literal_to_clause(cl, false, SIDE_PRODUCT, k, p_2);
            }
        }
    }
    //musi byt nejvyse jeden vedlejsi produkt takze tam muze byt jeden nebo zadny
    //porovnavame dva produkty vzdycky a potrebujeme 0 1  1 0  0 0 tim padem negace produktu
    //nebo negace produktu
}

/** Funkce vytvářející klauzule ošetřující podmínku, že v každém regionu
* se hlavní a vedlejší produkt liší
* @param formula výroková formule, do níž bude klauzule přidána
* @param num_of_regions počet regionů
* @param num_of_products počet produktů
*/
void main_side_products_different(CNF* formula, unsigned num_of_regions, unsigned num_of_products) {

    assert(formula != NULL);
    assert(num_of_regions > 0);
    for (unsigned k = 0; k < num_of_regions; ++k) {
        for (unsigned p_1 = 0; p_1 < num_of_products; ++p_1) {
                Clause* cl = create_new_clause(formula);
                add_literal_to_clause(cl, false, MAIN_PRODUCT, k, p_1);
                add_literal_to_clause(cl, false, SIDE_PRODUCT, k, p_1);
        }
    }
//porovnavame dva produkty a zase hledame 0 1  0 0  1 0 tim padem negace produktu nebo negace produktu

}

/** Funkce vytvářející klauzule ošetřující podmínku, že
* sousední regiony nesdílejí hlavní a vedlejší produkt.
* @param formula výroková formule, do níž bude klauzule přidána
* @param num_of_regions počet regionů
* @param num_of_products počet produktů
* @param neighbours seznamy sousedů
*/
void neighbour_regions_different_main_products(CNF* formula, unsigned num_of_regions, unsigned num_of_products, const NeighbourLists *neighbours) {
    assert(formula != NULL);
    assert(num_of_regions > 0);
    assert(neighbours != NULL);
    for(unsigned k_1 = 0;k_1 < num_of_regions;k_1++){
        for(unsigned k_2 = 0;k_2 < num_of_regions;k_2++){
            if(are_neighbours(neighbours, k_1,k_2)){
                for (unsigned p_1 = 0; p_1 < num_of_products; ++p_1) {
                        Clause* cl = create_new_clause(formula);
                        add_literal_to_clause(cl, false, MAIN_PRODUCT, k_1, p_1);
                        add_literal_to_clause(cl, false, MAIN_PRODUCT, k_2, p_1);
                        Clause* cl1 = create_new_clause(formula);
                        add_literal_to_clause(cl1, false, SIDE_PRODUCT, k_1, p_1);
                        add_literal_to_clause(cl1, false, SIDE_PRODUCT, k_2, p_1);
                    }

                }
            //prvni cast musi produkt muze byt pouze u jednoho jako Main a ne u druheho Main nebo neni u zadneho ->
            //negace Main nebo negace Main a druha cast je to same


            }



    }
    //
    // Zde doplňte řešení
    // Tip: Využijte implementovanou funkci are_neighbours.
    // Příklad použití:
    // unsigned region1 = 0;
    // unsigned region2 = 1;
    // if (are_neighbours(neighbours, region1, region2)) { ... }
    //
}

/** Funkce vytvářející klauzule ošetřující podmínku, že
* každý produkt je v některém regionu hlavním produktem.
* @param formula výroková formule, do níž bude klauzule přidána
* @param num_of_regions počet regionů
* @param num_of_products počet produktů
*/
void all_products_at_least_once_main_products(CNF* formula, unsigned num_of_regions, unsigned num_of_products) {

    assert(formula != NULL);
    assert(num_of_regions > 0);

    for (unsigned p = 0; p < num_of_products; ++p) {
        Clause* cl = create_new_clause(formula);
        for (unsigned k = 0; k < num_of_regions; ++k) {
            add_literal_to_clause(cl, true, MAIN_PRODUCT, k, p);
        }
    }

}

/** Funkce vytvářející klauzule ošetřující podmínku,
* že v hlavním regionu (v regionu 0) neexistuje žádný vedlejší produkt
* @param formula výroková formule, do níž bude klauzule přidána
* @param num_of_regions počet regionů
* @param num_of_products počet produktů
*/
void no_side_product_in_main_region(CNF* formula, unsigned num_of_regions, unsigned num_of_products) {

    assert(formula != NULL);
    assert(num_of_regions > 0);

    for (unsigned p = 0; p < num_of_products; ++p) {
        Clause* cl = create_new_clause(formula);
        add_literal_to_clause(cl, false, SIDE_PRODUCT, 0, p);
    }

}

/** Funkce vytvářející klauzule ošetřující podmínku,
* že produkt produkovaný v hlavním regionu (v regionu 0) jako hlavní produkt
* je ještě v některém regionu produkován jako vedlejší.
* @param formula výroková formule, do níž bude klauzule přidána
* @param num_of_regions počet regionů
* @param num_of_products počet produktů
*/
void main_region_main_product_as_side_product_elsewhere(CNF* formula, unsigned num_of_regions, unsigned num_of_products) {

    assert(formula != NULL);
    assert(num_of_regions > 0);
    for(unsigned p = 0;p < num_of_products;p++){
        Clause* cl = create_new_clause(formula);
        add_literal_to_clause(cl, false, MAIN_PRODUCT,0,p);
        for(unsigned k =0;k < num_of_regions;k++){

            add_literal_to_clause(cl,true,SIDE_PRODUCT,k,p);
        }
    }
    //produkt je hlavni produkt V hlavní regionu implikuje ze musi byt v nekterem regionu produkovan jako vedlejsim
    //pravidlo implikace produkt neni hlavni produkt v hlavnim regionu nebo je v nekterem regionu jako vedlejsim

}

/** Bonusová funkce k projektu
* @return vrací bonusovou odpověď
*/
char *bonus(void) {

    // Doplňte správný řetězecreturn "Komisař Maigret";
    return "Maigret";
}
