#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;
/* PERSON BASE CLASS*/

class Person
{
protected:
    string name;
    int age;

public:
    virtual void getDetails()
    {
        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Age: ";
        cin>>age;

        if(age <=0)
            throw runtime_error("Invalid Age");
    } 
virtual void displayDetails()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }

    virtual ~Person(){}
};

 
