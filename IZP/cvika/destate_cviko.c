/**
 * Kostra 10. cviceni predmetu IZP, rok 2024
 * @author Jakub Husa (ihusa@fit.vut.cz) a Ales Smrcka
 * @date   2024-12-09
 *
 * Tema cviceni:
 *  Abstraktni datove typy (linearni seznam)
 *
 * Vyzkousejte si:
 *  Doplnte definici vsech uvedenych funkci a na serveru
 *  merlin.fit.vutbr.cz overte ze v programu nedochazi k
 *  chybne praci s pameti (valgrind)
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/****************************/
/** Deklarace datovych typu */
/****************************/

/**
 * Object, pouzivany jako data polozky seznamu.
 */
typedef struct {
    int id;
    char* name;
} Object;

/**
 * Polozka, obsahuje data a ukazatel na dalsi polozku seznamu.
 * Aby struktura mohla ukazovat na svuj vlastni datovy typ
 * jeji deklarace a definice museji byt provedeny oddelene.
 */
typedef struct item Item; /** Deklarace datoveho typu */

struct item { /** Definice struktury */
    Object data;
    Item* next;
};

/**
 * Seznam, obsahuje ukazatel na svoji prvni polozku.
 */
typedef struct {
    Item* first;
} List;

/*********************/
/** Deklarace funkci */
/*********************/

void print_list(List* list);                    /** vypsani seznamu */
void print_item(Item* item);                    /** vypsani polozky */
List list_ctor();                               /** inicializace seznamu */
void list_insert_first(List* list, Item* item); /** vlozeni polozky na pocatek seznamu */


Item* item_ctor(Object data);                   /** inicilaizace polozky seznamu */
void list_delete_first(List* list);             /** odstraneni prvni polozky namu */
unsigned list_count(List* list);                /** vypocet delky seznamu */
Item* list_find_minid(List* list);              /** vyhledani polozky s nejmensim identifikatorem */
Item* list_find_name(List* list, char* name);   /** vyhledani polozky s danym jmenem */
void list_insert_last(List* list, Item* item);  /** vlozeni polozky na konec seznamu */
void list_insert_position(List* list, Item* item, unsigned pos); /** vlozeni polozky na zadanou pozici v seznamu */
void list_dtor(List* list);                     /** odstraneni vsech polozek seznamu */

/***************************/
/** Hlavni funkce programu */
/***************************/

