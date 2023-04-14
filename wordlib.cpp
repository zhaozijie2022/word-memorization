#include "wordlib.h"

void wordlib::readlib(string target) {
	lib.clear();
	ifstream infile(target);
	string wordline;
	vector<string> temp;
	word w;
	while (getline(infile, wordline)) //按行读取字符串 
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
	cout << "********************开始打印词库********************" << endl;
	int nums = lib.size();
	for (int i = 0; i < nums; i++) {
		lib[i].disp();
	}
	cout << "********************打印词库完毕********************" << endl << endl;
}

int  wordlib::search(string target) {
	//词典使用a~z的顺序存放单词,即字符串由小到大的顺序,二分搜索指定单词
	int a = 0, b = lib.size() - 1;
	int flag, pos;
	while (a <= b) {
		pos = (a + b) / 2;
		flag = target.compare(lib[pos].spell);
		if (0 == flag)
			return pos;
		else if (0 < flag) //正数,str1大
			a = (a + b) / 2 + 1;
		else if (0 > flag) //负数,str1小
			b = (a + b) / 2 - 1;
	}
	return -1;
}

void wordlib::del(int idx) {
	lib.erase(lib.begin() + idx);
}

void wordlib::check(int mode, int num) {
	queue<int> q;//用于存放要背的单词在词库中的序号的队列
	vector<int> p = creatrand(num, lib.size());//随机选择num个要背的不重复的单词
	vector<int> wrong;//用于存放错误习题的序号的向量
	word tmp;//当前正在背的单词
	int noww = 0;//now word 当前词在词库中的序号

	for (int i = 0; i < num; i++)//将num个单词入队列
		q.push(p[i]);

	switch (mode) {//3模式背单词
	case 1: {//看词选义
		int sel;
		while (!q.empty()) {
			noww = q.front();
			tmp = lib[noww];//取出第一个单词
			vector<int> res = createabcd(lib.size(), noww);//生成选项,前四个为0~词库大小的随机索引,最后一个是0~3之间的一个数,是正确答案所在的索引
			cout << "请根据所给单词拼写选出正确释义: " << tmp.spell << endl;
			cout << "1." << lib[res[0]].mean << "\t2." << lib[res[1]].mean << \
				"\t3." << lib[res[2]].mean << "\t4." << lib[res[3]].mean << endl;
			cin >> sel;
			if (sel != (res[4] + 1)) {//把索引变为顺序
				cout << "选择错误, 正确答案为: " << endl;
				lib[noww].disp();
				cout << endl;
				q.push(noww);//错误一次, 都要重新入队列以加深印象
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
			q.pop();//弹出第一个单词
		}
		break;
	}
	case 2: {//看义选词
		int sel;
		while (!q.empty()) {
			noww = q.front();
			tmp = lib[noww];//取出第一个单词
			vector<int> res = createabcd(lib.size(), noww);//生成选项,前四个为0~词库大小的随机索引,最后一个是0~3之间的一个数,是正确答案所在的索引
			cout << "请根据所给单词释义选出正确拼写: " << tmp.mean << endl;
			cout << "1." << lib[res[0]].spell << "\t2." << lib[res[1]].spell << \
				"\t3." << lib[res[2]].spell << "\t4." << lib[res[3]].spell << endl;
			cin >> sel;
			if (sel != (res[4] + 1)) {//把索引变为顺序
				cout << "选择错误, 正确答案为: " << endl;
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
			q.pop();//弹出第一个单词
		}
		break;
	}
	case 3: {//看义拼写
		string sel;
		while (!q.empty()) {
			noww = q.front();
			tmp = lib[noww];//取出第一个单词
			cout << "请根据所给释义给出正确拼写: " << tmp.mean << endl;
			cin >> sel;
			if (sel.compare(tmp.spell)) {
				cout << "拼写错误, 正确答案为: " << endl;
				lib[noww].disp();
				cout << endl;
				q.push(noww);//错误一次, 都要重新入一个队列以加深印象

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
				cout << "拼写正确: " << endl;
				lib[noww].disp();
				cout << endl;
			}
			q.pop();//弹出第一个单词
		}
		break;
	}
	}

	cout << "******背单词总结******" << endl;
	cout << "您这次一共背单词" << num << "个,一次正确" << num - wrong.size() << "个" << endl;
	cout << "错误" << wrong.size() << "次, 错误单词为: " << endl;
	for (int i = 0; i < wrong.size(); i++) {
		cout << lib[wrong[i]].spell << "\t";
		if (i % 5 == 0)	cout << endl;
	}cout << endl;
	cout << "按任意键退出本次背单词" << endl;
	getchar();
}



