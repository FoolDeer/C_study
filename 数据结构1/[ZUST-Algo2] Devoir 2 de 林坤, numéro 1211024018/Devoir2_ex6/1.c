#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Deque {
    Node* head;
    Node* tail;
    int size;
} Deque;

void initDeque(Deque* deque) {
    deque->head = NULL;
    deque->tail = NULL;
    deque->size = 0;
}

void enqueueHead(Deque* deque, int data) {
    // 创建一个新节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->head;

    if (deque->head == NULL) {
        // 如果队列为空，新节点为头节点和尾节点
       deque->head = newNode;
        deque->tail = newNode;
    } else {
        // 否则将新节点添加到头部，并更新头节点指针
        deque->head->prev = newNode;
        deque->head = newNode;
    }

    // 增加队列大小
    deque->size++;
}

void enqueueTail(Deque* deque, int data) {
    // 创建一个新节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = deque->tail;
    newNode->next = NULL;

    if (deque->tail == NULL) {
        // 如果队列为空，新节点为头节点和尾节点
        deque->head = newNode;
        deque->tail = newNode;
    } else {
        // 否则将新节点添加到尾部，并更新尾节点指针
        deque->tail->next = newNode;
        deque->tail = newNode;
    }

    // 增加队列大小
    deque->size++;
}

int dequeueHead(Deque* deque) {
    if (deque->head == NULL) {
        // 如果队列为空，返回0
        return 0;
    } else {
        // 否则删除头节点，并返回其数据
        int data = deque->head->data;
        Node* temp = deque->head;
        deque->head= deque->head->next;
        if (deque->head == NULL) {
            // 如果队列只有一个节点，更新尾节点指针为NULL
            deque->tail = NULL;
        } else {
            deque->head->prev = NULL;
        }
        free(temp);

        // 减少队列大小
        deque->size--;

        return data;
    }
}

int dequeueTail(Deque* deque) {
    if (deque->tail == NULL) {
        // 如果队列为空，返回0
        return 0;
    } else {
        // 否则删除尾节点，并返回其数据
        int data = deque->tail->data;
        Node* temp = deque->tail;
        deque->tail = deque->tail->prev;
        if (deque->tail == NULL) {
            // 如果队列只有一个节点，更新头节点指针为NULL
            deque->head = NULL;
        } else {
            deque->tail->next = NULL;
        }
        free(temp);

        // 减少队列大小
        deque->size--;

        return data;
    }
}

int main() {
    // 创建一个新的双向队列
    Deque deque;
    initDeque(&deque);

    // 在队列的头部和尾部添加元素
    enqueueHead(&deque, 1);
    enqueueTail(&deque,2);

    // 输出队列的大小
    printf("队列的大小为：%d\n", deque.size);

    // 输出队列中的所有元素
    printf("队列中的元素为：\n");
    Node* current = deque.head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // 删除队列头部和尾部的元素，并输出其值
    int head = dequeueHead(&deque);
    int tail = dequeueTail(&deque);
    printf("删除队列头部的元素：%d\n", head);
    printf("删除队列尾部的元素：%d\n", tail);

    // 输出队列的大小和剩余的元素
    printf("队列的大小为：%d\n", deque.size);
    printf("队列中剩余的元素为：\n");
    current = deque.head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}