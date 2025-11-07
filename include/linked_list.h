#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>
#include "memory_manager.h"

typedef struct Node {
    uint16_t data;
    struct Node* next;
} Node;

void list_init(Node** head);
void list_insert(Node** head, uint16_t data);
void list_delete(Node** head, uint16_t data);
void list_display(Node** head);
int list_count_nodes(Node** head);
void list_cleanup(Node** head);

#endif
