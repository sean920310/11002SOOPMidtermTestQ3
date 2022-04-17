#pragma once
#include <string>
#include <vector>
using namespace std;

typedef struct {
	string subName;
	float score;
}Subject;

class Student
{
private:
	int id;
	string name;
	vector<Subject> subjects;
public:
	static int count;
	static int defaultCount;
	static vector<Student> table;

	Student();
	Student(const Student& rhs);
	Student(string name);
	Student& operator=(const Student& rhs);
	bool operator==(const Student& rhs);
	string getName();
	vector<Subject> getSubject();
	int getId();
	void addGrade(string subject, int point);
	void deleteGrade(string subject);
	void deleteGrade();
	void printGrade();
};

