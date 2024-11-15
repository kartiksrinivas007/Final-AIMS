### Mini Course Registration System

This is a mini course registration system implemented in C++
There are three roles - an Admin, a student and a Teacher. Each has different access levels
for the database and can perform distinct operations, like offering courses/modifying courses and students on the other hand can enroll in courses. Students also have student IDs.

Assumptions:-
1. Single Teacher Per Course
3. Courses That are shown in Student CLI are only the ones which have Open registration

To compile

```shell
        cd code/
        g++ -o out *.cpp -std=c++14
        ./out
```

For a test, use the file `code/Testcase.txt` and execute  `./out < Testcase.txt`



