#include "Admin.h"

Admin::Admin(std::string un , std::string pw){
    this->user_name = un;
    this->password = pw;
}
void Admin::Addcourse(std::vector<Course>&dc, Course&c){
    dc.push_back(c);
}
void Admin::RemoveCourse(std::vector<Course>&dc, Course&c){
    std::vector<Course>::iterator it,it2;
    for (it = dc.begin(); it!= dc.end(); it++){
               if(it->course_name == c.course_name){
                   it2 = it;
               }
    }
    dc.erase(it2);
}
void Admin::Addstudent(std::vector<Student>&dc, Student&c){
    dc.push_back(c);
}
void Admin::RemoveStudent(std::vector<Student>&dc, Student&c){
    std::vector<Student>::iterator it,it2;
    for (it = dc.begin(); it!= dc.end(); it++){
               if(it->user_name == c.user_name){
                   it2 = it;
               }
    }
    dc.erase(it2);
}
void Admin::changestatus(Course &c,bool input){
    c.course_status = input;
}
void Admin::Addstudent(Course &c, Student &s){
    c.student_grades->push_back(std::make_pair(s,'U'));
}
void Admin::RemoveStudent(Course &c, Student &s){
    std::vector<std::pair<Student,char>>::iterator it, it2;
    for(it = (*c.student_grades).begin(); it != (*c.student_grades).end(); it++){
        if(it->first.user_name == s.user_name){
            it2 = it;
        }
    }
    (*c.student_grades).erase(it2);
}