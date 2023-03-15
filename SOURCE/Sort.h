#pragma once

// set 2: 11 ham sort
// dung de sort neu de chi yeu cau tinh thoi gian chay thi dung cac ham sort nay giup chay nhanh hon
void SelectionSort(int *a, int n);
void InsertionSort(int *a, int n);
void BubbleSort(int *a, int n);
void ShakerSort(int *a, int n);
void ShellSort(int *a, int n);
void HeapSort(int *a, int n);
void MergeSort(int *a, int l, int r);
void MergeSort(int *a, int n); // tien cho viec dung con tro ham
void QuickSort(int *a, int l, int r);
void QuickSort(int *a, int n); // de dung con tro ham
void CountingSort(int *a, int n);
void RadixSort(int *a, int n);
void FlashSort(int *a, int n);

// tinh so phep so sanh
// neu de co tinh phep so sanh thi dung cac ham sort ben duoi
void SelectionSort(int *a, int n, long long &comp);
void InsertionSort(int *a, int n, long long &comp);
void BubbleSort(int *a, int n, long long &comp);
void ShakerSort(int *a, int n, long long &comp);
void ShellSort(int *a, int n, long long &comp);
void HeapSort(int *a, int n, long long &comp);
void MergeSort(int *a, int l, int r, long long &comp);
void MergeSort(int *a, int n, long long &comp); // tien cho viec dung con tro ham
void QuickSort(int *a, int l, int r, long long &comp);
void QuickSort(int *a, int n, long long &comp); // de dung con tro ham
void CountingSort(int *a, int n, long long &comp);
void RadixSort(int *a, int n, long long &comp);
void FlashSort(int *a, int n, long long &comp);

// ham in mang de tien cho viec kiem tra
void PrintArray(int *a, int n);