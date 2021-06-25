#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"


int main(void) {
    printf("trying to make a queue...\n");
    Node *head = make_queue();
    if (head == NULL) {
        printf("head is null\n");
        return EXIT_FAILURE;
    } else {
        printf("queue created.\n");
    }
    printf("attempting to push alphabet...\n");
    for (char c = 'a'; c <= 'z'; c++) {
        if (push(head, c)) {
            printf("pushed %c\n", /*peak(head)*/ c);
        } else {
            printf("failed to push %c\n", c);
        }
    }
    printf("\n");

    // printf("attempting to pop node off...");
    // while (peak(head) != '\0') {
    //     printf("pop: %c , peak: %c\n", peak(head)  ? pop(head) : '!', peak(head));
    // } //this loop does the same thing as free_queue below

    printf("queue is free: %d", free_queue(head));
    return EXIT_SUCCESS;
}
