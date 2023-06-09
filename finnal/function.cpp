#include"function.h"
#include"teacher.h"
#include"student.h"
#include"Course.h"
#include"config.h"
istream& operator>>(istream& input, Teacher& teacher) {
    input >> teacher.name >> teacher.password;
    return input;
}
istream& operator>>(istream& input, Student& student) {
    input >> student.name >> student.password;
    return input;
}
void saveTeachers(const string& filename, const vector<Teacher>& teachers) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const auto& teacher : teachers) {
            outputFile << teacher.getName() << " " << teacher.getPassword() << endl;
        }
        outputFile.close();
    }
}
void saveStudents(const string& filename, const vector<Student>& students) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const auto& student : students) {
            outputFile << student.getName() << " " << student.getPassword() << endl;
        }
        outputFile.close();
    }
}
void saveCourses(const string& filename, const vector<Course*>& courses) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const auto& course : courses) {
            if (BCourse* bCourse = dynamic_cast<BCourse*>(course)) {
                outputFile << bCourse->getCourseID() << " "
                    << bCourse->getCourseName() << " "
                    << bCourse->getType() << " "
                    << bCourse->getTutoringTime() << " "
                    << bCourse->getTeacher() << endl;
            }
            else if (XCourse* xCourse = dynamic_cast<XCourse*>(course)) {
                outputFile << xCourse->getCourseID() << " "
                    << xCourse->getCourseName() << " "
                    << xCourse->getType() << " "
                    << xCourse->getTutoringTime() << " "
                    << xCourse->getTeacher() << endl;
            }
        }
        outputFile.close();
    }
}
void studentAddMessage(Student& student,string courseID) {
    string message;
    cout << "������������Ϣ��";
    cin >> message;

    student.addTutoringInfo(courseID, message);
}
void loaddata()
{
    ifstream teacherFile(teacherFilename);
    if (teacherFile.is_open()) {
        Teacher teacher("", "");
        while (teacherFile >> teacher) {
            teachers.push_back(teacher);
        }
        teacherFile.close();
    }

    // ���ļ�����ѧ����Ϣ
    ifstream studentFile(studentFilename);
    if (studentFile.is_open()) {
        Student student("", "");
        while (studentFile >> student) {
            students.push_back(student);
        }
        studentFile.close();
    }

    // ���ļ����ؿγ���Ϣ
    ifstream courseFile(courseFilename);
    if (courseFile.is_open()) {
        string courseID, courseName, courseType, tutoringTime, teacher;
        while (courseFile >> courseID >> courseName >> courseType >> tutoringTime >> teacher) {
            Course* course;
            if (courseType == "����") {
                course = new BCourse(courseID, courseName, tutoringTime, teacher);
            }
            else if (courseType == "ѡ��") {
                course = new XCourse(courseID, courseName, tutoringTime, teacher);
            }
            else {
                continue; // ������Ч�Ŀγ�����
            }
            courses.push_back(course);
        }
        courseFile.close();
    }
}
bool check(string t_name,int flag)
{
    if (flag == 1)
    {
        ifstream teacherFile(teacherFilename);
        if (teacherFile.is_open())
        {
            string m_name, m_password;
            while (teacherFile >> m_name >> m_password)
            {
                if (m_name == t_name)
                {
                    return false;
                }
            }
        }
    }
    else
    {
        ifstream studentFile(studentFilename);
        if (studentFile.is_open())
        {
            string m_name, m_password;
            while (studentFile >> m_name >> m_password)
            {
                if (m_name == t_name)
                {
                    return false;
                }
            }
        }
    }
    return true;

}
void showBCourse()
{
    ifstream courseFile(courseFilename);
    if (courseFile.is_open()) {
        string courseID, courseName, courseType, tutoringTime, teacher;
        while (courseFile >> courseID >> courseName >> courseType >> tutoringTime >> teacher) {
            if (courseType == "����") {
                cout << "�γ�ID��" << courseID << endl;
                cout << "�γ�����" << courseName << endl;
                cout << "���ɸ���ʱ�䣺" << tutoringTime << endl;
                cout << "�ο���ʦ��" << teacher << endl;
                cout << "---------------------------" << endl;
            }
        }
        courseFile.close();
    }
    else {
        cout << "�޷��򿪿γ��ļ���" << endl;
    }
}