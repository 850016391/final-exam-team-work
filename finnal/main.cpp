#pragma once
#include"Course.h"
#include"teacher.h"
#include"student.h"
#include"function.h"
#include"config.h"
#include"global.h"
int main(){
    //加载三种数据 
    loaddata();
    // 主循环
    menu();
    // 保存教师、学生和课程信息到文件
    saveTeachers(teacherFilename, teachers);
    saveStudents(studentFilename, students);
    saveCourses(courseFilename, courses);
    // 释放动态分配的内存
    for (auto& course : courses) {
        delete course;
    }
    return 0;
}