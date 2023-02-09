#include "support.h"

struct ListElement_t {
    void* element       = nullptr;
    ListElement_t* next = nullptr;
};

struct List_t {
    ListElement_t* head = nullptr;

    int elementSize     = 0;
    long size           = 0;
};

List_t* listCtr(int elementSize);
int pushFront(List_t* list, void* element);
void* top(List_t* list);
void* popFront(List_t* list);
List_t* listDtr(List_t* list);