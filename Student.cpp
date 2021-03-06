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
	cout << "Please input year:";
	stream >> date.Year;
	cout << "Please input month:";
	stream >> date.Mounth;
	cout << "Please input day:";
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
	cout << "Please input Student's Code:";
	cin >> Student_Code;
	cout << "Please input Student's Name:";
	cin >> Student_Name;
	char gender[3];
	do
	{
		cout << "Please input Student's gender(girl/boy):";
		cin >> gender;
		if (!strcmp(gender, "girl"))
			Student_Gender = true;
		else if (!strcmp(gender, "boy"))
			Student_Gender = false;
		else
			cout << "Input errors, please re-enter" << endl;
	} while (strcmp(gender, "girl") && strcmp(gender, "boy"));
	cout << "Please input Student's Birthday" << endl;
	cin >> Student_Birthday;
	cout << "Whether to choose courses(Y/N)" << endl;
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
			cout << "Class selection is cancelled" << endl;
		}
		else
			cout << "Input errors, please re-enter" << endl;
	} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
	

}

void Student::Modify(Linked_Courses &L)
{
	cout << endl;
	cout << "Please select the comtent to modifie:" << endl;  //请选择要修改的内容
	cout << "1.Student_Code" << endl;
	cout << "2.Student_Name" << endl;
	cout << "3.Student_Gender" << endl;
	cout << "4.Student_Birthday" << endl;
	cout << "5.Add_Course" << endl;
	cout << "6.Withdrawal_Course" << endl;
	cout << "7.List_added_courses" << endl;
	cout << endl;
	char a;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "Please input Student_Code:";
		cin >> Student_Code;
		break;
	case '2':
		cout << "Please input Student_Name:";
		cin >> Student_Name;
		break;
	case '3':
		char gender[3];
		do
		{
			cout << "Please input Student_Gender(girl/boy):";
			cin >> gender;
			if (!strcmp(gender, "girl"))
				Student_Gender = true;
			else if (!strcmp(gender, "boy"))
				Student_Gender = false;
			else
				cout << "Input errors, please re-enter" << endl;
		} while (strcmp(gender, "girl") && strcmp(gender, "boy"));
		break;
	case '4':
		cout << "Please input Student_Birthday:" << endl;
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
	cout << "Please input the Course code:";
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
		cout << "Not found" << endl << endl;
	else
	{
		cout << "Add course succeed" << endl << endl;
	}
}

void Student::Student_Withdraw_Course()
{
	cout << "Added_courses";
	Selected.Display();
	Selected.Delete();
}

