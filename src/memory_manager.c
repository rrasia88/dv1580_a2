#include "memory_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Simple memory pool allocator (first-fit strategy).
 * NOTE: This version is not yet thread-safe.
 */

typedef struct BlockHeader {
    size_t size;
    int free;
    struct BlockHeader* next;
} BlockHeader;

static void* memory_pool = NULL;
static size_t pool_size = 0;
static BlockHeader* free_list = NULL;

void mem_init(size_t size) {
    memory_pool = malloc(size);
    if (!memory_pool) {
        fprintf(stderr, "Error: memory pool allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    pool_size = size;
    free_list = (BlockHeader*)memory_pool;
    free_list->size = size - sizeof(BlockHeader);
    free_list->free = 1;
    free_list->next = NULL;
}

void* mem_alloc(size_t size) {
    BlockHeader* current = free_list;

    while (current != NULL) {
        if (current->free && current->size >= size) {
            current->free = 0;
            // Optional: split block (not necessary for now)
            return (void*)(current + 1);
        }
        current = current->next;
    }

    fprintf(stderr, "Error: no free block found (out of memory).\n");
    return NULL;
}

void mem_free(void* block) {
    if (!block) return;
    BlockHeader* header = ((BlockHeader*)block) - 1;
    header->free = 1;
}

void* mem_resize(void* block, size_t size) {
    if (!block) return mem_alloc(size);

    BlockHeader* header = ((BlockHeader*)block) - 1;
    if (header->size >= size) {
        return block; // current block big enough
    }

    void* new_block = mem_alloc(size);
    if (new_block) {
        memcpy(new_block, block, header->size);
        mem_free(block);
    }
    return new_block;
}

void mem_deinit() {
    free(memory_pool);
    memory_pool = NULL;
    free_list = NULL;
    pool_size = 0;
}
