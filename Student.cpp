#include "Student.h"

//************************************************************************************************************
//* Function name : Student::Student
//* Description   : the function is the constructor of the class student, the function initialize all the class member parameters using the constructor of person, or by default values
//* Parameters    : int id - the id of the new student
//*					char* name - the name of the new student
//* Return value  : None.
//************************************************************************************************************


Student::Student(int id, char* name) :
	Person(id, name), ee_course_num_(0), cs_course_num_(0)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		ee_course_array_[i] = NULL;
		cs_course_array_[i] = NULL;
	}
}

//************************************************************************************************************
//* Function name : Student::~Student
//* Description   : the function is the destructor of the class student, the function call the distructors
//* Parameters    : None.
//* Return value  : None.
//************************************************************************************************************

Student::~Student()
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
		delete ee_course_array_[i];
	for (int i = 0; i < MAX_COURSE_NUM; i++)
		delete cs_course_array_[i];
}

//************************************************************************************************************
//* Function name : Student::getCourseCnt
//* Description   : the function returns the sum of the courses that the student have
//* Parameters    : None.
//* Return value  : int - the number of all the courses
//************************************************************************************************************

int Student::getCourseCnt()
{
	return (ee_course_num_ + cs_course_num_);
}

//************************************************************************************************************
//* Function name : Student::addEE_Course
//* Description   : the function adds a new ee course to the list of the ee course of the student
//* Parameters    : None.
//* Return value  : bool - true if the add was successful and false if not
//************************************************************************************************************

bool Student::addEE_Course(EE_Course* ee_course)//change_ori
{
	if (ee_course == NULL)
		return false;
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_array_[i] == NULL)
		{
			ee_course_array_[i] = ee_course;
			ee_course_num_++;
			return true;
		}
	}
	return false;//the array is full
}

//************************************************************************************************************
//* Function name : Student::addCS_Course
//* Description   : the function adds a new cs course to the list of the cs course of the student
//* Parameters    : None.
//* Return value  : bool - true if the add was successful and false if not
//************************************************************************************************************

bool Student::addCS_Course(CS_Course* cs_course)
{
	if (cs_course == NULL)
		return false;
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (cs_course_array_[i] == NULL)
		{
			cs_course_array_[i] = cs_course;
			cs_course_num_++;
			return true;
		}
	}
	return false;//the array is full
}

//************************************************************************************************************
//* Function name : Student::remCourse
//* Description   : the function removes course with the given course num, first find if the course is ee or cs course and then remove it
//* Parameters    : course_num - the number of the course that we need to remove
//* Return value  : bool - true if the remove was successful and false if not
//************************************************************************************************************

bool Student::remCourse(int course_num)
{
	// loop that runs the both course arrays
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		// check if the course is ee course, and find it in the array
		if (ee_course_array_[i]->getNum() == course_num)
		{
			// if we found it we delete it and put NULL instead
			delete ee_course_array_[i];
			ee_course_array_[i] = NULL;
			ee_course_num_--;
			return true;
		}
		// if the course is cs course we do the same in rhe cs array
		if (cs_course_array_[i]->getNum() == course_num)
		{
			delete cs_course_array_[i];
			cs_course_array_[i] = NULL;
			cs_course_num_--;
			return true;
		}
	}
	// if the course is not in the both arrays we return false
	return false;
}

//************************************************************************************************************
//* Function name : Student::getEE_Course
//* Description   : the function return pointer to ee course with the given course number
//* Parameters    : course_num - the number of the course to return
//* Return value  : EE_Course* - pointer of the course with the given number
//************************************************************************************************************

EE_Course* Student::getEE_Course(int course_num)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_array_[i] != NULL)
		{
			if (ee_course_array_[i]->getNum() == course_num)
			{
				return ee_course_array_[i];
			}
		}
	}
	return NULL;
}

//************************************************************************************************************
//* Function name : Student::getCS_Course
//* Description   : the function return pointer to cs course with the given course number
//* Parameters    : course_num - the number of the course to return
//* Return value  : CS_Course* - pointer of the course with the given number
//************************************************************************************************************

CS_Course* Student::getCS_Course(int course_num)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (cs_course_array_[i] != NULL)
		{
			if (cs_course_array_[i]->getNum() == course_num)
			{
				return cs_course_array_[i];
			}
		}
	}
	return NULL;
}

//************************************************************************************************************
//* Function name : Student::getAvg
//* Description   : the function return the average of the all final grades of the student course's
//* Parameters    : None.
//* Return value  : int - the average of all the courses
//************************************************************************************************************

int Student::getAvg()
{
	// if the student have no courses the average is 0
	if ((ee_course_num_ + cs_course_num_) == 0)//change
		return 0;
	double sum_ee = 0;
	double sum_cs = 0;
	// loop the sums all the final grades of ee courses
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_array_[i] != NULL)
		{
			sum_ee = sum_ee + ee_course_array_[i]->getCourseGrade();
		}
	}
	// loop the sums all the final grades of cs courses
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (cs_course_array_[i] != NULL)
		{
			sum_cs = sum_cs + cs_course_array_[i]->getCourseGrade();
		}
	}
	// calculate the average and return it
	return (((sum_ee + sum_cs) / (ee_course_num_ + cs_course_num_)) + 0.5);
}

//************************************************************************************************************
//* Function name : Student::print
//* Description   : the function prints the student details and all the courses he have
//* Parameters    : None.
//* Return value  : None.
//*********************************************************************************************************

void Student::print()
{
	// prints the student details
	cout << "Student Name: " << name_ << '\n';
	cout << "Student ID: " << id_ << '\n';
	cout << "Average Grade: " << getAvg() << "\n\n";
	// loop that prints all the EE courses of the student
	cout << "EE Courses:" << '\n';
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_array_[i] != NULL)
		{
			char* course_name = ee_course_array_[i]->getName();
			cout << ee_course_array_[i]->getNum() << " " << course_name << ": " << ee_course_array_[i]->getCourseGrade() << '\n';
			delete[]course_name;
		}
	}
	cout << '\n';
	// loop that prints all the CS courses of the student
	cout << "CS Courses:" << '\n';
	for (int i = 0; i < cs_course_num_; i++)
	{
		if (cs_course_array_[i] != NULL)
		{
			char* course_name = cs_course_array_[i]->getName();
			cout << cs_course_array_[i]->getNum() << " " << course_name << ": " << cs_course_array_[i]->getCourseGrade() << "\n";
			delete[]course_name;
		}
	}
	cout << '\n';
	return;
}