#include "wordlib.h"

void wordlib::readlib(string target) {
	lib.clear();
	ifstream infile(target);
	string wordline;
	vector<string> temp;
	word w;
	while (getline(infile, wordline)) //���ж�ȡ�ַ��� 
	{
		temp.push_back(wordline);
		while (getline(infile, wordline)) {
			if ("" == wordline)  break;
			temp.push_back(wordline);
		}
		w = word(temp[0], temp[1], temp[2], temp[3]);
		lib.push_back(w);
		temp.clear();
	}
}

void wordlib::writelib(string target) {
	ofstream outfile(target);
	int n = lib.size();
	for (int i = 0; i < n; i++) {
		outfile << lib[i].spell << endl << lib[i].mean << \
			endl << lib[i].eg << endl << lib[i].egmean << endl << endl;
	}
	outfile.close();
}

void wordlib::sortlib() {
	sort(lib.begin(), lib.end());
}

void wordlib::printlib() {
	cout << "********************��ʼ��ӡ�ʿ�********************" << endl;
	int nums = lib.size();
	for (int i = 0; i < nums; i++) {
		lib[i].disp();
	}
	cout << "********************��ӡ�ʿ����********************" << endl << endl;
}

int  wordlib::search(string target) {
	//�ʵ�ʹ��a~z��˳���ŵ���,���ַ�����С�����˳��,��������ָ������
	int a = 0, b = lib.size() - 1;
	int flag, pos;
	while (a <= b) {
		pos = (a + b) / 2;
		flag = target.compare(lib[pos].spell);
		if (0 == flag)
			return pos;
		else if (0 < flag) //����,str1��
			a = (a + b) / 2 + 1;
		else if (0 > flag) //����,str1С
			b = (a + b) / 2 - 1;
	}
	return -1;
}

void wordlib::del(int idx) {
	lib.erase(lib.begin() + idx);
}

void wordlib::check(int mode, int num) {
	queue<int> q;//���ڴ��Ҫ���ĵ����ڴʿ��е���ŵĶ���
	vector<int> p = creatrand(num, lib.size());//���ѡ��num��Ҫ���Ĳ��ظ��ĵ���
	vector<int> wrong;//���ڴ�Ŵ���ϰ�����ŵ�����
	word tmp;//��ǰ���ڱ��ĵ���
	int noww = 0;//now word ��ǰ���ڴʿ��е����

	for (int i = 0; i < num; i++)//��num�����������
		q.push(p[i]);

	switch (mode) {//3ģʽ������
	case 1: {//����ѡ��
		int sel;
		while (!q.empty()) {
			noww = q.front();
			tmp = lib[noww];//ȡ����һ������
			vector<int> res = createabcd(lib.size(), noww);//����ѡ��,ǰ�ĸ�Ϊ0~�ʿ��С���������,���һ����0~3֮���һ����,����ȷ�����ڵ�����
			cout << "�������������ƴдѡ����ȷ����: " << tmp.spell << endl;
			cout << "1." << lib[res[0]].mean << "\t2." << lib[res[1]].mean << \
				"\t3." << lib[res[2]].mean << "\t4." << lib[res[3]].mean << endl;
			cin >> sel;
			if (sel != (res[4] + 1)) {//��������Ϊ˳��
				cout << "ѡ�����, ��ȷ��Ϊ: " << endl;
				lib[noww].disp();
				cout << endl;
				q.push(noww);//����һ��, ��Ҫ����������Լ���ӡ��
				bool found = false;
				for (int i = 0; i < wrong.size(); i++) {
					if (noww == wrong[i]) {
						found = true;
						break;
					}
				}
				if (!found)
					wrong.push_back(noww);
			}
			q.pop();//������һ������
		}
		break;
	}
	case 2: {//����ѡ��
		int sel;
		while (!q.empty()) {
			noww = q.front();
			tmp = lib[noww];//ȡ����һ������
			vector<int> res = createabcd(lib.size(), noww);//����ѡ��,ǰ�ĸ�Ϊ0~�ʿ��С���������,���һ����0~3֮���һ����,����ȷ�����ڵ�����
			cout << "�����������������ѡ����ȷƴд: " << tmp.mean << endl;
			cout << "1." << lib[res[0]].spell << "\t2." << lib[res[1]].spell << \
				"\t3." << lib[res[2]].spell << "\t4." << lib[res[3]].spell << endl;
			cin >> sel;
			if (sel != (res[4] + 1)) {//��������Ϊ˳��
				cout << "ѡ�����, ��ȷ��Ϊ: " << endl;
				lib[noww].disp();
				cout << endl;
				bool found = false;
				for (int i = 0; i < wrong.size(); i++) {
					if (noww == wrong[i]) {
						found = true;
						break;
					}
				}
				if (!found)
					wrong.push_back(noww);
			}
			q.pop();//������һ������
		}
		break;
	}
	case 3: {//����ƴд
		string sel;
		while (!q.empty()) {
			noww = q.front();
			tmp = lib[noww];//ȡ����һ������
			cout << "������������������ȷƴд: " << tmp.mean << endl;
			cin >> sel;
			if (sel.compare(tmp.spell)) {
				cout << "ƴд����, ��ȷ��Ϊ: " << endl;
				lib[noww].disp();
				cout << endl;
				q.push(noww);//����һ��, ��Ҫ������һ�������Լ���ӡ��

				bool found = false;
				for (int i = 0; i < wrong.size(); i++) {
					if (noww == wrong[i]) {
						found = true;
						break;
					}
				}
				if (!found)
					wrong.push_back(noww);
			}
			else {
				cout << "ƴд��ȷ: " << endl;
				lib[noww].disp();
				cout << endl;
			}
			q.pop();//������һ������
		}
		break;
	}
	}

	cout << "******�������ܽ�******" << endl;
	cout << "�����һ��������" << num << "��,һ����ȷ" << num - wrong.size() << "��" << endl;
	cout << "����" << wrong.size() << "��, ���󵥴�Ϊ: " << endl;
	for (int i = 0; i < wrong.size(); i++) {
		cout << lib[wrong[i]].spell << "\t";
		if (i % 5 == 0)	cout << endl;
	}cout << endl;
	cout << "��������˳����α�����" << endl;
	getchar();
}



