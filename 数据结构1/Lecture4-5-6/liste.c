// #include <stdio.h>
// #include <stdlib.h>

// //1) structure Element pour représenter un élément de la liste chaînée
// typedef struct Element Element;
// struct Element
// {
//   int nombre; // donnée
//   Element *suivant; // pointeur vers l’élément suivant de la liste
//   Element *precedent; // pointeur vers l'élément précédent de la liste
// };
// //2) La structure de contrôle
// typedef struct Liste Liste;
// struct Liste
// {
//   Element *premier; // pointeur vers le premier élément de la liste
//   Element *dernier; // pointeur vers le dernier élément de la liste
//   int cnt ; // compteur des éléments de la liste
// };

// Liste *initialisation()
// {
//   // Liste *liste = (Liste *)malloc(sizeof(Liste));
//   Liste *liste = malloc(sizeof(*liste));
//   if (liste == NULL)
//   {
//     exit(EXIT_FAILURE);
//   }
//   liste->premier = NULL;
//   liste->dernier = NULL;
//   liste->cnt = 0;
//   return liste;
// }
// void inserTete(Liste *liste, int nvNombre)
// {
//   Element *p = malloc(sizeof(*p));
//   p->nombre = nvNombre;
//   if(liste->premier==NULL && liste->dernier == NULL)
//   {
//     p->suivant = NULL;
//     p->precedent = NULL;
//     liste->premier = p;
//     liste->dernier = p;
//   }
//   else
//   {
//     p->suivant = liste->premier;
//     p->precedent = NULL;
//     liste->premier->precedent = p;
//     liste->premier=p;
//   }
//   liste->cnt += 1;
// }

// void inserQueue(Liste *liste, int nvNombre)
// {
//   Element *p = malloc(sizeof(*p));
//   p->nombre = nvNombre;
//   if(liste->premier==NULL && liste->dernier == NULL)
//   {
//     p->suivant = NULL;
//     p->precedent = NULL;
//     liste->premier = p;
//     liste->dernier = p;
//   }
//   else
//   {
//     p->precedent = liste->dernier;
//     p->suivant = NULL;
//     liste->dernier->suivant = p;
//     liste->dernier=p;
//   }
//   liste->cnt += 1;
// }

// void inserPos(Liste *liste, int nvNombre, int i)
// {
//   Element *p = malloc(sizeof(*p));
//   p->nombre = nvNombre;
//   if(liste->premier==NULL && liste->dernier == NULL)
//   {
//     p->suivant = NULL;
//     p->precedent = NULL;
//     liste->premier = p;
//     liste->dernier = p;
//   }
//   else if(i == 0)
//     inserTete(liste, nvNombre);
//   else if(i < liste->cnt)
//   {
//     Element *actuel = liste->premier;
//     for (int x = 1; x<i; x++ ){
//       actuel = actuel->suivant;
//     }
//     p->suivant = actuel->suivant;
//     p->precedent = actuel;
//     actuel->suivant->precedent = p;
//     actuel->suivant = p;
//   }
//   else
//   {
//     inserQueue(liste, nvNombre);
//     return;
//   }
//   liste->cnt += 1;
// }

// void suppTete(Liste *liste)
// {
//   if(liste)
//   {
//     Element *suppElem = liste->premier;
//     if(liste->cnt == 1)
//     {
//       liste->premier = NULL;
//       liste->dernier = NULL;
//       free(suppElem);
//     }
//     else
//     {
//       liste->premier = liste->premier->suivant;
//       liste->premier->precedent = NULL;
//       free(suppElem);
//     }
//     liste->cnt--;
//   }
// }

// void suppQueue(Liste *liste)
// {
//   if(liste)
//   {
//     Element *suppElem = liste->dernier;
//     if(liste->cnt == 1)
//     {
//       liste->premier = NULL;
//       liste->dernier = NULL;
//       free(suppElem);
//     }
//     else
//     {
//       liste->dernier = liste->dernier->precedent;
//       liste->dernier->suivant = NULL;
//       free(suppElem);
//     }
//     liste->cnt--;
//   }
// }

// void suppElemPos(Liste *liste, int i)
// {
//   if(liste || i>=0)
//   {
//     if(liste->cnt == 1)
//     {
//       free(liste->premier);
//       liste->premier = NULL;
//       liste->dernier = NULL;
//     }
//     else if(i > 0 && i < liste->cnt-1)
//     {
//       Element *avant = liste->premier;
//       for(int x = 1; x < i; x++)
//         avant = avant->suivant;
//       Element *suppElem = avant->suivant;
//       suppElem->suivant->precedent = suppElem->precedent;
//       avant->suivant = suppElem->suivant;
//       free(suppElem);
//     }
//     else if(i==0)
//     {
//       suppTete(liste);
//       return;
//     }
//     else
//     {
//       suppQueue(liste);
//       return;
//     }
//     liste->cnt--;
//   }
// }