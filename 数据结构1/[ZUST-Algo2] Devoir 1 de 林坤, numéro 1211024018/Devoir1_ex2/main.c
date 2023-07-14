#include <stdio.h>
#include <stdlib.h>
#include "Listechainee_double.h"
int main(void) { 
  Listed *liste = initialisation(); 
  printf("Insertion au debut, a la fin et au ieme element\n"); 
  inserTete(liste, 3); 
  afficherApartirDebut(liste); 
  inserTete(liste, 2); 
  afficherApartirDebut(liste); 
  inserQueue(liste,5); 
  afficherApartirDebut(liste); 
  inserPos(liste, 7, 2); 
  afficherApartirDebut(liste); 
  printf("affichage de la fin\n");     
  afficherApartirFin(liste); 
  printf("Retrait au debut, a la fin et au ieme element\n"); 
  suppTete(liste); 
  afficherApartirDebut(liste); 
  suppQueue(liste); 
  afficherApartirDebut(liste); 
  suppElemPos(liste, 0); 
  afficherApartirDebut(liste); 
  afficherApartirFin(liste); 
  return 0;
}