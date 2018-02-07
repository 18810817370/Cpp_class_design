#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

//����Date������ж�
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

//����Date��������
istream &operator >> (istream &stream, Date &date)
{
	cout << "��������:";
	stream >> date.Year;
	cout << "��������:";
	stream >> date.Mounth;
	cout << "��������:";
	stream >> date.Day;
	return stream;
}

//����Date�������
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
	cout << "������ѧ��ѧ��:";
	cin >> Student_Code;
	cout << "������ѧ������:";
	cin >> Student_Name;
	char gender[3];
	do
	{
		cout << "������ѧ���Ա�:";
		cin >> gender;
		if (!strcmp(gender, "Ů"))
			Student_Gender = true;
		else if (!strcmp(gender, "��"))
			Student_Gender = false;
		else
			cout << "�����������������" << endl;
	} while (strcmp(gender, "Ů") && strcmp(gender, "��"));
	cout << "������ѧ������" << endl;
	cin >> Student_Birthday;
	cout << "�Ƿ�ѡ��(Y/N)" << endl;
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
			cout << "��ȡ��ѡ��" << endl;
		}
		else
			cout << "�����������������" << endl;
	} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
	

}

void Student::Modify(Linked_Courses &L)
{
	cout << endl;
	cout << "��ѡ��Ҫ�޸ĵ�����:" << endl;
	cout << "1.ѧ��ѧ��" << endl;
	cout << "2.ѧ������" << endl;
	cout << "3.ѧ���Ա�" << endl;
	cout << "4.ѧ������" << endl;
	cout << "5.ѧ��ѡ��" << endl;
	cout << "6.ѧ���˿�" << endl;
	cout << "7.ѧ����ѡ�γ�" << endl;
	cout << endl;
	char a;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "������ѧ��ѧ��:";
		cin >> Student_Code;
		break;
	case '2':
		cout << "������ѧ������:";
		cin >> Student_Name;
		break;
	case '3':
		char gender[3];
		do
		{
			cout << "������ѧ���Ա�:";
			cin >> gender;
			if (!strcmp(gender, "Ů"))
				Student_Gender = true;
			else if (!strcmp(gender, "��"))
				Student_Gender = false;
			else
				cout << "�����������������" << endl;
		} while (strcmp(gender, "Ů") && strcmp(gender, "��"));
		break;
	case '4':
		cout << "������ѧ������" << endl;
		cin >> Student_Birthday;
		break;
	case '5':
		Student_Select_Course(L);											//�����пγ̱�L��ѡ��
		break;
	case '6':
		Student_Withdraw_Course();
		break;
	case '7':
		Selected.Display();													//��Linked_Courses��̳еĺ�������ʾ��ѡ�Ŀγ�
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
	cout << "������Ҫѡ��Ŀγ̱��:";
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
		cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
	else
	{
		cout << "ѡ�γɹ�" << endl << endl;
	}
}

void Student::Student_Withdraw_Course()
{
	cout << "��ѡ�γ�";
	Selected.Display();
	Selected.Delete();
}

