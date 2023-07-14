// #include <stdio.h>
// #include <stdlib.h>

// // 1) structure Element pour représenter un élément de la liste chaînée
// typedef struct Element Element;
// struct Element {
//   int nombre;       // donnée
//   Element *suivant; // pointeur vers l’élément suivant de la liste
// };

// // 2) La structure de contrôle
// typedef struct Liste Liste;
// struct Liste {
//   Element *premier; // pointeur vers le premier élément de la liste
//   int cnt;          // compteur des éléments de la liste
// };

// Liste *initialisation() {
//   Liste *liste = malloc(sizeof(Liste));
//   if (liste == NULL) {
//     exit(EXIT_FAILURE);
//   }
//   liste->premier = NULL;
//   liste->cnt = 0;
//   return liste;
// }

// void inserTete(Liste *liste, int nvNombre) {
//   /* Création du nouvel élément */
//   Element *nouveau = malloc(sizeof(*nouveau));
//   if (nouveau == NULL) {
//     exit(EXIT_FAILURE);
//   }
//   if (liste->premier == NULL) {
//     /* Insertion de l'élément au début de la liste si la liste est vide*/
//     nouveau->suivant = nouveau;
//     nouveau->nombre = nvNombre;
//     liste->premier = nouveau;
//     liste->cnt += 1;
//   } else {
//     /* Insertion de l'élément au début de la liste si la liste n'est pas vide*/
//     nouveau->suivant = liste->premier;
//     nouveau->nombre = nvNombre;
//     Element *actuel = liste->premier;
//     while (actuel->suivant != liste->premier) {
//       actuel = actuel->suivant;
//     }
//     liste->premier = nouveau;
//     actuel->suivant = liste->premier;
//     liste->cnt += 1;
//   }
// }

// void inserQueue(Liste *liste, int nvNombre) {
//   /* verification que la liste n'est pas vide*/
//   if (liste->premier == NULL) {
//     printf("\nLa liste est vide\n");
//     inserTete(liste, nvNombre);
//   }
//   /* création du nouvel élément*/
//   Element *nouveau = malloc(sizeof(Element));
//   if (nouveau == NULL) {
//     printf("\nerreur d'allocation mémoire\n");
//     exit(0);
//   }
//   nouveau->nombre = nvNombre;
//   nouveau->suivant = liste->premier;
//   /* rattachement de le nouveau élément à la fin de queue de la liste */
//   Element *actuel = liste->premier;
//   while (actuel->suivant != liste->premier) {
//     actuel = actuel->suivant;
//   }
//   actuel->suivant = nouveau;
//   liste->cnt++;
// }

// void inserPos(Liste *liste, int v, int i) {
//   if (liste->premier == NULL || i == 0) {
//     inserTete(liste, v);
//   } else {
//     if (i < liste->cnt) {
//       Element *nouveau = malloc(sizeof(Element));
//       if (nouveau == NULL) {
//         printf("\nerreur d'allocation mémoire\n");
//         exit(0);
//       }
//       Element *actuel = liste->premier;
//       for (int x = 1; x < i; x++) {
//         actuel = actuel->suivant;
//       }
//       nouveau->nombre = v;
//       nouveau->suivant = actuel->suivant;
//       actuel->suivant = nouveau;
//       liste->cnt += 1;
//     } else {
//       printf("la posisition est plus grand que le nombre des éléments --> "
//              "inserQueue");
//       inserQueue(liste, v);
//     }
//   }
// }

// void suppTete(Liste *liste) {
//   if (liste->premier == NULL) {
//     printf("\nLa liste est vide \n");
//     exit(0);
//   }
//   Element *suppE = liste->premier;
//   Element *actuel = liste->premier;
//   while (actuel->suivant != liste->premier) {
//     actuel = actuel->suivant;
//   }
//   liste->premier = suppE->suivant;
//   actuel->suivant = liste->premier;
//   free(suppE);
//   liste->cnt--;
// }

// void suppQueue(Liste *liste) {
//   /* verification que la liste n'est pas vide*/
//   if (liste->premier == NULL) {
//     printf("\nLa liste est vide\n");
//     exit(0);
//   }
//   /* suppression de le dernier élément de la liste */
//   if (liste->cnt == 1)
//     suppTete(liste);
//   else {
//     Element *actuel = liste->premier;
//     while (actuel->suivant->suivant != liste->premier) {
//       actuel = actuel->suivant;
//     }
//     free(actuel->suivant);
//     actuel->suivant = liste->premier;
//     liste->cnt--;
//   }
// }

// void suppElemPos(Liste *liste, int i) {
//   if (liste->premier == NULL && i < 1) {
//     printf("\n La liste est vide\n");
//     exit(0);
//   }
//   if (liste->cnt == 1)
//     suppTete(liste);
//   Element *avant = liste->premier;
//   for (int x = 1; x < i; x++)
//     avant = avant->suivant;
//   Element *suppElem = avant->suivant;
//   avant->suivant = suppElem->suivant;
//   free(suppElem);
//   liste->cnt--;
// }

// int consultElem(Liste *liste, int i){
//   if (i >= 0 && i < liste->cnt)
//   {
//     Element *actuel = liste->premier;
//     while(i>0)
//     {
//       actuel = actuel->suivant;
//       i--;
//     }
//     return actuel->nombre;
//   }
//   else exit(0);
// }