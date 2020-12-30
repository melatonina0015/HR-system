#include <employeeClass.hpp>
#include <iostream>
#include <string>

using namespace std;

Employee::Employee(int ID, string NAME, string SURNAME, string DEPARTMENT, string POSITION, double SALARY)
{

    id =ID;
    name = NAME;
    surname = SURNAME;
    department = DEPARTMENT;
    position = POSITION;
    salary = SALARY;
}

void Employee::print()
{
    cout << "ID = " << id << "\t"
         << "Name = " << name << "\t"
         << "Surname = " << surname << "\t"
         << "Department = " << department << "\t"
         << "Position = " << position << "\t"
         << "Salary = " << salary << endl;
}