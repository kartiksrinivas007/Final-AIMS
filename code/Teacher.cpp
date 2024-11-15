#include "Teacher.h"

Teacher::Teacher(std::string name, std::string password){
    this->user_name = name;
    this->password = password;

}
Teacher::Teacher(){
    user_name = "default teacher";
    password = "default password teacher";
}
