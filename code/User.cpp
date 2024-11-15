#include"User.h"

User::User(){
    user_name = "default_user101";
    password = "default_password_101";
}
User::User( std::string un , std::string pw){
    user_name = un;
    password = pw;
}
void User::show_info()
{
    std::cout<<"Name = "<<user_name<<"\n";
}