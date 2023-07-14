#include <stdio.h>
#include <stdlib.h>
#ifndef ENSEMBLE_H
#define ENSEMBLE_H

typedef struct {
  int NbEMax; // nombre d'élément maximum de l'ensemble
  int NbE;    // nombre d'élément présents dans l'ensemble
  int *tab;   // conteneur des éléments de l'ensemble
} Ensemble;

// 1)
int *AllouerTableau(int n);
// 2)
Ensemble *AllouerEnsemble(int n);
// 3)
void liberer(Ensemble *ensemble);
// 4)
void afficher(Ensemble *ensemble);
// 5)
void *insert(Ensemble *ensemble, int element);
// 6)
int rechercher(Ensemble *ensemble, int element);
// 7)
void *intersection(Ensemble *ensemble1, Ensemble *ensemble2);
// 8)
void *Reunion(Ensemble *ensemble1, Ensemble *ensemble2);
// 9)
Ensemble *tabensemble(int* tab, int n);

#endif