
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
        cout << "����û��ѡ���κογ�!" << endl;
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
            cout << "�γ�:" << course->getCourseName() << " ��������Ϣ:" << endl;
            ifstream inputFile(courseID + ".txt");
            if (inputFile.is_open()) {
                string line;
                while (getline(inputFile, line)) {
                    cout << line << endl;
                }
                inputFile.close();
            }
            else {
                cout << "�޷��������ļ�!" << endl;
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
            cout << "������������γ�:" << course->getCourseName() << endl;
            ofstream outputFile(courseID + ".txt", ios::app);
            if (outputFile.is_open()) {
                outputFile << info << endl;
                outputFile.close();
            }
            else {
                cout << "�޷��������ļ�!" << endl;
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
                cout << "������������γ�:" << courseName << endl;
                ofstream outputFile(courseID + ".txt", ios::app);
                if (outputFile.is_open()) {
                    outputFile << info << endl;
                    outputFile.close();
                }
                else {
                    cout << "�޷��������ļ�!" << endl;
                }
                outputFile.close();
                break;
            }
        }
        courseFile.close();
    }
    else {
        cout << "�޷��򿪿γ��ļ���" << endl;
    }
    if (flag == 0)
    {
        cout << "û�д˿γ̣�" << endl;
    }
}
