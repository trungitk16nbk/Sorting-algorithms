#include "Command.h"

// loai 1: chuyen chuoi thanh ham sap xep tuong ung
typedef void (*Sort)(int *, int);
Sort StringToFunc1(const string &s)
{
    if (s == "selection-sort")
        return SelectionSort;
    if (s == "insertion-sort")
        return InsertionSort;
    if (s == "bubble-sort")
        return BubbleSort;
    if (s == "shaker-sort")
        return ShakerSort;
    if (s == "shell-sort")
        return ShellSort;
    if (s == "heap-sort")
        return HeapSort;
    if (s == "merge-sort")
        return MergeSort;
    if (s == "quick-sort")
        return QuickSort;
    if (s == "counting-sort")
        return CountingSort;
    if (s == "radix-sort")
        return RadixSort;
    if (s == "flash-sort")
        return FlashSort;

    return nullptr;
}

// loai 2: chuyen chuoi thanh ham sap xep va tinh so sanh tuong ung
typedef void (*Sort_Comp)(int *, int, long long &);
Sort_Comp StringToFunc2(const string &s)
{
    if (s == "selection-sort")
        return SelectionSort;
    if (s == "insertion-sort")
        return InsertionSort;
    if (s == "bubble-sort")
        return BubbleSort;
    if (s == "shaker-sort")
        return ShakerSort;
    if (s == "shell-sort")
        return ShellSort;
    if (s == "heap-sort")
        return HeapSort;
    if (s == "merge-sort")
        return MergeSort;
    if (s == "quick-sort")
        return QuickSort;
    if (s == "counting-sort")
        return CountingSort;
    if (s == "radix-sort")
        return RadixSort;
    if (s == "flash-sort")
        return FlashSort;

    return nullptr;
}

// chuyen loai data built tu chuoi ve so nguyen
int TypeData(const string &s)
{
    if (s == "-rand")
        return 0;
    if (s == "-sorted")
        return 1;
    if (s == "-rev")
        return 2;
    if (s == "-nsorted")
        return 3;
    return -1;
}

// chuyen chuoi thanh so
int StringToInt(const string &s)
{
    bool check = true;
    int Num = 0;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] >= '0' && s[i] <= '9')
        {
            Num = Num * 10 + (int)(s[i] - '0');
        }
        else
        {
            check = false;
            break;
        }

    if (check)
        return Num;
    return -1;
}

// chuyen loai da ta thanh ten tuong ung
string TypeDataToString(int type)
{
    switch (type)
    {
    case 0:
        return "Randomize";
    case 1:
        return "Sorted";
    case 2:
        return "Reverse-Sorted";
    case 3:
        return "Nearly-Sorted";
    }
    return "";
}

// in thoi gian chay hoac so phep so sanh hoac ca 2
void PrintTime_Comp(int *a, int n, string TypePrint, string SortFunc)
{
    if (TypePrint == "-time")
    {
        void (*_Sort)(int *, int) = StringToFunc1(SortFunc);
        cout << "Running time: " << TimeExecutionSortFunction(a, n, _Sort) << endl;
    }
    else
    {
        long long comp = 0;
        void (*_Sort)(int *, int, long long &) = StringToFunc2(SortFunc);
        double Time = TimeExecutionAndCompareSortFunction(a, n, comp, _Sort);

        if (TypePrint == "-comp")
            cout << "Comparisions: " << comp << endl;
        else
        {
            cout << "Running time: " << Time << endl;
            cout << "Comparisions: " << comp << endl;
        }
    }
}

// kiem tra thuat toan nhap vao co dung ten khong
bool CheckAlgorithms(string SortFunc)
{

    void (*_Sort)(int *, int) = StringToFunc1(SortFunc);
    if (!_Sort)
    {
        cout << "Algorithm not found!!!!" << endl;
        return false;
    }

    return true;
}

