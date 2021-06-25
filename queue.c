#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"


struct node {
  char character;
  Node *next;
};


Node * make_queue() {
    Node *head = (Node *)malloc(sizeof(Node));
    if (head != NULL) {
        head->character = '\0';
        head->next = NULL;
    }
    return head;
}

bool push(Node *head, char c) {
    if (head == NULL) return false;
    Node *counter = head;
    //printf("head exists.\n");

    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) return false;
    node->next = NULL;
    node->character = c;
    //printf("node generated.\n");

    while (counter->next != NULL) {
        counter = counter->next;
    }

    counter->next = node;
    // check all the cases
    return true;
}

char pop(Node *head) {
    if (head == NULL) return '\0';
    Node *tracker = head->next;
    if (tracker != NULL) {
        //printf("found the first node.\n");
        head->next = head->next->next;
        char c = tracker->character;
        free(tracker);
        return c;
    }
    return '\0';
}

char peak(Node *head) {
    if (head == NULL) return '\0';
    if (head->next == NULL) return '\0';
    return head->next->character;
}

bool free_queue(Node *head) {
    if (head == NULL) return false;
    Node *tracker = head->next;
    if (tracker == NULL) {
        printf("queue is already empty");
        return false;
    }
    while (tracker != NULL) {
        head->next = head->next->next;
        char c = tracker->character;
        free(tracker);
        tracker = head->next;
        printf("%c is gone\n", c);
    }
    return true;
}
