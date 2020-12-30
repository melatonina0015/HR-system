#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string.h>
#include <string>
#include <employeeClass.hpp>
#include <HRMS.hpp>
#include <typeinfo>
#include <rapidcsv.h>
#include <vector>
#include <map>
#include <set>


using namespace std;
using namespace rapidcsv;

int gen_ID(HRMS &HR);
int main()
{
    HRMS hr;
    Document doc("../hr.csv");

    hr.readCSV(doc);

    int choice=0;
    bool loop=true;
    while(loop)
    {
        cout << "1.\tPrint all employees\n";
        cout << "2.\tPrint all employees from department\n";
        cout << "3.\tPrint all employees salaries\n";
        cout << "4.\tPrint all employees salaries(sorted)\n";
        cout << "5.\tAdd new employee\n";
        cout << "6.\tChange employee's salary\n";
        cout << "7.\tExit\n";
        cin  >> choice;
        cout << endl;

        switch(choice)
        {
            case 7:
            {
                loop=false;
                break;
            }
            case 1:
            {
                hr.print_all();
                break;
            }
            case 2:
            {
                set <string> tmp;
                string dep;
                cout << "Available departments:\n";
                for(int i = 0; i < hr.hr.size(); i++){
                    tmp.insert(hr.hr[i].department);
                }
                system("cls");
                set<string>::iterator it;
                for(it = tmp.begin(); it != tmp.end(); ++it){
                    cout << *it << endl;
                }
                cout << "Or print \"All\"";
                cout << "Choose department: ";
                cin >> dep;
                hr.print_department(dep, tmp);
                break;
            }
            case 3:
            {
                hr.print_salaries();
                break;
            }
            case 4:
            {
                hr.print_salaries_sorted();
                break;
            }
            case 5:
            {
                double sal;
                string name, surname, dep, pos;
                cout << "Type name:" << endl;
                cin >> name;
                cout << "Type surname" << endl;
                cin >> surname;
                cout << "Type department" << endl;
                cin >> dep;
                cout << "Type job" << endl;
                cin >> pos;
                cout << "Type salary" << endl;
                cin >> sal;
                Employee New(gen_ID(hr), name, surname, dep, pos, sal);
                hr.add(New,doc);
                break;
            }
            case 6:
            {
                int id;
                double sal;
                cout << "Type ID:" << endl;
                cin >> id;
                cout << "Type new salary" << endl;
                cin >>  sal;
                hr.change_salary(id, sal, doc);
                break;
            }
            default:
            {
                std::cout << "Typed wrong value!" << std::endl;
                break;
            }
        }
    }

    system("pause");
    return 0;
}
int gen_ID(HRMS &HR)
{
    int max = 0;
    for(int i = 0; i < HR.hr.size(); i++)
    {
        if(HR.hr[i].id > max)
        {
            max = HR.hr[i].id;
        }
    }
    return max+1;
}
