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
		cout << "0.��ʼ���γ�����" << endl;
		cout << "1.�����¿γ�" << endl;
		cout << "2.��ʾȫ�������ڿγ�" << endl;
		cout << "3.���ҿγ� " << endl;
		cout << "4.ɾ���γ�" << endl;
		cout << "5.�޸Ŀγ�" << endl;
		cout << "E.����ѧ������ϵͳ" << endl;
		cout << "Q.�˳�" << endl << endl;
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
			cout << "�����������������" << endl;
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
			cout << "0.��ʼ��ѧ������" << endl;
			cout << "1.�����ѧ����Ϣ" << endl;
			cout << "2.��ʾȫ������������ѧ����Ϣ" << endl;
			cout << "3.����ѧ����Ϣ" << endl;
			cout << "4.ɾ��ѧ����Ϣ" << endl;
			cout << "5.�޸�ѧ����Ϣ" << endl;
			cout << "6.��ʾ��ѡ�γ�" << endl;
			cout << "Q.�˳�" << endl << endl;
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
				cout << "�����������������" << endl;
				break;
			}
			Sleep(500);
			system("cls");
		} while (select != 'Q');
	}
	return 0;
}