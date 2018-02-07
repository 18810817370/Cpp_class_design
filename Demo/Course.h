#pragma once
#include <string>
#include <iostream>
using namespace std;
//1��	���ٶ���γ����ѧ���ࡣ�γ���������Ҫ����γ̱�š��γ����ơ��γ����ͣ�ͨʶ�Ρ�רҵ�����Ρ�רҵ�����֣����ڿν�ʦ��ѧʱ��ѧ�ֵ���Ϣ�Լ���Ӧ��Ա������


class Course
{
private:
	char Course_Code[10], Course_Name[10], Course_Type, Course_Teacher[10];
	int Course_Time, Course_Unit;
public:
	Course();
	~Course();
	void Input();																//�������
	void Modify();																//�޸ĸ���
	char *get_Course_Code() { return Course_Code; };							//���ؿγ̺ţ��ⲿ�ӿ�
	char *get_Course_Name() { return Course_Name; };							//����
	char get_Course_type() { return Course_Type; };								//�γ����� a.����b.רҵ����c.רҵ
	char *get_Course_Teacher() { return Course_Teacher; };						//�ڿν�ʦ
	int get_Course_Time() { return Course_Time; };								//��ʱ
	int get_Course_Unit() { return Course_Unit; };								//ѧ��
	void input_Course_Code(char c[10]) { strcpy_s(Course_Code,c); };			//����������
	void input_Course_Name(char c[10]) { strcpy_s(Course_Name,c); };
	void input_Course_type(char c) { Course_Type = c; };
	void input_Course_Teacher(char c[10]) { strcpy_s(Course_Teacher,c); };
	void input_Course_Time(int c) { Course_Time = c; };
	void input_Course_Unit(int c) { Course_Unit = c; };							
};


//��������Ľڵ㣬����ʾ����ڵ��ڵĳ�Ա�����м̳�Course�ࣩ
class LNode_Course:public Course
{
public:
	LNode_Course *next = NULL;
	void Display();																//��ʾ�ڵ���Ϣ
	bool select();																//�Ƿ�ѡ���ſ�
	void Copy(LNode_Course *&p);												//����
};


//������ɵ�����
class Linked_Courses
{
public:
	LNode_Course *head=NULL, *rear=NULL;
	void Init();																//��ʼ��
	void Into_Linked_Courses();													//�����¿γ̼�������
	void Searche_Courses();														//�����ֱ�׼���ҷ��������Ľڵ�
	void Display();																//��ʾȫ��������Ϣ
	void Delete();																//����ɾ�����ں�ɾ��ȷ�ϣ�
	void Courses_Modify();														//�����޸�
};
