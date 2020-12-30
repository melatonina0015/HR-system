#include <string.h>
#include <string>
#ifndef employeeClass_hpp
#define employeeClass_hpp

using namespace std;

class Employee
{
    public:

    int id;
    string name;
    string surname;
    string department;
    string position;
    double salary;
    Employee(int id, string name, string surname, string department, string position, double salary);
    void print();
};

#endif