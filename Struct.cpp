// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;

// -- additional_libraries
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
// -- additional_libraries -- azur3
// #include TimerClock.h

// Classes

// Functions

struct empDetails
{
    string EmpName;
    int EmpId;
    long int EmpSalary;
    string EmpDept;
    string Desg;
};

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    // cout << "Working Properly \n";

    // -- Creating Data set
    struct empDetails emp1;
    emp1.EmpName = "Sunil";
    emp1.EmpDept = "Finace";
    emp1.EmpId = 12345;
    emp1.EmpSalary= 200;
    emp1.Desg = "CFO";

    // -- Printing Details
    cout << "Name : " << emp1.EmpName << endl;
    cout << "Department : " << emp1.EmpDept << endl;
    cout << "Emp id : " << emp1.EmpId << endl;
    cout << "Desg. : " << emp1.Desg << endl;
    cout << "Salary : " << emp1.EmpSalary << endl;

    return 0;
}