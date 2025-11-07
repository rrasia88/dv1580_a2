#include "linked_list.h"
#include <stdio.h>

void list_init(Node** head) {
    *head = NULL;
}

void list_insert(Node** head, uint16_t data) {
    Node* new_node = (Node*)mem_alloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Error: mem_alloc failed in list_insert.\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void list_delete(Node** head, uint16_t data) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // not found

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    mem_free(temp);
}

void list_display(Node** head) {
    Node* temp = *head;
    printf("[");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(", ");
        temp = temp->next;
    }
    printf("]\n");
}

int list_count_nodes(Node** head) {
    int count = 0;
    Node* temp = *head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void list_cleanup(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* next = temp->next;
        mem_free(temp);
        temp = next;
    }
    *head = NULL;
}
