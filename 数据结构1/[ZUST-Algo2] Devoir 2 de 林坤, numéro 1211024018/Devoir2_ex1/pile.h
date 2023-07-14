#ifndef PILES
#define PILES
#include <stdio.h>
#include <stdlib.h>

typedef float Element;
struct SCellule {
  Element info;
  struct SCellule *psuiv;
};

typedef struct SCellule *Cellule;

struct SPile{
  struct SCellule *sommet;
  int nbElements;
};

typedef struct SPile *Pile;

Pile pileVide(); 	// creer une pile vide (initialiser)
Pile pileAjouter(Pile p, Element e); //ajouter un élément au sommet de la pile
Pile pileSupprimer(Pile p);	//supprimer l’élément au sommet de la pile
Element pileSommet(Pile p);	//renvoyer l’élément au sommet de la pile
#endif
