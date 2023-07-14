// #include <stdio.h>
// #include <stdlib.h>

// typedef float TypeDonnee;
// typedef struct Cell {
//   TypeDonnee donnee;
//   struct Cell *suivant; /* pointeur sur la cellule suivante */
// } TypeCellule;
// typedef TypeCellule *Pile; /* la pile est un pointeur */
// /* sur la tête de liste */

// Pile Initialiser() { return NULL; /* on retourne une liste vide */ }

// int EstVide(Pile P) {
//   /* renvoie 1 si la liste est vide */
//   return (P == NULL) ? 1 : 0;
// }

// int EstPleine(Pile P) { return 0; }

// int AccederSommet(Pile P, TypeDonnee *pelem) {
//   if (EstVide(P))
//     return 1;         /* on retourne un code d’erreur */
//   *pelem = P->donnee; /* on renvoie l’élément */
//   return 0;
// }

// void Empiler(Pile *pP, TypeDonnee elem) {
//   Pile q;                                         // TypeCellule*
//   q = (TypeCellule *)malloc(sizeof(TypeCellule)); /* allocation */
//   q->donnee = elem; /* ajout de l’élément à empiler */
//   q->suivant = *pP; /* insertion en tête de liste */
//   *pP = q;          /* mise à jour de la tête de liste */
// }

// int Depiler(Pile *pP, TypeDonnee *pelem) {
//   Pile q;
//   if (EstVide(*pP))
//     return 1;             /* on ne peut pas supprimer d’élément */
//   *pelem = (*pP)->donnee; /* on renvoie l’élément de tête */
//   q = *pP;              /* mémorisation d’adresse de la première cellule */
//   *pP = (*pP)->suivant; /* passage au suivant */
//   free(q);              /* destruction de la cellule mémorisée */
//   return 0;
// }

// void Detruire(Pile *pP) {
//   Pile q;
//   while (*pP != NULL) /* parcours de la liste */
//   {
//     q = *pP; /* mémorisation de l’adresse */
//     /* passage au suivant avant destruction : */
//     *pP = (*pP)->suivant;
//     free(q); /* destruction de la cellule mémorisée */
//   }
//   *pP = NULL; /* liste vide */
// }

// void Vider(Pile *pP) {
//   Detruire(pP); /* destruction de la liste */
//   *pP = NULL;   /* liste vide */
// }