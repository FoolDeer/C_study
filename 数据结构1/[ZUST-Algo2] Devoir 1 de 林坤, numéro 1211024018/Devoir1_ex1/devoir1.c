#include <stdio.h>
#include <stdlib.h>
#include"devoir1.h"
//1
int* allouerTableau(int n) {
    int* tab = (int*)malloc(n * sizeof(int));
    return tab;
}

 //2
Ensemble* allouerEnsemble(int n) {
    Ensemble* ensemble = (Ensemble*)malloc(sizeof(Ensemble));
    if (ensemble == NULL) {
        printf("Erreur : allocation dynamique de m茅moire 茅chou茅e.\n");
        exit(EXIT_FAILURE);
    }
    ensemble->NbEMax = n;
    ensemble->NbE = 0;
    ensemble->tab = allouerTableau(n);
    return ensemble;
}
//3
void liberer(Ensemble* ensemble) {
    free(ensemble->tab);
    free(ensemble);
}
//4
void afficher(Ensemble* ensemble) {
    printf("{");
    for (int i = 0; i < ensemble->NbE; i++) {
        printf(" %d", ensemble->tab[i]);
    }
    printf(" }\n");
}

//5
Ensemble *tabensemble(int* tab, int n) {
    Ensemble* ensemble = allouerEnsemble(n);
    for(int i=0;i<ensemble->NbE-1;i++){
      for(int j=i+1;j<ensemble->NbE;j++){
        if(ensemble->tab[i]==ensemble->tab[j]){
          ensemble->tab[j]=ensemble->tab[j+1];
        }
      }
    }
  return ensemble;
}

//6
void *insert(Ensemble *ensemble, int element){
  if (ensemble->NbE == ensemble->NbEMax) {
        printf("L'ensemble est plein, impossible d'inserer un nouvel element.\n");
    return ensemble;
    } 
    int i = ensemble->NbE - 1;
    while (i >= 0 && ensemble->tab[i] > element) {
        ensemble->tab[i+1] = ensemble->tab[i];
        i--;
    }
    ensemble->tab[i+1] = element;
    ensemble->NbE++;
  return ensemble;
}

//7
int rechercher(Ensemble *ensemble,int element){
    int tete = 0;
    int queue = ensemble->NbE - 1;
    
    while (tete <= queue) {
        int milieu = (tete + queue) / 2;
        if (ensemble->tab[milieu] == element) {
            return 1;
        } else if (ensemble->tab[milieu] < element) {
            queue = milieu + 1;
        } else {
            tete = milieu - 1;
        }
    }
  return 0;
}

//8
void *intersection(Ensemble *n1, Ensemble *n2) {
    Ensemble *intersection1;
    intersection1->NbEMax = n1->NbEMax;
    intersection1->tab = (int*) malloc(intersection1->NbEMax * sizeof(int));
    intersection1->NbE = 0;
  int i=0,j=0,x=0;
    while (i < n1->NbE && j < n2->NbE) {
      if (n1->tab[i] == n2->tab[j]) {
        intersection1->tab[x] = n1->tab[i];
        i++;
        j++;
        x++;
    }
    }
  return intersection1;
}

//9
void *Reunion(Ensemble *n1, Ensemble *n2) {
  Ensemble *intersection2;
  intersection2->NbEMax = n1->NbEMax + n2->NbEMax;
  intersection2->NbE = 0;
  intersection2->tab = (int *)malloc(intersection2->NbEMax * sizeof(int));

  int i = 0,j=0,x=0;
  while (i < n1->NbE && j < n2->NbE) {
    if (n1->tab[i] == n2->tab[j]) {
      intersection2->tab[x] = n1->tab[i];
      x++;
      intersection2->NbE++;
      i++;
      j++;
    } else if (n1->tab[i] < n2->tab[j]) {
      intersection2->tab[x] =n1->tab[i];
      x++;
      intersection2->NbE++;
      i++;
      intersection2->tab[x] =n2->tab[j];
      x++;
      intersection2->NbE++;
      j++;
    } else if(n1->tab[i] > n2->tab[j]) {
      intersection2->tab[x] = n2->tab[j];
      x++;
      intersection2->NbE++;
      j++;
      intersection2->tab[x] = n1->tab[i];
      x++;
      intersection2->NbE++;
      i++;
    }
  }
  return intersection2;
}
