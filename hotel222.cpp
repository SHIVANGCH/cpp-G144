#include<iostream>
#include<string>
#include<vector>

using namespace std;

/* ---------------------------
   BASE CLASS : PERSON
---------------------------*/

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


/* ---------------------------
   DERIVED CLASS : CUSTOMER
---------------------------*/

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


/* ---------------------------
   BASE CLASS : ROOM
---------------------------*/

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


/* ---------------------------
   DERIVED CLASS : STANDARD ROOM
---------------------------*/

class StandardRoom : public Room
{

public:

    int getPrice()
    {
        return 2000;
    }

    void displayRoom()
    {
        cout<<"Room Number : "<<roomNumber<<endl;
        cout<<"Room Type : Standard"<<endl;
        cout<<"Price : 2000 per night"<<endl;
    }

};


/* ---------------------------
   DERIVED CLASS : DELUXE ROOM
---------------------------*/

class DeluxeRoom : public Room
{

public:

    int getPrice()
    {
        return 4000;
    }

    void displayRoom()
    {
        cout<<"Room Number : "<<roomNumber<<endl;
        cout<<"Room Type : Deluxe"<<endl;
        cout<<"Price : 4000 per night"<<endl;
    }

};


/* ---------------------------
   BOOKING CLASS
---------------------------*/

class Booking
{

private:

    Customer customer;
    Room* room;

    int days;
    int bill;

public:

    Booking()
    {
        days=0;
        bill=0;
        room=NULL;
    }

    void createBooking(Room* r)
    {

        try
        {

            if(r->isBooked())
            {
                throw "Room already booked!";
            }

            room=r;

            cout<<"\nEnter Customer Details\n";

            customer.inputCustomer();

            cout<<"Enter number of days : ";
            cin>>days;

            r->bookRoom();

            bill = r->getPrice() * days;

            cout<<"Booking successful!\n";

        }

        catch(const char* msg)
        {
            cout<<"Error : "<<msg<<endl;
        }

    }

    void displayBooking()
    {

        cout<<"\n------ BOOKING DETAILS ------\n";

        customer.displayCustomer();

        cout<<"Room Number : "<<room->getRoomNumber()<<endl;

        cout<<"Days Stayed : "<<days<<endl;

        cout<<"Total Bill : "<<bill<<endl;

    }

};


/* ---------------------------
   HOTEL CLASS
---------------------------*/

class Hotel
{

private:

    vector<Room*> rooms;

    vector<Booking> bookings;

public:

    Hotel()
    {

        int i;

        for(i=1;i<=5;i++)
        {
            StandardRoom* s=new StandardRoom();

            s->setRoomNumber(i);

            rooms.push_back(s);
        }

        for(i=6;i<=10;i++)
        {
            DeluxeRoom* d=new DeluxeRoom();

            d->setRoomNumber(i);

            rooms.push_back(d);
        }

    }


    void showRooms()
    {

        cout<<"\n------- ROOM LIST -------\n";

        for(int i=0;i<rooms.size();i++)
        {

            rooms[i]->displayRoom();

            if(rooms[i]->isBooked())
                cout<<"Status : Booked\n";
            else
                cout<<"Status : Available\n";

            cout<<endl;
        }

    }


    void bookRoom()
    {

        int number;

        showRooms();

        cout<<"Enter room number to book : ";
        cin>>number;

        if(number<1 || number>rooms.size())
        {
            cout<<"Invalid room number\n";
            return;
        }

        Booking b;

        b.createBooking(rooms[number-1]);

        bookings.push_back(b);

    }


    void showBookings()
    {

        cout<<"\n------ ALL BOOKINGS ------\n";

        if(bookings.size()==0)
        {
            cout<<"No bookings yet\n";
            return;
        }

        for(int i=0;i<bookings.size();i++)
        {
            bookings[i].displayBooking();
        }

    }

};


/* ---------------------------
   MAIN FUNCTION
---------------------------*/

int main()
{

    Hotel hotel;

    int choice;

    while(true)
    {

        cout<<"\n===== HOTEL MANAGEMENT SYSTEM =====\n";

        cout<<"1. View Rooms\n";

        cout<<"2. Book Room\n";

        cout<<"3. View Bookings\n";

        cout<<"4. Exit\n";

        cout<<"Enter choice : ";

        cin>>choice;

        switch(choice)
        {

            case 1:

                hotel.showRooms();

                break;


            case 2:

                hotel.bookRoom();

                break;


            case 3:

                hotel.showBookings();

                break;


            case 4:

                cout<<"Thank you\n";

                return 0;


            default:

                cout<<"Invalid choice\n";

        }

    }

}