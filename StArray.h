#ifndef STARRAY_H
#define STARRAY_H

#include <iostream>
#include <string.h>
#include "Proj.h"
#include "Course.h"
#include "CS_Course.h"
#include "EE_Course.h"
#include "Person.h"
#include "Student.h"
using namespace std;

class StArray
{
public:
	StArray();
	~StArray();

	bool addStudent(int std_id, char* std_name);
	bool addEE_Course(int std_id, int course_num, char* course_name, int hw_num, double hw_weight);
	bool addCS_Course(int std_id, int course_num, char* course_name, int hw_num, double hw_weight, bool is_takef, char* book_name);
	bool setHwGrade(int std_id, int course_num, int hw_id, int hw_grade);
	bool setExamGrade(int std_id, int course_num, int exam_grade);
	bool setFactor(int course_num, int factor);
	bool printStudent(int std_id);
	void printAll();
	void resetStArray();

private:
	Student* students_array_[MAX_STUDENT_NUM];
	int students_num_;
};

#endif
