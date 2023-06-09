#include"Course.h"
//构造函数
Course::Course(const string& id, const string& name, const string& time)
    : courseID(id), courseName(name), tutoringTime(time) {}
//得到课程ID
string Course::getCourseID() const {
    return courseID;
}
//得到课程名
string Course::getCourseName() const {
    return courseName;
}
//
string Course::getTutoringTime() const {
    return tutoringTime;
}
//Bcourse 构造函数
BCourse::BCourse(const string& id, const string& name, const string& time, const string& teacherName)
    : Course(id, name, time), teacher(teacherName) {}
//得到类型
string BCourse::getType() const {
    return "必修";
}
//展示课程细节
void BCourse::showDetails() const {
    cout << "课程名：" << getCourseName() << endl;
    cout << "课程类型：" << getType() << endl;
    cout << "答疑辅导时间：" << tutoringTime << endl;
    cout << "任课老师：" << teacher << endl;
}
//
string BCourse::getTeacher() const {
    return teacher;
}

XCourse::XCourse(const string& id, const string& name, const string& time, const string& teacherName)
    : Course(id, name, time), teacher(teacherName) {}

string XCourse::getType() const {
    return "选修";
}

void XCourse::showDetails() const {
}

string XCourse::getTeacher() const {
    return teacher;
}