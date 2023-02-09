#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "dynamicList.h"

DList_t* dlistCtr(int elementSize) {
    ON_ERROR(elementSize <= 0, "Element size must be greater than 0!", nullptr);

    DList_t* list = (DList_t*) calloc(1, sizeof(DList_t));
    ON_ERROR(!list, "Unable to allocate memory!", nullptr);

    list->values    = calloc(2, (size_t) elementSize);
    ON_ERROR(!(list->values), "Unable to allocate memory!", nullptr);

    list->capacity  = 2;
    list->valueSize = elementSize;

    return list;
}

int dpushFront(DList_t* list, void* element) {
    ON_ERROR(!list || !element, "Nullptr! Ai-ai-ai!", FAILURE);

    memcpy(((char*) list->values) + list->valueSize * list->size, element, (size_t) list->valueSize);
    list->size++;

    if (list->size >= list->capacity) dresizeList(list);

    return SUCCESS;
}

void* dtop(DList_t* list) {
    ON_ERROR(!list, "Nullptr! Ai-ai-ai!", nullptr);

    void* val = calloc(1, (size_t) list->valueSize);
    val = memcpy(val, ((char*) list->values) + list->valueSize * (list->size - 1), (size_t) list->valueSize);

    return val;
}

int dresizeList(DList_t* list) {
    ON_ERROR(!list, "Nullptr! Ai-ai-ai!", FAILURE);

    list->values = realloc(list->values, (size_t) list->capacity * 2 * (size_t) list->valueSize);
    ON_ERROR(!(list->values), "Nullptr! Ai-ai-ai!", FAILURE);

    list->capacity *= 2;

    return SUCCESS;
}

void* dpopFront(DList_t* list) {
    ON_ERROR(!list, "Nullptr! Ai-ai-ai!", nullptr);
    ON_ERROR(list->size <= 0, "List empty!", nullptr);

    void* val = calloc(1, (size_t) list->valueSize);
    val = memcpy(val, ((char*) list->values) + list->valueSize * (list->size - 1), (size_t) list->valueSize);

    list->size--;

    return val;
}

DList_t* dlistDtr(DList_t* list) {
    ON_ERROR(!list, "Nullptr! Ai-ai-ai!", nullptr);

    free(list->values);
    free(list);

    return nullptr;
} 