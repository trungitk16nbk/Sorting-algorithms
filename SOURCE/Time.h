#pragma once

// tinh thoi gian thuc thi
typedef void (*Sort)(int *, int);
double TimeExecutionSortFunction(int *a, int n, Sort SortFunction);

// tinh thoi gian thuc hien va so phep so sanh
typedef void (*Sort_Comp)(int *, int, long long &);
double TimeExecutionAndCompareSortFunction(int *a, int n, long long &comp, Sort_Comp SortFunction);
