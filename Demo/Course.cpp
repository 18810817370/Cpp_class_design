#include "Course.h"
#include <string>
#include <iostream>
using namespace std;


Course::Course()
{
}


Course::~Course()
{
}

void Course::Input()
{
	cout << "请输入课程编号:";
	cin >> Course_Code;
	cout << "请输入课程名称:";
	cin >> Course_Name;
	do
	{
		cout << "请选择课程类型:a.通识课、b.专业基础课、c.专业课" << endl;
		cin >> Course_Type;
		if (Course_Type == 'a' || Course_Type == 'A' || Course_Type == 'b' || Course_Type == 'B' || Course_Type == 'c' || Course_Type == 'C')
			break;
		else
			cout << "输入错误，请重新输入" << endl;
	} while (1);
	cout << "请输入授课教师:";
	cin >> Course_Teacher;
	cout << "请输入课程学时:";
	cin >> Course_Time;
	cout << "请输入课程学分:";
	cin >> Course_Unit;
}


void Course::Modify()
{
	cout << endl;
	cout << "请选择要修改的内容:" << endl;
	cout << "1.课程编号" << endl;
	cout << "2.课程名称" << endl;
	cout << "3.课程类型" << endl;
	cout << "4.授课教师" << endl;
	cout << "5.课程学时" << endl;
	cout << "6.课程学分" << endl;
	cout << endl;
	char a;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "请输入课程编号:";
		cin >> Course_Code;
		break;
	case '2':
		cout << "请输入课程名称:";
		cin >> Course_Name;
		break;
	case '3':
		do
		{
			cout << "请选择课程类型:a.通识课、b.专业基础课、c.专业课" << endl;
			cin >> Course_Type;
			if (Course_Type == 'a' || Course_Type == 'A' || Course_Type == 'b' || Course_Type == 'B' || Course_Type == 'c' || Course_Type == 'C')
				break;
			else
				cout << "输入错误，请重新输入" << endl;
		} while (1);
		break;
	case '4':
		cout << "请输入授课教师:";
		cin >> Course_Teacher;
		break;
	case '5':
		cout << "请输入课程学时:";
		cin >> Course_Time;
		break;
	case '6':
		cout << "请输入课程学分:";
		cin >> Course_Unit;
		break;
	default:
		break;
	}

}


void LNode_Course::Display()
{
	cout << endl;
	cout << "课程编号:" << get_Course_Code() << endl;
	cout << "课程名称:" << get_Course_Name() << endl;
	cout << "课程类型:";
	switch (get_Course_type())
	{
	case'a':
	case'A':
		cout << "通识课" << endl;
		break;
	case'b':
	case'B':
		cout << "专业基础课" << endl;
		break;
	case'c':
	case'C':
		cout << "专业课" << endl;
		break;
	default:
		break;
	}
	cout << "授课教师:" << get_Course_Teacher() << endl;
	cout << "课程学时:" << get_Course_Time() << endl;
	cout << "课程学分:" << get_Course_Unit() << endl;
	cout << endl;
}


bool LNode_Course::select()
{
	char Confirm;
	cout << "是否选择这门课(Y/N)" << endl;
	cin >> Confirm;
	do
	{
		if (Confirm == 'Y' || Confirm == 'y')
		{
			return true;
		}
		else if (Confirm == 'N' || Confirm == 'n')
		{
			return false;
		}
		else
			cout << "输入错误，请重新输入" << endl;
	} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
}


void LNode_Course::Copy(LNode_Course*&p)
{
	input_Course_Code(p->get_Course_Code());
	input_Course_Name(p->get_Course_Name());
	input_Course_Teacher(p->get_Course_Teacher());
	input_Course_Time(p->get_Course_Time());
	input_Course_Unit(p->get_Course_Unit());
	input_Course_type(p->get_Course_type());
}

void Linked_Courses::Init()
{
	cout << endl;
	LNode_Course *p;
	while (head != NULL)
	{
		p = head;
		head = p->next;
		delete p;
	}
	cout << "初始化完成" << endl;
	cout << endl;
}


void Linked_Courses::Into_Linked_Courses()
{
	cout << endl;
	LNode_Course *p = new LNode_Course;
	if (head == NULL)
	{
		head = p;
		rear = p;
	}
	else
	{
		rear->next = p;
	}	
	p->Input();
	rear = p;
	cout << endl;
}


void Linked_Courses::Searche_Courses()
{
	LNode_Course *p;
	char a, search[10], type;
	int s, i(0);
	cout << endl;
	cout << "1.按课程编号搜索" << endl;
	cout << "2.按课程名称搜索" << endl;
	cout << "3.按课程类型搜索" << endl;
	cout << "4.按授课教师搜索" << endl;
	cout << "5.按课程学时搜索" << endl;
	cout << "6.按课程学分搜索" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "请输入要搜索课程编号:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Code(), search))
			{
				p->Display();
				i++;
			}
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '2':
		cout << "请输入要搜索课程名称:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Name(), search))
			{	
				p->Display();
				i++;
			}
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '3':
		cout << "请输入要搜索的课程类型:a.通识课、b.专业基础课、c.专业课" << endl;
		cin >> type;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_type() == type)
			{
				p->Display();
				i++;
			}	
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '4':
		cout << "请输入要搜索课程的授课教师:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Teacher(), search))
			{
				p->Display();
				i++;
			}	
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '5':
		cout << "请输入要搜索课程学时:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Time() == s)
			{
				p->Display();
				i++;
			}	
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '6':
		cout << "请输入要搜索课程学分:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Unit() == s)
			{
				p->Display();
				i++;
			}	
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		break;
	}
}


