#pragma once
#ifndef WORDLIB_H
#define WORDLIB_H
#include "global_func.h"
/*此头文件中定义了基础词库类
	单词包含拼写,翻译,例句和例句翻译
	提供看词选义,看义选词,看义拼写三种背单词方式
	提供打印词库, 插入和删除单词操作
*/
class word {
public:
	string spell;
	string mean;
	string eg;
	string egmean;
	void disp() {
		cout << spell << endl;
		cout << mean << endl;
		cout << "例句:\t" << eg << endl;
		cout << "\t" << egmean << endl;
	}
	word(string sp = "cosmos", string me = "cosmos", string e = "cosmos", string em = "cosmos") {
		spell = sp; mean = me; eg = e; egmean = em;
	}
	bool operator> (word& b) { return (spell.compare(b.spell) > 0); }
	bool operator==(word& b) { return (spell.compare(b.spell) == 0); }
	bool operator< (word& b) { return (spell.compare(b.spell) < 0); }
	bool operator<=(word& b) { return (spell.compare(b.spell) <= 0); }
	bool operator>=(word& b) { return (spell.compare(b.spell) <= 0); }
};

class wordlib {
public:
	vector<word> lib;
	void readlib(string target = "stdlib.txt");//从文本中读取词库
	void writelib(string target = "std_out.txt");//向目标文件中写入
	void sortlib();//从a~z对词库排序
	void printlib();
	int search(string target);
	void del(int idx);//idx为索引,从0开始
	void check(int mode, int num);//用mode模式背num个单词
};











#endif
