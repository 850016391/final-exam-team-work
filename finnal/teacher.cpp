#include "teacher.h"
#include "course.h"

Teacher::Teacher(const string& teacherName, const string& teacherPassword)
    : name(teacherName), password(teacherPassword) {}

string Teacher::getName() const {
    return name;
}

string Teacher::getPassword() const {
    return password;
}

vector<Course*> Teacher::getCourseList() const {
    return courses;
}

void Teacher::addCourse(Course* course) {
    courses.push_back(course);
}

void Teacher::searchCourses() const {
    if (courses.empty()) {
        cout << "您还没有添加任何课程！" << endl;
        return;
    }

    cout << "您的课程列表：" << endl;
    for (const auto& course : courses) {
        course->showDetails();
        cout << endl;
    }
}

void Teacher::addTutoringInfo(const string& courseID, const string& info) {
    for (const auto& course : courses) {
        if (course->getCourseID() == courseID) {
            cout << "留言已添加至课程：" << course->getCourseName() << endl;
            // 在此处执行添加留言的操作
            ofstream outputFile(courseID + ".txt", ios::app);
            if (outputFile.is_open()) {
                outputFile << info << endl;
                outputFile.close();
            }
            else {
                cout << "无法打开留言文件！" << endl;
            }

            break;
        }
    }
}

void Teacher::deleteCourse(const string& courseID) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if ((*it)->getCourseID() == courseID) {
            delete* it;
            courses.erase(it);
            break;
        }
    }
}
