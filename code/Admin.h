#ifndef ADMIN_H
#define ADMIN_H
#include "Course.h"
#include "User.h"
class Admin : public User{
     public:
        Admin(std::string un ,std::string pw);
        void Addstudent(std::vector<Student>& ,Student&);
        void RemoveStudent(std::vector<Student>&,Student &);
        void Addcourse(std::vector<Course>&,Course&);
        void RemoveCourse(std::vector<Course>&,Course&);
        void Addstudent(Course &c, Student &s);
        void RemoveStudent(Course &c, Student &s);
        void changestatus(Course &c,bool);
};
#endif