#include "Database.h"

void Database::Term(){
    std::cout<<"~";
}
void Database::Initialize_database(){

    students.push_back(Student(15,"Kartik","Kartikrox101"));
    students.push_back(Student(16,"Ajit","Ajitrox101"));
    students.push_back(Student(63,"Tanmay","Tanmayrox101"));
    students.push_back(Student(33,"Pranav Nayak","Pranavrox101"));
    students.push_back(Student(55,"Kartheek Tammanba","Kartheekrox101"));
    students.push_back(Student(22,"Poorvika C","poorvikarox101"));
    students.push_back(Student(63,"Rachit","Rachitrox101"));

    std::vector<Student>students_new({students[3],students[2],students[4]});

    
    Teacher subruk("Subruk","subruk123");
    Teacher Nitin("Nitin","Nitin123");
    Teacher MVP("MVP","mvprox101");
    Teacher Aravind("Aravind","aravindisdabest101");
    Teacher RakeshVenkat("Rakesh","Rakeshlovestotravel");

    teachers.push_back(subruk);
    teachers.push_back(Nitin);
    teachers.push_back(Aravind);
    teachers.push_back(MVP);
    teachers.push_back(RakeshVenkat);

    courses.push_back(Course(2030,"TOC",subruk,students));
    courses.push_back(Course(2443,"Algorithms",Nitin,students));
    Course Comput(5660, "Computational Number Theory",Aravind,students_new);
    courses.push_back(Comput);
    Student pruthvi(25, "Pruthviraj","pruthvilovestosing");
    students.push_back(pruthvi);
    courses.push_back(Course(5342,"Quantum Computing",MVP,students));

    Admin Naresh("Naresh","Nareshrox101");
    Admin Mahesh("Mahesh","Maheshrox101");
    admins.push_back(Naresh);
    admins.push_back(Mahesh);
}
void Database::ShowAdmin(){
    std::cout<<"################### COURSES ########################"<<std::endl<<std::endl;
    for (auto &c : courses)
    {
        std::cout<<"------------------"<<c.course_name<<"--------------------- "<<std::endl;
        std::cout<<"Name = "<<c.course_name<<" Professor = "<<c.course_instructor->user_name<<" ID =  "<<c.course_id<<" Status =  "<<c.course_status<<"  "<<std::endl;
        std::cout<<"------------------ Students Under Course --------------------- "<<std::endl;
            for (auto sc : *c.student_grades){
               
                sc.first.show_info();
            }
    }
    std::cout<<"---------------------------------------------- "<<std::endl;
std::cout<<"------------------------------ ALL STUDENTS -----------------------------"<<std::endl;
for(auto s:students){
    s.printstudent();
}
    

}
void Database::ShowStudentGrades(Student &s){
    std::cout<<"########### REGISTERED COURSES FOR "<< s.user_name <<" ############"<<std::endl;
   for (auto &c:courses){
       c.showstudentInfo(s);
   }
   std::cout<<"############ COURSES AVAILABLE FOR REGISTRATION #########"<<std::endl;
   for (auto &c :courses){
       if(c.course_status)
       {
           std::cout<<"Course Instructor - "<<c.course_instructor->user_name<<" || Course Name - "<< c.course_name<<" || Course ID "<<c.course_id<<std::endl;
       }
   }


}
void Database::ShowTeacher(Teacher &t){
   for (auto &c: courses){
       if(c.course_instructor->user_name == t.user_name){
            c.showcourseInfo();
       }
   }
}

