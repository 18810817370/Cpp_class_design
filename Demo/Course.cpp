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
	cout << "������γ̱��:";
	cin >> Course_Code;
	cout << "������γ�����:";
	cin >> Course_Name;
	do
	{
		cout << "��ѡ��γ�����:a.ͨʶ�Ρ�b.רҵ�����Ρ�c.רҵ��" << endl;
		cin >> Course_Type;
		if (Course_Type == 'a' || Course_Type == 'A' || Course_Type == 'b' || Course_Type == 'B' || Course_Type == 'c' || Course_Type == 'C')
			break;
		else
			cout << "�����������������" << endl;
	} while (1);
	cout << "�������ڿν�ʦ:";
	cin >> Course_Teacher;
	cout << "������γ�ѧʱ:";
	cin >> Course_Time;
	cout << "������γ�ѧ��:";
	cin >> Course_Unit;
}


void Course::Modify()
{
	cout << endl;
	cout << "��ѡ��Ҫ�޸ĵ�����:" << endl;
	cout << "1.�γ̱��" << endl;
	cout << "2.�γ�����" << endl;
	cout << "3.�γ�����" << endl;
	cout << "4.�ڿν�ʦ" << endl;
	cout << "5.�γ�ѧʱ" << endl;
	cout << "6.�γ�ѧ��" << endl;
	cout << endl;
	char a;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "������γ̱��:";
		cin >> Course_Code;
		break;
	case '2':
		cout << "������γ�����:";
		cin >> Course_Name;
		break;
	case '3':
		do
		{
			cout << "��ѡ��γ�����:a.ͨʶ�Ρ�b.רҵ�����Ρ�c.רҵ��" << endl;
			cin >> Course_Type;
			if (Course_Type == 'a' || Course_Type == 'A' || Course_Type == 'b' || Course_Type == 'B' || Course_Type == 'c' || Course_Type == 'C')
				break;
			else
				cout << "�����������������" << endl;
		} while (1);
		break;
	case '4':
		cout << "�������ڿν�ʦ:";
		cin >> Course_Teacher;
		break;
	case '5':
		cout << "������γ�ѧʱ:";
		cin >> Course_Time;
		break;
	case '6':
		cout << "������γ�ѧ��:";
		cin >> Course_Unit;
		break;
	default:
		break;
	}

}


void LNode_Course::Display()
{
	cout << endl;
	cout << "�γ̱��:" << get_Course_Code() << endl;
	cout << "�γ�����:" << get_Course_Name() << endl;
	cout << "�γ�����:";
	switch (get_Course_type())
	{
	case'a':
	case'A':
		cout << "ͨʶ��" << endl;
		break;
	case'b':
	case'B':
		cout << "רҵ������" << endl;
		break;
	case'c':
	case'C':
		cout << "רҵ��" << endl;
		break;
	default:
		break;
	}
	cout << "�ڿν�ʦ:" << get_Course_Teacher() << endl;
	cout << "�γ�ѧʱ:" << get_Course_Time() << endl;
	cout << "�γ�ѧ��:" << get_Course_Unit() << endl;
	cout << endl;
}


bool LNode_Course::select()
{
	char Confirm;
	cout << "�Ƿ�ѡ�����ſ�(Y/N)" << endl;
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
			cout << "�����������������" << endl;
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
	cout << "��ʼ�����" << endl;
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
	cout << "1.���γ̱������" << endl;
	cout << "2.���γ���������" << endl;
	cout << "3.���γ���������" << endl;
	cout << "4.���ڿν�ʦ����" << endl;
	cout << "5.���γ�ѧʱ����" << endl;
	cout << "6.���γ�ѧ������" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "������Ҫ�����γ̱��:";
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
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '2':
		cout << "������Ҫ�����γ�����:";
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
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '3':
		cout << "������Ҫ�����Ŀγ�����:a.ͨʶ�Ρ�b.רҵ�����Ρ�c.רҵ��" << endl;
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
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '4':
		cout << "������Ҫ�����γ̵��ڿν�ʦ:";
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
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '5':
		cout << "������Ҫ�����γ�ѧʱ:";
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
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '6':
		cout << "������Ҫ�����γ�ѧ��:";
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
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	default:
		cout << "�����������������" << endl;
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
		cout << "û�пγ�" << endl;
	cout << endl;
}


void Linked_Courses::Delete()
{
	LNode_Course *p, *o = NULL;
	char a, search[10], Confirm, type;
	int s, i(0);
	cout << endl;
	cout << "1.���γ̱��ɾ��" << endl;
	cout << "2.���γ�����ɾ��" << endl;
	cout << "3.���γ�����ɾ��" << endl;
	cout << "4.���ڿν�ʦɾ��" << endl;
	cout << "5.���γ�ѧʱɾ��" << endl;
	cout << "6.���γ�ѧ��ɾ��" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "������Ҫɾ���γ̱��:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Code(), search))
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '2':
		cout << "������Ҫɾ���γ�����:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Name(), search))
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '3':
		cout << "������Ҫɾ���Ŀγ�����:a.ͨʶ�Ρ�b.רҵ�����Ρ�c.רҵ��" << endl;
		cin >> type;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_type() == type)
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '4':
		cout << "������Ҫɾ���γ̵��ڿν�ʦ:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Teacher(), search))
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '5':
		cout << "������Ҫɾ���γ�ѧʱ:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Time() == s)
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '6':
		cout << "������Ҫɾ���γ�ѧ��:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Unit() == s)
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	default:
		cout << "�����������������" << endl;
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
	cout << "1.���γ̱�������޸�" << endl;
	cout << "2.���γ����������޸�" << endl;
	cout << "3.���γ����������޸�" << endl;
	cout << "4.���ڿν�ʦ�����޸�" << endl;
	cout << "5.���γ�ѧʱ�����޸�" << endl;
	cout << "6.���γ�ѧ�������޸�" << endl;
	cout << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		cout << "������Ҫ�޸Ŀγ̱��:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Code(), search))
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ���޸�(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "�޸ĳɹ�" << endl;
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '2':
		cout << "������Ҫ�޸Ŀγ�����:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Name(), search))
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ���޸�(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "�޸ĳɹ�" << endl;
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '3':
		cout << "������Ҫ�޸ĵĿγ�����:a.ͨʶ�Ρ�b.רҵ�����Ρ�c.רҵ��" << endl;
		cin >> type;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_type() == type)
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ���޸�(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "�޸ĳɹ�" << endl;
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '4':
		cout << "������Ҫ�޸Ŀγ̵��ڿν�ʦ:";
		cin >> search;
		p = head;
		while (p != NULL)
		{
			if (!strcmp(p->get_Course_Teacher(), search))
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ���޸�(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "�޸ĳɹ�" << endl;
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '5':
		cout << "������Ҫ�޸Ŀγ�ѧʱ:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Time() == s)
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ���޸�(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "�޸ĳɹ�" << endl;
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	case '6':
		cout << "������Ҫ�޸Ŀγ�ѧ��:";
		cin >> s;
		p = head;
		while (p != NULL)
		{
			if (p->get_Course_Unit() == s)
			{
				p->Display();
				i++;
				cout << "�Ƿ�ȷ���޸�(Y/N)" << endl;
				cin >> Confirm;
				do
				{
					if (Confirm == 'Y' || Confirm == 'y')
					{
						p->Modify();
						cout << "�޸ĳɹ�" << endl;
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
		if (i == 0)
			cout << "δ�ҵ���Ӧ�γ�" << endl << endl;
		break;
	default:
		cout << "�����������������" << endl;
		break;
	}
	cout << endl;
}
