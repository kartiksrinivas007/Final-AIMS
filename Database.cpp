#include "Database.h"

void Database::Initialize_database(){

    students.push_back(Student(15,"Kartik","Kartikrox101"));
    students.push_back(Student(16,"Ajit","Ajitrox101"));
    students.push_back(Student(63,"Tanmay","Tanmayrox101"));

    Teacher subruk("Subramanyam Kalyanasundaram","subruk123");
    Teacher Nitin("Nitin Saurabh","Nitin123");

    teachers.push_back(subruk);
    teachers.push_back(Nitin);
    teachers.push_back(Teacher("NR aravind", "Arurox102"));

    courses.push_back(Course(2030,"TOC",subruk,students));
    courses.push_back(Course(2443,"Algorithms",Nitin,students));
    // students[0].printstudent();
    // courses[0].gradeupdate(students[0],'A');
    // courses[0].showcourseInfo();
    // courses[1].showcourseInfo();
    // students.push_back(Student(24,"Anish","Anishrox101")); 
    // //usee auto& for references !
    // courses[0].Addstudent(students[3]);
    // courses[0].showcourseInfo();
    // courses[0].RemoveStudent(students[3]);
    // students.pop_back();
    // courses[0].showcourseInfo();
    // Course Comput(5660, "Computational Number Theory",teachers[2],students);
    // Student pruthvi(25, "Pruthviraj","pruthvilovestosing");
      Admin Naresh("Naresh","Nareshrox101");
      Admin Mahesh("Mahesh","Maheshrox101");
      admins.push_back(Naresh);
      admins.push_back(Mahesh);
    // Naresh.Addcourse(courses, Comput);
    // Naresh.Addstudent(Comput,pruthvi);
    // courses[2].showcourseInfo();
   // courses[1].showstudentInfo(students[0]);
    //ModeAdmin(Naresh);
    //ModeStudent(students[0]);
}
void Database::ShowAdmin(){
    std::cout<<"###################Courses########################"<<std::endl<<std::endl;
    for (auto &c : courses)
    {
        std::cout<<"------------------"<<c.course_name<<"--------------------- "<<std::endl;
        std::cout<<"Name = "<<c.course_name<<" Prof = "<<c.course_instructor->user_name<<" ID =  "<<c.course_id<<" Status =  "<<c.course_status<<"  "<<std::endl;
        std::cout<<"------------------Students--------------------- "<<std::endl;
            for (auto sc : *c.student_grades){
               
                sc.first.show_info();
            }
    }
    std::cout<<"---------------------------------------------- "<<std::endl;
std::cout<<"------------------------------ALL STUDENTS -----------------------------"<<std::endl;
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
    std::cout<<"------------------Press -1 to exit------------------"<<std::endl;
    std::cout<<"#Enter 1 to Remove Student from Course\n#Enter 2 to Add Student to Course\n#Enter 3 to Add Course"<<std::endl;
    std::cout<<"#Enter 4 to Remove Course\n#Enter 5 to change Course Status\n#Enter 6 to Add New Student\n#Enter 7 to Remove Student"<<std::endl;
    while(std::cin>>input && input != -1){

        switch(input){
            case 1: 
            {
                int s,c;
                std::cout<<"Enter Course ID Exactly"<<std::endl;
                std::cin>>c;
                Course* k = getCourse(c);
                if(k!= NULL)
                {
                    std::cout<<"Enter Student ID"<<std::endl;
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
                std::cin>>c;
                Course* k = getCourse(c);
                if(k!= NULL)
                {
                    std::cout<<"Enter Student ID"<<std::endl;
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
                    int cc;
                    std::cin>>cc;
                    std::vector<Student>student_list;
                    std::cout<<"Enter Student List by Roll number , Enter \"-1\" to stop adding students"<<std::endl;
                    int input2;
                    while(std::cin>>input2 && input2 != -1){
                        Student* j = getStudent(input2);
                        if(j != NULL){
                                        student_list.push_back(*j);
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
                std::cin>>rn;
                Student s(rn,name,"Defualt_password");
                alpha.Addstudent(students,s);
                ShowAdmin();
                break;
            }
           

            case 7:{
                int rn;
                std::cout<<"Enter Student ID"<<std::endl;
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
    }
}
void Database::ModeTeacher(Teacher &alpha){
    ShowTeacher(alpha);
    std::cout<<"------------------Press -1 to exit------------------"<<std::endl;
    std::cout<<"#Enter 1 to Change Course Grade"<<std::endl;
    int input;
    while(std::cin>>input && input != -1){
        switch(input){
            case 1:
            {
                int rn;
                std::cout<<"Enter Student ID(Roll Number)"<<std::endl;
                std::cin>>rn;
                Student *s = getStudent(rn);
                Course *c = getCourse(alpha);
                if(c!= NULL){
                    char grade;
                    std::cout<<"Enter New Grade"<<std::endl;
                    std::cin>>grade;
                    c->gradeupdate(*s,grade);
                }
                ShowTeacher(alpha);
                break;
            }
        }
    }
}
void Database::ModeStudent(Student &s){
    ShowStudentGrades(s);
    std::cout<<"------------------Press -1 to exit------------------"<<std::endl;
    std::cout<<"#Enter 1 to  Regsiter For a Course"<<std::endl;
    std::cout<<"#Enter 2 to  De - register for a Course"<<std::endl;
    int input;
    while(std::cin>>input && input != -1){
        switch(input){
            case 1:{
                int cc;
                std::cout<<"Enter course ID"<<std::endl;
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