#pragma once
#include"Course.h"
#include"teacher.h"
#include"student.h"
#include"function.h"
#include"config.h"
#include"global.h"
int main(){
    //������������ 
    loaddata();
    // ��ѭ��
    menu();
    // �����ʦ��ѧ���Ϳγ���Ϣ���ļ�
    saveTeachers(teacherFilename, teachers);
    saveStudents(studentFilename, students);
    saveCourses(courseFilename, courses);
    // �ͷŶ�̬������ڴ�
    for (auto& course : courses) {
        delete course;
    }
    return 0;
}