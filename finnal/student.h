#pragma once
#include <string>  
#include <vector>
#include<fstream>
#include "course.h"

using namespace std;

class Student {
private:
    string name;
    string password;
    vector<Course*> selectedCourses;

public:
    Student(const string& studentName, const string& studentPassword);

    string getName() const;
    string getPassword() const;

    void selectCourse(Course* course);
    void dropCourse(const string& courseID);
    void showSelectedCourses() const;
    void showTutoringInfo(const string& courseID) const;
    void addTutoringInfo(const string& courseID, const string& info);

    friend istream& operator>>(istream& input, Student& student);
};