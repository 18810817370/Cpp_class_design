#pragma once
#include "Course.h"
//学生类至少需要定义学号、姓名、性别、出生日期、所选的两门课程及两门课程的总学分以及相应成员函数。

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
	void Input(Linked_Courses &L);												//输入学生基本信息（包含选课）
	void Modify(Linked_Courses &L);												//修改学生基本信息（包含选课）
	char *get_Student_Code() { return Student_Code; };							//返回学号，外部接口
	char *get_Student_Name() { return Student_Name; };							//姓名
	bool get_Student_Gender() { return Student_Gender; };						//以bool形式返回性别，女:1/男:0
	Date get_Student_Birthday() { return Student_Birthday; };					//Date形式返回生日
	Linked_Courses get_Selected() { return Selected; }							//返回已选课程
	void Student_Select_Course(Linked_Courses &L);								//从课表L中选课
	void Student_Withdraw_Course();												//退课
};

class LNode_Student:public Student
{
public:
	LNode_Student *next = NULL;
	void Display();																//显示节点信息
};

class Linked_Students
{
private:
	LNode_Student *head = NULL, *rear = NULL;
public:
	void Init();
	void Into_Linked_Students(Linked_Courses &L);								//创建新课程加入链表
	void Searche_Stuents();														//按各种标准查找符合条件的节点
	void Display();																//显示全部表内信息
	void Delete();																//查找删除（内含删除确认）
	void Students_Modify(Linked_Courses &L);									//查找修改（可选课退课）
};

