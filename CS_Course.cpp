#include "CS_Course.h"

//************************************************************************************************************
//* Function name : CS_Course::CS_Course
//* Description   : constructor of the CS_Course object
//* Parameters    : int course_num, char* course_name, int hw_num, double hw_weight, bool is_takef, char* course_book
//* Return value  : None.
//************************************************************************************************************

CS_Course::CS_Course(int course_num, char* course_name, int hw_num, double hw_weight, bool is_takef, char* course_book) : 
	Course(course_num, course_name, hw_num, hw_weight), is_takef_(is_takef)
{
	course_book_ = new char[strlen(course_book) + 1];
	strcpy(course_book_, course_book);
}

//************************************************************************************************************
//* Function name : CS_Course::~CS_Course
//* Description   : destructor of the CS_Course object
//* Parameters    : None.
//* Return value  : None.
//************************************************************************************************************

CS_Course::~CS_Course()
{
	delete []course_book_;
}

//************************************************************************************************************
//* Function name : CS_Course::isTakef
//* Description   : tells us if the hw on this course are "Takef" or not.CONST function!
//* Parameters    : None.
//* Return value  : bool - true(if takef) false (if not takef)
//************************************************************************************************************

bool CS_Course::isTakef() const
{
	return is_takef_;
}

//************************************************************************************************************
//* Function name : CS_Course::getBook
//* Description   : returns a pointer to a copy of the course book name
//* Parameters    : None.
//* Return value  : char* copy_book - ptr to the course book name
//************************************************************************************************************

char* CS_Course::getBook()
{
	char* copy_book = new char[strlen(course_book_) + 1];
	strcpy(copy_book, course_book_);
	return copy_book;
}

//************************************************************************************************************
//* Function name : CS_Course::setTakef
//* Description   : given the hw in this course should be takef(or not),sets it to be so.
//* Parameters    : bool is_takef (true if the hw takef)
//* Return value  : bool true(always)
//************************************************************************************************************

bool CS_Course::setTakef(bool is_takef)
{
	is_takef_ = is_takef;
	return true;
}

//************************************************************************************************************
//* Function name : CS_Course::setBook
//* Description   : given a pointer to a book name,sets it to be the new name of the course book.
//* Parameters    : char* course_new_book
//* Return value  : None.
//************************************************************************************************************

void CS_Course::setBook(char* course_new_book)
{
	delete []course_book_;
	course_book_ = new char[strlen(course_new_book) + 1];
	strcpy(course_book_, course_new_book);
}

//************************************************************************************************************
//* Function name : CS_Course::getCourseGrade
//* Description   : wiht respect to the fact that hw are takef or not , exam grade and hw grade returns the course final grade
//* Parameters    : None.
//* Return value  : int exam_grade
//************************************************************************************************************

int CS_Course::getCourseGrade() const
{
	int course_grade = (1 - hw_weight_)*exam_grade_ + hw_weight_*getHwAverage() + 0.5; //calc grade with hw
	if (is_takef_ == true)
	{
		return course_grade;
	}
	else if (is_takef_ == false)
	{
		if (course_grade > exam_grade_)//exam is better then exam with hw
			return course_grade;
		else
			return exam_grade_;
	}
}
