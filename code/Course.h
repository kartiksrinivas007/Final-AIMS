#include "Teacher.h"
#include "Student.h"
#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<bits/stdc++.h>
#include<utility>

class Course{
    public:
       friend class Admin;
       int course_id;
       std::string course_name;
       Teacher* course_instructor;
       std::vector<std::pair<Student,char>>* student_grades;
       bool course_status;
       Course();
       Course(int,std::string,Teacher&,std::vector<Student>); 
       int getCourseId(){  return course_id;   }
       void gradeupdate(Student &s,char a);
       void Addstudent(Student &s);
       void RemoveStudent(Student &s);
       void showcourseInfo();
       void showstudentInfo(Student &s);
    //    ~Course();

        bool operator< (const Course& c) const
            {
                if(c.course_id < this->course_id)
                    return true;
                else return false;
            }
};
#endif