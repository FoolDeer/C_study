#include "Listechainee_simple.h"
#include <stdio.h>
#include <stdlib.h>

// fonction d'initialisation
Liste *initialisation() {
  Liste *liste = malloc(sizeof(*liste));
  if (liste == NULL) {
    exit(EXIT_FAILURE);
  }
  liste->premier = NULL;
  liste->cnt = 0;
  return liste;
}

// insérer à la tête
void inserTete(Liste *liste, int nvNombre) {
  Element *nouveau = malloc(sizeof(*nouveau));
  if (liste == NULL || nouveau == NULL)
    exit(EXIT_FAILURE);
  nouveau->suivant = liste->premier;
  nouveau->nombre = nvNombre;
  liste->premier = nouveau;
  liste->cnt++;
}

// insérer à la queue
void inserQueue(Liste *liste, int nvNombre) {
  if (liste->premier == NULL) {
    printf("La liste est vide \n");
    inserTete(liste, nvNombre);
  }
  Element *nouveau = malloc(sizeof(*nouveau));
  if (nouveau == NULL) {
    printf("\nerreur d'allocation mémoire\n");
    exit(0);
  }
  nouveau->nombre = nvNombre;
  nouveau->suivant = NULL; // inserer a la fin

  Element *actuel = liste->premier;
  while (actuel->suivant != NULL) {
    actuel = actuel->suivant;
  }
  actuel->suivant = nouveau;
  liste->cnt++;
}

// insérer à la i-ème position
void insereIPosition(Liste *liste, int nvNombre, int i) {
  if (liste->premier == NULL || i == 0) {
    inserTete(liste, nvNombre);
  } else {
    if (i < liste->cnt) {
      Element *nouveau = malloc(sizeof(*nouveau));
      if (nouveau == NULL) {
        printf("\nerreur d'allocation mémoire\n");
        exit(0);
      }
      Element *actuel = liste->premier;
      for (int x = 1; x < i; x++) {
        actuel = actuel->suivant;
      }
      nouveau->nombre = nvNombre;
      nouveau->suivant = actuel->suivant;
      actuel->suivant = nouveau;
      liste->cnt++;
    } else {
      printf("la posisition est plus grand que le nombre des éléments --> "
             "inserQueue");
    }
  }
}

// supprimer à la tête
void suppTete(Liste *liste) {
  if (liste->premier == NULL) {
    printf("\nLa liste est vide \n");
    exit(0);
  }
  Element *suppE = liste->premier;
  liste->premier = suppE->suivant;
  free(suppE);
  liste->cnt--;
}

// supprimer à la queue
void suppQueue(Liste *liste) {
  if (liste->premier == NULL) {
    printf("\nLa liste est vide\n");
    exit(0);
  }
  if (liste->cnt == 1) {
    suppTete(liste);
  } else {
    Element *actuel = liste->premier;
    while (actuel->suivant->suivant != NULL) {
      actuel = actuel->suivant;
    }
    free(actuel->suivant);
    actuel->suivant = NULL;
    liste->cnt--;
  }
}

// supprimer à la i-ème position
void suppIPos(Liste *liste, int i) {
  if (liste->premier == NULL || i <= 0) {
    printf("\nLa liste est vide\n");
    exit(0);
  }
  if (liste->cnt == 1) {
    suppTete(liste);
  }
  Element *avant = liste->premier;
  for (int x = 1; x < i; x++) {
    avant = avant->suivant;
  }
  Element *suppE = avant->suivant;
  avant->suivant = suppE->suivant;
  free(suppE);
  liste->cnt--;
}

