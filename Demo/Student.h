#pragma once
#include "Course.h"
//ѧ����������Ҫ����ѧ�š��������Ա𡢳������ڡ���ѡ�����ſγ̼����ſγ̵���ѧ���Լ���Ӧ��Ա������

class Date
{
public:
	int Day, Mounth, Year;
	friend bool operator == (const Date &a ,const Date &b);
	friend istream &operator >> (istream &stream,Date & date);
	friend ostream &operator << (ostream &stream, Date & date);
};




class Student:public Linked_Courses
{
private:
	char Student_Code[10], Student_Name[15]; 
	bool Student_Gender;
	Date Student_Birthday;
	Linked_Courses Selected;
public:
	Student();
	~Student();
	void Input(Linked_Courses &L);												//����ѧ��������Ϣ������ѡ�Σ�
	void Modify(Linked_Courses &L);												//�޸�ѧ��������Ϣ������ѡ�Σ�
	char *get_Student_Code() { return Student_Code; };							//����ѧ�ţ��ⲿ�ӿ�
	char *get_Student_Name() { return Student_Name; };							//����
	bool get_Student_Gender() { return Student_Gender; };						//��bool��ʽ�����Ա�Ů:1/��:0
	Date get_Student_Birthday() { return Student_Birthday; };					//Date��ʽ��������
	Linked_Courses get_Selected() { return Selected; }							//������ѡ�γ�
	void Student_Select_Course(Linked_Courses &L);								//�ӿα�L��ѡ��
	void Student_Withdraw_Course();												//�˿�
};

class LNode_Student:public Student
{
public:
	LNode_Student *next = NULL;
	void Display();																//��ʾ�ڵ���Ϣ
};

class Linked_Students
{
private:
	LNode_Student *head = NULL, *rear = NULL;
public:
	void Init();
	void Into_Linked_Students(Linked_Courses &L);								//�����¿γ̼�������
	void Searche_Stuents();														//�����ֱ�׼���ҷ��������Ľڵ�
	void Display();																//��ʾȫ��������Ϣ
	void Delete();																//����ɾ�����ں�ɾ��ȷ�ϣ�
	void Students_Modify(Linked_Courses &L);									//�����޸ģ���ѡ���˿Σ�
};

