#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Sort.h"
#include "Time.h"
#include "dataGenerator.h"
using namespace std;

// chuyen chuoi sang con tro ham sort
//loai 1: chi dung tinh thoi gian so sanh
typedef void (*Sort)(int *, int);
Sort StringToFunc1(const string &s);
// loai 2: co yeu cau tinh so phep so sanh
typedef void (*Sort_Comp)(int *, int, long long &);
Sort_Comp StringToFunc2(const string &s);

// chuyen loai data built tu chuoi ve so nguyen
int TypeData(const string &s);

// chuyen loai da ta thanh ten tuong ung
string TypeDataToString(int type);

// chuyen chuoi thanh so
int StringToInt(const string &s);

// in thoi gian chay hoac so phep so sanh hoac ca 2
void PrintTime_Comp(int *a, int n, string TypePrint, string SortFunc);

// kiem tra thuat toan nhap vao co dung ten khong
bool CheckAlgorithms(string SortFunc);

// xu ly cac loai nhap comand line
// loai 1: 1 thuat toan
void Algorithms_mode(vector<string> &command);

// loai 2: chay 2 thuat toan
void Comparison_mode(vector<string> &command);

// ham xu ly tat ca va xuat ket qua
void Process(vector<string> &command);

// ham tro giup nhap comand line
// cu phap [tenchuongtrinh] help
void Help();