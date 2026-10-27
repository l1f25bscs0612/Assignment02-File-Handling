
    /*
 * Name       : Minahil Yasir
 * Reg No     : L1F24BSCS0081
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
#include<fstream>//fix1: <fstream> was missing.
    using namespace std;

    int main() {
        ifstream inFile("stock.txt");
        if (!inFile) // fix2:! is used whether the file failed to open.
        {
            cout << "stock.txt not found!" << endl;
            return 1;
        }

        ofstream reorder("reorder.txt",ios::app);// fix3: the requirnments says that old data should be remain same.

        char code[10];
        int qty, count = 0, low = 0;
        double price;
        double total = 0;// fix4: double could preserve decimal value of total.

        while (count < 50 && inFile >> code >> qty >> price) {
            count++;
            total = total + qty * price;
            if (qty < 10) {
                reorder << code << " " << qty << endl;// fix 5: every low stock should print separatedly
                low++;
            }
        }
        inFile.close();
        reorder.close();

        cout << "Items: " << count << endl;
        cout << "Total stock value: " << total << endl;
        cout << "Low stock items: " << low << endl;
        return 0;
    }

