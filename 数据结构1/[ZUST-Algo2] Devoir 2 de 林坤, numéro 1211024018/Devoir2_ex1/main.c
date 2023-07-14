#include <stdio.h>
#include "pile.h"

int main() {
  Pile p = pileVide();
  p = pileAjouter(p, 5.0);
  p = pileAjouter(p, 8.0);
  p = pileAjouter(p, 12.0);

  printf("Sommet de la pile: %f\n", pileSommet(p));

  p = pileSupprimer(p);
  printf("Sommet de la pile après suppression: %f\n", pileSommet(p));

  return 0;
}