int main()
{
    printf("====================================== item_ctor\n");
    Item* item;
    printf("Vytvarim seznam\n");
    List list = list_ctor();
    printf("Vytvarim polozku HONZA\n");
    Object o0 = {20, "Honza"};
    item = item_ctor(o0);
    printf("Vkladam polozku na pocatek seznamu\n");
    list_insert_first(&list, item);
    printf("Vypisuji seznam:\n");
    print_list(&list);

    printf("====================================== item_ctor\n");
    printf("====================================== list_delete_first\n");

    printf("Vytvarim polozku ALES\n");
    Object o1 = {70, "Ales"};
    item = item_ctor(o1);
    printf("Vkladam polozku na pocatek seznamu\n");
    list_insert_first(&list, item);
    printf("Vypisuji seznam:\n");
    print_list(&list);
    printf("Odstranuji prvni polozku seznamu\n");
    list_delete_first(&list);
    printf("Vypisuji seznam:\n");
    print_list(&list);

    printf("====================================== list_delete_first\n");
    printf("====================================== list_count\n");

    printf("Pocitam pocet polozek seznamu:\n");
    printf("  Seznam obsahuje %i polozek\n", list_count(&list));
    printf("Vytvarim polozku PETR\n");
    Object o2 = {10, "Petr"};
    item = item_ctor(o2);
    printf("Vkladam polozku na pocatek seznamu\n");
    list_insert_first(&list, item);
    printf("Vytvarim polozku DAVID\n");
    Object o3 = {30, "David"};
    item = item_ctor(o3);
    printf("Vkladam polozku na pocatek seznamu\n");
    list_insert_first(&list, item);
    printf("Vypisuji seznam:\n");
    print_list(&list);
    printf("Pocitam pocet polozek seznamu:\n");
    printf("  Seznam obsahuje %d polozek\n", list_count(&list));

    printf("====================================== list_count\n");
    printf("====================================== list_find_minid\n");

    printf("Vyhledavam prvek s nejmensim ID:\n");
    item = list_find_minid(&list);
    print_item(item);

    printf("====================================== list_find_minid\n");
    printf("====================================== list_find_name\n");

    printf("Odstranuji prvni polozku seznamu\n");
    list_delete_first(&list);
    printf("Vypisuji seznam:\n");
    print_list(&list);
    printf("Vyhledavam prvek DAVID:\n");
    item = list_find_name(&list, "David");
    print_item(item);
    printf("Vyhledavam prvek HONZA:\n");
    item = list_find_name(&list, "Honza");
    print_item(item);

    printf("====================================== list_find_name\n");
    printf("====================================== list_insert_last\n");

    printf("Vytvarim polozku KAREL\n");
    Object o4 = {40, "Karel"};
    item = item_ctor(o4);
    printf("Vkladam polozku na konec seznamu\n");
    list_insert_last(&list, item);
    printf("Vypisuji seznam:\n");
    print_list(&list);

    printf("====================================== list_insert_last\n");
    printf("====================================== list_insert_position\n");

    printf("Vytvarim polozku ZDENEK\n");
    Object o5 = {50, "Zdenek"};
    item = item_ctor(o5);
    printf("Vkladam polozku za druhy prvek seznamu\n");
    list_insert_position(&list, item, 2);
    printf("Vypisuji seznam:\n");
    print_list(&list);
    printf("Vytvarim polozku ROMAN\n");
    Object o6 = {60, "Roman"};
    item = item_ctor(o6);
    printf("Vkladam polozku za sedmy prvek seznamu\n");
    list_insert_position(&list, item, 7);
    printf("Vypisuji seznam:\n");
    print_list(&list);

    printf("====================================== list_insert_position\n");
    printf("====================================== list_dtor\n");

    printf("Pocitam pocet polozek seznamu:\n");
    printf("  Seznam obsahuje %d polozek\n", list_count(&list));
    printf("Odstranuji vsechny polozky seznamu\n");
    list_dtor(&list);
    printf("Vypisuji seznam:\n");
    print_list(&list);
    printf("Pocitam pocet polozek seznamu:\n");
    printf("  Seznam obsahuje %d polozek\n", list_count(&list));

    printf("====================================== list_dtor\n");
    return 0;
}

/*****************************************/
/** Definice funkci ktere uz jsou hotove */
/*****************************************/

/**
 * Vypis vsech polozek seznamu.
 * TUTO FUNKCI NEUPRAVUJTE!
 */
void print_list(List* list)
{
    if(list == NULL)
        return;

    unsigned index = 0;

    for (Item* item = list->first; item != NULL; item = item->next)
    {
        printf("  ITEM %i:", index);
        print_item(item);
        index++;
    }

}

/**
 * Vypis jedne konkretni polozky.
 * TUTO FUNKCI NEUPRAVUJTE!
 */
void print_item(Item* item)
{
    if (item == NULL)
        printf("  (null)\n");
    else
        printf("  [ID: %i  NAME: %s]\n", item->data.id, item->data.name);
}

/**
 * Vytvoreni prazdneho seznamu.
 * Seznam je alokovan automaticky.
 * TUTO FUNKCI NEUPRAVUJTE!
 */
List list_ctor()
{
    List list;
    list.first = NULL;
    return list;
}

/**
 * Vlozeni polozky na pocatek seznamu.
 * TUTO FUNKCI NEUPRAVUJTE!
 */
void list_insert_first(List* list, Item* item)
{
    if ((list == NULL) || (item == NULL))
        return;
    item->next = list->first;
    list->first = item;
}

/*********************************************/
/** Definice funkci ktere je potreba dodelat */
/*********************************************/

