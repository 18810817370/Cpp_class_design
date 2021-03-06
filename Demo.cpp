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
		cout << "0.Initialize the course list" << endl;
		cout << "1.Create new course" << endl;
		cout << "2.Show all courses" << endl;
		cout << "3.Find courses " << endl;
		cout << "4.Delite courses" << endl;
		cout << "5.Modify course" << endl;
		cout << "g.Go to student management system" << endl;
		cout << "e.Exit" << endl << endl;
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
		case 'g':
			break;
		case 'e':
			break;
		default:
			cout << "Input errors, please re-enter" << endl;
			break;
		}
		Sleep(1000);
		system("cls");
	} while (select != 'g' && select != 'e');
	if (select == 'g')
	{
		Linked_Students S;
		S.Init();
		Sleep(500);
		system("cls");
		do
		{
			cout << "0.Initialize the students list" << endl;
			cout << "1.Add new student information" << endl;
			cout << "2.Show all student information" << endl;
			cout << "3.Find student information" << endl;
			cout << "4.Delete student information" << endl;
			cout << "5.Modify student information" << endl;
			cout << "6.Show optional courses" << endl;
			cout << "e.Exit" << endl << endl;
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
			case 'e':
				break;
			default:
				cout << "Input errors, please re-enter" << endl;
				break;
			}
			Sleep(1000);
			system("cls");
		} while (select != 'e');
	}
	return 0;
}