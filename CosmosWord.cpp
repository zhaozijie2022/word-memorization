#include "global_func.h"
#include "wordlib.h"

#include<stdio.h>
struct Student
{
	int num;
	int score;
	char name[20];

}student[5];
void input(struct Student* p)
{
	int i;
	printf_s("请按 学号，分数，姓名格式输入数据如：20200101，99，ZhangSan\n");
	for (i = 0; i <= 4; i++)
	{
		printf_s("请输入下一组数据。\n");
		scanf_s("%d,%d,%s", &p->num, &p->score, (*p).name, 20);
		p++;
	}
}
void output(struct Student* p)
{
	int i;
	for (i = 0; i < 5; i++)
		printf("NO. % d\tname: % s \tscore: % d\n", (p + i)->num, (p + i)->name, (p + i)->score);
}
/*int main()
{
	input(student);
	output(student);
	return 0;
}*/


/*int main() {
	setconsoleoutputcp(65001);
	cout << "***welcome to cosmos word***" << endl;
	cout << "正在读取词库..." << endl;
	wordlib nowlib;
	nowlib.readlib();
	int mode = 1;
	while (mode != 4) {
		cout << "请选择功能..." << endl;
		cout << "1.打印词库\n2.查询单词\n3.背单词\n4.退出系统" << endl;
		cin >> mode;
		while (mode > 4 || mode < 1) {
			cout << "输入有误,请重新输入!" << endl;
			cin >> mode;
		}
		switch (mode) {
		case 1: {nowlib.printlib(); break; }
		case 2: {
			wstring target;
			cout << "请输入你想查询的单词" << endl;
			wcin >> target;
			int w = nowlib.search(target);
			if (-1 == w) cout << "查询单词不在词库" << endl << endl;
			else { cout << endl; nowlib.lib[w].disp(); cout << endl; }
			break;
		}
		case 3: {
			int mode1, num;
			cout << "请选择背单词模式" << endl;
			cout << "1.看词选义\t2.看义选词\t3.看义拼写" << endl;
			cin >> mode1;
			while (mode1 > 3 || mode1 < 1) {
				cout << "输入有误,请重新输入!" << endl;
				cin >> mode1;
			}
			cout << "请选择背单词的个数, 当前词库单词总数为:" << nowlib.lib.size() << endl;;
			cin >> num;
			while (num > nowlib.lib.size()) {
				cout << "输入有误,请重新输入!" << endl;
				cin >> num;
			}
			nowlib.check(mode1, num);
		}
		}
	}

}*/