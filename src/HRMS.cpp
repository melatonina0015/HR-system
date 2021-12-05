#include <iostream>
#include <HRMS.hpp>
#include <employeeClass.hpp>
#include <vector>
#include <rapidcsv.h>
#include <algorithm>
#include <set>
#include <string>
#include <string.h>


using namespace std;
using namespace rapidcsv;

void HRMS::readCSV(Document &DOC)
{
    int ID;
    string NAME, SURNAME, DEPARTMENT, POSITION;
    double SALARY;
    for(int i = 0; i < DOC.GetRowCount(); i++)
    {
        ID = DOC.GetCell<int>(0,i);
        NAME = DOC.GetCell<string>(1,i);
        SURNAME = DOC.GetCell<string>(2,i);
        DEPARTMENT = DOC.GetCell<string>(3,i);
        POSITION = DOC.GetCell<string>(4,i);
        SALARY = DOC.GetCell<double>(5,i);

        hr.push_back(Employee{ID, NAME, SURNAME, DEPARTMENT, POSITION, SALARY});
    }
}
void HRMS::print_all()
{
    for(int i = 0; i < hr.size(); i++)
    {
        cout << "ID = " << hr[i].id << "\t"
         << "Name = " << hr[i].name << "\t"
         << "Surname = " << hr[i].surname << "\t"
         << "Department = " << hr[i].department << "\t"
         << "Position = " << hr[i].position << "\t"
         << "Salary = " << hr[i].salary << endl;
    }
    cout << endl << endl;
}
void HRMS::print_department(string department, set<string> &s)
{
    cout << department << ": " << endl;
    if(department.compare("All") == 0){
        set<string>::iterator itr;

        for(itr = s.begin(); itr != s.end(); ++itr){
            cout << *itr << ":\n";
            for(int i = 0; i < hr.size(); i++){   
                if(hr[i].department.compare(*itr) == 0){
                    cout << "\t" << hr[i].id << " " << hr[i].name << " " << hr[i].surname << endl;
                }
            }
        }
    }
    else{
        for(int i = 0; i < hr.size(); i++){
            if(hr[i].department.compare(department) == 0){
                cout << "\t" << hr[i].id << " " << hr[i].name << " " << hr[i].surname << endl;
            }
        }
    }
    cout << endl << endl;
    
}
void HRMS::print_salaries()
{
    for(int i = 0; i < hr.size(); i++)
    {
        cout << "Salary = " << hr[i].salary << "\t"
             << "ID = " << hr[i].id << "\t"
             << "Name = " << hr[i].name << "\t"
             << "Surname = " << hr[i].surname << endl;
    }
}
void HRMS::print_salaries_sorted()
{
    vector<Employee> tmp;
    for(int i = 0; i < hr.size(); i++){
        tmp.push_back(hr[i]);
    }
    sort(tmp.begin(), tmp.end(), [](const Employee& lhs, const Employee& rhs) {
      return lhs.salary < rhs.salary;
    });

    for(auto it = tmp.begin(); it != tmp.end(); it++) {
      cout << "ID = " << it->id << "\t"
         << "Name = " << it->name << "\t"
         << "Surname = " << it->surname << "\t"
         << "Department = " << it->department << "\t"
         << "Position = " << it->position << "\t"
         << "Salary = " << it->salary << endl;
   }

}
void HRMS::change_salary(int id, double salary, Document &DOC)
{
    for(int i = 0; i < hr.size(); i++){
        if(DOC.GetCell<int>(0,i) == id){
            DOC.SetCell(5,i,salary);
            DOC.Save("../hr.csv");
            hr[i].salary = salary;
            cout << "Salary changed; New data:\n"
                 << "ID = " << hr[i].id << "\n"
                 << "Name = " << hr[i].name << "\n"
                 << "Surname = " << hr[i].surname << "\n"
                 << "Department = " << hr[i].department << "\n"
                 << "Position = " << hr[i].position << "\n"
                 << "Salary = " << hr[i].salary << endl;
        }
    }
}
void HRMS::add(Employee &emp, Document &DOC)
{
    hr.push_back(emp);
    int d = hr.size() - 1;
    DOC.SetRow<string>(DOC.GetRowCount(),vector<string>({to_string(hr[d].id), hr[d].name, hr[d].surname, hr[d].department, hr[d].position, to_string(hr[d].salary)}));
    DOC.Save("../hr.csv");
}