void LNode_Student::Display()
{
	cout << endl;
	cout << "Student_Code:" << get_Student_Code() << endl;
	cout << "Student_Name:" << get_Student_Name() << endl;
	cout << "Student_Gender:";
	if (get_Student_Gender())
		cout << "girl" << endl;
	else
		cout << "boy" << endl;
	cout << "Student_Birthday:" << get_Student_Birthday() << endl;
	cout << "Added_Courses:" << endl;
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
	cout << "Initialization is complete" << endl;
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
	cout << "1.Search by Sutdent_Code" << endl;
	cout << "2.Search by Sutdent_Name" << endl;
	cout << "3.Search by Sutdent_Gender" << endl;
	cout << "4.Search by Sutdent_Birthday" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{	
	case '1':
		cout << "Please enter the Student_Code to search:";
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
		cout << "Please enter the Student_Name to search:";
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
		cout << "Please enter the Student_Gender to search:";
		do
		{
			cin >> search;
			if (!strcmp(search ,"girl"))
				gender = true;
			else if (!strcmp(search, "boy"))
				gender = false;
			else
				cout << "Input errors, please re-enter" << endl;
		} while (strcmp(search, "girl") && strcmp(search, "boy"));
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
		cout << "Please enter the Student_Birthday to search" << endl;
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
		cout << "Input errors, please re-enter" << endl;
		break;
	}
	if (i == 0)
		cout << "Not found the student" << endl << endl;
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
		cout << "There is no Student's information" << endl;
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
	cout << "1.Delete by Student_Code" << endl;
	cout << "2.Delete by Student_Name" << endl;
	cout << "3.Delete by Student_Gender" << endl;
	cout << "4.Delete by Student_Birthday" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "Please enter the Student_Code to delete:";
		cin >> search;
		p = head;
		o = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Code(), search))
			{
				p->Display();
				i++;
				cout << "Please confirm deletion(Y/N)" << endl;
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
						cout << "The information is deleted" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "The deletion is canceled" << endl;
					}
					else
						cout << "Input errors, please re-enter" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		break;
	case '2':
		cout << "Please enter the Student_Name to delete:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Name(), search))
			{
				p->Display();
				i++;
				cout << "Please confirm deletion(Y/N)" << endl;
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
						cout << "The information is deleted" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "The deletion is canceled" << endl;
					}
					else
						cout << "Input errors, please re-enter" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		break;
	case '3':
		cout << "Please enter the Student_Gender to delete:";
		do
		{
			cin >> gender;
			if (!strcmp(gender, "girl"))
				student_gender = true;
			else if (!strcmp(gender, "boy"))
				student_gender = false;
			else
				cout << "Input errors, please re-enter" << endl;
		} while (strcmp(gender, "girl") && strcmp(gender, "boy"));
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Gender() == student_gender)
			{
				p->Display();
				i++;
				cout << "Please confirm deletion(Y/N)" << endl;
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
						cout << "The information is deleted" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "The deletion is canceled" << endl;
					}
					else
						cout << "Input errors, please re-enter" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		break;
	case '4':
		cout << "Please enter the Student_Birthday to delete" << endl;
		cin >> Birthday;
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Birthday() == Birthday)
			{
				p->Display();
				i++;
				cout << "Please confirm deletion(Y/N)" << endl;
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
						cout << "The information is deleted" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "The deletion is canceled" << endl;
					}
					else
						cout << "Input errors, please re-enter" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		break;
	default:
		cout << "Input errors, please re-enter" << endl;
		break;
	}
	if (i == 0)
		cout << "Not found" << endl;
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
	cout << "1.Modify by Sutdent_Code" << endl;
	cout << "2.Modify by Sutdent_Name" << endl;
	cout << "3.Modify by Sutdent_Gender" << endl;
	cout << "4.Modify by Sutdent_Birthday" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "Please enter the Student_Code to modify:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Code(), search))
			{
				p->Display();
				i++;
				cout << "Confirm the changes(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
						cout << "Modify complete" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "Changes are canceled" << endl;
					}
					else
						cout << "Input errors, please re-enter" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		break;
	case '2':
		cout << "Please enter the Student_Name to modify:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Name(), search))
			{
				p->Display();
				i++;
				cout << "Confirm the changes(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
						cout << "Modify complete" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "Changes are canceled" << endl;
					}
					else
						cout << "Input errors, please re-enter" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		break;
	case '3':
		cout << "Please enter the Student_Gender to modify:";
		do
		{
			cin >> gender;
			if (!strcmp(gender, "girl"))
				student_gender = true;
			else if (!strcmp(gender, "boy"))
				student_gender = false;
			else
				cout << "Input errors, please re-enter" << endl;
		} while (strcmp(gender, "girl") && strcmp(gender, "boy"));
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Gender() == student_gender)
			{
				p->Display();
				i++;
				cout << "Confirm the changes(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
						cout << "Modify complete" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "Changes are canceled" << endl;
					}
					else
						cout << "Input errors, please re-enter" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		break;
	case '4':
		cout << "Please enter the Student_Birthday to modify" << endl;
		cin >> Birthday;
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Birthday() == Birthday)
			{
				p->Display();
				i++;
				cout << "Confirm the changes(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
						cout << "Modify complete" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "Changes are canceled" << endl;
					}
					else
						cout << "Input errors, please re-enter" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		break;
	default:
		cout << "Input errors, please re-enter" << endl;
		break;
	}
	if (i == 0)
		cout << "Not found" << endl << endl;
	cout << endl;
}
