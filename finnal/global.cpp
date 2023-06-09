#include"global.h"
void menu() 
{
    int i;
    int option;
    string username, password;

    while (true) 
    {
        system("cls");
        cout << "��ӭʹ�ÿγ̹���ϵͳ��" << endl;
        cout << "��ѡ��������ͣ�" << endl;
        cout << "1. ��ʦ��¼" << endl;
        cout << "2. ѧ����¼" << endl;
        cout << "3. �����˺�" << endl;
        cout << "0. �˳�" << endl;
        cout << "��ѡ�������";
        cin >> option;

        if (option == 0) 
        {
            break;
        }
        if (option == 1) {
            cout << "�������û�����";
            cin >> username;
            cout << "���������룺";
            cin >> password;
            bool isTeacherFound = false;
            Teacher* currentTeacher = nullptr;

            for (auto& teacher : teachers) {
                if (teacher.getName() == username && teacher.getPassword() == password) {
                    isTeacherFound = true;
                    currentTeacher = &teacher;
                    break;
                }
            }

            if (!isTeacherFound) {
                cout << "�û������������" << endl;
                system("pause");//ͣ���ڵ�ǰҳ��
                continue;
            }

            while (true) {
                system("cls");
                cout << "��ӭ����ʦ " << currentTeacher->getName() << "��" << endl;
                cout << "��ѡ�������" << endl;
                cout << "1. �鿴�ҵĿγ�" << endl;
                cout << "2. ��ӿγ�" << endl;
                cout << "3. ɾ���γ�" << endl;
                cout << "4. �������" << endl;
                cout << "0. ����" << endl;
                cout << "��ѡ�������";
                cin >> option;

                if (option == 0) {
                    break;
                }

                switch (option) {
                case 1:
                    currentTeacher->searchCourses();
                    break;
                case 2: {
                    string courseID, courseName, tutoringTime, courseType, teacher;
                    cout << "������γ�ID��";
                    cin >> courseID;
                    // ���γ�ID�Ƿ��Ѵ���
                    bool isCourseIDExists = false;
                    for (const auto& course : courses) {
                        if (course->getCourseID() == courseID) {
                            isCourseIDExists = true;
                            break;
                        }
                    }

                    if (isCourseIDExists) {
                        cout << "�γ�ID�Ѵ��ڣ�" << endl;
                        break;
                    }
                    cout << "������γ�����";
                    cin >> courseName;
                    cout << "��������ɸ���ʱ�䣺";
                    cin >> tutoringTime;
                    cout << "������γ����ͣ�����/ѡ�ޣ���";
                    cin >> courseType;
                    cout << "�������ο���ʦ��";
                    cin >> teacher;

                    Course* course;
                    if (courseType == "����") {
                        course = new BCourse(courseID, courseName, tutoringTime, teacher);
                    }
                    else if (courseType == "ѡ��") {
                        course = new XCourse(courseID, courseName, tutoringTime, teacher);
                    }
                    else {
                        cout << "��Ч�Ŀγ����ͣ�" << endl;
                        break;
                    }

                    currentTeacher->addCourse(course);
                    courses.push_back(course);
                    saveCourses(courseFilename, courses);
                    break;
                }
                case 3: {
                    string courseID;
                    cout << "������Ҫɾ���Ŀγ�ID��";
                    cin >> courseID;

                    currentTeacher->deleteCourse(courseID);
                    saveCourses(courseFilename, courses);
                    break;
                }
                case 4: {
                    string courseID, message;
                    cout << "������γ�ID��";
                    cin >> courseID;
                    cout << "������������Ϣ��";
                    cin >> message;

                    currentTeacher->addTutoringInfo(courseID, message);
                    break;
                }
                default:
                    cout << "��Ч�Ĳ�����" << endl;
                    break;
                }
                system("pause");
            }
        }
        else if (option == 2) {
            cout << "�������û�����";
            cin >> username;
            cout << "���������룺";
            cin >> password;
            bool isStudentFound = false;
            Student* currentStudent = nullptr;

            for (auto& student : students) {
                if (student.getName() == username && student.getPassword() == password) {
                    isStudentFound = true;
                    currentStudent = &student;
                    break;
                }
            }

            if (!isStudentFound) {
                cout << "�û������������" << endl;
                system("pause");
                continue;
            }

            while (true) {
                system("cls");
                cout << "��ӭ��ѧ�� " << currentStudent->getName() << "��" << endl;
                cout << "��ѡ�������" << endl;
                cout << "1. �鿴��ѡ�γ�" << endl;
                cout << "2. �鿴���޿γ�" << endl;
                cout << "3. ѡ��γ�" << endl;
                cout << "4. ��ѡ�γ�" << endl;
                cout << "5. �ش�γ̴���" << endl;
                cout << "0. ����" << endl;
                cout << "��ѡ�������";
                cin >> option;

                if (option == 0) {
                    break;
                }

                switch (option) {
                case 1:
                    currentStudent->showSelectedCourses();
                    break;
                case 2: 
                    // ��ȡ�γ��ļ�����ʾ���޿γ��б�
                    showBCourse();
                    break;
                case 3: {
                    ifstream courseFile(courseFilename);
                    if (courseFile.is_open()) {
                        string courseID, courseName, courseType, tutoringTime, teacher;
                        while (courseFile >> courseID >> courseName >> courseType >> tutoringTime >> teacher) {
                            if (courseType == "ѡ��") {
                                cout << "�γ�ID��" << courseID << endl;
                                cout << "�γ�����" << courseName << endl;
                                cout << "���ɸ���ʱ�䣺" << tutoringTime << endl;
                                cout << "�ο���ʦ��" << teacher << endl;
                                cout << "---------------------------" << endl;
                            }
                            else {
                                cout << "��ʦ��δ�ϴ�ѡ�޿γ�" << endl;
                            }

                        }
                        courseFile.close();
                    }
                    else {
                        cout << "�޷��򿪿γ��ļ���" << endl;
                    }

                    string courseID;
                    cout << "������Ҫѡ��Ŀγ�ID��";
                    cin >> courseID;

                    bool isCourseFound = false;
                    for (auto& course : courses) {
                        if (course->getCourseID() == courseID) {
                            currentStudent->selectCourse(course);
                            isCourseFound = true;
                            break;
                        }
                    }

                    if (!isCourseFound) {
                        cout << "δ�ҵ�ָ���Ŀγ̣�" << endl;
                    }
                    else {
                        cout << "ѡ�γɹ���" << endl;
                        currentStudent->showSelectedCourses();  // ��ʾ��ѡ�γ�
                    }
                    break;
                }
                case 4: {
                    string courseID;
                    cout << "������Ҫ��ѡ�Ŀγ�ID��";
                    cin >> courseID;

                    currentStudent->dropCourse(courseID);
                    break;
                }
                case 5: {
                    string courseID;
                    cout << "������γ�ID��";
                    cin >> courseID;
                    currentStudent->showTutoringInfo(courseID);
                    studentAddMessage(*currentStudent,courseID);
                    break;
                }
                default:
                    cout << "��Ч�Ĳ�����" << endl;
                    break;
                }
                system("pause");
            }
        }
        else if (option == 3) 
        {
            string accountType;
            cout << "�������˺����ͣ�ѧ��/��ʦ����" << endl;
            cin >> accountType;
            if (accountType == "ѧ��") {
                string studentName, studentPassword;
                cout << "������ѧ�����������룺" << endl;
                cin >> studentName >> studentPassword;
                if (check(studentName,0))
                {
                    students.push_back(Student(studentName, studentPassword));
                    saveStudents(studentFilename, students);
                    cout << "����ѧ���˺ųɹ�" << endl;
                }
                else
                {
                    cout << "����ʧ�ܣ����д�ѧ���˺�" << endl;
                }

            }
            else if (accountType == "��ʦ") 
            {
                string teacherName, teacherPassword;
                cout << "�������ʦ���������룺" << endl;
                cin >> teacherName >> teacherPassword;
                if (check(teacherName, 1))
                {
                    teachers.push_back(Teacher(teacherName, teacherPassword));
                    saveTeachers(teacherFilename, teachers);
                    cout << "������ʦ�˺ųɹ�" << endl;
                }
                else
                {
                    cout << "����ʧ�ܣ����д˽�ʦ�˺�" << endl;
                }

            }
            else {
                cout << "��Ч���˺����͡�" << endl;
            }
             system("pause");
        }
        else 
        {
            cout << "��Ч����ݣ�" << endl;
            system("pause");
        }
    }
}