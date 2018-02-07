#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

//重载Date类相等判断
bool operator == (const Date &a, const Date &b)
{
	if (a.Day == b.Day
		&&	a.Mounth == b.Mounth
		&&	a.Year == b.Year
		)
		return true;
	else
		return false;
}

//重载Date类输入流
istream &operator >> (istream &stream, Date &date)
{
	cout << "请输入年:";
	stream >> date.Year;
	cout << "请输入月:";
	stream >> date.Mounth;
	cout << "请输入日:";
	stream >> date.Day;
	return stream;
}

//重载Date类输出流
ostream &operator << (ostream &stream, Date &date)
{
	stream << date.Year;
	cout << "/";
	stream << date.Mounth; 
	cout << "/";
	stream << date.Day;
	return stream;
}

Student::Student()
{
}

Student::~Student()
{
}

void Student::Input(Linked_Courses &L)
{
	cout << "请输入学生学号:";
	cin >> Student_Code;
	cout << "请输入学生姓名:";
	cin >> Student_Name;
	char gender[3];
	do
	{
		cout << "请输入学生性别:";
		cin >> gender;
		if (!strcmp(gender, "女"))
			Student_Gender = true;
		else if (!strcmp(gender, "男"))
			Student_Gender = false;
		else
			cout << "输入错误，请重新输入" << endl;
	} while (strcmp(gender, "女") && strcmp(gender, "男"));
	cout << "请输入学生生日" << endl;
	cin >> Student_Birthday;
	cout << "是否选课(Y/N)" << endl;
	char Confirm;
	do
	{
		cin >> Confirm;
		if (Confirm == 'Y' || Confirm == 'y')
		{
			Student_Select_Course(L);
		}
		else if (Confirm == 'N' || Confirm == 'n')
		{
			cout << "以取消选课" << endl;
		}
		else
			cout << "输入错误，请重新输入" << endl;
	} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
	

}

void Student::Modify(Linked_Courses &L)
{
	cout << endl;
	cout << "请选择要修改的内容:" << endl;
	cout << "1.学生学号" << endl;
	cout << "2.学生姓名" << endl;
	cout << "3.学生性别" << endl;
	cout << "4.学生生日" << endl;
	cout << "5.学生选课" << endl;
	cout << "6.学生退课" << endl;
	cout << "7.学生已选课程" << endl;
	cout << endl;
	char a;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "请输入学生学号:";
		cin >> Student_Code;
		break;
	case '2':
		cout << "请输入学生姓名:";
		cin >> Student_Name;
		break;
	case '3':
		char gender[3];
		do
		{
			cout << "请输入学生性别:";
			cin >> gender;
			if (!strcmp(gender, "女"))
				Student_Gender = true;
			else if (!strcmp(gender, "男"))
				Student_Gender = false;
			else
				cout << "输入错误，请重新输入" << endl;
		} while (strcmp(gender, "女") && strcmp(gender, "男"));
		break;
	case '4':
		cout << "请输入学生生日" << endl;
		cin >> Student_Birthday;
		break;
	case '5':
		Student_Select_Course(L);											//从已有课程表L中选择
		break;
	case '6':
		Student_Withdraw_Course();
		break;
	case '7':
		Selected.Display();													//从Linked_Courses里继承的函数，显示已选的课程
		break;
	default:
		break;
	}
}

void Student::Student_Select_Course(Linked_Courses &L)
{
	L.Display();
	char code[10];
	int i(0);
	LNode_Course *p;
	cout << "请输入要选择的课程编号:";
	cin >> code;
	p = L.head;
	while (p != NULL)
	{
		if (!strcmp(p->get_Course_Code(), code))
		{
			LNode_Course *s = new LNode_Course;
			if (Selected.head == NULL)
			{
				Selected.head = s;
				Selected.rear = s;
			}
			else
			{
				Selected.rear->next = s;
			}
			s->Copy(p);
			Selected.rear = s;
			i = 1;
		}
		p = p->next;
	}
	if (i == 0)
		cout << "未找到相应课程" << endl << endl;
	else
	{
		cout << "选课成功" << endl << endl;
	}
}

void Student::Student_Withdraw_Course()
{
	cout << "已选课程";
	Selected.Display();
	Selected.Delete();
}

void LNode_Student::Display()
{
	cout << endl;
	cout << "学生学号:" << get_Student_Code() << endl;
	cout << "学生姓名:" << get_Student_Name() << endl;
	cout << "学生性别:";
	if (get_Student_Gender())
		cout << "女" << endl;
	else
		cout << "男" << endl;
	cout << "学生生日:" << get_Student_Birthday() << endl;
	cout << "学生已选课程:" << endl;
	get_Selected().Display();
	cout << endl;
}

void Linked_Students::Init()
{
	cout << endl;
	LNode_Student *p;
	while (head != NULL)
	{
		p = head;
		head = p->next;
		delete p;
	}
	cout << "初始化完成" << endl;
	cout << endl;
}

