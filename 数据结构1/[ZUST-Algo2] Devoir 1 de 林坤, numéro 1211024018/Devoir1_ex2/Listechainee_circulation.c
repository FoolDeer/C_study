#include "Listechainee_circulation.h"
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
void inserTete(Liste *liste, int nombre) {
  /*Creation du nouvel element*/
  Element *nouv = malloc(sizeof(*nouv));
  if (nouv == NULL) {
    exit(EXIT_FAILURE);
  }

  if (liste->premier == NULL) {
    nouv->suivant = nouv;
    nouv->nombre = nombre;
    liste->premier = nouv;
    liste->cnt += 1;
  } else {
    nouv->suivant = liste->premier;
    nouv->nombre = nombre;
    Element *actuel = liste->premier;
    while (actuel->suivant != liste->premier) {
      actuel = actuel->suivant;
    }
    liste->premier = nouv;
    actuel->suivant = liste->premier;
    liste->cnt += 1;
  }
}
// insérer à la queue
void inserQueue(Liste*liste, int nombre) {
  /*verification que la liste n'est pas vide*/
  if (liste->premier == NULL) {
    printf("\nLa liste est vide\n");
    inserTete(liste, nombre);
  }
  /*creation du nouvel element*/
  Element *nouv = (Element *)malloc(sizeof(Element));
  if (nouv == NULL) {
    printf("\n erreur d'allocation memoire\n");
    exit(0);
  }
  nouv->nombre = nombre;
  nouv->suivant = liste->premier;

  /*rattachement de le nouveau element a la fin de queue de la liste*/
  Element *actuel = liste->premier;
  while (actuel->suivant != liste->premier) {
    actuel = actuel->suivant;
  }
  actuel->suivant = nouv;
  liste -> cnt ++;
}
// insérer à la i-ème position
void inserIPos(Liste *liste, int nombre, int i) {
  if (liste->premier == NULL || i == 0) {
    inserTete(liste, nombre);
  } else {
    if (i < liste->cnt) {
      Element *nouv = (Element *)malloc(sizeof(Element));
      if (nouv == NULL) {
        printf("\nerreur d'allocation memoire\n");
        exit(0);
      }
      Element *actuel = liste->premier;
      for (int j = 1; j < i; j++) {
        actuel = actuel->suivant;
      }
      nouv->nombre = nombre;
      nouv->suivant = actuel->suivant;
      actuel->suivant = nouv;
      liste->cnt += 1;
    } else {
      inserQueue(liste, nombre);
    }
  }
}
// supprimer à la tête
void suppTete(Liste *liste) {
  if (liste->premier == NULL) {
    printf("\nLa liste est vide \n");
    exit(0);
  }

  Element *supp = liste->premier;
  Element *actuel = liste->premier;
  while (actuel->suivant != liste->premier) {
    actuel = actuel->suivant;
  }
  liste->premier = liste->premier->suivant;
  actuel->suivant = liste->premier;
  liste->cnt--;
  free(supp);
}
// supprimer à la queue
void suppQueue(Liste *liste) {
  /* verification que la liste n'est pas vide*/
  if (liste->premier == NULL) {
    printf("\nLa liste est vide\n");
    exit(0);
  }
  /* suppression de le dernier élément de la liste */
  if (liste->cnt == 1)
    suppTete(liste);
  else {

    Element *actuel = liste->premier;
    while (actuel->suivant->suivant != liste->premier) {
      actuel = actuel->suivant;
    }
    free(actuel->suivant);
    actuel->suivant = liste->premier;
    liste->cnt--;
  }
}

// supprimer à la i-ème position
void suppElemPos(ListeC *listec, int i) {
  if (listec->premier == NULL && i < 1) {
    printf("\n La liste est vide\n");
    exit(0);
  }
  if (listec->cnt == 1)
    suppTete(liste);
  ElementC *avant = liste->premier;
  for (int x = 1; x < i; x++)
    avant = avant->suivant;
  Element *suppElem = avant->suivant;
  avant->suivant = suppElem->suivant;
  free(suppElem);
  liste->cnt--;
}

// fonction d’affichage
void afficherListe(Liste *liste) {
  Element *actuel = liste->premier;
  while (actuel->suivant != liste->premier) {
    printf("%d -> ", actuel->nombre);
    actuel = actuel->suivant;
  }
  printf("%d ->>>> %d\n", actuel->nombre, actuel->suivant->nombre);
}