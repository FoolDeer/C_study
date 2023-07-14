#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    unsigned int key;
    struct node *left;
    struct node *right;
} node ;

void AddNode(node **root, unsigned int key) {
    if (*root == NULL) {
        // si l'arbre est vide, on crée un nouveau nœud
        *root = (node*)malloc(sizeof(node));
        (*root)->key = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (key < (*root)->key) {
        // si la clé est inférieure à la clé du nœud courant, on insère dans le sous-arbre gauche
        AddNode(&((*root)->left), key);
    } else if (key > (*root)->key) {
        // si la clé est supérieure à la clé du nœud courant, on insère dans le sous-arbre droit
        AddNode(&((*root)->right), key);
    }
}

void DeleteNode(node **root, unsigned int key) {
    if (*root == NULL) {
        // si l'arbre est vide, on ne peut rien supprimer
        return;
    } else if (key < (*root)->key) {
        // si la clé est inférieure à la clé du nœud courant, on cherche dans le sous-arbre gauche
        DeleteNode(&((*root)->left), key);
    } else if (key > (*root)->key) {
        // si la clé est supérieure à la clé du nœud courant, on cherche dans le sous-arbre droit
        DeleteNode(&((*root)->right), key);
    } else {
        // si on a trouvé le nœud à supprimer
        if ((*root)->left == NULL && (*root)->right == NULL) {
            // cas 1 : le nœud est une feuille, on le supprime simplement
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            // cas 2 : le nœud a un seul fils à droite, on remplace le nœud par son fils
            node *tmp = *root;
            *root = (*root)->right;
            free(tmp);
        } else if ((*root)->right == NULL) {
            // cas 2 : le nœud a un seul fils à gauche, on remplace le nœud par son fils
            node *tmp = *root;
            *root = (*root)->left;
            free(tmp);
        } else {
            // cas 3 : le nœud a deux fils, on trouve le successeur (nœud le plus à gauche du sous-arbre droit)
            // on copie la clé du successeur dans le nœud à supprimer, puis on supprime le successeur
            node *succ = (*root)->right;
            while (succ->left != NULL) {
                succ = succ->left;
            }
            (*root)->key = succ->key;
            DeleteNode(&((*root)->right), succ->key);
        }
    }
}

void PrintTree(node *root, int level) {
    if (root == NULL) {
        return;
    }

    level += 5;
    PrintTree(root->right, level);
    printf("\n");

    for (int i = 5; i < level; i++) {
        printf(" ");
    }
    printf("| ->%u\n", root->key);

    PrintTree(root->left, level);
}

void AB2ABR(node **root, node *ab) {
    if (ab == NULL) {
        return;
    }
    AB2ABR(root, ab->left);
    AddNode(root, ab->key);
    AB2ABR(root, ab->right);
}

int main() {
    node *root = NULL;
    AddNode(&root, 10);
    AddNode(&root, 5);
    AddNode(&root, 15);
    AddNode(&root, 3);
    AddNode(&root, 8);
    AddNode(&root, 13);
    AddNode(&root, 20);
    printf("Arbre initial :\n");
    PrintTree(root, 0);
    printf("Suppression du nœud 3 :\n");
    DeleteNode(&root, 3);
    PrintTree(root, 0);
    printf("Suppression du nœud 15 :\n");
    DeleteNode(&root,15);
    PrintTree(root, 0);
    printf("Suppression du nœud 10 :\n");
    DeleteNode(&root, 10);
    PrintTree(root, 0);
    return 0;
}