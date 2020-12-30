#include <string.h>
#include <string>
#include <list>
#include <employeeClass.hpp>
#include <rapidcsv.h>
#include <vector>
#include <set>

#ifndef HRMS_hpp
#define HRMS_hpp

using namespace std;
using namespace rapidcsv;

class HRMS
{
    public:

    vector<Employee> hr;
    void readCSV(Document &DOC);
    void print_all();
    void print_department(string department, set<string>& s);
    void print_salaries();
    void print_salaries_sorted();
    void change_salary(int id, double salary, Document &DOC);
    void add(Employee &emp, Document &DOC);
    
};

#endif