void Linked_Courses::Display()
{
	cout << endl;
	LNode_Course *p = head;
	int i(0);
	while (p != NULL)
	{
		p->Display();
		i++;
		p = p->next;
	}
	if (i == 0)
		cout << "没有课程" << endl;
	cout << endl;
}


void Linked_Courses::Delete()
{
	LNode_Course *p, *o = NULL;
	char a, search[10], Confirm, type;
	int s, i(0);
	cout << endl;
	cout << "1.按课程编号删除" << endl;
	cout << "2.按课程名称删除" << endl;
	cout << "3.按课程类型删除" << endl;
	cout << "4.按授课教师删除" << endl;
	cout << "5.按课程学时删除" << endl;
	cout << "6.按课程学分删除" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "请输入要删除课程编号:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Code(), search))
			{
				p->Display();
				i++;
				cout << "是否确认删除(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						if (p == head)
						{
							head = p->next;
							delete p;
							p = head;
						}
						else
						{
							o->next = p->next;
							delete p;
							p = o;
						}
						cout << "删除成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消删除此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '2':
		cout << "请输入要删除课程名称:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Name(), search))
			{
				p->Display();
				i++;
				cout << "是否确认删除(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						if (p == head)
						{
							head = p->next;
							delete p;
							p = head;
						}
						else
						{
							o->next = p->next;
							delete p;
							p = o;
						}
						cout << "删除成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消删除此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '3':
		cout << "请输入要删除的课程类型:a.通识课、b.专业基础课、c.专业课" << endl;
		cin >> type;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_type() == type)
			{
				p->Display();
				i++;
				cout << "是否确认删除(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						if (p == head)
						{
							head = p->next;
							delete p;
							p = head;
						}
						else
						{
							o->next = p->next;
							delete p;
							p = o;
						}
						cout << "删除成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消删除此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '4':
		cout << "请输入要删除课程的授课教师:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Teacher(), search))
			{
				p->Display();
				i++;
				cout << "是否确认删除(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						if (p == head)
						{
							head = p->next;
							delete p;
							p = head;
						}
						else
						{
							o->next = p->next;
							delete p;
							p = o;
						}
						cout << "删除成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消删除此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '5':
		cout << "请输入要删除课程学时:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Time() == s)
			{
				p->Display();
				i++;
				cout << "是否确认删除(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						if (p == head)
						{
							head = p->next;
							delete p;
							p = head;
						}
						else
						{
							o->next = p->next;
							delete p;
							p = o;
						}
						cout << "删除成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消删除此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '6':
		cout << "请输入要删除课程学分:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Unit() == s)
			{
				p->Display();
				i++;
				cout << "是否确认删除(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						if (p == head)
						{
							head = p->next;
							delete p;
							p = head;
						}
						else
						{
							o->next = p->next;
							delete p;
							p = o;
						}
						cout << "删除成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消删除此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		break;
	}
	cout << endl;
}


void Linked_Courses::Courses_Modify()
{
	LNode_Course *p;
	char a, search[10], Confirm, type;
	int s, i(0);
	cout << endl;
	cout << "1.按课程编号搜索修改" << endl;
	cout << "2.按课程名称搜索修改" << endl;
	cout << "3.按课程类型搜索修改" << endl;
	cout << "4.按授课教师搜索修改" << endl;
	cout << "5.按课程学时搜索修改" << endl;
	cout << "6.按课程学分搜索修改" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "请输入要修改课程编号:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Code(), search))
			{
				p->Display();
				i++;
				cout << "是否确认修改(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "修改成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消修改此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '2':
		cout << "请输入要修改课程名称:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Name(), search))
			{
				p->Display();
				i++;
				cout << "是否确认修改(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "修改成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消修改此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '3':
		cout << "请输入要修改的课程类型:a.通识课、b.专业基础课、c.专业课" << endl;
		cin >> type;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_type() == type)
			{
				p->Display();
				i++;
				cout << "是否确认修改(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "修改成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消修改此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '4':
		cout << "请输入要修改课程的授课教师:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Teacher(), search))
			{
				p->Display();
				i++;
				cout << "是否确认修改(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "修改成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消修改此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '5':
		cout << "请输入要修改课程学时:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Time() == s)
			{
				p->Display();
				i++;
				cout << "是否确认修改(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "修改成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消修改此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	case '6':
		cout << "请输入要修改课程学分:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Unit() == s)
			{
				p->Display();
				i++;
				cout << "是否确认修改(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "修改成功" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消修改此课程" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		if (i == 0)
			cout << "未找到相应课程" << endl << endl;
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		break;
	}
	cout << endl;
}
