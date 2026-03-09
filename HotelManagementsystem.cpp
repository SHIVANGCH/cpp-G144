#include<iostream>
using namespace std;
class Person{
protected:
    string name;
    int age;
    string phone;
public:
  Person(){
        name= ;
        age=0;
        phone="";
}

    void inputPerson(){
        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Age: ";
        cin>>age;

        cout<<"Enter Phone Number: ";
        cin>>phone;
}

    void displayPerson(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Phone : "<<phone<<endl;
}
};
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
        
    void displayCustomer()
    {
        displayPerson();

        cout<<"Customer ID : "<<customerID<<endl;
    }

};
class Room // base class Room
{

protected:

    int roomNumber;
    bool booked;

public:
