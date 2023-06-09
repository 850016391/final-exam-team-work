#pragma once
#include <string>  
#include <vector>
#include <fstream>
#include "course.h" 
using namespace std;

class Teacher {
private:
    string name;
    string password;
    vector<Course*> courses;
public:
    Teacher(const string& teacherName, const string& teacherPassword);

    string getName() const;
    string getPassword() const;
    vector<Course*> getCourseList() const;
    void addCourse(Course* course);
    void deleteCourse(const string& courseID);
    void searchCourses() const;
    void addTutoringInfo(const string& courseID, const string& info);

    friend istream& operator>>(istream& input, Teacher& teacher);
};