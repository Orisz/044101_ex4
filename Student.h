#ifndef STUDENT_H
#define STUDENT_H
#include "Proj.h"
#include "Course.h"
#include "CS_Course.h"
#include "EE_Course.h"
#include "Person.h"
#include <iostream>
#include <string.h>

using namespace std;

class Student : public Person
{
public:
	Student(int id, char* name);
	~Student();

	int getCourseCnt();
	bool addEE_Course(EE_Course* ee_course);
	bool addCS_Course(CS_Course* cs_course);
	bool remCourse(int course_num);
	EE_Course* getEE_Course(int course_num);
	CS_Course* getCS_Course(int course_num);
	int getAvg();
	void print();

private:
	EE_Course* ee_course_array_[MAX_COURSE_NUM];
	int ee_course_num_;
	CS_Course* cs_course_array_[MAX_COURSE_NUM];
	int cs_course_num_;
};

#endif
