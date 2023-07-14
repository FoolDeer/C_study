#include <stdio.h>
#include <stdlib.h>

// 定义队列节点结构体
struct QueueNode {
    int data;  // 节点数据
    struct QueueNode* next;  // 指向下一个节点的指针
};

// 定义队列结构体
struct Queue {
    struct QueueNode* front;  // 指向队列前端的指针
    struct QueueNode* rear;  // 指向队列尾端的指针
};

// 初始化队列
void init_queue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// 检查队列是否为空
int is_empty(struct Queue* q) {
    return (q->front == NULL);
}

// 向队列尾部添加元素
void enqueue(struct Queue* q, int data) {
    // 创建新节点
    struct QueueNode* new_node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    new_node->data = data;
    new_node->next = NULL;

    // 如果队列为空，则设置队列前端和尾端都指向新节点
    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        // 将新节点添加到队列尾部
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// 从队列前端删除元素
int dequeue(struct Queue* q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty.\n");
        return -1;
    } else {
        // 获取队列前端节点的数据
        int data = q->front->data;

        // 删除队列前端节点
        struct QueueNode* temp = q->front;
        q->front = q->front->next;
        free(temp);

        // 如果队列现在为空，则将队列尾端也设置为空
        if (q->front == NULL) {
            q->rear = NULL;
        }

        return data;
    }
}

// 获取队列前端节点的数据（但不删除它）
int peek(struct Queue* q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty.\n");
        return -1;
    } else {
        return q->front->data;
    }
}

// 打印队列中的所有元素
void print_queue(struct Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
    } else {
        struct QueueNode* current = q->front;
        printf("Queue: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}