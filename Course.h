#ifndef COURSE_H
#define COURSE_H

using namespace std;

class Course {
public:
	Course(int course_num, char* course_name, int hw_num, double hw_weight);//more constructors???
	~Course();

	int getNum() const;
	char* getName() const;
	int getExamGrade() const;
	int getHwGrade(int hw_id) const;
	int getHwNum() const;
	double getHwWeigh() const;
	double getHwAverage() const;
	int getCourseGrade() const;
	bool setExamGrade(int exam_grade);
	bool setHwGrade(int hw_id, int hw_grade);

protected:
	int course_num_;
	char* course_name_;
	int hw_num_;
	double hw_weight_;
	int exam_grade_;
	int* hw_grade_;	
};

#endif
