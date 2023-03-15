#include "sort.h"
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// hoan vi 2 so nguyen
void Swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// in mang
void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

// 1: Selection Sort (da hoc)
void SelectionSort(int *a, int n)
{
    int min_id; // luu vi tri cua phan tu nho nhat cua doan chua xet
    for (int i = 0; i < n; ++i)
    {
        min_id = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[min_id])
                min_id = j; // luu lai vi tri phan tu nho nhat trong doan dang xet de tiep tuc xet

        // chuyen phan tu nhu nhat len dau doan dang duoc xet
        if (min_id != i)
            Swap(a[i], a[min_id]);
    }
}

// 2: Insertion Sort (da hoc)
void InsertionSort(int *a, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int temp = a[i]; // luu gia tri de sau chen dung vi tri
        int j = i - 1;   // xet cac phan tu phia sau de chen

        // chuyen cac phan tu lon hon temp len 1 vi tri
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

// 3: BubbleSort cai tien 2 (da hoc thay Phuong)
void BubbleSort(int *a, int n)
{
    int k = n - 1; // lu lai vi tri doi cho cuoi cung cua lan duyet
    bool check = false;
    for (int i = n - 1; i >= 0; --i)
    {
        check = false;
        i = k;
        for (int j = 0; j < i; ++j)
            if (a[j] > a[j + 1])
            {
                swap(a[j + 1], a[j]);
                check = true; //co su dung sap xep
                k = j + 1;
            }

        //neu ko co sap xep la  mang da dung
        if (check == false)
            break;
    }
}

//4: Shaker Sort cai tien cua BubbleSort (thay phuong huong dan)
void ShakerSort(int *a, int n)
{
    int l = 1, r = n - 1, k = n - 1;
    do
    {
        // dua phan tu lon nhat ve cuoi
        for (int j = r; j >= l; j--)
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                k = j;
            }
        l = k + 1;

        // dua phan tu nho nhat ve dau
        for (int j = l; j <= r; j++)
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                k = j;
            }
        r = k - 1;

    } while (l <= r);
}

// 5: ShellSort
void ShellSort(int *a, int n)
{
    int k;
    //k la so lan chia mang duoc tach ra de lam
    k = log(n) / log(2); // tach theo n/2 nên k = log2(n)

    int *h = new int[k];
    h[k - 1] = 1;

    for (int i = k - 1; i > 0; i--)
    {
        //h[] la mang cac khoang cach trong moi lan phan tach
        h[i - 1] = h[i] * 2 + 1;
    }

    // sap xep cac doan da phan hoach
    for (int step = k - 1; step > 0; step--)
    {
        int tmp = h[step];

        //sap xep mang con bang InsertionSort
        for (int i = tmp; i < n; i++)
        {
            int temp = a[i];
            int j = i - tmp;
            while (temp < a[j] && j >= 0)
            {
                a[j + tmp] = a[j];
                j = j - tmp;
            }
            a[j + tmp] = temp;
        }
    }
}

