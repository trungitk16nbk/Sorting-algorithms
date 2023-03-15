#include "Sort.h"
#include <time.h>

// tinh thoi gian thuc thi cua ham sort
typedef void (*Sort)(int *, int);
double TimeExecutionSortFunction(int *a, int n, Sort SortFunction)
{
    clock_t start, end;
    double time_taken;

    start = clock();
    SortFunction(a, n);
    end = clock();

    time_taken = ((double)(end - start)) / (CLOCKS_PER_SEC);
    return time_taken;
}

// Tinh thoi gian va so phep so sanh
typedef void (*Sort_Comp)(int *, int, long long &);
double TimeExecutionAndCompareSortFunction(int *a, int n, long long &comp, Sort_Comp SortFunction)
{
    clock_t start, end;
    double time_taken;

    start = clock();
    SortFunction(a, n, comp);
    end = clock();

    time_taken = ((double)(end - start)) / (CLOCKS_PER_SEC);
    return time_taken;
}