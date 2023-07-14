#include <stdio.h>
#include <stdlib.h>
#include "Listechainee_double.h"

Listed *initialisation() {
  // Liste *liste =(liste *)malloc(sizeof(Liste));
  Listed *listed = malloc(sizeof(*listed));

  if (listed == NULL) {
    exit(EXIT_FAILURE);
  }

  listed->premier = NULL;
  listed->dernier = NULL;
  listed->cnt = 0;

  return listed;
}

void inserTete(Listed *listed, int nvNombre) {
  Element *s = malloc(sizeof(*s));
  s->nombre = nvNombre;
  if (listed->premier == NULL && listed->dernier == NULL) {
    s->suivant = NULL;
    s->precedent = NULL;
    listed->premier = s;
    listed->dernier = s;
  } else {
    s->suivant = listed->premier;
    s->precedent = NULL;
    listed->premier->precedent = s;
    listed->premier = s;
  }
  listed->cnt += 1;
}

void inserQueue(Listed *listed, int nvNombre) {
  Element *p = malloc(sizeof(*p));
  p->nombre = nvNombre;
  if (listed->premier == NULL && listed->dernier == NULL) {
    p->suivant = NULL;
    p->precedent = NULL;
    listed->premier = p;
    listed->dernier = p;
  } else {
    p->precedent = listed->dernier;
    p->suivant = NULL;
    listed->dernier->suivant = p;
    listed->dernier = p;
  }
  listed->cnt += 1;
}

void inserPos(Listed *listed, int nvNombre, int i) {
  Element *p = malloc(sizeof(*p));
  p->nombre = nvNombre;
  if (listed->premier == NULL && listed->dernier == NULL) {
    p->suivant = NULL;
    p->precedent = NULL;
    listed->premier = p;
    listed->dernier = p;
  } else if (i == 0)
    inserTete(listed, nvNombre);
  else if (i < listed->cnt) {
    Element *actuel = listed->premier;
    for (int x = 1; x < i; x++) {
      actuel = actuel->suivant;
    }
    p->suivant = actuel->suivant;
    p->precedent = actuel;
    actuel->suivant->precedent = p;
    actuel->suivant = p;
  } else {
    inserQueue(listed, nvNombre);
    return;
  }
  listed->cnt += 1;
}

void suppTete(Listed *listed) {
  if (listed) {
    Element *suppElem = listed->premier;
    if (listed->cnt == 1) {
      listed->premier = NULL;
      listed->dernier = NULL;
      free(suppElem);
    } else {
      listed->premier = listed->premier->suivant;
      listed->premier->precedent = NULL;
      free(suppElem);
    }
    listed->cnt--;
  }
}

void suppQueue(Listed *listed) {
  if (listed) {
    Element *suppElem = listed->dernier;
    if (listed->cnt == 1) {
      listed->premier = NULL;
      listed->dernier = NULL;
      free(suppElem);
    } else {
      listed->dernier = listed->dernier->precedent;
      listed->dernier->suivant = NULL;
      free(suppElem);
    }
    listed->cnt--;
  }
}

void suppElemPos(Listed *listed, int i) {
  if (listed || i >= 0) {
    if (listed->cnt == 1) {
      free(listed->premier);
      listed->premier = NULL;
      listed->dernier = NULL;
    } else if (i > 0 && i < listed->cnt - 1) {
      Element *avant = listed->premier;
      for (int x = 1; x < i; x++)
        avant = avant->suivant;
      Element *suppElem = avant->suivant;
      suppElem->suivant->precedent = suppElem->precedent;
      avant->suivant = suppElem->suivant;
      free(suppElem);
    } else if (i == 0) {
      suppTete(listed);
      return;
    } else {
      suppQueue(listed);
      return;
    }
    listed->cnt--;
  }
}

void afficherApartirDebut(Listed *listed) {
  Element *p;
  p = listed->premier;
  while (p) {
    printf("%d ->", p->nombre);
    p = p->suivant;
  }
  printf("NULL\n");
}

void afficherApartirFin(Listed *listed) {
  Element *p;
  p = listed->dernier;
  while (p) {
    printf("%d ->", p->nombre);
    p = p->precedent;
  }
  printf("NULL\n");
}