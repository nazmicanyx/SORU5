#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* q, char c) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = c;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

char dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return '\0';
    }

    struct Node* temp = q->front;
    char c = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return c;
}

void remove_duplicates(struct Queue* q) {
    struct Node* curr = q->front;

    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            dequeue(q);
            curr = q->front;
        }
        else {
            curr = curr->next;
        }
    }
}

void print_queue(struct Queue* q) {
    struct Node* curr = q->front;

    while (curr != NULL) {
        printf("%c ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main() {
    struct Queue q = { NULL, NULL };
    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'B');
    enqueue(&q, 'B');
    enqueue(&q, 'C');
    enqueue(&q, 'D');
    enqueue(&q, 'D');
    enqueue(&q, 'E');
    enqueue(&q, 'E');
    enqueue(&q, 'E');

    printf(": ");
    print_queue(&q);

    remove_duplicates(&q);

    printf(": ");
    print_queue(&q);

    return 0;
}
