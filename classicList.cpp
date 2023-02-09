#include <stdio.h>
#include <malloc.h>
#include <string.h>


#include "classicList.h"

List_t* listCtr(int elementSize) {
    ON_ERROR(elementSize <= 0, "Element size must be greater than 0!", nullptr);

    List_t* list = (List_t*) calloc(1, sizeof(List_t));
    ON_ERROR(!list, "Unable to allocate memory!", nullptr);

    list->elementSize = elementSize;

    return list;
}

int pushFront(List_t* list, void* element) {
    ON_ERROR(!list || !element, "Nullptr! Ai-ai-ai!", FAILURE);

    ListElement_t* newElem = (ListElement_t*) calloc(1, sizeof(ListElement_t));
    ON_ERROR(!newElem, "Unable to allocate memory!", FAILURE);

    newElem->element = calloc(1, (size_t) list->elementSize);
    newElem->element = memcpy(newElem->element, element, (size_t) list->elementSize);

    newElem->next = list->head;

    list->head = newElem;

    return SUCCESS;
}

void* top(List_t* list) {
    ON_ERROR(!list, "Nullptr! Ai-ai-ai!", nullptr);
    ON_ERROR(!(list->head), "List empty!", nullptr);

    return list->head->element;
}

void* popFront(List_t* list) {
    ON_ERROR(!list, "Nullptr! Ai-ai-ai!", nullptr);
    ON_ERROR(!(list->head), "List empty!", nullptr);

    void* val = list->head->element;

    ListElement_t* oldHead = list->head;
    list->head = oldHead->next;

    free(oldHead);

    return val;
}

List_t* listDtr(List_t* list) {
    ON_ERROR(!list, "Nullptr! Ai-ai-ai!", nullptr);

    ListElement_t* cur = list->head;
    while (cur) {
        ListElement_t* oldCur = cur;
        cur = cur->next;

        free(oldCur);
    }

    free(list);

    return nullptr;
}