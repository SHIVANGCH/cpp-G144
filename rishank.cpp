#include<iostream>
#include<string>
#include<vector>

using namespace std;

//BASE CLASS PERSON

class Person
{
protected:
    string name;
    int age;
    string phone;

public:
    Person()
    {
        name="";
        age=0;
        phone="";
    }

    void inputPerson()
    {
        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Age: ";
        cin>>age;

        cout<<"Enter Phone Number: ";
        cin>>phone;
    }

    void displayPerson()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Phone : "<<phone<<endl;
    }
};

//DERIVED CLASS CUSTOMER

class Customer : public Person
{
private:
    int customerID;

public:
    Customer()
    {
        customerID=0;
    }

    void inputCustomer()
    {
        inputPerson();

        cout<<"Enter Customer ID : ";
        cin>>customerID;
    }

    void displayCustomer()
    {
        displayPerson();

        cout<<"Customer ID : "<<customerID<<endl;
    }
};

//BASE CLASS: ROOM

class Room
{
protected:
    int roomNumber;
    bool booked;

public:
    Room()
    {
        roomNumber=0;
        booked=false;
    }

    void setRoomNumber(int n)
    {
        roomNumber=n;
    }

    int getRoomNumber()
    {
        return roomNumber;
    }

    bool isBooked()
    {
        return booked;
    }

    void bookRoom()
    {
        booked=true;
    }

    void freeRoom()
    {
        booked=false;
    }

    virtual int getPrice()
    {
        return 0;
    }

    virtual void displayRoom()
    {
        cout<<"Room Number : "<<roomNumber<<endl;
    }
};
