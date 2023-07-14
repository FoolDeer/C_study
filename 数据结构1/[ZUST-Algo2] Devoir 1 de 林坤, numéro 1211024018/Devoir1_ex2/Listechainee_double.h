#ifndef LISTECHAINEESIMPLE_H
#define LISTECHAINEESIMPLE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element {
  int nombre;          // donnee
  Element *suivant;   // pointeur vers l'element suivant de la liste
  Element *precedent; // pointeur vers l'element precedent de la liste
};
typedef struct Listed Listed;
struct Listed {
  Element *premier; // pointeur vers le premier element de la liste
  Element *dernier; // pointeur vers le dernier element de la liste
  int cnt;           // compteur des element de la liste
};

Listed *initialisation();
void inserTete(Listed *listed, int nvNombre);
void inserQueue(Listed *listed, int nvNombre);
void inserPos(Listed *listed, int nvNombre, int i);
void suppTete(Listed *listed);
void suppQueue(Listed *listed);
void suppElemPos(Listed *listed, int i);
void afficherApartirDebut(Listed *listed);
void afficherApartirFin(Listed *listed);
#endif