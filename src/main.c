#include "linked_list.h"
#include <stdio.h>

int main() {
    Node* head;
    mem_init(1024 * 10); // 10KB pool
    list_init(&head);

    list_insert(&head, 10);
    list_insert(&head, 20);
    list_insert(&head, 30);
    list_display(&head);

    list_delete(&head, 20);
    list_display(&head);

    printf("Number of nodes: %d\n", list_count_nodes(&head));

    list_cleanup(&head);
    mem_deinit();
    return 0;
}