void Algorithms_mode(vector<string> &command)
{
    cout << "ALGORITHM MODE" << '\n';
    int size_cmd = command.size();

    if (size_cmd == 6) // Command 2
    {
        ofstream fi("input.txt", ios::out); // luu du lieu sau khi sinh
        int n = StringToInt(command[3]);
        fi << n << endl; // luu so phan tu

        int *a = new int[n];
        GenerateData(a, n, TypeData(command[4]));
        for (int i = 0; i < n; ++i)
            fi << a[i] << " "; // ;luu phan tu

        fi.close();

        if (!CheckAlgorithms(command[2]))
        {
            cout << "Pls Try " << command[0] << " --help for get more infomation!" << endl;
            delete[] a;
            return;
        }

        cout << "Algorthm: " << command[2] << endl;
        cout << "Input size: " << n << endl;
        cout << "Input order: ";

        int type = TypeData(command[4]);
        if (type == -1)
        {
            cout << "Error: unknown data type!\n";
            cout << "Pls Try " << command[0] << " --help for get more infomation!" << endl;
            delete[] a;
            return;
        }
        ofstream fo("output.txt", ios::out); // luu ket qua sau khi sap xep
        cout << TypeDataToString(type) << endl;
        cout << "----------------------------\n";
        PrintTime_Comp(a, n, command[5], command[2]);
        for (int i = 0; i < n; ++i)
            fo << a[i] << " "; // luu ket qua

        fo.close();
        delete[] a;
    }
    else if (size_cmd == 5) // command 1 or command 3
    {
        int n = StringToInt(command[3]);
        if (n != -1) // command 3
        {
            int *a = new int[n];

            if (!CheckAlgorithms(command[2]))
            {
                cout << "Pls Try " << command[0] << " --help for get more infomation!" << endl;
                delete[] a;
                return;
            }
            cout << "Algorthm: " << command[2] << endl;
            cout << "Input size: " << n << endl;

            string s = "input_";
            int type = 0;
            while (type < 4)
            {
                int kk = 1;
                if (type == 1)
                    kk = 3;
                if (type == 2)
                    kk = 4;
                if (type == 3)
                    kk = 2;
                string ss = s + to_string(kk) + ".txt";
                ofstream fi(ss, ios::out);

                fi << n << endl;
                GenerateData(a, n, type);
                for (int i = 0; i < n; ++i)
                    fi << a[i] << " ";
                fi.close();

                cout << "Input order: " << TypeDataToString(type) << endl;
                cout << "--------------------------\n";
                PrintTime_Comp(a, n, command[4], command[2]);
                cout << endl;
                type++;
            }
            delete[] a;
        }
        else // command 1
        {
            ifstream fi;
            fi.open(command[3], ios::in);
            fi >> n;
            int *a = new int[n];
            for (int i = 0; i < n; ++i)
                fi >> a[i];
            fi.close();

            if (!CheckAlgorithms(command[2]))
            {
                cout << "Pls Try " << command[0] << " --help for get more infomation!" << endl;
                delete[] a;
                return;
            }
            ofstream fo("output.txt", ios::out); // luu ket qua sau khi sap xep
            cout << "Algorthm: " << command[2] << endl;
            cout << "Input file: " << command[3] << endl;
            cout << "Input size: " << n << endl;
            cout << "--------------------\n";
            PrintTime_Comp(a, n, command[4], command[2]);
            for (int i = 0; i < n; ++i)
                fo << a[i] << " ";
            fo.close();
            delete[] a;
        }
    }
    else
        cout << "Input Errol!!!!\n";
}

// loai 2: chay 2 thuat toan
void Comparison_mode(vector<string> &command)
{
    cout << "COMPARE MODE" << '\n';
    int size_cmd = command.size();
    if (size_cmd == 5) // command 4
    {
        if (!CheckAlgorithms(command[2]) || !CheckAlgorithms(command[3]))
        {
            cout << "Pls Try " << command[0] << " --help for get more infomation!" << '\n';
            return;
        }

        int n;
        ifstream fi;
        fi.open(command[4], ios::in);
        fi >> n;
        int *a = new int[n];
        for (int i = 0; i < n; ++i)
            fi >> a[i];
        fi.close();

        cout << "Algorthm: " << command[2] << " | " << command[3] << endl;
        cout << "Input file: " << command[4] << endl;
        cout << "Input size: " << n << endl;
        cout << "--------------------\n";

        double Time1, Time2;
        long long comp1 = 0, comp2 = 0;
        int *b;
        CopyArray(a, b, n);
        void (*_Sort1)(int *, int, long long &) = StringToFunc2(command[2]);
        Time1 = TimeExecutionAndCompareSortFunction(b, n, comp1, _Sort1);

        void (*_Sort2)(int *, int, long long &) = StringToFunc2(command[3]);
        Time2 = TimeExecutionAndCompareSortFunction(a, n, comp2, _Sort2);

        cout << "Running time: " << Time1 << " | " << Time2 << endl;
        cout << "Comparisions: " << comp1 << " | " << comp2 << endl;

        delete[] b;
        delete[] a;
    }
    else if (size_cmd == 6) // command 5
    {
        if (!CheckAlgorithms(command[2]) || !CheckAlgorithms(command[3]))
        {
            cout << "Pls Try " << command[0] << " --help for get more infomation!" << endl;
            return;
        }

        int n = StringToInt(command[4]);
        int *a = new int[n];
        int type = TypeData(command[5]);

        cout << "Algorthm: " << command[2] << " | " << command[3] << endl;
        cout << "Input size: " << n << endl;
        cout << "Input order: " << TypeDataToString(type) << endl;
        cout << "-----------------------\n";
        ofstream fi("input.txt", ios::out);
        fi << n << endl;
        GenerateData(a, n, type);
        for (int i = 0; i < n; ++i)
            fi << a[i] << " ";
        fi.close();

        double Time1, Time2;
        long long comp1 = 0, comp2 = 0;
        int *b;
        CopyArray(a, b, n);
        void (*_Sort1)(int *, int, long long &) = StringToFunc2(command[2]);
        Time1 = TimeExecutionAndCompareSortFunction(b, n, comp1, _Sort1);

        void (*_Sort2)(int *, int, long long &) = StringToFunc2(command[3]);
        Time2 = TimeExecutionAndCompareSortFunction(a, n, comp2, _Sort2);

        cout << "Running time: " << Time1 << " | " << Time2 << endl;
        cout << "Comparisions: " << comp1 << " | " << comp2 << endl;

        delete[] b;
        delete[] a;
    }
    else
        cout << "Input Errol \n";
}

// ham xu ly tat ca va xuat ket qua
void Process(vector<string> &command)
{
    if (command[1] == "-a")
        Algorithms_mode(command);
    if (command[1] == "-c")
        Comparison_mode(command);
}

// ham tro giup nhap comand line
// cu phap [tenchuongtrinh] help
void Help()
{
    fstream f("help.txt", ios::in);
    string s;

    while (!f.eof())
    {
        getline(f, s);
        cout << s << endl;
    }
    f.close();
}
