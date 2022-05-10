#include"Student.h"

Student::Student(){
    roll_number = 100;
    user_name = "Kartik";
    password = "Kartikrox101";
}
Student::Student(int rn , std::string username, std::string pw){
       roll_number = rn;
       user_name = username;
       password = pw;
}
void Student::printstudent(){
    std::cout<<"Username -"<<this->user_name<<" | ";
    std::cout<<"Roll Number -"<<this->roll_number<<std::endl;
}
// Student::~Student(){
//     std::cout<<" Student "<<this->user_name<<" Deleted "<<std::endl;
// }