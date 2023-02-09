#include "support.h"

struct DList_t {
    void* values = nullptr;

    long size           = 0;
    long capacity       = 0;
    int valueSize       = 0;
};

DList_t* dlistCtr(int elementSize);
int dpushFront(DList_t* list, void* element);
void* dtop(DList_t* list);
int dresizeList(DList_t* list);
void* dpopFront(DList_t* list);
DList_t* dlistDtr(DList_t* list);  