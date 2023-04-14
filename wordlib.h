#pragma once
#ifndef WORDLIB_H
#define WORDLIB_H
#include "global_func.h"
/*��ͷ�ļ��ж����˻����ʿ���
	���ʰ���ƴд,����,��������䷭��
	�ṩ����ѡ��,����ѡ��,����ƴд���ֱ����ʷ�ʽ
	�ṩ��ӡ�ʿ�, �����ɾ�����ʲ���
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
		cout << "����:\t" << eg << endl;
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
	void readlib(string target = "stdlib.txt");//���ı��ж�ȡ�ʿ�
	void writelib(string target = "std_out.txt");//��Ŀ���ļ���д��
	void sortlib();//��a~z�Դʿ�����
	void printlib();
	int search(string target);
	void del(int idx);//idxΪ����,��0��ʼ
	void check(int mode, int num);//��modeģʽ��num������
};











#endif
