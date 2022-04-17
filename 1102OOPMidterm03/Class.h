#pragma once
#include "Student.h"



typedef struct Record{
	string subject;
	int studentNum;
	vector<string> studentName;
	vector<float> scores;
}Record;

class Class
{
private:
	vector<Student> students;
public:
	static vector<Record> records;
	Class();
	void refreshRecords();
	void addStudent(Student student);
	void deleteStudent(Student student);
	void deleteStudent(string studentName);
	void printNumOfStudent(string subjectName);
	void printNumOfStudent();
	void printAvgScore(string subjectName);
	void printAvgScore();
	void printSubjectInformation(string subjectName);
	void printSubjectInformation();
};

