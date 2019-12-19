#ifndef EE_COURSE_H
#define EE_COURSE_H

#include "Course.h"
#include <iostream>
#include <string.h>

using namespace std;

class EE_Course : public Course 
{
public: 
	EE_Course(int course_num, char* course_name, int hw_num, double hw_weight);
	~EE_Course();

	int getFactor() const;
	bool setFactor(int factor);
	int getCourseGrade() const;

private:
	int factor_;

};

#endif
