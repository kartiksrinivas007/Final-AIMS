#include<iostream>
#include"Student.h"
#include"User.h"
#include"Course.h"
#include "Teacher.h"
#include "Admin.h"
#include "Database.h"
using namespace std;
void Term()
{
    std::cout<<"~";
}
int main()
{
    Admin Naresh("Naresh","Nareshrox101");
    Database d;
    d.Initialize_database();
    d.ShowDatabase();
    int input;
    std::cout<<"----------------------------LOGIN-------------------------------"<<std::endl;
    cout<<"#Enter 1 if you are an Admin"<<std::endl;
    cout<<"#Enter 2 if you are a Student"<<std::endl;
    cout<<"#Enter 3 if you are a Teacher"<<std::endl;
    cout<<"--------------------------------ENTER - 1 TO EXIT -------------------"<<std::endl;
    Term();
    while(cin>>input && input != -1){
      
      switch(input){
          case 1:
          {
              d.ModeAdmin(Naresh);
              break;
          }
          case 2:
          {
              int s;
              cout<<"#Enter Student ID"<<std::endl;
              Term();
              cin>>s;
              Student *k = d.getStudent(s);
              d.ModeStudent(*k);
              d.ShowAdmin();
              break;
          }
          case 3:
          {
              string t;
              cout<<"#Enter Teacher Name"<<std::endl;
              std::cin.ignore();
              getline(cin,t);
              Teacher *k = d.getTeacher(t);
              d.ModeTeacher(*k);
              d.ShowAdmin();
              break;

          }
      }
      std::cout<<"----------------------------LOGIN-------------------------------"<<std::endl;
      cout<<"#Enter 1 if you are an Admin"<<std::endl;
      cout<<"#Enter 2 if you are a Student"<<std::endl;
      cout<<"#Enter 3 if you are a Teacher"<<std::endl;
      cout<<"--------------------------------ENTER - 1 TO EXIT -------------------"<<std::endl;
      Term();
    }
    return 0;
}