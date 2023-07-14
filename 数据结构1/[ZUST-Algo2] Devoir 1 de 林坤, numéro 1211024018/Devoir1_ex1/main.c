#include <stdio.h>
#include <stdlib.h>
#include"devoir1.h"
int main() {
  int i;
  int *tab1 = AllouerTableau(5);
  for (int i = 0; i < 5; i++) {
    tab1[i] = i + 1;
  }
  Ensemble *ensemble1 = AllouerEnsemble(5);
  afficher(ensemble1);
  int m = rechercher(ensemble1, 4);
  if (m == 1) {
    printf("L'element 4 est present dans l'ensemble\n");
  } else {
    printf("L'element 4 n'est pas present dans l'ensemble\n");
  }
  int *tab2 = AllouerTableau(5);
  for (i = 0; i < 5; i++) {
    tab2[i] = i + 2;
  }
  Ensemble *ensemble2 = tabensemble(tab2, 5);
  printf("Ensemble1:");
  afficher(ensemble1);
  printf("Ensemble2:");
  afficher(ensemble2);
  Ensemble *intersection1 = intersection(ensemble1, ensemble2);
  printf("Intersection des ensembles:");
  afficher(intersection1);
  Ensemble *reunion1 = Reunion(ensemble1, ensemble2);
  printf("Union des ensembles:");
  afficher(reunion1);
  liberer(ensemble1);
  liberer(ensemble2);
  liberer(intersection1);
  liberer(reunion1);
  free(tab1);
  free(tab2);
  return 0;
}