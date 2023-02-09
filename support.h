#ifndef SUPPORT_H
#define SUPPORT_H

enum Response {
    SUCCESS = 1,
    FAILURE = 0,
};


#define ON_ERROR(expr, errStr, retVal) {                 \
    if (expr) {                                           \
        fprintf(stderr, "FATAL ERROR: %s\n", errStr);      \
        return retVal;                                      \
    }                                                        \
}                                                             \


#endif