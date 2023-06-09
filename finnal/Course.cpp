#include"Course.h"
//���캯��
Course::Course(const string& id, const string& name, const string& time)
    : courseID(id), courseName(name), tutoringTime(time) {}
//�õ��γ�ID
string Course::getCourseID() const {
    return courseID;
}
//�õ��γ���
string Course::getCourseName() const {
    return courseName;
}
//
string Course::getTutoringTime() const {
    return tutoringTime;
}
//Bcourse ���캯��
BCourse::BCourse(const string& id, const string& name, const string& time, const string& teacherName)
    : Course(id, name, time), teacher(teacherName) {}
//�õ�����
string BCourse::getType() const {
    return "����";
}
//չʾ�γ�ϸ��
void BCourse::showDetails() const {
    cout << "�γ�����" << getCourseName() << endl;
    cout << "�γ����ͣ�" << getType() << endl;
    cout << "���ɸ���ʱ�䣺" << tutoringTime << endl;
    cout << "�ο���ʦ��" << teacher << endl;
}
//
string BCourse::getTeacher() const {
    return teacher;
}

XCourse::XCourse(const string& id, const string& name, const string& time, const string& teacherName)
    : Course(id, name, time), teacher(teacherName) {}

string XCourse::getType() const {
    return "ѡ��";
}

void XCourse::showDetails() const {
}

string XCourse::getTeacher() const {
    return teacher;
}