void Database::ModeAdmin(Admin &alpha){
    int input;
    std::string inputstring;
    ShowAdmin();
    std::cout<<"#Enter -1 to exit"<<std::endl;
    std::cout<<"#Enter 1 to Remove Student from Course\n#Enter 2 to Add Student to Course\n#Enter 3 to Add Course"<<std::endl;
    std::cout<<"#Enter 4 to Remove Course\n#Enter 5 to change Course Status\n#Enter 6 to Add New Student\n#Enter 7 to Remove Student"<<std::endl;
    Term();
    while(std::cin>>input && input != -1){

        switch(input){
            case 1: 
            {
                int s,c;
                std::cout<<"Enter Course ID Exactly"<<std::endl;
                Term();
                std::cin>>c;
                Course* k = getCourse(c);
                if(k!= NULL)
                {
                    std::cout<<"Enter Student ID"<<std::endl;
                    Term();
                    std::cin>>s;
                    Student* j = getStudent(s);
                    if(j != NULL){
                            alpha.RemoveStudent(*k, *j);
                    }
                }
                ShowAdmin();
                break;   
            }
            case 2:
            {
                int s,c;
                std::cout<<"Enter Course ID Exactly"<<std::endl;
                Term();
                std::cin>>c;
                Course* k = getCourse(c);
                if(k!= NULL)
                {
                    std::cout<<"Enter Student ID"<<std::endl;
                    Term();
                    std::cin>>s;
                    Student* j = getStudent(s);
                    if(j != NULL){
                            alpha.Addstudent(*k, *j);
                    }
                }
                ShowAdmin();
                break;  
                
            }
            case 3:
            {
                std::string c;
                std::string t;
                std::cout<<"Enter Course Name to be Created "<<std::endl;
                std::cin.ignore();
                getline(std::cin,c);
                    std::cout<<"Enter Teacher Name for the Course"<<std::endl;
                    getline(std::cin,t);
                    Teacher* l = getTeacher(t);
                    if(l!= NULL)
                    {
                    std::cout<<"Enter Course ID"<<std::endl;
                    Term();
                    int cc;
                    std::cin>>cc;
                    std::vector<Student>student_list;
                    std::cout<<"Enter Student List by Roll number , Enter \"-1\" to stop adding students"<<std::endl;
                    Term();
                    int input2;
                    while(std::cin>>input2 && input2 != -1){
                        Student* j = getStudent(input2);
                        if(j != NULL){
                                        student_list.push_back(*j);
                                        Term();
                                    }
                             
                    }
                    Course C(cc,c,*l,student_list);
                    alpha.Addcourse(courses,C);  
                    }                                       
                    
                
                ShowAdmin();
                break;  

            }
            case 4:{
                int c;
                std::cout<<"Enter Course ID"<<std::endl;
                Term();
                std::cin>>c;
                Course* tbr = getCourse(c);
                if(tbr != NULL){
                        alpha.RemoveCourse(courses, *tbr);
                }
                ShowAdmin();
                break;
            }
            case 5:
            {
                int c;
                std::cout<<"Enter Course ID"<<std::endl;
                Term();
                std::cin>>c;
                Course* tbr = getCourse(c);
                if(tbr != NULL){
                        alpha.changestatus(*tbr,true);
                }
                ShowAdmin();
                break;

            }
            case 6:
            {
                std::string name;
                int rn;
                std::cout<<"Enter Student Name"<<std::endl;
                std::cin.ignore();
                getline (std::cin, name);
                std::cout<<"Enter Student ID"<<std::endl;
                Term();
                std::cin>>rn;
                Student s(rn,name,"Defualt_password");
                alpha.Addstudent(students,s);
                ShowAdmin();
                break;
            }
           

            case 7:{
                int rn;
                std::cout<<"Enter Student ID"<<std::endl;
                Term();
                std::cin>>rn;
                Student *s = getStudent(rn);
                alpha.RemoveStudent(students,*s);
                ShowAdmin();
                break;
            }
    
        }
    std::cout<<"------------------Press -1 to exit------------------"<<std::endl;
    std::cout<<"#Enter 1 to Remove Student from Course\n#Enter 2 to Add Student to Course\n#Enter 3 to Add Course"<<std::endl;
    std::cout<<"#Enter 4 to Remove Course\n#Enter 5 to Float Course\n#Enter 6 to Add New Student\n#Enter 7 to Remove Student"<<std::endl;
    Term();
    }
}
void Database::ModeTeacher(Teacher &alpha){
    ShowTeacher(alpha);
    std::cout<<"------------------Press -1 to exit------------------"<<std::endl;
    std::cout<<"#Enter 1 to Change Course Grade"<<std::endl;
    Term();
    int input;
    while(std::cin>>input && input != -1){
        switch(input){
            case 1:
            {
                int rn;
                std::cout<<"Enter Student ID(Roll Number)"<<std::endl;
                Term();
                std::cin>>rn;
                Student *s = getStudent(rn);
                Course *c = getCourse(alpha);
                if(c!= NULL){
                    char grade;
                    std::cout<<"Enter New Grade"<<std::endl;
                    Term();
                    std::cin>>grade;
                    c->gradeupdate(*s,grade);
                }
                ShowTeacher(alpha);
                break;
            }
        }
    std::cout<<"------------------Press -1 to exit------------------"<<std::endl;
    std::cout<<"#Enter 1 to Change Course Grade"<<std::endl;
    Term();
    }
}
void Database::ModeStudent(Student &s){
    ShowStudentGrades(s);
    std::cout<<"------------------Press -1 to exit------------------"<<std::endl;
    std::cout<<"#Enter 1 to  Regsiter For a Course"<<std::endl;
    std::cout<<"#Enter 2 to  De - register for a Course"<<std::endl;
    Term();
    int input;
    while(std::cin>>input && input != -1){
        switch(input){
            case 1:{
                int cc;
                std::cout<<"Enter course ID"<<std::endl;
                Term();
                std::cin>>cc;
                Course *k = getCourse(cc);
                if( k != NULL){
                k->Addstudent(s);
                }
                ShowStudentGrades(s);
                break;
            }
            case 2:
            {
                int cc;
                std::cout<<"Enter course ID"<<std::endl;
                Term();
                std::cin>>cc;
                Course *k = getCourse(cc);
                if(k != NULL)
                {
                k->RemoveStudent(s);
                }
                ShowStudentGrades(s);
                break;

            }
        }
    std::cout<<"------------------Press -1 to exit------------------"<<std::endl;
    std::cout<<"#Enter 1 to  Regsiter For a Course"<<std::endl;
    std::cout<<"#Enter 2 to  De - register for a Course"<<std::endl;
    Term();

    }

}
Course* Database::getCourse(int cc){
    for (auto &c: courses){
            if(c.course_id == cc){
                    return &c;
            }
    }
    std::cout<<"Unable to find course!\n";
    return NULL;
}
Student* Database::getStudent(int ss){
    for (auto &s :students){
            if( s.roll_number == ss){
                    return &s;
            }
    }
    std::cout<<"Unable to find Student!\n";
    return NULL;
}
Teacher* Database::getTeacher(std::string tt){
      for (auto &t :teachers){
            if( t.user_name == tt){
                    return &t;
            }
    }
    std::cout<<"Unable to find Teacher!\n";
    return NULL;
}
Course* Database::getCourse(Teacher &t){
    for(auto &c: courses){
        if(c.course_instructor->user_name == t.user_name){
                return &c;
        }
    }
    return NULL;
}
void Database::ShowDatabase(){
    std::cout<<"------------------------DATABASE------------------------\n\n";
    std::cout<<"############### COURSES ##################\n"<<std::endl;
    for(auto & c:courses){
            c.showcourseInfo();
    }
    std::cout<<"############## STUDENTS #################\n"<<std::endl;
    for(auto &s :students){
        s.printstudent();
    }
    std::cout<<"---------------------------------------------------------\n\n";

}