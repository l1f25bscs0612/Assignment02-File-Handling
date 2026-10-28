/*
   Name       : minahil yasir 
 * Reg No     : Your Registration Number
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship List
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char path[100];
    char name[30], topName[30];
    double cgpa, total = 0, average;
    double topCGPA = 0;
    int n, count = 0, eligible = 0;

    cout << "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);

    if (!inFile.is_open())
    {
        cout << "Could not open " << path << "!" << endl;
        return 1;
    }

    if (!(inFile >> n))
    {
        inFile.close();
        cout << "No students found!" << endl;
        return 0;
    }

    if (n > 30)
    {
        cout << "Too many students!" << endl;
        inFile.close();
        return 0;
    }

    inFile.ignore(100, '\n');

    ofstream outFile("scholarship.txt");

    while (count < n)
    {
        if (!inFile.getline(name, 30, ','))
            break;

        if (!(inFile >> cgpa))
            break;

        inFile.ignore(100, '\n');

        cout << "[" << name << "] CGPA: " << cgpa << endl;

        total = total + cgpa;

        if (count == 0 || cgpa > topCGPA)
        {
            topCGPA = cgpa;
            strcpy(topName, name);
        }

        if (cgpa >= 3.50)
        {
            outFile << name << "," << cgpa << endl;
            eligible++;
        }

        count++;
    }

    inFile.close();
    outFile.close();

    if (count < n)
    {
        cout << "Warning: only " << count
            << " of " << n << " records found." << endl;
    }

    if (count == 0)
    {
        cout << "No students found!" << endl;
        return 0;
    }

    average = total / count;

    cout << "Students: " << count << endl;
    cout << "Average CGPA: " << average << endl;
    cout << "Eligible for scholarship: " << eligible << endl;
    cout << "Top student: " << topName
        << " (" << topCGPA << ")" << endl;

    return 0;
}
