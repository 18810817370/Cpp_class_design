#include <iostream> 
#include <windows.h>
#include "Course.h"
#include "Student.h"
using namespace std;
int main()
{
	Linked_Courses L;
	char select;
	do
	{
		cout << "0.初始化课程链表" << endl;
		cout << "1.创建新课程" << endl;
		cout << "2.显示全部链表内课程" << endl;
		cout << "3.查找课程 " << endl;
		cout << "4.删除课程" << endl;
		cout << "5.修改课程" << endl;
		cout << "E.进入学生管理系统" << endl;
		cout << "Q.退出" << endl << endl;
		cin >> select;
		switch (select)
		{
		case '0':
			L.Init();
			break;
		case '1':
			L.Into_Linked_Courses();
			break;
		case '2':
			L.Display();
			break;
		case '3':
			L.Searche_Courses();
			break;
		case '4':
			L.Delete();
			break;
		case '5':
			L.Courses_Modify();
			break;
		case 'E':
			break;
		case 'Q':
			break;
		default:
			cout << "输入错误请重新输入" << endl;
			break;
		}
		Sleep(500);
		system("cls");
	} while (select != 'E' && select != 'Q');
	if (select == 'E')
	{
		Linked_Students S;
		S.Init();
		do
		{
			cout << "0.初始化学生链表" << endl;
			cout << "1.添加新学生信息" << endl;
			cout << "2.显示全部链表内所有学生信息" << endl;
			cout << "3.查找学生信息" << endl;
			cout << "4.删除学生信息" << endl;
			cout << "5.修改学生信息" << endl;
			cout << "6.显示可选课程" << endl;
			cout << "Q.退出" << endl << endl;
			cin >> select;
			switch (select)
			{
			case '0':
				S.Init();
				break;
			case '1':
				S.Into_Linked_Students(L);
				break;
			case '2':
				S.Display();
				break;
			case '3':
				S.Searche_Stuents();
				break;
			case '4':
				S.Delete();
				break;
			case '5':
				S.Students_Modify(L);
				break;
			case '6':
				L.Display();
			case 'Q':
				break;
			default:
				cout << "输入错误请重新输入" << endl;
				break;
			}
			Sleep(500);
			system("cls");
		} while (select != 'Q');
	}
	return 0;
}