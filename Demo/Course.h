#pragma once
#include <string>
#include <iostream>
using namespace std;
//1、	至少定义课程类和学生类。课程类至少需要定义课程编号、课程名称、课程类型（通识课、专业基础课、专业课三种）、授课教师、学时、学分等信息以及相应成员函数。


class Course
{
private:
	char Course_Code[10], Course_Name[10], Course_Type, Course_Teacher[10];
	int Course_Time, Course_Unit;
public:
	Course();
	~Course();
	void Input();																//输入各项
	void Modify();																//修改各项
	char *get_Course_Code() { return Course_Code; };							//返回课程号，外部接口
	char *get_Course_Name() { return Course_Name; };							//课名
	char get_Course_type() { return Course_Type; };								//课程类型 a.基础b.专业基础c.专业
	char *get_Course_Teacher() { return Course_Teacher; };						//授课教师
	int get_Course_Time() { return Course_Time; };								//课时
	int get_Course_Unit() { return Course_Unit; };								//学分
	void input_Course_Code(char c[10]) { strcpy_s(Course_Code,c); };			//以下是输入
	void input_Course_Name(char c[10]) { strcpy_s(Course_Name,c); };
	void input_Course_type(char c) { Course_Type = c; };
	void input_Course_Teacher(char c[10]) { strcpy_s(Course_Teacher,c); };
	void input_Course_Time(int c) { Course_Time = c; };
	void input_Course_Unit(int c) { Course_Unit = c; };							
};


//构造链表的节点，可显示输出节点内的成员（公有继承Course类）
class LNode_Course:public Course
{
public:
	LNode_Course *next = NULL;
	void Display();																//显示节点信息
	bool select();																//是否选这门课
	void Copy(LNode_Course *&p);												//复制
};


//构造完成的链表
class Linked_Courses
{
public:
	LNode_Course *head=NULL, *rear=NULL;
	void Init();																//初始化
	void Into_Linked_Courses();													//创建新课程加入链表
	void Searche_Courses();														//按各种标准查找符合条件的节点
	void Display();																//显示全部表内信息
	void Delete();																//查找删除（内含删除确认）
	void Courses_Modify();														//查找修改
};
