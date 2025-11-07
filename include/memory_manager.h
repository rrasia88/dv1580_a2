#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <stddef.h>

/**
 * Initializes the memory manager with a given total pool size.
 */
void mem_init(size_t size);

/**
 * Allocates a block of memory from the pool.
 */
void* mem_alloc(size_t size);

/**
 * Frees a previously allocated block of memory.
 */
void mem_free(void* block);

/**
 * Resizes a block of memory, returning a new pointer if moved.
 */
void* mem_resize(void* block, size_t size);

/**
 * Deinitializes the memory manager, freeing all resources.
 */
void mem_deinit();

#endif
