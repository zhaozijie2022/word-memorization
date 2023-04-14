#pragma once
#ifndef GLOBAL_FUNC_H
#define GLOBAL_FUNC_H
//包含本项目所有需要包含的头文件、库
//其他的头文件和源文件对于库头文件, 只需引用此函数即可
#pragma warning(disable : 4996)//忽略vs为加强安全性将fun改为fun_s的警告
#pragma warning(disable : 4018)//忽略有符号与无符号数比较大小的警告
#pragma execution_character_set("unicode")
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <windows.h>
#include <locale>

using namespace std;

vector<int> creatrand(int num, int m);//生成num个0~m的不重复的随机整数
vector<int> createabcd(int m, int t);//生成3个0~m之间的不重复且不包含t的随机数, 且将t随机插入序列, 向量最后一个变量是t的位置





#endif
