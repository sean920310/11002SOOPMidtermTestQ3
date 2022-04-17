#include "Class.h"
#include <iostream>
#include <algorithm>

vector<Record> Class::records = {};

void Class::refreshRecords(){
	records.clear();
	
	sort(students.begin(), students.end(), [](Student stu1, Student stu2) {return stu1.getId() < stu2.getId(); });

	for (auto stu : students) {
		for (auto sub : stu.getSubject()) {
			int i = 0;
			for (; i < records.size(); i++) {
				if (records[i].subject == sub.subName) {
					records[i].studentNum++;
					records[i].studentName.push_back(stu.getName());
					records[i].scores.push_back(sub.score);
					break;
				}
			}
			if (i == records.size()) {
				Record newRec;
				newRec.studentNum = 1;
				newRec.subject = sub.subName;
				newRec.studentName.push_back(stu.getName());
				newRec.scores.push_back(sub.score);
				records.push_back(newRec);
			}
		}
	}
}

Class::Class()
{
	students = {};
}

void Class::addStudent(Student student)
{
	for (auto stu : students) {
		if (stu == student) {
			cout << "Error: The student " << student.getName() << " is already in the class.\n";
			return;
		}
	}
	students.push_back(student);
	
}

void Class::deleteStudent(Student student)
{
	int i = 0;
	for (; i < students.size(); i++) {
		if (students[i] == student)
			break;
	}
	if (i != students.size()) {
		students.erase(students.begin() + i);
	}
	else
	{
		cout << "Error: Student " << student.getName() << " could not be found.\n";
	}
}

void Class::deleteStudent(string studentName)
{
	int i = 0;
	for (; i < students.size(); i++) {
		if (students[i].getName() == studentName)
			break;
	}
	if (i != students.size()) {
		students.erase(students.begin() + i);
	}
	else
	{
		cout << "Error: Student " << studentName << " could not be found.\n";
	}
}

void Class::printNumOfStudent(string subjectName)
{
	Record newRec;
	newRec.studentNum = 0;
	newRec.subject = subjectName;
	for (auto stu : students) {
		for (auto sub : stu.getSubject()) {
			if (sub.subName == subjectName)
				newRec.studentNum++;
		}
	}
	if (newRec.studentNum)
		cout << subjectName << " " << newRec.studentNum << endl;
	else
		cout << "Error: Subject " << subjectName << " could not be found.\n";
}

void Class::printNumOfStudent()
{
	refreshRecords();
	for (auto rec : records) {
		cout << rec.subject << " " << rec.studentNum << endl;
	}
	
}

void Class::printAvgScore(string subjectName)
{
	Record newRec;
	newRec.studentNum = 0;
	newRec.subject = subjectName;
	for (auto stu : students) {
		for (auto sub : stu.getSubject()) {
			if (sub.subName == subjectName) {
				newRec.studentNum++;
				newRec.scores.push_back(sub.score);
			}
		}
	}
	float avg = 0;
	for (auto n : newRec.scores) {
		avg += n;
	}
	avg /= newRec.studentNum;
	if (newRec.studentNum)
		cout << subjectName << " " << avg << endl;
	else
		cout << "Error: Subject " << subjectName << " could not be found.\n";
}

void Class::printAvgScore()
{
	refreshRecords();
	for (auto rec : records) {
		float avg = 0;
		for (auto n : rec.scores) {
			avg += n;
		}
		avg /= rec.studentNum;
		cout << rec.subject << " " << avg << endl;
	}
}

void Class::printSubjectInformation(string subjectName)
{
	Record newRec;
	newRec.studentNum = 0;
	newRec.subject = subjectName;
	for (auto stu : students) {
		for (auto sub : stu.getSubject()) {
			if (sub.subName == subjectName) {
				newRec.studentNum++;
				newRec.studentName.push_back(stu.getName());
				newRec.scores.push_back(sub.score);
			}
		}
	}
	if (newRec.studentNum) {
		cout << "Subject name: "<<subjectName << endl;
		cout << "Num of students: " << newRec.studentNum << endl;
		for (int i = 0; i < newRec.studentNum;i++) {
			cout << newRec.studentName[i] << " " << newRec.scores[i]<<endl;
		}

	}
	else
		cout << "Error: Subject " << subjectName << " could not be found.\n";
}

void Class::printSubjectInformation()
{
	refreshRecords();
	for (auto rec : records) {
		cout << "Subject name: " << rec.subject << endl;
		cout << "Num of students: " << rec.studentNum << endl;
		for (int i = 0; i < rec.studentNum; i++) {
			cout << rec.studentName[i] << " " << rec.scores[i] << endl;
		}
	}
}
