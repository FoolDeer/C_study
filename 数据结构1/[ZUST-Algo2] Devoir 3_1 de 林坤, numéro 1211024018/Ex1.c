// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node {
//   struct Node *left;
//   char data;
//   struct Node *right;
// }Node;

// Node* createNode(char data) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// Node* insert(Node* root, char data) {
//     if (root == NULL) {
//         return createNode(data);
//     }

//     if (data < root->data) {
//         root->left = insert(root->left, data);
//     } else {
//         root->right = insert(root->right, data);
//     }

//     return root;
// }
// void preOrderTraversal(Node* root) {
//     if (root == NULL) {
//         return;
//     }

//     printf("%d ", root->data);
//     preOrderTraversal(root->left);
//     preOrderTraversal(root->right);
// }

// void inOrderTraversal(Node* root) {
//     if (root == NULL) {
//         return;
//     }

//     inOrderTraversal(root->left);
//     printf("%d ", root->data);
//     inOrderTraversal(root->right);
// }

// void postOrderTraversal(Node* root) {
//     if (root == NULL) {
//         return;
//     }

//     postOrderTraversal(root->left);
//     postOrderTraversal(root->right);
//     printf("%d ", root->data);
// }

// int main() {
//     Node* root = NULL;
//     root = insert(root, 50);
//     insert(root, 30);
//     insert(root, 20);
//     insert(root, 40);
//     insert(root, 70);
//     insert(root, 60);
//     insert(root, 80);

//     printf("Pre-Order Traversal:\n");
//     preOrderTraversal(root);
//     printf("\n");

//     printf("In-Order Traversal:\n");
//     inOrderTraversal(root);
//     printf("\n");

//     printf("Post-Order Traversal:\n");
//     postOrderTraversal(root);
//     printf("\n");

//     return 0;
// }