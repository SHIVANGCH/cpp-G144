#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Customer {
public:
    int roomNumber;
    char name[50];
    char address[100];
    char phone[15];
    int days;
    float bill;

    void input() {
        cout << "\nEnter Room Number: ";
        cin >> roomNumber;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 50);
        cout << "Enter Address: ";
        cin.getline(address, 100);
        cout << "Enter Phone: ";
        cin.getline(phone, 15);
        cout << "Enter Number of Days: ";
        cin >> days;
        bill = days * 1000; // fixed rate
    }

    void display() {
        cout << "\nRoom Number: " << roomNumber;
        cout << "\nName: " << name;
        cout << "\nAddress: " << address;
        cout << "\nPhone: " << phone;
        cout << "\nDays Stayed: " << days;
        cout << "\nTotal Bill: " << bill << endl;
    }
};

class Hotel {
private:
    Customer cust;
public:
    void addCustomer() {
        ofstream fout("hotel.dat", ios::binary | ios::app);
        cust.input();
        fout.write((char*)&cust, sizeof(cust));
        fout.close();
        cout << "\nCustomer Added Successfully!\n";
    }

    void displayAll() {
        ifstream fin("hotel.dat", ios::binary);
        while (fin.read((char*)&cust, sizeof(cust))) {
            cust.display();
            cout << "\n----------------------";
        }
        fin.close();
    }

    void searchCustomer() {
        int room;
        cout << "\nEnter Room Number to Search: ";
        cin >> room;

        ifstream fin("hotel.dat", ios::binary);
        bool found = false;

        while (fin.read((char*)&cust, sizeof(cust))) {
            if (cust.roomNumber == room) {
                cust.display();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "\nCustomer Not Found!";
        fin.close();
    }

    void deleteCustomer() {
        int room;
        cout << "\nEnter Room Number to Delete: ";
        cin >> room;

        ifstream fin("hotel.dat", ios::binary);
        ofstream fout("temp.dat", ios::binary);

        bool found = false;

        while (fin.read((char*)&cust, sizeof(cust))) {
            if (cust.roomNumber != room) {
                fout.write((char*)&cust, sizeof(cust));
            } else {
                found = true;
            }
        }

        fin.close();
        fout.close();

        remove("hotel.dat");
        rename("temp.dat", "hotel.dat");

        if (found)
            cout << "\nRecord Deleted Successfully!";
        else
            cout << "\nRecord Not Found!";
    }

    void updateCustomer() {
        int room;
        cout << "\nEnter Room Number to Update: ";
        cin >> room;

        fstream file("hotel.dat", ios::binary | ios::in | ios::out);
        bool found = false;

        while (file.read((char*)&cust, sizeof(cust))) {
            if (cust.roomNumber == room) {
                cout << "\nEnter New Details:\n";
                cust.input();

                file.seekp(-sizeof(cust), ios::cur);
                file.write((char*)&cust, sizeof(cust));
                found = true;
                break;
            }
        }

        file.close();

        if (found)
            cout << "\nRecord Updated Successfully!";
        else
            cout << "\nRecord Not Found!";
    }

    void calculateBill() {
        int room;
        cout << "\nEnter Room Number: ";
        cin >> room;

        ifstream fin("hotel.dat", ios::binary);
        bool found = false;

        while (fin.read((char*)&cust, sizeof(cust))) {
            if (cust.roomNumber == room) {
                cout << "\n---- BILL DETAILS ----";
                cust.display();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "\nCustomer Not Found!";
        fin.close();
    }
};

void menu() {
    cout << "\n\n====== HOTEL MANAGEMENT SYSTEM ======\n";
    cout << "1. Add Customer\n";
    cout << "2. Display All Customers\n";
    cout << "3. Search Customer\n";
    cout << "4. Update Customer\n";
    cout << "5. Delete Customer\n";
    cout << "6. Calculate Bill\n";
    cout << "7. Exit\n";
    cout << "Enter Choice: ";
}

int main() {
    Hotel h;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            h.addCustomer();
            break;
        case 2:
            h.displayAll();
            break;
        case 3:
            h.searchCustomer();
            break;
        case 4:
            h.updateCustomer();
            break;
        case 5:
            h.deleteCustomer();
            break;
        case 6:
            h.calculateBill();
            break;
        case 7:
            cout << "\nExiting...";
            break;
        default:
            cout << "\nInvalid Choice!";
        }
    } while (choice != 7);

    return 0;
}
