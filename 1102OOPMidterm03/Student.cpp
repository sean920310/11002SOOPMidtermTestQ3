#include "Student.h"
#include <iostream>

int Student::count = 0;
int Student::defaultCount = 0;

vector<Student> Student::table = {};


Student::Student()
{
	this->id = count;
	this->name = "Student" + to_string(defaultCount++);
	count++;
	table.push_back(*this);
}

Student::Student(const Student& rhs)
{
	this->id = rhs.id;
	this->name = rhs.name;
	this->subjects = rhs.subjects;
}

Student::Student(string name)
{
	bool isSame = false;
	if (name.find("Student") != size_t(0)) {
		for (auto n : table) {
			if (n.name == name) {
				isSame = true;
				break;
			}
		}
		if (isSame) {
			cout << "Error: The name " << name << " exists. Use default name: Student" << defaultCount << ".\n";
			this->name = "Student" + to_string(defaultCount++);
		}
		else {
			this->name = name;
		}
	}
	else
	{
		cout << "Error: The name Student is reserved word. Use default name: Student" << defaultCount << ".\n";
		this->name = "Student" + to_string(defaultCount++);
	}
	id = count++;
	table.push_back(*this);
}

Student& Student::operator=(const Student& rhs)
{
	this->id = rhs.id;
	this->name = rhs.name;
	this->subjects = rhs.subjects;
	return *this;
}

bool Student::operator==(const Student& rhs)
{
	return (this->name == rhs.name);
}

string Student::getName()
{
	return this->name;
}

vector<Subject> Student::getSubject()
{
	return this->subjects;
}

int Student::getId()
{
	return id;
}

void Student::addGrade(string subject, int point)
{
	for (auto& sub : subjects) {
		if (sub.subName == subject) {
			sub.score = point;
			return;
		}
	}
	Subject newSub = { subject,point };
	subjects.push_back(newSub);
}

void Student::deleteGrade(string subject)
{
	int i = 0;
	for (; i < subjects.size(); i++) {
		if (subjects[i].subName == subject)
			break;
	}
	if (i == subjects.size())
		cout << "Error: Subject " << subject << " could not be found.\n";
	else
		subjects.erase(subjects.begin() + i);
}

void Student::deleteGrade()
{
	subjects.clear();
}

void Student::printGrade()
{
	if (!subjects.size()) {
		cout << "Error: Grade could not be found.\n";
		return;
	}
	cout << "ID: " << id << " Name: " << name << endl;
	for (auto sub : subjects) {
		cout << sub.subName << " " << sub.score << endl;
	}
}
