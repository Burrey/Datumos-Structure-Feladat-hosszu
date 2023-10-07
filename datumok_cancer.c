#include <stdio.h>
#include <stdbool.h>
#include <math.h>
typedef struct Datum {
  int ev, honap, nap;
} Datum;

void datum_kiir(Datum d) {
  printf("%d %d %d", d.ev, d.honap, d.nap);
}

int datum_ev_napja(Datum d) {
  int szamlalo = 0;
  int honapok[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for(int i = 0; i < d.honap; i++) {
    szamlalo += honapok[i];
  }
  szamlalo += d.nap;
  if(d.ev % 4 == 0 && d.ev % 100 != 0 || d.ev % 400 == 0) {
    szamlalo++;
  }
  return szamlalo;
}

int datum_kivon(Datum kisebb, Datum nagyobb) {
  int datum_szamlalo = 0;
  int honapok[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int szokoev = 0;
  for(int i = kisebb.ev; i <= nagyobb.ev; i++) {
    if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
      szokoev++;
    }
  }
  /*IF NAGYOBBIK MONTH > 2, ONLY THEN ADD*/
  datum_szamlalo += szokoev; /* ???? */
  int nagyobbik = nagyobb.ev * 365;
  int kisebbik = kisebb.ev * 365;
  datum_szamlalo += nagyobbik - kisebbik;
  if (datum_ev_napja(kisebb) > datum_ev_napja(nagyobb)) {
    datum_szamlalo -= datum_ev_napja(kisebb) - datum_ev_napja(nagyobb);
  }
  if (datum_ev_napja(nagyobb) > datum_ev_napja(kisebb)) {
    datum_szamlalo += datum_ev_napja(nagyobb) - datum_ev_napja(kisebb);
  }
  return datum_szamlalo;
}

int milyen_nap(Datum d) {
  Datum alap;
  alap.ev = 1900;
  alap.honap = 1;
  alap.nap = 1;
  int kulonbseg = datum_kivon(alap, d);
  int moddolt = kulonbseg % 7;
  return moddolt;
}

int main(void) {
  Datum proba_datum;
  /*Datum proba_datum2;
  scanf("%d %d %d %d %d %d",
    &proba_datum.ev, &proba_datum.honap, 
    &proba_datum.nap, &proba_datum2.ev, 
    &proba_datum2.honap, &proba_datum2.nap);
  printf("%d", abs(datum_kivon(proba_datum, proba_datum2))); */
  scanf("%d %d %d", &proba_datum.ev, &proba_datum.honap, &proba_datum.nap);
  switch(milyen_nap(proba_datum)) {
    case 0:
      printf("Hétfő");
      break;
    case 1:
      printf("Kedd");
      break; 
    case 2:
      printf("Szerda");
      break;
    case 3:
      printf("Csütörtök");
      break;
    case 4:
      printf("Péntek");
      break;
    case 5:
      printf("Szombat");
      break;
    case 6:
      printf("Vasárnap");
      break;
  }
  return 0;
}