/**
 * Vytvoreni polozky.
 * Alokuje novou polozku a nastavi jeji "data" a "next".
 * Protoze funkce vraci ukazatel, polozka musi byl alokovana dynamicky (malloc).
 * Pozor na rozdil mezi velikosti "sizeof(Item)" a "sizeof(item)" !!!
 */
Item* item_ctor(Object data)
{
    Item* item = NULL;
    item = malloc(sizeof(Item));
    if(!item){
        return  NULL;
    }
    item->data.name = data.name;
    item->data.id = data.id;
    item->next = NULL;
    return item;
}

/**
 * Odstraneni prvni polozky seznamu.
 * Pokud je seznam prazdny, funkce neprovede nic a ukonci se.
 * Pokud seznam neni prazdny, pocatek seznamu (list->first) presune na druhou polozku.
 * A byvalou prvni polozku uvolni z pameti (free).
 */
void list_delete_first(List* list)
{
    if(list->first != NULL)
    {
        Item *temp = list->first;
        list->first = list->first->next;
        free(temp);
    }
}

/**
 * Spocitani poctu polozek seznamu.
 * Vytvori pomocny ukazatel, na akualni pozku seznamu (Item* active).
 * Ukazatel nastavi na prvni polozku seznamu.
 * Dokud ukazatel ukazuje na nejakou platnou polozku (!= NULL) inkrementuje pocitadlo a prechazi na nasledujici polozku.
 * Po skonceni cyklu vrati hodnotu pocitadla.
 */
unsigned list_count(List* list)
{
    unsigned count = 0;
    Item* active = list->first;
    while(active){
    active = active->next;
    count++;
    }
    return count;
}

/**
 * Nalzani polozky s nej nejnizsim ID.
 * Vytvori ukazatele pro aktivni a nejmensi polozku.
 * Prvni polozku seznamu prohlasi za nejmensi.
 * Projde pres vsechny polozky seznamu, a pokud najde polozku s nizsim ID, aktualizuje ukazatel na nejmensi polozku.
 * Po skonncei cyklu vrati ukazatel na nejmensi polozku.
 */
Item* list_find_minid(List* list)
{
    Item* active = list->first;
    Item* minid = list->first;
    while(active){

        if(active->data.id < minid->data.id){
            minid = active;
            }
        active = active->next;
    }
    return minid;
}

/**
 * V seznamu najde polozku odpovidajicim jmenem.
 * Pokud seznam hledanou polozku neobsahuje, vraci NULL.
 */
Item* list_find_name(List* list, char* name)
{
    Item *active = list->first;
    while(active){
        if(strcmp(active->data.name,name) == 0){
        return active;
        }
        active = active->next;

    }
    return NULL;
}

/**
 * Na konec seznamu vlozi novou polozku.
 */
void list_insert_last(List* list, Item* item)
{
    if(list->first == NULL){
        list->first = item;
        item->next = NULL;
    }else{
    Item *active = list->first;
    while(active->next != NULL){
        active = active->next;
    }
    active->next = item;
    item->next = NULL;
    }
}

/**
 * Za N-tou polozku seznamu vlozi novou polozku.
 * Pokud seznam obsahuje mene jak N polozek, polozku vlozi na konec seznamu.
 */
void list_insert_position(List* list, Item* item, unsigned pos)
{
    if(list->first == NULL || pos ==0){
        item->next = list->first;
        list->first = item;
        return;

    }
    Item *active = list->first;
    unsigned counting = 0;
    while (active->next != NULL) {
        if(counting == pos - 1){
            item->next = active->next;
            active->next = item;
            return;
        }
        counting++;
        active = active->next;
    }
    item->next = NULL;
    active->next = item;

}

/**
 * Ze seznamu odstrani vsechny polozky, a uvolni je z pameti (free).
 */
void list_dtor(List* list)
{
    Item *active = list->first;
    while(active){
        Item *temp = active->next;
        free(active);
        active = temp;
    }
    list->first = NULL;
}

