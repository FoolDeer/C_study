#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct PriorityQueue {
    Node* head;
} PriorityQueue;

void initPriorityQueue(PriorityQueue* pq) {
    pq->head = NULL;
}

void enqueue(PriorityQueue* pq, int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;

    if (pq->head == NULL || priority > pq->head->priority) {
        newNode->next = pq->head;
        pq->head = newNode;
    } else {
        Node* current = pq->head;
        while (current->next != NULL && priority <= current->next->priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeue(PriorityQueue* pq) {
    if (pq->head == NULL) {
        printf("队列为空！\n");
        return 0;
    } else {
        int data = pq->head->data;
        Node* temp = pq->head;
        pq->head = pq->head->next;
        free(temp);
        return data;
   }
}

int main() {
    PriorityQueue pq;
    initPriorityQueue(&pq);

    // 添加元素
    enqueue(&pq, 5, 2);
    enqueue(&pq, 3, 1);
    enqueue(&pq, 7, 3);
    enqueue(&pq, 2, 1);
    enqueue(&pq, 8, 4);

    // 删除并输出元素
    printf("从优先队列中删除的元素：");
    while (pq.head != NULL) {
        int data = dequeue(&pq);
        printf("%d ", data);
    }

    return 0;
}