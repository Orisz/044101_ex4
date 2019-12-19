#include "StArray.h"

//************************************************************************************************************
//* Function name : StArray::StArray
//* Description   : constructor - starting number of students - zero
//* Parameters    : None.
//* Return value  : None.
//************************************************************************************************************
StArray::StArray() : 
	students_num_(0)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		students_array_[i] = NULL;
	}
}
//************************************************************************************************************
//* Function name : StArray::~StArray
//* Description   : destructor
//* Parameters    : None.
//* Return value  : None.
//************************************************************************************************************
StArray::~StArray()
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
		delete students_array_[i];
}
//************************************************************************************************************
//* Function name : StArray::addStudent
//* Description   : when given a student id and name create a student object and put it inside starray
//* Parameters    : int std_id - the student unique id number. char* std_name - thestudent name
//* Return value  : bool - false when student id is ilegal of we didnt get his name (the pointer to it)
//* 				true when the student object was created appropriatly and added to starray
//************************************************************************************************************
bool StArray::addStudent(int std_id, char* std_name)
{
	if (std_id <= 0 || std_name == NULL)
		return false;
	Student* new_student = new Student(std_id, std_name);
	students_array_[students_num_] = new_student;
	students_num_++;
	return true;
}
//************************************************************************************************************
//* Function name : StArray::addEE_Course
//* Description   : with the paramaters given creating an EE course and puts it in the wanted student
//* Parameters    : int std_id - student id , int course_num, char* course_name, int hw_num, double hw_weight
//* Return value  : bool - false if paramaters ilegal/the student doesnt exist/we cloudn't add the course
//*					true - when we added the course as needed
//************************************************************************************************************
bool StArray::addEE_Course(int std_id, int course_num, char* course_name, int hw_num, double hw_weight)
{
	if (std_id <= 0 || course_num <= 0 || course_name == NULL || hw_num < 0 || hw_weight < 0 || hw_weight > 1)//paramater check
		return false;
	for (int i = 0; i < students_num_; i++)//loop over the students array
	{
		if (std_id == students_array_[i]->getID())//we found the wanted student
		{
			EE_Course* new_ee_course = new EE_Course(course_num, course_name, hw_num, hw_weight);//create the course object
			if (students_array_[i]->addEE_Course(new_ee_course) == true)//add the course
			{
				return true;
			}
			else//we failed to add the course
			{
				delete new_ee_course;
				return false;
			}
		}
	}
	return false;//we didnt find the student
}
//************************************************************************************************************
//* Function name : StArray::addCS_Course
//* Description   : with the parameters creating CS course and puts it inside the student
//* Parameters    : int std_id - the student id number, int course_num, char* course_name, int hw_num, double hw_weight, bool is_takef - true if the hw takef, char* book_name
//* Return value  : bool - false if paramaters ilegal/the student doesnt exist/we cloudn't add the course
//*					true - when we added the course as needed
//************************************************************************************************************
bool StArray::addCS_Course(int std_id, int course_num, char* course_name, int hw_num, double hw_weight, bool is_takef, char* book_name)
{
	if (std_id <= 0 || course_num <= 0 || course_name == NULL || hw_num < 0 || hw_weight < 0 || hw_weight > 1 || book_name == NULL)//paramater check
		return false;
	for (int i = 0; i < students_num_; i++)//loop over the students array
	{
		if (std_id == students_array_[i]->getID())//we found the student
		{
			CS_Course* new_cs_course = new CS_Course(course_num, course_name, hw_num, hw_weight, is_takef, book_name);//creating the course object
			if (students_array_[i]->addCS_Course(new_cs_course) == true)//adding the course object
			{
				return true;
			}
			else//we failed to add the course
			{
				delete new_cs_course;
				return false;
			}
		}
	}
	return false;//we didnt find the student
}
//************************************************************************************************************
//* Function name : StArray::setHwGrade
//* Description   : we search a student and put the hw grade in the course specified
//* Parameters    : int std_id - the student id number , int course_num, int hw_id, int hw_grade
//* Return value  : bool - false if paramaters ilegal/the student doesnt exist.
//*					true - when we added the course as needed
//************************************************************************************************************
bool StArray::setHwGrade(int std_id, int course_num, int hw_id, int hw_grade)
{
	if (std_id <= 0 || course_num <= 0 || hw_id < 0 || hw_grade < 0 || hw_grade > 100)//checking paramaters
		return false;
	for (int i = 0; i < students_num_; i++)//loop over students array
	{
		if (std_id == students_array_[i]->getID())//we found the student
		{
			EE_Course* cur_ee_course = students_array_[i]->getEE_Course(course_num);//find the wanted course 
			if (NULL != cur_ee_course)//if the course exists
			{
				if (cur_ee_course->setHwGrade(hw_id, hw_grade) == true)//setting the hw grade
					return true;//here I changed to if else
				else
					return false;
			}
			CS_Course* cur_cs_course = students_array_[i]->getCS_Course(course_num);//same here if the course is CS course
			if (NULL != cur_cs_course)
			{
				if (cur_cs_course->setHwGrade(hw_id, hw_grade) == true)
					return true;//here I changed to if else
				else
					return false;
			}
		}
	}
	return false;//we didnt find the student
}

