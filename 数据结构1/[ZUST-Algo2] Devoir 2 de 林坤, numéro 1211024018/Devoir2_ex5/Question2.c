#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void copyEvenToNewList(Node* f1, Node** f2) {
    Node* current = f1;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            // 添加偶数到新队列F2
            if (*f2 == NULL) {
                *f2 = (Node*)malloc(sizeof(Node));
                (*f2)->data = current->data;
                (*f2)->next = NULL;
            } else {
                Node* temp = *f2;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = (Node*)malloc(sizeof(Node));
                temp->next->data = current->data;
                temp->next->next = NULL;
            }
        }
        current = current->next;
    }
}

int main() {
    // 创建队列F1
    Node* f1 = (Node*)malloc(sizeof(Node));
    f1->data = 1;
    f1->next = (Node*)malloc(sizeof(Node));
    f1->next->data = 2;
    f1->next->next = (Node*)malloc(sizeof(Node));
    f1->next->next->data = 3;
    f1->next->next->next = (Node*)malloc(sizeof(Node));
    f1->next->next->next->data = 4;
    f1->next->next->next->next = NULL;

    // 创建队列F2
    Node* f2 = NULL;

    // 输出复制前的队列F1
    printf("复制前的队列F1: ");
    printList(f1);
    printf("\n");

    // 将F1的偶数复制到F2中
    copyEvenToNewList(f1, &f2);

    // 输出复制后的队列F2
    printf("复制后的队列F2: ");
    printList(f2);
    printf("\n");

    // 输出复制后的队列F1
    printf("复制后的队列F1: ");
    printList(f1);
    printf("\n");

    // 释放内存
    Node* current = f2;
    while (current != NULL) {
        Node* temp = current        ->next;
        free(current);
        current = temp;
    }
    free(f1);

    return 0;
}