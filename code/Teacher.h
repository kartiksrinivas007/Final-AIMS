#ifndef TEACHER_H
#define TEACHER_H
#include "User.h"
class Teacher : public User{
    friend class Admin;
    friend class Course;
    public :
        Teacher(std::string, std::string);
        Teacher();
};
#endif