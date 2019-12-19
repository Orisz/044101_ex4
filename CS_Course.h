#ifndef CS_COURSE_H
#define CS_COURSE_H

#include "Course.h"
#include <iostream>
#include <string.h>

using namespace std;

class CS_Course : public Course
{
public:
	CS_Course(int course_num, char* course_name, int hw_num, double hw_weight, bool is_takef, char* course_book);
	~CS_Course();

	bool isTakef() const;
	char* getBook();
	bool setTakef(bool is_takef);
	void setBook(char* course_new_book);
	int getCourseGrade() const;


private:
	bool is_takef_;
	char* course_book_;
};

#endif
