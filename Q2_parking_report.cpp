
    /*
 * Name       : Minahil Yasir
 * Reg No     : L1F24BSCS0081
 * Assignment : 02 - File Handling
 * Question   : Q2_parking_report
 */


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream inFile("parking.txt");
    ofstream outFile("receipts.txt");

    if (!inFile)
    {
        cout << "parking.txt cannot be opened";
        return 0;
    }

    int d, m, y;
    char slash;

    inFile >> d >> slash >> m >> slash >> y;

    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');

    cout << d << "/" << m << "/" << y << endl;

    outFile << d << "/" << m << "/" << y << endl;

    char plate[15];
    char type, colon;

    int inHour, inMinute;
    int outHour, outMinute;

    int vehicles = 0;
    int cars = 0;
    int bikes = 0;
    int totalCollected = 0;
    int longestMinutes = -1;

    while (inFile >> plate >> type >> inHour >> colon >> inMinute >> outHour >> colon >> outMinute)
    {
        int start = inHour * 60 + inMinute;
        int finish = outHour * 60 + outMinute;

        int minutes = finish - start;

        int hours = minutes / 60;
        int remainingMinutes = minutes % 60;

        int chargedHours = (minutes + 59) / 60;

        if (chargedHours == 0)
        {
            chargedHours = 1;
        }

        int rate;

        if (type == 'C')
        {
            rate = 100;
        }
        else
        {
            rate = 40;
        }

        int fee = chargedHours * rate;

        cout << plate << " ";

        if (type == 'C')
        {
            cout << "Car ";
        }
        else
        {
            cout << "Bike ";
        }

        cout << hours << " h "
            << remainingMinutes << " min "
            << "Fee: " << fee << endl;

        outFile << plate << " " << fee << endl;

        vehicles++;

        if (type == 'C')
        {
            cars++;
        }
        else
        {
            bikes++;
        }

        totalCollected += fee;

        if (minutes > longestMinutes)
        {
            longestMinutes = minutes;
        }
    }

    if (vehicles == 0)
    {
        cout << "No vehicles found!" << endl;
    }
    else
    {
        cout << "Vehicles: " << vehicles << endl;

        cout << "Cars: " << cars
            << " Bikes: " << bikes << endl;

        cout << "Total collected: "
            << totalCollected << endl;

    }

    inFile.close();
    outFile.close();

    return 0;
}
