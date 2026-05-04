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
