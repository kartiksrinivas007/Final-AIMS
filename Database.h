#ifndef DATABASE_H
#define DATABASE_H
#include "Course.h"
#include "Admin.h"
class Database{
        private:
            std::vector<Course>courses;
            std::vector<Student>students;
            std::vector<Teacher>teachers;
            std::vector<Admin>admins;
        public:
            void Term();
            void Initialize_database();
            void ShowDatabase();
            void ShowStudentGrades(Student &s);
            void ShowAdmin();
            void ShowTeacher(Teacher &t);
            void ModeAdmin(Admin &alpha);
            void ModeTeacher(Teacher &alpha);
            void ModeStudent(Student &);
            Course* getCourse(int);
            Student* getStudent(int);
            Teacher* getTeacher(std::string);
            Course* getCourse(Teacher&);
};
#endif