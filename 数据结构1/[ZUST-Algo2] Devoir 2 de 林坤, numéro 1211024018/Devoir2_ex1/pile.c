#include "pile.h"

Pile pileVide() {
  Pile p = (Pile)malloc(sizeof(struct SPile));
  p->sommet = NULL;
  p->nbElements = 0;
  return p;
}

Pile pileAjouter(Pile p, Element e) {
  Cellule newCell = (Cellule)malloc(sizeof(struct SCellule));
  newCell->info = e;
  newCell->psuiv = p->sommet;
  p->sommet = newCell;
  p->nbElements++;
  return p;
}

Pile pileSupprimer(Pile p) {
  if (p->nbElements > 0) {
    Cellule oldCell = p->sommet;
    p->sommet = p->sommet->psuiv;
    free(oldCell);
    p->nbElements--;
  }
  return p;
}

Element pileSommet(Pile p) {
  if (p->nbElements > 0) {
    return p->sommet->info;
  } else {
    printf("Erreur: La pile est vide.\n");
    return -1;
  }
}