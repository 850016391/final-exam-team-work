#include"global.h"
void menu() 
{
    int i;
    int option;
    string username, password;

    while (true) 
    {
        system("cls");
        cout << "欢迎使用课程管理系统！" << endl;
        cout << "请选择操作类型：" << endl;
        cout << "1. 教师登录" << endl;
        cout << "2. 学生登录" << endl;
        cout << "3. 创建账号" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作：";
        cin >> option;

        if (option == 0) 
        {
            break;
        }
        if (option == 1) {
            cout << "请输入用户名：";
            cin >> username;
            cout << "请输入密码：";
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
                cout << "用户名或密码错误！" << endl;
                system("pause");//停留在当前页面
                continue;
            }

            while (true) {
                system("cls");
                cout << "欢迎，教师 " << currentTeacher->getName() << "！" << endl;
                cout << "请选择操作：" << endl;
                cout << "1. 查看我的课程" << endl;
                cout << "2. 添加课程" << endl;
                cout << "3. 删除课程" << endl;
                cout << "4. 添加留言" << endl;
                cout << "0. 返回" << endl;
                cout << "请选择操作：";
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
                    cout << "请输入课程ID：";
                    cin >> courseID;
                    // 检查课程ID是否已存在
                    bool isCourseIDExists = false;
                    for (const auto& course : courses) {
                        if (course->getCourseID() == courseID) {
                            isCourseIDExists = true;
                            break;
                        }
                    }

                    if (isCourseIDExists) {
                        cout << "课程ID已存在！" << endl;
                        break;
                    }
                    cout << "请输入课程名：";
                    cin >> courseName;
                    cout << "请输入答疑辅导时间：";
                    cin >> tutoringTime;
                    cout << "请输入课程类型（必修/选修）：";
                    cin >> courseType;
                    cout << "请输入任课老师：";
                    cin >> teacher;

                    Course* course;
                    if (courseType == "必修") {
                        course = new BCourse(courseID, courseName, tutoringTime, teacher);
                    }
                    else if (courseType == "选修") {
                        course = new XCourse(courseID, courseName, tutoringTime, teacher);
                    }
                    else {
                        cout << "无效的课程类型！" << endl;
                        break;
                    }

                    currentTeacher->addCourse(course);
                    courses.push_back(course);
                    saveCourses(courseFilename, courses);
                    break;
                }
                case 3: {
                    string courseID;
                    cout << "请输入要删除的课程ID：";
                    cin >> courseID;

                    currentTeacher->deleteCourse(courseID);
                    saveCourses(courseFilename, courses);
                    break;
                }
                case 4: {
                    string courseID, message;
                    cout << "请输入课程ID：";
                    cin >> courseID;
                    cout << "请输入留言信息：";
                    cin >> message;

                    currentTeacher->addTutoringInfo(courseID, message);
                    break;
                }
                default:
                    cout << "无效的操作！" << endl;
                    break;
                }
                system("pause");
            }
        }
        else if (option == 2) {
            cout << "请输入用户名：";
            cin >> username;
            cout << "请输入密码：";
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
                cout << "用户名或密码错误！" << endl;
                system("pause");
                continue;
            }

            while (true) {
                system("cls");
                cout << "欢迎，学生 " << currentStudent->getName() << "！" << endl;
                cout << "请选择操作：" << endl;
                cout << "1. 查看已选课程" << endl;
                cout << "2. 查看必修课程" << endl;
                cout << "3. 选择课程" << endl;
                cout << "4. 退选课程" << endl;
                cout << "5. 回答课程答疑" << endl;
                cout << "0. 返回" << endl;
                cout << "请选择操作：";
                cin >> option;

                if (option == 0) {
                    break;
                }

                switch (option) {
                case 1:
                    currentStudent->showSelectedCourses();
                    break;
                case 2: 
                    // 读取课程文件并显示必修课程列表
                    showBCourse();
                    break;
                case 3: {
                    ifstream courseFile(courseFilename);
                    if (courseFile.is_open()) {
                        string courseID, courseName, courseType, tutoringTime, teacher;
                        while (courseFile >> courseID >> courseName >> courseType >> tutoringTime >> teacher) {
                            if (courseType == "选修") {
                                cout << "课程ID：" << courseID << endl;
                                cout << "课程名：" << courseName << endl;
                                cout << "答疑辅导时间：" << tutoringTime << endl;
                                cout << "任课老师：" << teacher << endl;
                                cout << "---------------------------" << endl;
                            }
                            else {
                                cout << "教师暂未上传选修课程" << endl;
                            }

                        }
                        courseFile.close();
                    }
                    else {
                        cout << "无法打开课程文件！" << endl;
                    }

                    string courseID;
                    cout << "请输入要选择的课程ID：";
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
                        cout << "未找到指定的课程！" << endl;
                    }
                    else {
                        cout << "选课成功！" << endl;
                        currentStudent->showSelectedCourses();  // 显示已选课程
                    }
                    break;
                }
                case 4: {
                    string courseID;
                    cout << "请输入要退选的课程ID：";
                    cin >> courseID;

                    currentStudent->dropCourse(courseID);
                    break;
                }
                case 5: {
                    string courseID;
                    cout << "请输入课程ID：";
                    cin >> courseID;
                    currentStudent->showTutoringInfo(courseID);
                    studentAddMessage(*currentStudent,courseID);
                    break;
                }
                default:
                    cout << "无效的操作！" << endl;
                    break;
                }
                system("pause");
            }
        }
        else if (option == 3) 
        {
            string accountType;
            cout << "请输入账号类型（学生/教师）：" << endl;
            cin >> accountType;
            if (accountType == "学生") {
                string studentName, studentPassword;
                cout << "请输入学生姓名和密码：" << endl;
                cin >> studentName >> studentPassword;
                if (check(studentName,0))
                {
                    students.push_back(Student(studentName, studentPassword));
                    saveStudents(studentFilename, students);
                    cout << "创建学生账号成功" << endl;
                }
                else
                {
                    cout << "创建失败，已有此学生账号" << endl;
                }

            }
            else if (accountType == "教师") 
            {
                string teacherName, teacherPassword;
                cout << "请输入教师姓名和密码：" << endl;
                cin >> teacherName >> teacherPassword;
                if (check(teacherName, 1))
                {
                    teachers.push_back(Teacher(teacherName, teacherPassword));
                    saveTeachers(teacherFilename, teachers);
                    cout << "创建教师账号成功" << endl;
                }
                else
                {
                    cout << "创建失败，已有此教师账号" << endl;
                }

            }
            else {
                cout << "无效的账号类型。" << endl;
            }
             system("pause");
        }
        else 
        {
            cout << "无效的身份！" << endl;
            system("pause");
        }
    }
}