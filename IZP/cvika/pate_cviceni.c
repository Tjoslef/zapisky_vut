#include <stdio.h>
#include <math.h>
typedef struct {
 float x;
 float y;


}bod ;


typedef struct Strojuhelnik
 {
bod A;
bod B;
bod C;
} trojuhelnik ;

float obvod(trojuhelnik T){
   float obvod = sqrt((T.A.x - T.B.x) * (T.A.x - T.B.x) + (T.A.y - T.B.y) * (T.A.y - T.B.y))  // AB
                + sqrt((T.B.x - T.C.x) * (T.B.x - T.C.x) + (T.B.y - T.C.y) * (T.B.y - T.C.y))  // BC
                + sqrt((T.A.x - T.C.x) * (T.A.x - T.C.x) + (T.A.y - T.C.y) * (T.A.y - T.C.y)); // CA
    return obvod;
}
float obsah(trojuhelnik T){
    float obsah = 0.5 * fabs(T.A.x *(T.B.y - T.C.y) + T.B.x * (T.C.y - T.A.y) + T.C.x * (T.A.y - T.B.y));
    if (obsah == 0){
        printf("nejde vypocitat obsah body jsou koliearni");

    }
    return obsah;

}
bod teziste(trojuhelnik T){
    bod tez;
    tez.x = (T.A.x + T.B.x + T.C.x) / 3.0;
    tez.y = (T.A.y + T.B.y + T.C.y) / 3.0;
    return tez;

}
int main() {
 trojuhelnik T;
 scanf("%f %f", &T.A.x, &T.A.y);
 scanf("%f %f", &T.B.x, &T.B.y);
 scanf("%f %f", &T.C.x, &T.C.y);

 printf ("Obvod = %.3f\n", obvod(T));
 printf ("Obsah = %.3f\n", obsah(T));
 bod S = teziste (T); // pocitame teziste
 printf (" Teziste = (%.3f, %.3f)\n", S.x, S.y);
 return 0;
 }
