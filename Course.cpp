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
	cout << "Please input Course_Code:";
	cin >> Course_Code;
	cout << "Please input Course_Name:";
	cin >> Course_Name;
	do
	{
		cout << "Please select course types: a. General Studies, b. Professional Basics, c. Professional Courses" << endl;
		cin >> Course_Type;
		if (Course_Type == 'a' || Course_Type == 'A' || Course_Type == 'b' || Course_Type == 'B' || Course_Type == 'c' || Course_Type == 'C')
			break;
		else
			cout << "Input errors, please re-enter" << endl;
	} while (1);
	cout << "Please input Course_Teacher:";
	cin >> Course_Teacher;
	cout << "Please input Course_Time:";
	cin >> Course_Time;
	cout << "Please input Course_Unit:";
	cin >> Course_Unit;
}


void Course::Modify()
{
	cout << endl;
	cout << "Please enter the content to modify:" << endl;
	cout << "1.Course_Code" << endl;
	cout << "2.Course_Name" << endl;
	cout << "3.Course_Type" << endl;
	cout << "4.Course_Teacher" << endl;
	cout << "5.Course_Time" << endl;
	cout << "6.Course_Unit" << endl;
	cout << endl;
	char a;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "Please enter the Course_Code:";
		cin >> Course_Code;
		break;
	case '2':
		cout << "Please enter the Course_Name:";
		cin >> Course_Name;
		break;
	case '3':
		do
		{
			cout << "Please select course types: a. General Studies, b. Professional Basics, c. Professional Courses" << endl;
			cin >> Course_Type;
			if (Course_Type == 'a' || Course_Type == 'A' || Course_Type == 'b' || Course_Type == 'B' || Course_Type == 'c' || Course_Type == 'C')
				break;
			else
				cout << "Input errors, please re-enter" << endl;
		} while (1);
		break;
	case '4':
		cout << "Please enter the Course_Teacher:";
		cin >> Course_Teacher;
		break;
	case '5':
		cout << "Please enter the Course_Time:";
		cin >> Course_Time;
		break;
	case '6':
		cout << "Please enter the Course_Unit:";
		cin >> Course_Unit;
		break;
	default:
		break;
	}

}


void LNode_Course::Display()
{
	cout << endl;
	cout << "Course_Code:" << get_Course_Code() << endl;
	cout << "Course_Name:" << get_Course_Name() << endl;
	cout << "Course_Type:";
	switch (get_Course_type())
	{
	case'a':
	case'A':
		cout << "General Studies" << endl;
		break;
	case'b':
	case'B':
		cout << "Professional Basics" << endl;
		break;
	case'c':
	case'C':
		cout << "Professional Courses" << endl;
		break;
	default:
		break;
	}
	cout << "Course_Teacher:" << get_Course_Teacher() << endl;
	cout << "Course_Time:" << get_Course_Time() << endl;
	cout << "Course_Unit:" << get_Course_Unit() << endl;
	cout << endl;
}


bool LNode_Course::select()
{
	char Confirm;
	cout << "Whether select the course(Y/N)" << endl;
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
			cout << "Input errors, please re-enter" << endl;
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
	cout << "Initialization is complete" << endl;
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
	cout << "1.Search by Course_Code" << endl;
	cout << "2.Search by Course_Name" << endl;
	cout << "3.Search by Course_Type" << endl;
	cout << "4.Search by Course_Teacher" << endl;
	cout << "5.Search by Course_Time" << endl;
	cout << "6.Search by Course_Unit" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "Please enter the Course_Code to search:";
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
			cout << "Not found the course" << endl << endl;
		break;
	case '2':
		cout << "Please enter the Course_Name to search:";
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
			cout << "Not found the course" << endl << endl;
		break;
	case '3':
		cout << "Please enter the Course_Type to search:a. General Studies, b. Professional Basics, c. Professional Courses" << endl;
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
			cout << "Not found the course" << endl << endl;
		break;
	case '4':
		cout << "Please enter the Course_Teacher to search:";
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
			cout << "Not found the course" << endl << endl;
		break;
	case '5':
		cout << "Please enter the Course_Time to search:";
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
			cout << "Not found the course" << endl << endl;
		break;
	case '6':
		cout << "Please enter the Course_Unit to search:";
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
			cout << "Not found the course" << endl << endl;
		break;
	default:
		cout << "Input errors, please re-enter" << endl;
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
		cout << "There are no courses" << endl;
	cout << endl;
}


void Linked_Courses::Delete()
{
	LNode_Course *p, *o = NULL;
	char a, search[10], Confirm, type;
	int s, i(0);
	cout << endl;
	cout << "1.Delete by Course_Code" << endl;
	cout << "2.Delete by Course_Name" << endl;
	cout << "3.Delete by Course_Type" << endl;
	cout << "4.Delete by Course_Teacher" << endl;
	cout << "5.Delete by Course_Time" << endl;
	cout << "6.Delete by Course_Unit" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "Please enter the Course_Code to delete:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Code(), search))
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
						cout << "The deletion is succeed" << endl;
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	case '2':
		cout << "Please enter the Course_Name to delete:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Name(), search))
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
						cout << "The deletion is succeed" << endl;
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	case '3':
		cout << "Please enter the Course_Type to delete:a. General Studies, b. Professional Basics, c. Professional Courses" << endl;
		cin >> type;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_type() == type)
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
						cout << "The deletion is succeed" << endl;
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	case '4':
		cout << "Please enter the Course_Teacher to delete:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Teacher(), search))
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
						cout << "The deletion is succeed" << endl;
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	case '5':
		cout << "Please enter the Course_Time to delete:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Time() == s)
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
						cout << "The deletion is succeed" << endl;
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	case '6':
		cout << "Please enter the Course_Unit to delete:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Unit() == s)
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
						cout << "The deletion is succeed" << endl;
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	default:
		cout << "Input errors, please re-enter" << endl;
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
	cout << "1.Modify by Course_Code" << endl;
	cout << "2.Modify by Course_Name" << endl;
	cout << "3.Modify by Course_Type" << endl;
	cout << "4.Modify by Course_Teacher" << endl;
	cout << "5.Modify by Course_Time" << endl;
	cout << "6.Modify by Course_Unit" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "Please enter the Course_Code to modity:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Code(), search))
			{
				p->Display();
				i++;
				cout << "Confirm the changes(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	case '2':
		cout << "Please enter the Course_Name to modity:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Name(), search))
			{
				p->Display();
				i++;
				cout << "Confirm the changes(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	case '3':
		cout << "Please enter the Course_Type to modity:a. General Studies, b. Professional Basics, c. Professional Courses" << endl;
		cin >> type;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_type() == type)
			{
				p->Display();
				i++;
				cout << "Confirm the changes(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	case '4':
		cout << "Please enter the Course_Teacher to modity:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Teacher(), search))
			{
				p->Display();
				i++;
				cout << "Confirm the changes(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	case '5':
		cout << "Please enter the Course_Time to modity:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Time() == s)
			{
				p->Display();
				i++;
				cout << "Confirm the changes(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	case '6':
		cout << "Please enter the Course_Unit to modity:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Unit() == s)
			{
				p->Display();
				i++;
				cout << "Confirm the changes(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
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
		if (i == 0)
			cout << "Not found the course" << endl << endl;
		break;
	default:
		cout << "Input errors, please re-enter" << endl;
		break;
	}
	cout << endl;
}
