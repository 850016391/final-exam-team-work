
#include "student.h"
#include "course.h"
#include"config.h"
#include"function.h"

Student::Student(const string& studentName, const string& studentPassword)
    : name(studentName), password(studentPassword) {}

string Student::getName() const {
    return name;
}

string Student::getPassword() const {
    return password;
}

void Student::selectCourse(Course* course) {
    selectedCourses.push_back(course);
}

void Student::dropCourse(const string& courseID) {
    for (auto it = selectedCourses.begin(); it != selectedCourses.end(); ++it) {
        if ((*it)->getCourseID() == courseID) {
            selectedCourses.erase(it);
            break;
        }
    }
}

void Student::showSelectedCourses() const {
    if (selectedCourses.empty()) {
        cout << "您还没有选择任何课程!" << endl;
        return;
    }

    for (const auto& course : selectedCourses) {
        course->showDetails();
        cout << endl;
    }
}

void Student::showTutoringInfo(const string& courseID) const {
    for (const auto& course : selectedCourses) {
        if (course->getCourseID() == courseID) {
            cout << "课程:" << course->getCourseName() << " 的留言信息:" << endl;
            ifstream inputFile(courseID + ".txt");
            if (inputFile.is_open()) {
                string line;
                while (getline(inputFile, line)) {
                    cout << line << endl;
                }
                inputFile.close();
            }
            else {
                cout << "无法打开留言文件!" << endl;
            }
            break;
        }
    }
}

void Student::addTutoringInfo(const string& courseID, const string& info) {
    int flag = 0;
    for (const auto& course : selectedCourses) {
        if (course->getCourseID() == courseID) {
            flag = 1;
            cout << "留言已添加至课程:" << course->getCourseName() << endl;
            ofstream outputFile(courseID + ".txt", ios::app);
            if (outputFile.is_open()) {
                outputFile << info << endl;
                outputFile.close();
            }
            else {
                cout << "无法打开留言文件!" << endl;
            }
            outputFile.close();
            break;
        }
    }
    ifstream courseFile(courseFilename);
    if (courseFile.is_open()) {
        string m_courseID, courseName, courseType, tutoringTime, teacher;
        while (courseFile >> m_courseID >> courseName >> courseType >> tutoringTime >> teacher) 
        {
            if (m_courseID == courseID)
            {
                flag = 1;
                cout << "留言已添加至课程:" << courseName << endl;
                ofstream outputFile(courseID + ".txt", ios::app);
                if (outputFile.is_open()) {
                    outputFile << info << endl;
                    outputFile.close();
                }
                else {
                    cout << "无法打开留言文件!" << endl;
                }
                outputFile.close();
                break;
            }
        }
        courseFile.close();
    }
    else {
        cout << "无法打开课程文件！" << endl;
    }
    if (flag == 0)
    {
        cout << "没有此课程！" << endl;
    }
}