void LNode_Student::Display()
{
	cout << endl;
	cout << "ѧ��ѧ��:" << get_Student_Code() << endl;
	cout << "ѧ������:" << get_Student_Name() << endl;
	cout << "ѧ���Ա�:";
	if (get_Student_Gender())
		cout << "Ů" << endl;
	else
		cout << "��" << endl;
	cout << "ѧ������:" << get_Student_Birthday() << endl;
	cout << "ѧ����ѡ�γ�:" << endl;
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
	cout << "��ʼ�����" << endl;
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
	cout << "1.��ѧ��ѧ������" << endl;
	cout << "2.��ѧ����������" << endl;
	cout << "3.��ѧ���Ա�����" << endl;
	cout << "4.��ѧ����������" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{	
	case '1':
		cout << "������Ҫ����ѧ����ѧ��:";
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
		cout << "������Ҫ����ѧ��������:";
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
		cout << "������Ҫ����ѧ�����Ա�:";
		do
		{
			cin >> search;
			if (!strcmp(search ,"Ů"))
				gender = true;
			else if (!strcmp(search, "��"))
				gender = false;
			else
				cout << "�����������������" << endl;
		} while (strcmp(search, "Ů") && strcmp(search, "��"));
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
		cout << "������Ҫ����ѧ��������" << endl;
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
		cout << "�����������������" << endl;
		break;
	}
	if (i == 0)
		cout << "δ�ҵ���Ӧѧ��" << endl << endl;
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
		cout << "û��ѧ����Ϣ" << endl;
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
	cout << "1.��ѧ��ѧ��ɾ��" << endl;
	cout << "2.��ѧ������ɾ��" << endl;
	cout << "3.��ѧ���Ա�ɾ��" << endl;
	cout << "4.��ѧ������ɾ��" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "������Ҫɾ��ѧ����ѧ��:";
		cin >> search;
		p = head;
		o = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Code(), search))
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ��ɾ��(Y/N)" << endl;
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
						cout << "ɾ���ɹ�" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "ȡ��ɾ����ѧ����Ϣ" << endl;
					}
					else
						cout << "�����������������" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		break;
	case '2':
		cout << "������Ҫɾ��ѧ��������:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Name(), search))
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ��ɾ��(Y/N)" << endl;
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
						cout << "ɾ���ɹ�" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "ȡ��ɾ����ѧ����Ϣ" << endl;
					}
					else
						cout << "�����������������" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		break;
	case '3':
		cout << "������Ҫɾ��ѧ�����Ա�:";
		do
		{
			cin >> gender;
			if (!strcmp(gender, "Ů"))
				student_gender = true;
			else if (!strcmp(gender, "��"))
				student_gender = false;
			else
				cout << "�����������������" << endl;
		} while (strcmp(gender, "Ů") && strcmp(gender, "��"));
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Gender() == student_gender)
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ��ɾ��(Y/N)" << endl;
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
						cout << "ɾ���ɹ�" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "ȡ��ɾ���˿γ�" << endl;
					}
					else
						cout << "�����������������" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		break;
	case '4':
		cout << "������Ҫɾ��ѧ��������" << endl;
		cin >> Birthday;
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Birthday() == Birthday)
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ��ɾ��(Y/N)" << endl;
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
						cout << "ɾ���ɹ�" << endl;
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "ȡ��ɾ���˿γ�" << endl;
					}
					else
						cout << "�����������������" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			o = p;
			if (p != NULL)
				p = p->next;
		}
		break;
	default:
		cout << "�����������������" << endl;
		break;
	}
	if (i == 0)
		cout << "δ�ҵ���Ӧѧ��" << endl;
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
	cout << "1.��ѧ��ѧ�������޸�" << endl;
	cout << "2.��ѧ�����������޸�" << endl;
	cout << "3.��ѧ���Ա������޸�" << endl;
	cout << "4.��ѧ�����������޸�" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "������Ҫ�޸�ѧ����ѧ��:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Code(), search))
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ���޸�(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "ȡ���޸Ĵ�ѧ����Ϣ" << endl;
					}
					else
						cout << "�����������������" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		break;
	case '2':
		cout << "������Ҫ�޸�ѧ��������:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Student_Name(), search))
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ���޸�(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "ȡ���޸Ĵ�ѧ����Ϣ" << endl;
					}
					else
						cout << "�����������������" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		break;
	case '3':
		cout << "������Ҫ�޸�ѧ�����Ա�:";
		do
		{
			cin >> gender;
			if (!strcmp(gender, "Ů"))
				student_gender = true;
			else if (!strcmp(gender, "��"))
				student_gender = false;
			else
				cout << "�����������������" << endl;
		} while (strcmp(gender, "Ů") && strcmp(gender, "��"));
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Gender() == student_gender)
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ���޸�(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "ȡ���޸Ĵ˿γ�" << endl;
					}
					else
						cout << "�����������������" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		break;
	case '4':
		cout << "������Ҫ�޸�ѧ��������" << endl;
		cin >> Birthday;
		p = head;
		while (p != NULL)
		{
			if (p->get_Student_Birthday() == Birthday)
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ���޸�(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify(L);
					}
					else if (Confirm == 'N' || Confirm == 'n')
					{
						cout << "ȡ���޸Ĵ˿γ�" << endl;
					}
					else
						cout << "�����������������" << endl;
				} while (Confirm != 'Y' && Confirm != 'y' && Confirm != 'N' && Confirm != 'n');
			}
			p = p->next;
		}
		break;
	default:
		cout << "�����������������" << endl;
		break;
	}
	if (i == 0)
		cout << "δ�ҵ���Ӧѧ��" << endl << endl;
	cout << endl;
}
