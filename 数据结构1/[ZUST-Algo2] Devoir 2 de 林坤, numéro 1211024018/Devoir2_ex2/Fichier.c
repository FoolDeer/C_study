#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int est_correctement_parenthese(char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        exit(1);
    }

    char pile[100] = "";
    int sommet_pile = -1;
    char* correspondance = "([{)]}";

    char ligne[100];
    while (fgets(ligne, 100, fichier) != NULL) {
        for (int i = 0; i < strlen(ligne); i++) {
            char caractere = ligne[i];
            if (strchr("([{", caractere) != NULL) {
                sommet_pile++;
                pile[sommet_pile] = caractere;
            }
            else if (strchr(")]}", caractere) != NULL) {
                if (sommet_pile < 0 || correspondance[strchr("([{", pile[sommet_pile]) - correspondance] != caractere) {
                    fclose(fichier);
                    return 0;
                }
                sommet_pile--;
            }
        }
    }

    fclose(fichier);
    return sommet_pile == -1;
}

int main() {
    if (est_correctement_parenthese("fichier.txt")) {
        printf("Le fichier est correctement parenthésé.\n");
    } else {
        printf("Le fichier n'est pas correctement parenthésé.\n");
    }
    return 0;
}