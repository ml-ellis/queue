#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>


typedef struct node Node;

Node * make_queue(void);
bool push(Node *, char);
char pop(Node *);
char peak(Node *);
bool free_queue(Node *);

#endif
