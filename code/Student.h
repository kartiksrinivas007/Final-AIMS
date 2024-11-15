#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<vector>
#include "User.h"

class Student : public User{
    friend class Admin;
    friend class Teacher;
        
    public:
            int roll_number;
            Student();
            Student(int, std::string, std::string);
            void printstudent();
};
#endif