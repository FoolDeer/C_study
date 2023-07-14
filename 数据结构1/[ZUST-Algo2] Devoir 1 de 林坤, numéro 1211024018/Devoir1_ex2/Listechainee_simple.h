#ifndef LISTECHAINEESIMPLE_H
#define LISTECHAINEESIMPLE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element {
  int nombre;       // donnee
  Element *suivant; // pointeur vers l'element suivant de la liste
};

typedef struct Liste Liste;
struct Liste {
  Element *premier; // pointeur vers le premier element de la liste
  int cnt;          // compteur des element de la liste
};

// fonction d'initialisation
Liste *initialisation();
// insérer à la tête
void inserTete(Liste *liste, int nvNombre);
// insérer à la queue
void inserQueue(Liste *liste, int nvNombre);
// insérer à la i-ème position
void inserIPos(Liste *liste, int nvNombre, int i);
// supprimer à la tête
void suppTete(Liste *liste);
// supprimer à la queue
void suppQueue(Liste *liste);
// supprimer à la i-ème position
void suppIPos(Liste *liste, int i);


#endif