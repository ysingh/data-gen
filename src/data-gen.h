#ifndef DATA_GEN_H
#define DATA_GEN_H

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

typedef enum supportedTypes { t_char, t_int, t_double } supportedTypes;
typedef enum orderings { o_increasing, o_decreasing, o_random } orderings;
typedef enum sorts { sorted, unsorted, nearlySorted } sorts;

void* getTestData(size_t size, supportedTypes type, orderings ordering, sorts sort, bool repeats);

int* getRandomIntArray(size_t size);
int* getSortedIntArray(size_t size);
int* getNearlySortedIntArray(size_t size);
int* getReverseSortedIntArray(size_t size);
int* getNearlySortedReverseIntArray(size_t size);

double* getRandomDoubleArray(size_t size);
double* getSortedDoubleArray(size_t size);
double* getNearlySortedDoubleArray(size_t size);
double* getReverseSortedDoubleArray(size_t size);
double* getNearlySortedReverseDoubleArray(size_t size);

char* getRandomCharArray(size_t size);
char* getSortedCharArray(size_t size);
char* getNearlySortedCharArray(size_t size);
char* getReverseSortedCharArray(size_t size);
char* getNearlySortedReverseCharArray(size_t size);
#endif