void Linked_Students::Into_Linked_Students(Linked_Courses &L)
{
	cout << endl;
	LNode_Student *p = new LNode_Student;
	if (head == NULL)
	{
		head = p;
		rear = p;
	}
	else
	{
		rear->next = p;
	}
	p->Input(L);
	rear = p;
	cout << endl;
}

void Linked_Students::Searche_Stuents()
{
	LNode_Student *p;
	char a, search[10];
	int i(0);
	bool gender;
	Date Birthday;
	cout << endl;
	cout << "1.按学生学号搜索" << endl;
	cout << "2.按学生姓名搜索" << endl;
	cout << "3.按学生性别搜索" << endl;
	cout << "4.按学生生日搜索" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{	
	case '1':
		cout << "请输入要搜索学生的学号:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Code(), search))
			{
				p->Display();
				i++;
			}	
			p = p->next;
		}
		break;
	case '2':
		cout << "请输入要搜索学生的姓名:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Name(), search))
			{
				p->Display();
				i++;
			}
			p = p->next;
		}
		break;
	case '3':
		cout << "请输入要搜索学生的性别:";
		do
		{
			cin >> search;
			if (!strcmp(search ,"女"))
				gender = true;
			else if (!strcmp(search, "男"))
				gender = false;
			else
				cout << "输入错误，请重新输入" << endl;
		} while (strcmp(search, "女") && strcmp(search, "男"));
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Gender() == gender)
			{
				p->Display();
				i++;
			}
			p = p->next;
		}
		break;
	case '4':
		cout << "请输入要搜索学生的生日" << endl;
		cin >> Birthday;
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Birthday() == Birthday)
			{
				p->Display();
				i++;
			}
			p = p->next;
		}
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		break;
	}
	if (i == 0)
		cout << "未找到相应学生" << endl << endl;
}

void Linked_Students::Display()
{
	cout << endl;
	LNode_Student *p = head;
	int i(0);
	while (p != NULL)
	{
		p->Display();
		i++;
		p = p->next;
	}
	if (i == 0)
		cout << "没有学生信息" << endl;
	cout << endl;
}

void Linked_Students::Delete()
{
	LNode_Student *p, *o=NULL;
	char a, search[10], Confirm;
	char gender[3];
	int i(0);
	bool student_gender;
	Date Birthday;
	cout << endl;
	cout << "1.按学生学号删除" << endl;
	cout << "2.按学生姓名删除" << endl;
	cout << "3.按学生性别删除" << endl;
	cout << "4.按学生生日删除" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "请输入要删除学生的学号:";
		cin >> search;
		p = head;
		o = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Code(), search))
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
						cout << "取消删除此学生信息" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		break;
	case '2':
		cout << "请输入要删除学生的姓名:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Name(), search))
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
						cout << "取消删除此学生信息" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		break;
	case '3':
		cout << "请输入要删除学生的性别:";
		do
		{
			cin >> gender;
			if (!strcmp(gender, "女"))
				student_gender = true;
			else if (!strcmp(gender, "男"))
				student_gender = false;
			else
				cout << "输入错误，请重新输入" << endl;
		} while (strcmp(gender, "女") && strcmp(gender, "男"));
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Gender() == student_gender)
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
		break;
	case '4':
		cout << "请输入要删除学生的生日" << endl;
		cin >> Birthday;
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Birthday() == Birthday)
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
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		break;
	}
	if (i == 0)
		cout << "未找到相应学生" << endl;
	cout << endl;
}

void Linked_Students::Students_Modify(Linked_Courses &L)
{
	LNode_Student *p;
	char a, search[10], Confirm;
	char gender[3];
	int i(0);
	bool student_gender;
	Date Birthday;
	cout << endl;
	cout << "1.按学生学号搜索修改" << endl;
	cout << "2.按学生姓名搜索修改" << endl;
	cout << "3.按学生性别搜索修改" << endl;
	cout << "4.按学生生日搜索修改" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "请输入要修改学生的学号:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Code(), search))
			{
				p->Display();
				i++;
				cout << "是否确认修改(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消修改此学生信息" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		break;
	case '2':
		cout << "请输入要修改学生的姓名:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Name(), search))
			{
				p->Display();
				i++;
				cout << "是否确认修改(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "取消修改此学生信息" << endl;
					}
					else
						cout << "输入错误，请重新输入" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		break;
	case '3':
		cout << "请输入要修改学生的性别:";
		do
		{
			cin >> gender;
			if (!strcmp(gender, "女"))
				student_gender = true;
			else if (!strcmp(gender, "男"))
				student_gender = false;
			else
				cout << "输入错误，请重新输入" << endl;
		} while (strcmp(gender, "女") && strcmp(gender, "男"));
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Gender() == student_gender)
			{
				p->Display();
				i++;
				cout << "是否确认修改(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
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
		break;
	case '4':
		cout << "请输入要修改学生的生日" << endl;
		cin >> Birthday;
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Birthday() == Birthday)
			{
				p->Display();
				i++;
				cout << "是否确认修改(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
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
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		break;
	}
	if (i == 0)
		cout << "未找到相应学生" << endl << endl;
	cout << endl;
}
