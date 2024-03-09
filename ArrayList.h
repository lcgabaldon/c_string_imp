#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>

typedef struct {
    void **array;
    size_t size;
    size_t capacity;
}ArrayList_t;

ArrayList_t *AL_init(void);

int AL_free(ArrayList_t *AL, int (*delete_data)(void *));

void AL_print(ArrayList_t *AL, void (*print_data)(void *));

void *AL_get_at(ArrayList_t *AL, size_t i);

int AL_set_at(ArrayList_t *AL, size_t i, void *elem, void *(*copy_data)(void *), int (*delete_data)(void *));

int AL_insert_first(ArrayList_t *AL, void *elem, void *(*copy_data)(void *));

int AL_delete_first(ArrayList_t *AL, int (*delete_data)(void *));

int AL_append(ArrayList_t *AL, void *elem, void *(*copy_data)(void *));

int AL_delete_last(ArrayList_t *AL, int (*delete_data)(void *));

int AL_insert_at(ArrayList_t *AL, size_t i, void *elem, void *(*copy_data)(void *));

int AL_delete_at(ArrayList_t *AL, size_t i, int (*delete_data)(void *));

#endif