#pragma once
#include <string>
#include<iostream>
using namespace std;
class Course {
protected:
    string courseID;
    string courseName;
    string tutoringTime;

public:
    Course(const string& id, const string& name, const string& time);

    virtual string getType() const = 0;
    virtual void showDetails() const = 0;

    string getCourseID() const;

    string getCourseName() const;

    string getTutoringTime() const;

};
class BCourse : public Course {
private:
    string teacher;

public:
    BCourse(const string& id, const string& name, const string& time, const string& teacherName);

    string getType() const override;

    void showDetails() const override;

    string getTeacher() const;
};
class XCourse : public Course {
private:
    string teacher;

public:
    XCourse(const string& id, const string& name, const string& time, const string& teacherName);

    string getType() const override;

    void showDetails() const override;

    string getTeacher() const;
};
