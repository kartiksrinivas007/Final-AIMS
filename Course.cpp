#include"Course.h"

Course::Course()
{
    course_id = 0;
    course_name = "undefined";
    course_instructor = new Teacher("undefined teacher","undefined Password");
    student_grades = new std::vector<std::pair<Student,char>>();
    course_status = true;
    //grades = {};
}
Course::Course(int cc, std::string cn, Teacher &t, std::vector<Student>students){
 course_id = cc;
 course_instructor = new Teacher(t.user_name,t.password);
 course_name = cn ;
 course_status = true;
 student_grades = new std::vector<std::pair<Student,char>>();
 for (auto x: students){
     student_grades->push_back(std::make_pair(x,'U'));
 }

}
void Course::gradeupdate(Student &s,char a){
    for (auto &x: *(student_grades)){
        if(x.first.user_name == s.user_name){
                x.second = a;
        }
    }
}
void Course::showcourseInfo(){
    std::cout<<"---------------"<<course_id<<"----------"<<course_instructor->user_name<<"------------------"<<std::endl;
    for (auto x: *(student_grades)){
        std::cout<<"Name = "<< x.first.user_name<<" |  Roll number = "<<x.first.roll_number<<" | Grade = "<<x.second<<std::endl;
    }
}
void Course::Addstudent(Student &s){
    (*student_grades).push_back(std::make_pair(s,'U'));
}
void Course::RemoveStudent(Student &s){
    std::vector<std::pair<Student,char>>::iterator it,it2;
    for (it = (*(student_grades)).begin(); it != (*student_grades).end() ; it ++ ){
        if(it->first.user_name == s.user_name){
            it2 = it;
        }
    }
    (*student_grades).erase(it2);
}
void Course::showstudentInfo(Student &s){
        for (auto sc:*(student_grades)){
                if(sc.first.user_name == s.user_name){
                    std::cout<<"Course - "<<course_name<<" |  Grade - "<<sc.second<<std::endl;
                }
        }
}