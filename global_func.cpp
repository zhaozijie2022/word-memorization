#include "global_func.h"

vector<int> creatrand(int num, int m) {
	srand(time(NULL));
	vector<int> p;
	int tmp;
	bool b;
	for (int i = 0; i < num; i++) {
		tmp = rand() % m;
		b = true;
		for (int j = 0; j < i; j++)
			if (tmp == p[j]) { i--; b = false; break; }
		if (b)
			p.push_back(tmp);
	}
	return p;
}

vector<int> createabcd(int m, int t) {
	srand(time(NULL));
	vector<int> p;
	int tmp, pos;
	bool b;
	for (int i = 0; i < 3; i++) {
		do {
			tmp = rand() % m;
		} while (tmp == t);
		b = true;
		for (int j = 0; j < i; j++)
			if (tmp == p[j]) { i--; b = false; break; }
		if (b)
			p.push_back(tmp);;
	}
	pos = rand() % 4;//生成选项所在的位置
	p.insert(p.begin() + pos, t);
	p.push_back(pos);
	return p;
}















