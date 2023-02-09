#include <stdio.h>
#include <stdlib.h>

#include "tests.h"
#include "time.h"

void classicTest1(List_t* classicList) {
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 1000000; i++) {
            int value = i;
            pushFront (classicList, &value);
        }

        for (int i = 0; i < 500000; i++) {
            popFront (classicList);
        }

        for (int i = 0; i < 750000; i++) {
            int value = i;
            pushFront (classicList, &value);
        }
    }
}

void dynamicTest1(DList_t* dynamicList) {
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 1000000; i++) {
            int value = i;
            dpushFront (dynamicList, &value);
        }

        for (int i = 0; i < 500000; i++) {
            dpopFront (dynamicList);
        }

        for (int i = 0; i < 750000; i++) {
            int value = i;
            dpushFront (dynamicList, &value);
        }
    }
}

void test1() {
    List_t*  classicList = listCtr (sizeof(int));
    DList_t* dynamicList = dlistCtr(sizeof(int));

    clock_t start = clock();
    classicTest1(classicList);
    clock_t finish = clock();

    clock_t dstart = clock();
    dynamicTest1(dynamicList);
    clock_t dfinish = clock();

    fprintf(stderr, "TEST-1\nОдносвязный список: %f\nДинамический массив: %f\n\n", 
                    (double) (finish - start) / CLOCKS_PER_SEC, (double) (dfinish - dstart) / CLOCKS_PER_SEC);

    listDtr(classicList);
    dlistDtr(dynamicList);
}


void classicTest2(List_t* classicList) {
    for (int i = 0; i < 1000000; i++) {
        int value = i;
        pushFront (classicList, &value);
    }

    for (int m = 0; m < 9; m++) {
        for (int j = 0; j < 100; j++) {
            for (int i = 0; i < 10000; i++) {
                popFront (classicList);
            }

            for (int i = 0; i < 10000; i++) {
                int value = i;
                pushFront (classicList, &value);
            }
        }
    }
}

void dynamicTest2(DList_t* dynamicList) {
    for (int i = 0; i < 1000000; i++) {
        int value = i;
        dpushFront (dynamicList, &value);
    }

    for (int m = 0; m < 9; m++) {
        for (int j = 0; j < 100; j++) {
            for (int i = 0; i < 10000; i++) {
                dpopFront (dynamicList);
            }

            for (int i = 0; i < 10000; i++) {
                int value = i;
                dpushFront (dynamicList, &value);
            }
        }
    }
}

void test2() {
    List_t*  classicList = listCtr (sizeof(int));
    DList_t* dynamicList = dlistCtr(sizeof(int));

    clock_t start = clock(), finish = 0;
    classicTest2(classicList);
    finish = clock();

    clock_t dstart = clock(), dfinish = 0;
    dynamicTest2(dynamicList);
    dfinish = clock();

    printf("TEST-2\nОдносвязный список: %f\nДинамический массив: %f\n\n", 
                    (double) (finish - start) / CLOCKS_PER_SEC, (double) (dfinish - dstart) / CLOCKS_PER_SEC);

    listDtr(classicList);
    dlistDtr(dynamicList);
}



void classicTest3(List_t* classicList) {
    for (int i = 0; i < 1000000; i++) {
        int num = rand() % (2 + 1 - 1) + 1;

        pushFront(classicList, &num);
    }

    for (int i = 0; i < 1000000; i++) {
        int num = rand() % (2 + 1 - 1) + 1;

        if (num == 1) pushFront(classicList, &num);
        else popFront(classicList);
    }
}

void dynamicTest3(DList_t* dynamicList) {
    for (int i = 0; i < 1000000; i++) {
        int num = rand() % (2 + 1 - 1) + 1;

        dpushFront(dynamicList, &num);
    }

    for (int i = 0; i < 1000000; i++) {
        int num = rand() % (2 + 1 - 1) + 1;

        if (num == 1) dpushFront(dynamicList, &num);
        else dpopFront(dynamicList);
    }
}

void test3() {
    List_t*  classicList = listCtr (sizeof(int));
    DList_t* dynamicList = dlistCtr(sizeof(int));

    srand((unsigned) time(NULL));

    clock_t start = clock(), finish = 0;
    classicTest3(classicList);
    finish = clock();

    clock_t dstart = clock(), dfinish = 0;
    dynamicTest3(dynamicList);
    dfinish = clock();

    printf("TEST-3\nОдносвязный список: %f\nДинамический массив: %f\n\n", 
                    (double) (finish - start) / CLOCKS_PER_SEC, (double) (dfinish - dstart) / CLOCKS_PER_SEC);

    listDtr(classicList);
    dlistDtr(dynamicList);
}