// 6: HeapSort: Duoc thay Phuong huong dan y tuong
void sift(int a[], int left, int right)
{
    int i = left;
    int j = 2 * i + 1;
    int x = a[i];
    while (j <= right)
    {
        if (j < right)
            if (a[j] < a[j + 1])
                j = j + 1;
        if (x >= a[j])
            break;
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = x;
}

// ham heap sort chinh
void HeapSort(int a[], int n)
{
    int left = (n - 1) / 2;
    int right = n - 1;
    while (left >= 0)
    {
        sift(a, left, right);
        left--;
    }
    //tao ra heap
    while (right > 0)
    {
        swap(a[0], a[right]);
        right--;
        sift(a, 0, right);
    }
}

//7.Merge Sort
void merge(int *a, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tao 2 mang luu 2 mang duoc chia
    int *L = new int[n1]; // luu doan l -> m
    int *R = new int[n2]; // luu doan m+ 1 r

    // sao chep du lieu tuong ung vao 2 mang
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    // Tron 2 mang con lai de duoc mang sap xep

    // vi tri dau tien cua con L
    int i = 0;
    // Vi tri dau tien cua mang con R
    int j = 0;
    // vi tri dau cua mang sau khi hop nhat
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // copy doan con lai cua L neu chua duoc tron vao
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    // copy doan con lai cua L neu chua duoc tron vao
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

//
void MergeSort(int *a, int l, int r)
{
    if (l >= r)
    {
        return; // mang da sap xep xong
    }
    int m = (l + r - 1) / 2;
    // chia doi mang lien tuc de tron
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

//8.Quick Sort (duoc hoc luc cap 2)
void QuickSort(int *a, int l, int r)
{
    int x = (l + r) / 2;
    int pivot = a[x]; // chon phan tu o giua lam pivot
    int i, j;
    i = l;
    j = r;
    do
    {
        while (a[i] < pivot)
            i++; // neu nho hon pivot thi xet so ke tiep
        while (a[j] > pivot)
            j--; // neu lon hon pivot thi lui ve truoc de xet
        if (i <= j)
        {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (l < j)
        QuickSort(a, l, j); // goi lai de xet
    if (i < r)
        QuickSort(a, i, r); // goi lai de xet
}

//9.Counting Sort (Thay Phuong day)
void CountingSort(int *a, int n)
{

    int *b = new int[n];
    int Max = a[0];

    for (int i = 0; i < n; i++)
    {
        if (a[i] > Max)
            Max = a[i];
    }

    int *f = new int[Max + 1]{0};

    for (int i = 0; i < n; i++)
        f[a[i]]++;

    for (int i = 1; i <= Max; i++)
        f[i] += f[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        b[f[a[i]] - 1] = a[i];
        f[a[i]]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = b[i];

    delete[] f;
    delete[] b;
}

//10.Radix Sort (Thay Phuong day)

// lay chu so hang k (don vi: k =1 ..->)
int digit(int n, int k)
{
    int temp = n % (int)pow(10, k);
    return temp / pow(10, k - 1);
}

// CountingSort cua tung chu so cua cac phan tu a
void sort(int a[], int n, int k)
{
    int *b = new int[n];
    int *f = new int[10]{0}; // luu tan xuat cua cac chu so

    for (int i = 0; i < n; i++)
        f[digit(a[i], k)]++;

    for (int i = 1; i < 10; i++)
        f[i] += f[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = digit(a[i], k);
        b[f[temp] - 1] = a[i];
        f[temp]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = b[i];

    delete[] f;
    delete[] b;
}

void RadixSort(int a[], int n)
{
    int max = a[0], maxk = 0;
    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    while (max != 0)
    {
        max = max / 10;
        maxk++;
    }
    for (int i = 1; i <= maxk; i++)
        sort(a, n, i);
}

// 11: FlashSort (Thay phuong day)
void FlashSort(int *a, int n)
{
    //Giai doan 1:
    // tu chon so phan lop la (0.43 * n) (thay noi chon nhu nay chay nhanh nhat)
    int Min = a[0];
    int max_pos = 0;
    int m = int(0.43 * n);

    for (int i = 1; i < n; i++)
    {
        if (a[i] < Min)
            Min = a[i];
        if (a[i] > a[max_pos])
            max_pos = i;
    }

    if (a[max_pos] == Min)
        return;

    int *L = new int[m];
    for (int i = 0; i < m; i++)
        L[i] = 0;

    double Temp = (double)(m - 1) / (a[max_pos] - Min);
    for (int i = 0; i < n; i++)
    {
        int k = int(Temp * (a[i] - Min));
        ++L[k];
    }
    for (int i = 1; i < m; i++)
        L[i] += L[i - 1];
    swap(a[max_pos], a[0]);
    //Phan vung thu m-1 chi chua max (co the co nhieu a[i] = max)
    //L[k] se chi vao bien ben phai cua phan lop thu k
    //Giai doan 2:
    int j = 0;
    int k = m - 1;
    int cnt = 0;
    int Save = 0;
    while (cnt < n - 1)
    {
        while (j > L[k] - 1)
        {
            j++;
            k = int(Temp * (a[j] - Min));
        }
        Save = a[j];
        if (k < 0)
            break;
        while (j != L[k])
        {
            k = int(Temp * (Save - Min));
            Swap(Save, a[--L[k]]);
            cnt++;
        }
    }

    //Giai doan 3
    //Phan lop thu m-1 da duoc xap
    //Phan lop k: L[k]->L[k+1]-1
    //dung insertionSort sap thu phai -> trai
    int l, r, mid, tmp;
    for (int i = 1; i < n; i++)
    {
        l = 0;
        r = i - 1;
        tmp = a[i];
        while (l <= r)
        {
            mid = (r + l) / 2;
            if (a[mid] > tmp)
                r = mid - 1;
            else
                l = mid + 1;
        }
        for (j = i - 1; j >= l; j--)
            a[j + 1] = a[j];
        a[l] = tmp;
    }

    delete[] L;
}
// 2 ham nay de tien cho viec dung con tro ham thoi
void QuickSort(int *a, int n)
{
    QuickSort(a, 0, n - 1);
}

void MergeSort(int *a, int n)
{
    MergeSort(a, 0, n - 1);
}

//------------ dem phep so sanh ----------------

// 1: Selection Sort (da hoc)
void SelectionSort(int *a, int n, long long &comp)
{
    int min_id; // luu vi tri cua phan tu nho nhat cua doan chua xet
    for (int i = 0; ++comp && i < n; ++i)
    {
        min_id = i;
        for (int j = i + 1; ++comp && j < n; ++j)
            if (++comp && a[j] < a[min_id])
                min_id = j; // luu lai vi tri phan tu nho nhat trong doan dang xet de tiep tuc xet

        // chuyen phan tu nhu nhat len dau doan dang duoc xet
        if (++comp && min_id != i)
            Swap(a[i], a[min_id]);
    }
}

// 2: Insertion Sort (da hoc)
void InsertionSort(int *a, int n, long long &comp)
{
    for (int i = 1; ++comp && i < n; ++i)
    {
        int temp = a[i]; // luu gia tri de sau chen dung vi tri
        int j = i - 1;   // xet cac phan tu phia sau de chen

        // chuyen cac phan tu lon hon temp len 1 vi tri
        while (++comp && j >= 0 && ++comp && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

// 3: BubbleSort cai tien 2 (da hoc thay Phuong)
void BubbleSort(int *a, int n, long long &comp)
{
    int k = n - 1; // lu lai vi tri doi cho cuoi cung cua lan duyet
    bool check = false;
    for (int i = n - 1; ++comp && i >= 0; --i)
    {
        check = false;
        i = k;
        for (int j = 0; ++comp && j < i; ++j)
            if (++comp && a[j] > a[j + 1])
            {
                swap(a[j + 1], a[j]);
                check = true; //co su dung sap xep
                k = j + 1;
            }

        //neu ko co sap xep la  mang da dung
        if (++comp && check == false)
            break;
    }
}

//4: Shaker Sort cai tien cua BubbleSort (thay phuong huong dan)
void ShakerSort(int *a, int n, long long &comp)
{
    int l = 1, r = n - 1, k = n - 1;
    do
    {
        // dua phan tu lon nhat ve cuoi
        for (int j = r; ++comp && j >= l; j--)
            if (++comp && a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                k = j;
            }
        l = k + 1;

        // dua phan tu nho nhat ve dau
        for (int j = l; ++comp && j <= r; j++)
            if (++comp && a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                k = j;
            }
        r = k - 1;

    } while (++comp && l <= r);
}

// 5: ShellSort
void ShellSort(int *a, int n, long long &comp)
{
    int k;
    //k la so lan chia mang duoc tach ra de lam
    k = log(n) / log(2); // tach theo n/2 nên k = log2(n)

    int *h = new int[k];
    h[k - 1] = 1;

    for (int i = k - 1; ++comp && i > 0; i--)
    {
        //h[] la mang cac khoang cach trong moi lan phan tach
        h[i - 1] = h[i] * 2 + 1;
    }

    // sap xep cac doan da phan hoach
    for (int step = k - 1; ++comp && step > 0; step--)
    {
        int tmp = h[step];

        //sap xep mang con bang InsertionSort
        for (int i = tmp; ++comp && i < n; i++)
        {
            int temp = a[i];
            int j = i - tmp;
            while (++comp && temp < a[j] && ++comp && j >= 0)
            {
                a[j + tmp] = a[j];
                j = j - tmp;
            }
            a[j + tmp] = temp;
        }
    }
}

// 6: HeapSort: Duoc thay Phuong huong dan y tuong
void sift(int a[], int left, int right, long long &comp)
{
    int i = left;
    int j = 2 * i + 1;
    int x = a[i];
    while (++comp && j <= right)
    {
        if (++comp && j < right)
            if (a[j] < a[j + 1])
                j = j + 1;
        if (++comp && x >= a[j])
            break;
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = x;
}

// ham heap sort chinh
void HeapSort(int a[], int n, long long &comp)
{
    int left = (n - 1) / 2;
    int right = n - 1;
    while (++comp && left >= 0)
    {
        sift(a, left, right, comp);
        left--;
    }
    //tao ra heap
    while (++comp && right > 0)
    {
        swap(a[0], a[right]);
        right--;
        sift(a, 0, right, comp);
    }
}

//7.Merge Sort
void merge(int *a, int l, int m, int r, long long &comp)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Tao 2 mang luu 2 mang duoc chia
    int *L = new int[n1]; // luu doan l -> m
    int *R = new int[n2]; // luu doan m+ 1 r

    // sao chep du lieu tuong ung vao 2 mang
    for (int i = 0; ++comp && i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; ++comp && j < n2; j++)
        R[j] = a[m + 1 + j];

    // Tron 2 mang con lai de duoc mang sap xep

    // vi tri dau tien cua con L
    int i = 0;
    // Vi tri dau tien cua mang con R
    int j = 0;
    // vi tri dau cua mang sau khi hop nhat
    int k = l;

    while (++comp && i < n1 && ++comp && j < n2)
    {
        if (++comp && L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // copy doan con lai cua L neu chua duoc tron vao
    while (++comp && i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    // copy doan con lai cua L neu chua duoc tron vao
    while (++comp && j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

//
void MergeSort(int *a, int l, int r, long long &comp)
{
    if (++comp && l >= r)
    {
        return; // mang da sap xep xong
    }
    int m = (l + r - 1) / 2;
    // chia doi mang lien tuc de tron
    MergeSort(a, l, m, comp);
    MergeSort(a, m + 1, r, comp);
    merge(a, l, m, r, comp);
}

//8.Quick Sort (duoc hoc luc cap 2)
void QuickSort(int *a, int l, int r, long long &comp)
{
    int x = (l + r) / 2;
    int pivot = a[x]; // chon phan tu o giua lam pivot
    int i, j;
    i = l;
    j = r;
    do
    {
        while (++comp && a[i] < pivot)
            i++; // neu nho hon pivot thi xet so ke tiep
        while (++comp && a[j] > pivot)
            j--; // neu lon hon pivot thi lui ve truoc de xet
        if (++comp && i <= j)
        {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (++comp && i < j);
    if (++comp && l < j)
        QuickSort(a, l, j, comp); // goi lai de xet
    if (++comp && i < r)
        QuickSort(a, i, r, comp); // goi lai de xet
}

//9.Counting Sort (Thay Phuong day)
void CountingSort(int *a, int n, long long &comp)
{

    int *b = new int[n];
    int Max = a[0];

    for (int i = 1; ++comp && i < n; i++)
    {
        if (a[i] > Max)
            Max = a[i];
    }

    int *f = new int[Max + 1]{0};

    for (int i = 0; ++comp && i < n; i++)
        f[a[i]]++;

    for (int i = 1; ++comp && i <= Max; i++)
        f[i] += f[i - 1];
    for (int i = n - 1; ++comp && i >= 0; i--)
    {
        b[f[a[i]] - 1] = a[i];
        f[a[i]]--;
    }
    for (int i = 0; ++comp && i < n; i++)
        a[i] = b[i];

    delete[] f;
    delete[] b;
}

//10.Radix Sort (Thay Phuong day)

// lay chu so hang k (don vi: k =1 ..->) . code o phia tren
// int digit(int n, int k)
// {
//     int temp = n % (int)pow(10, k);
//     return temp / pow(10, k - 1);
// }

// CountingSort cua tung chu so cua cac phan tu a
void sort(int a[], int n, int k, long long &comp)
{
    int *b = new int[n];
    int *f = new int[10]{0}; // luu tan xuat cua cac chu so

    for (int i = 0; ++comp && i < n; i++)
        f[digit(a[i], k)]++;

    for (int i = 1; ++comp && i < 10; i++)
        f[i] += f[i - 1];
    for (int i = n - 1; ++comp && i >= 0; i--)
    {
        int temp = digit(a[i], k);
        b[f[temp] - 1] = a[i];
        f[temp]--;
    }
    for (int i = 0; ++comp && i < n; i++)
        a[i] = b[i];

    delete[] f;
    delete[] b;
}

void RadixSort(int a[], int n, long long &comp)
{
    int max = a[0], maxk = 0;
    for (int i = 1; ++comp && i < n; i++)
    {
        if (++comp && max < a[i])
            max = a[i];
    }
    while (++comp && max != 0)
    {
        max = max / 10;
        maxk++;
    }
    for (int i = 1; ++comp && i <= maxk; i++)
        sort(a, n, i, comp);
}

// 11: FlashSort (Thay phuong day)
void FlashSort(int *a, int n, long long &comp)
{
    //Giai doan 1:
    // tu chon so phan lop la (0.43 * n) (thay noi chon nhu nay chay nhanh nhat)
    int Min = a[0];
    int max_pos = 0;
    int m = int(0.43 * n);

    for (int i = 1; ++comp && i < n; i++)
    {
        if (++comp && a[i] < Min)
            Min = a[i];
        if (++comp && a[i] > a[max_pos])
            max_pos = i;
    }

    if (++comp && a[max_pos] == Min)
        return;

    int *L = new int[m];
    for (int i = 0; ++comp && i < m; i++)
        L[i] = 0;

    double Temp = (double)(m - 1) / (a[max_pos] - Min);
    for (int i = 0; ++comp && i < n; i++)
    {
        int k = int(Temp * (a[i] - Min));
        ++L[k];
    }
    for (int i = 1; ++comp && i < m; i++)
        L[i] += L[i - 1];
    swap(a[max_pos], a[0]);
    //Phan vung thu m-1 chi chua max (co the co nhieu a[i] = max)
    //L[k] se chi vao bien ben phai cua phan lop thu k
    //Giai doan 2:
    int j = 0;
    int k = m - 1;
    int cnt = 0;
    int Save = 0;
    while (++comp && cnt < n - 1)
    {
        while (++comp && j > L[k] - 1)
        {
            j++;
            k = int(Temp * (a[j] - Min));
        }
        Save = a[j];
        if (++comp && k < 0)
            break;
        while (++comp && j != L[k])
        {
            k = int(Temp * (Save - Min));
            Swap(Save, a[--L[k]]);
            cnt++;
        }
    }

    //Giai doan 3
    //Phan lop thu m-1 da duoc xap
    //Phan lop k: L[k]->L[k+1]-1
    //dung insertionSort sap thu phai -> trai
    int l, r, mid, tmp;
    for (int i = 1; ++comp && i < n; i++)
    {
        l = 0;
        r = i - 1;
        tmp = a[i];
        while (++comp && l <= r)
        {
            mid = (r + l) / 2;
            if (++comp && a[mid] > tmp)
                r = mid - 1;
            else
                l = mid + 1;
        }
        for (j = i - 1; ++comp && j >= l; j--)
            a[j + 1] = a[j];
        a[l] = tmp;
    }

    delete[] L;
}
// 2 ham nay de tien cho viec dung con tro ham thoi
void QuickSort(int *a, int n, long long &comp)
{
    QuickSort(a, 0, n - 1, comp);
}

void MergeSort(int *a, int n, long long &comp)
{
    MergeSort(a, 0, n - 1, comp);
}
