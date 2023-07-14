// #include <stdio.h>
// #include <stdlib.h>
// // en utilisant l’allocation Statistique
// // etudiant est un alias de struct étudiant
//   typedef struct etudiant etudiant;
//   struct etudiant {
//     char nom[128];
//     char prenom[128];
//     int promo;
//   };
//   void changePromo(etudiant *e, int promo) {
//   (*e).promo = promo; // ou e->promo=promo
//   }
//   void printEtudiant(etudiant e){
//   printf("nom: %s prénom: %s promo: %d", e.nom, e.prenom,  e.promo);
//   }
// int main (void)
//   {
//   etudiant lea = { "Durand", "Léa", 2016 };
//   changePromo(&lea, 2017);
//   printEtudiant(lea);
//   return 0;
// }

// // en utilisant l’allocation dynamique
// #include <stdio.h>
// #include <stdlib.h>
//   typedef struct {
//     char nom[128];
//     char prenom[128];
//     int promo;
//   } etudiant;
//   void affEtudiant(etudiant e) {
//     printf("nom: %s prénom: %s promo: %d\n", e.nom, e.prenom, e.promo);
//   }
//   void lireEtudiant(etudiant *e) {
//     printf("nom: ");
//     scanf("%s", e->nom);
//     printf("prénom: ");
//     scanf("%s", e->prenom);
//     printf("promo: ");
//     scanf("%d", &e->promo);
//   }
// int main(void) {
//   int n, i;
//   printf("quel est le nombre d'étudiants à saisir : ");
//   scanf("%d", &n);
//   etudiant *listeEtudiants = (etudiant *) malloc (n *sizeof(etudiant));
//   if (!listeEtudiants) {
//     printf("Impossible d'allouer la mémoire:\n");
//     return 1;
//   }
//   for (i=0; i<n; i++)
//     lireEtudiant(listeEtudiants+i);
//   if (n>0)
//     printf("Vous avez saisi les étudiants suivants\n");
//   else
//     printf("Liste vide\n");
//   for (i=0; i<n; i++)
//     affEtudiant(listeEtudiants[i]);
//   free(listeEtudiants);
//   return 0;
// }
