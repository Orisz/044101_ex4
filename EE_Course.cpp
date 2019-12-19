#include "EE_Course.h"

//************************************************************************************************************
//* Function name : EE_Course::EE_Course
//* Description   : constructor of an EE_Course object
//* Parameters    : int course_num , char* course_name, int hw_num, double hw_weight
//* Return value  : None.
//************************************************************************************************************

EE_Course::EE_Course(int course_num, char* course_name, int hw_num, double hw_weight):
	Course(course_num, course_name, hw_num, hw_weight), factor_(0)
{}

//************************************************************************************************************
//* Function name : EE_Course::~EE_Course
//* Description   : destructor of an EE_Course object
//* Parameters    : None.
//* Return value  : None.
//************************************************************************************************************

EE_Course::~EE_Course()
{}

//************************************************************************************************************
//* Function name : EE_Course::getFactor
//* Description   : returns the given factor on the course_grade.CONST function
//* Parameters    : None.
//* Return value  : int factor - the fctor given
//************************************************************************************************************

int EE_Course::getFactor() const
{
	return factor_;
}

//************************************************************************************************************
//* Function name : EE_Course::setFactor
//* Description   : given a desired factor value sets it as the course factor
//* Parameters    : int factor
//* Return value  : bool true (if the factor within the legal range) false(factor value ilegal)
//************************************************************************************************************

bool EE_Course::setFactor(int factor)
{
	if (factor > 100 || factor < -100)
		return false;
	factor_ = factor;
	return true;
}

//************************************************************************************************************
//* Function name : EE_Course::getCourseGrade
//* Description   : with respect to the factor,exam and hw grades returns the course final grade.CONST function
//* Parameters    : None.
//* Return value  : int coure_grade
//************************************************************************************************************

int EE_Course::getCourseGrade() const
{
	int course_grade = (1 - hw_weight_)*exam_grade_ + hw_weight_*getHwAverage() + 0.5 + factor_;
	if (course_grade > 100)
		course_grade = 100;
	else if (course_grade < 0)
		course_grade = 0;
	return course_grade;
}