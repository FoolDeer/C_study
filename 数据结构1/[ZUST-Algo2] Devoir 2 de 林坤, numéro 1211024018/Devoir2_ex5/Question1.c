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

void moveEvenBeforeOdd(Node** f1, Node** f2) {
    Node* even = NULL; // 存储偶数的队列
    Node* odd = NULL; // 存储奇数的队列
    Node* current = *f1;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            // 添加偶数到even队列
            if (even == NULL) {
                even = current;
                *f2 = current;
            } else {
                even->next = current;
                even = even->next;
            }
        } else {
            // 添加奇数到odd队列
            if (odd == NULL) {
                odd = current;
            } else {
                odd->next = current;
                odd =odd->next;
            }
        }
        current = current->next;
    }

    // 将even队列和odd队列连接起来
    if (even != NULL) {
        even->next = odd;
    } else {
        *f2 = odd;
    }

    // 结尾处理odd队列
    if (odd != NULL) {
        odd->next = NULL;
    }

    // 结尾处理even队列
    if (even != NULL) {
        even->next = NULL;
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

    // 初始化队列F2
    Node* f2 = NULL;

    // 输出排序前的队列F1
    printf("排序前的队列F1: ");
    printList(f1);
    printf("\n");

    //排序F1并将偶数移到F2中
    moveEvenBeforeOdd(&f1, &f2);

    // 输出排序后的队列F2
    printf("排序后的队列F2: ");
    printList(f2);
    printf("\n");

    // 输出排序后的队列F1
    printf("排序后的队列F1: ");
    printList(f1);
    printf("\n");

    // 释放内存
    free(f1);
    free(f2);

    return 0;
}