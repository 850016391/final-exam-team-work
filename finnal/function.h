#pragma once
#include"teacher.h"
#include"student.h"
using namespace std;
istream& operator>>(istream& input, Teacher& teacher);
istream& operator>>(istream& input, Student& student);
void saveTeachers(const string& filename, const vector<Teacher>& teachers);
void saveStudents(const string& filename, const vector<Student>& students);
void saveCourses(const string& filename, const vector<Course*>& courses);
void studentAddMessage(Student& student,string);
void loaddata();
bool check(string,int);
void showBCourse();