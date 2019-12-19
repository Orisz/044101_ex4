#include <iostream>
#include "Course.h"
#include <string.h>

//************************************************************************************************************
//* Function name : Course::Course
//* Description   : constructor of Course Object
//* Parameters    : number of the course , the name of thecourse , number of hw assingments , the weight of the hw
//* Return value  : None.
//************************************************************************************************************

Course::Course(int course_num, char* course_name, int hw_num, double hw_weight):
	course_num_(course_num), hw_num_(hw_num), hw_weight_(hw_weight) 
{
	course_name_ = new char[strlen(course_name)+1];
	strcpy(course_name_, course_name);
	if (hw_num != 0)
	{
		hw_grade_ = new int[hw_num];
		for(int i = 0 ; i < hw_num ; i++)
		{
			hw_grade_[i] = 0;
		}
	}
	exam_grade_ = 0;
}

//************************************************************************************************************
//* Function name : Course::~Course
//* Description   : destructor of Course Object
//* Parameters    : None.
//* Return value  : None.
//************************************************************************************************************

Course::~Course() {
	delete []course_name_;
	if (hw_num_ != 0)
		delete []hw_grade_;
}

//************************************************************************************************************
//* Function name : Course::getNum
//* Description   : retuns the number of the course.CONST function!
//* Parameters    : None.
//* Return value  : int the number o the course
//************************************************************************************************************

int Course::getNum() const
{
	return course_num_;
}

//************************************************************************************************************
//* Function name : Course::getName
//* Description   : retuns a pointer to a copy of the course name.CONST function!
//* Parameters    : None.
//* Return value  : char* ptr to the course name
//************************************************************************************************************

char* Course::getName() const
{
	char* copy_name = new char[strlen(course_name_) + 1];
	strcpy(copy_name, course_name_);
	return copy_name;
}

//************************************************************************************************************
//* Function name : Course::getExamGrade
//* Description   : retuns the course exam grade.CONST function!
//* Parameters    : None.
//* Return value  : int exam grade
//************************************************************************************************************

int Course::getExamGrade() const
{
	return exam_grade_;
}

//************************************************************************************************************
//* Function name : Course::getHwGrade
//* Description   : retuns the hw grade of a specific hw paper.CONST function!
//* Parameters    : int hw_id - the specific hw paper we want to know its grade
//* Return value  : int hw grade
//************************************************************************************************************

int Course::getHwGrade(int hw_id) const
{
	if (hw_id > hw_num_)
		return 0;
	return hw_grade_[hw_id];
}

//************************************************************************************************************
//* Function name : Course::getHwNum
//* Description   : retuns the number of hw papres we have.CONST function!
//* Parameters    : None.
//* Return value  : int hw num
//************************************************************************************************************

int Course::getHwNum() const
{
	return hw_num_;
}

//************************************************************************************************************
//* Function name : Course::getHwWeigh
//* Description   : retuns the Weight of the hw in this course.CONST function!
//* Parameters    : None.
//* Return value  : int hw weight
//************************************************************************************************************

double Course::getHwWeigh() const
{
	return hw_weight_;
}

//************************************************************************************************************
//* Function name : Course::getHwAverage
//* Description   : retuns the average of all the hw papers in the course.CONST function!
//* Parameters    : None.
//* Return value  : double -  the average hw grade
//************************************************************************************************************

double Course::getHwAverage() const
{
	if (hw_num_ == 0)
		return 0;
	double sum = 0;
	for (int i = 0; i < hw_num_; i++)
	{
		sum = sum + hw_grade_[i];
	}
	return (sum / hw_num_);
}

//************************************************************************************************************
//* Function name : Course::getCourseGrade
//* Description   : retuns the course final grade with respect to the exam and the hw.CONST function!
//* Parameters    : None.
//* Return value  : int -  course grade
//************************************************************************************************************

int Course::getCourseGrade() const
{
	int course_grade = (1-hw_weight_)*exam_grade_ + hw_weight_*getHwAverage() + 0.5;
	return course_grade;
}

//************************************************************************************************************
//* Function name : Course::setExamGrade
//* Description   : given a grade within the range sets it as the course exam grade
//* Parameters    : int - exam_grade
//* Return value  : bool - true (when all went well) , false (when the grade wasn't legal)
//************************************************************************************************************

bool Course::setExamGrade(int exam_grade)//answer from shirel
{
	if (exam_grade > 100 || exam_grade < 0)
		return false;
	exam_grade_ = exam_grade;
	return true;
}

//************************************************************************************************************
//* Function name : Course::setHwGrade
//* Description   : given a grade within the range and a hw_id puts it as the hw grade in the course
//* Parameters    : int - hw_id , int - hw_grade
//* Return value  : bool - true (when all went well) , false (when one of the parameters wasn't legal)
//************************************************************************************************************

bool Course::setHwGrade(int hw_id, int hw_grade)
{
	if (hw_id >= hw_num_ || hw_grade > 100 || hw_grade < 0)//instead of hw_id > hw_num_ its hw_id >= hw_num_
		return false;
	hw_grade_[hw_id] = hw_grade;
	return true;
}
