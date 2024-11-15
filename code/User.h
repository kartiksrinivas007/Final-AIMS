#ifndef USER_H
#define USER_H
#include<iostream>
#include<vector>
#include<string>
// #include "types.h"


class User{
  public:
   std::string user_name;
   std::string password;
    virtual void show_info();
    User();
    User(std::string,std::string);
};
#endif