//************************************************************************************************************
//* Function name : StArray::setExamGrade
//* Description   : the function sets exam grade of the given course for a given student id 
//* Parameters    : std_id - the id of the student we need to set the exam grade for him
//*					course_num - the number of the course we need to set the exam grade
//*					exam_grade - the grade of the exam we need to set
//* Return value  : bool - true if the set was succeeded, and false if not
//************************************************************************************************************

bool StArray::setExamGrade(int std_id, int course_num, int exam_grade)
{
// first check that all input arguments are good
	if (std_id <= 0 || course_num <= 0 || exam_grade < 0 || exam_grade > 100)
		return false;
// loop that runs over all the students in the array
	for (int i = 0; i < students_num_; i++)
	{
// search the student wuth the given id		
		if (std_id == students_array_[i]->getID())
		{
// check if the course is ee course, if yes we set the hw grade for this course			
			EE_Course* cur_ee_course = students_array_[i]->getEE_Course(course_num);
			if (NULL != cur_ee_course)
			{
				cur_ee_course->setExamGrade(exam_grade);
				return true;
			}
// check if the course is cs course, if yes we set the hw grade for this course
			CS_Course* cur_cs_course = students_array_[i]->getCS_Course(course_num);
			if (NULL != cur_cs_course)
			{
				cur_cs_course->setExamGrade(exam_grade);
				return true;
			}
		}
	}
	return false;
}

//************************************************************************************************************
//* Function name : StArray::setFactor
//* Description   : the function sets the factor of the given course for all the students who take the course
//* Parameters    : course_num - the number of the course we need to set the factor
//*					factor - the factor we need to set
//* Return value  : bool - true if the set was succeeded, and false if not
//************************************************************************************************************

bool StArray::setFactor(int course_num, int factor)
{
// first check that all input arguments are good
	if (course_num <= 0 || factor > 100 || factor < -100)
		return false;
// counter to check if we found at least one student that is taking this course
	int counter = 0;
// run over all the sudents in the array, check if the student take the course and set the factor
	for (int i = 0; i < students_num_; i++)
	{
		EE_Course* cur_ee_course = students_array_[i]->getEE_Course(course_num);
		if (cur_ee_course != NULL)
		{
			counter++;
			cur_ee_course->setFactor(factor);
		}
	}
// if we didn't find any student that takes the course we need ti return false
	if (counter == 0)
		return false;
	return true;
}

//************************************************************************************************************
//* Function name : StArray::printStudent
//* Description   : the function prints student details for a given student id 
//* Parameters    : std_id - the id of the student we need to print
//* Return value  : bool - true if the print was succeeded (if the student exists), and false if not
//************************************************************************************************************

bool StArray::printStudent(int std_id)
{
	if (std_id <= 0)
		return false;
// loop search for the student with the given student id
	for (int i = 0; i < students_num_; i++)
	{
		if (std_id == students_array_[i]->getID())
		{
			students_array_[i]->print();
			return true;
		}
	}
	return false;
}

//************************************************************************************************************
//* Function name : StArray::printAll
//* Description   : the function prints all the students in the array 
//* Parameters    : None.
//* Return value  : None.
//************************************************************************************************************

void StArray::printAll()
{
	for (int i = 0; i < students_num_; i++)
	{
		students_array_[i]->print();
	}
	return;
}

//************************************************************************************************************
//* Function name : StArray::resetArray
//* Description   : the function resets the array, delete all the students 
//* Parameters    : None.
//* Return value  : None.
//************************************************************************************************************

void StArray::resetStArray()
{
	for (int i = 0; i < students_num_; i++)
	{
		delete students_array_[i];
		students_array_[i] = NULL;
	}
	students_num_ = 0;
	return;
}
