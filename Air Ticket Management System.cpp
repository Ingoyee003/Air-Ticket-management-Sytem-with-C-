#include<bits/stdc++.h>
#include<windows.h>
#include<unistd.h>
#include<fstream>
using namespace std;

int passenger_num;
int ticket_num;
int time1 = 70000;

/// Function To Place The Cursor Position(X,Y) On the Screen:
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

///  #Class #1
class passenger
{
private:

    string P_ID, name, mobile;
    int tickets, payment;

public:

    /// Default Constructor
    passenger(){}

    /// Constructor
    passenger(string P_ID, string name, string mobile, int tickets, int payment)
    {
        this->P_ID    = P_ID;
        this->name    = name;
        this->mobile  = mobile;
        this->tickets = tickets;
        this->payment = payment;
    }

    void show_passenger()
    {
        usleep(time1);
        cout << "\t\t\tID      : " << P_ID << endl;
        usleep(time1);
        cout << "\t\t\tNAME    : " << name << endl;
        usleep(time1);
        cout << "\t\t\tMOBILE  : " << mobile << endl;
        usleep(time1);
        printf( "\t\t\tTICKETS : %03d\n", tickets );
        usleep(time1);
        cout << "\t\t\tPAYMENT : " << payment << endl;
    }

    friend void write_passenger_info();
    friend void read_passenger_info();

    friend void search_passenger();

}passenger_arr[100];


///  #Class #2
class ticket
{
private:

    string T_ID, from, to;
    int price, available, distance, arrival, departure;

public:

    /// Default Constructor
    ticket(){}

    /// Constructor
    ticket(string T_ID, string from,string to, int price, int available, int distance, int arrival, int departure)
    {
        this->T_ID      = T_ID;
        this->from      = from;
        this->to        = to;
        this->price     = price;
        this->available = available;
        this->distance = distance;
        this->arrival = arrival;
        this->departure = departure;
    }

    string getT_ID() const
    {
        return T_ID;
    }

    int get_price() const
    {
        return price;
    }

    void show_ticket()
    {
        usleep(time1);
        cout << "\t\t\tID        : " << T_ID << endl;
        usleep(time1);
        cout << "\t\t\tFROM      : " << from << endl;
        usleep(time1);
        cout << "\t\t\tTO        : " << to << endl;
        usleep(time1);
        cout << "\t\t\tPRICE     : " << price << endl;
        usleep(time1);
        printf( "\t\t\tAVAILABLE : %03d\n", available );
        usleep(time1);
        printf( "\t\t\tDISTANCE  : %04d\n", distance );
        usleep(time1);
        printf( "\t\t\tARRIVAL   : %04d\n", arrival );
        usleep(time1);
        printf( "\t\t\tDEPARTURE : %04d\n", departure );
    }

    friend void write_ticket_info();
    friend void read_ticket_info();

    friend void add_ticket_existing();
    friend void edit_ticket();
    friend void update_price();
    friend void delete_ticket();

    friend void buy_ticket();

    friend void heap_sort_tickets();

}ticket_arr[100];

/// (Ticket_Write) Function to Write Ticket info in file
void write_ticket_info()
{
    fstream write("ticket.txt",ios::out);

    write << ticket_num << endl;

    for(int i=0; i<ticket_num; i++)
    {
        write << ticket_arr[i].T_ID << endl;
        write << ticket_arr[i].from << endl;
        write << ticket_arr[i].to << endl;
        write << ticket_arr[i].price << endl;
        write << ticket_arr[i].available << endl;
        write << ticket_arr[i].distance << endl;
        write << ticket_arr[i].arrival << endl;
        write << ticket_arr[i].departure << endl;
    }

    write.close();
}

/// (Ticket_Read) Function to Read Ticket info from file
void read_ticket_info()
{
    fstream read("ticket.txt",ios::in);

    read >> ticket_num;

    for(int i=0; i<ticket_num; i++)
    {
        read >> ticket_arr[i].T_ID;

        read.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(read, ticket_arr[i].from);
        getline(read, ticket_arr[i].to);

        read >> ticket_arr[i].price;
        read >> ticket_arr[i].available;
        read >> ticket_arr[i].distance;
        read >> ticket_arr[i].arrival;
        read >> ticket_arr[i].departure;
    }

    read.close();
}


/// (Passenger_Write) Function to Write Passenger info in file
void write_passenger_info()
{
    fstream write("passenger.txt",ios::out);

    write << passenger_num << endl;

    for(int i=0; i<passenger_num; i++)
    {
        write << passenger_arr[i].P_ID << endl;
        write << passenger_arr[i].name << endl;
        write << passenger_arr[i].mobile << endl;
        write << passenger_arr[i].tickets << endl;
        write << passenger_arr[i].payment << endl;
    }

    write.close();
}

/// (Passenger_Read) Function to Read Ticket info from file
void read_passenger_info()
{
    fstream read("passenger.txt",ios::in);

    read >> passenger_num;

    for(int i=0; i<passenger_num; i++)
    {
        read >> passenger_arr[i].P_ID;

        read.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(read, passenger_arr[i].name);
        getline(read, passenger_arr[i].mobile);

        read >> passenger_arr[i].tickets;
        read >> passenger_arr[i].payment;
    }

    read.close();
}

void heapify(ticket arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].get_price() > arr[largest].get_price())
        largest = left;

    if (right < n && arr[right].get_price() > arr[largest].get_price())
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort_tickets()
{
    read_ticket_info();

    for (int i = ticket_num / 2 - 1; i >= 0; i--)
        heapify(ticket_arr, ticket_num, i);

    for (int i = ticket_num - 1; i > 0; i--)
    {
        swap(ticket_arr[0], ticket_arr[i]);
        heapify(ticket_arr, i, 0);
    }
}


void screen_cls()
{
    for(int i=0; i<=40; i++)
    {
        gotoxy(1,i);
        cout << "                                                                                                                                                            " ;

        fflush(stdout);
        usleep(9999);
    }
}


///  Manager [1]
void add_ticket_new()
{
    system("cls");

    system("color E4");

    read_ticket_info();

    string ID, from, to;
    int price, available, distance, arrival, departure;

    cout << "\n\n\n";

    cout << "\t\t\t<-- ### Add TICKET (New Route) PROCESS  ### -->" << endl;

    cout << "\n\t\t\tID        : ";
    cin >> ID;

    cout << "\t\t\tFROM      : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, from);

    cout << "\t\t\tTO        : ";
    getline(cin, to);

    cout << "\t\t\tPRICE     : ";
    cin >> price;

    cout << "\t\t\tAVAILABLE : ";
    cin >> available;

    cout << "\t\t\tDISTANCE  : ";
    cin >> distance;

    cout << "\t\t\tARRIVAL   : ";
    cin >> available;

    cout << "\t\t\tDEPARTURE : ";
    cin >> departure;

    ticket_arr[ticket_num] = ticket(ID, from, to, price, available, distance, arrival, departure);

    ticket_num++;

    write_ticket_info();

    usleep(time1*5);

    cout << "\n\n\n";
    cout << "\t\t\tAdding TICKET (New Route) Successful...";

    cout << "\n\n";
    cout << "\t\t\tPress Enter To Continue...";

    fflush(stdin);
    getchar();

}

///  Manager [2]
void add_ticket_existing()
{
    system("cls");

    system("color E4");

    read_ticket_info();

    cout << "\n\n\n";

    if(ticket_num == 0)
    {
        cout << "\t\t\tAdd TICKET first...";
    }
    else
    {
        string ID;
        int new_ticket, index = -1;

        cout << "\t\t\t<-- ### Add TICKET (Existing) PROCESS  ### -->\n" << endl;

        cout << "\t\t\tEnter Ticket ID : ";
        cin >> ID;

        for(int i=0; i<ticket_num; i++)
        {
            if(ID == ticket_arr[i].T_ID)
            {
                index = i;
            }
        }

        if(index != -1)
        {
            cout << "\n\n\t\t\tEnter amount of tickets : ";
            cin >> new_ticket;

            ticket_arr[index].available += new_ticket;

            write_ticket_info();

            usleep(time1*5);

            cout << "\n\n\n";
            cout << "\t\t\tAdding TICKET (Existing) Successful...";

        }
        else
        {
            system("cls");

            system("color C0");

            usleep(time1*5);

            cout << "\n\n\n\n\n";
            cout << "\t\t\tID did not match...";
        }

    }

    usleep(time1*5);

    cout << "\n\n\n";
    cout << "\t\t\tPress Enter To Continue...";

    fflush(stdin);
    getchar();

}

///  Manager [3]
void edit_ticket()
{
    system("cls");

    system("color E4");

    read_ticket_info();

    cout << "\n\n\n";

    if(ticket_num == 0)
    {
        cout << "\t\t\tAdd TICKET first...";
    }
    else
    {
        string ID;
        int new_ticket, index = -1;

        cout << "\t\t\t<-- ### TICKET EDIT PROCESS  ### -->\n" << endl;

        cout << "\t\t\tEnter Ticket ID : ";
        cin >> ID;

        for(int i=0; i<ticket_num; i++)
        {
            if(ID == ticket_arr[i].T_ID)
            {
                index = i;
            }
        }

        if(index != -1)
        {
            string ID, from, to;
            int price, available, distance, arrival, departure;

            cout << "\n\n\n";

            cout << "\t\t\t<-- ### Add TICKET (New Route) PROCESS  ### -->" << endl;

            cout << "\n\t\t\tID        : ";
            cin >> ID;

            cout << "\t\t\tFROM      : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, from);

            cout << "\t\t\tTO        : ";
            getline(cin, to);

            cout << "\t\t\tPRICE     : ";
            cin >> price;

            cout << "\t\t\tAVAILABLE : ";
            cin >> available;

            cout << "\t\t\tDISTANCE  : ";
            cin >> distance;

            cout << "\t\t\tARRIVAL   : ";
            cin >> arrival;

            cout << "\t\t\tDEPARTURE : ";
            cin >> departure;

            ticket_arr[index] = ticket(ID, from, to, price, available, distance, arrival, departure);

            write_ticket_info();

            usleep(time1*5);

            cout << "\n\n\n";
            cout << "\t\t\tEDITING TICKET Successful...";

        }
        else
        {
            system("cls");

            system("color C0");

            usleep(time1*5);

            cout << "\n\n\n\n\n";
            cout << "\t\t\tID did not match...";
        }

    }

    usleep(time1*5);

    cout << "\n\n\n";
    cout << "\t\t\tPress Enter To Continue...";

    fflush(stdin);
    getchar();

}

///  Manager [4]
void update_price()
{
    system("cls");

    system("color E4");

    read_ticket_info();

    cout << "\n\n\n";

    if(ticket_num == 0)
    {
        cout << "\t\t\tAdd TICKET first...";
    }
    else
    {
        string ID;
        int new_price, index = -1;

        cout << "\t\t\t<-- ### UPDATE TICKET PRICE PROCESS  ### -->\n" << endl;

        cout << "\t\t\tEnter Ticket ID : ";
        cin >> ID;

        for(int i=0; i<ticket_num; i++)
        {
            if(ID == ticket_arr[i].T_ID)
            {
                index = i;
            }
        }

        if(index != -1)
        {
            cout << "\n\n\t\t\tEnter new price : ";
            cin >> new_price;

            ticket_arr[index].price = new_price;

            write_ticket_info();

            usleep(time1*5);

            cout << "\n\n\n";
            cout << "\t\t\tUPDATE TICKET PRICE Successful...";

        }
        else
        {
            system("cls");

            system("color C0");

            usleep(time1*5);

            cout << "\n\n\n\n\n";
            cout << "\t\t\tID did not match...";
        }

    }

    usleep(time1*5);

    cout << "\n\n\n";
    cout << "\t\t\tPress Enter To Continue...";

    fflush(stdin);
    getchar();
}

///  Manager [5]
void delete_ticket()
{
    system("cls");

    system("color E4");

    read_ticket_info();

    cout << "\n\n\n";

    if(ticket_num == 0)
    {
        cout << "\t\t\tAdd TICKET first...";
    }
    else
    {
        string ID;
        int new_price, index = -1;

        cout << "\t\t\t<-- ### DELETE TICKET PROCESS  ### -->\n" << endl;

        cout << "\t\t\tEnter Ticket ID to DELETE : ";
        cin >> ID;

        for(int i=0; i<ticket_num; i++)
        {
            if(ID == ticket_arr[i].T_ID)
            {
                index = i;
            }
        }

        if(index != -1)
        {
            for(int i=index; i<ticket_num; i++)
            {
                ticket_arr[i] = ticket_arr[i+1];
            }

            ticket_num--;

            write_ticket_info();

            usleep(time1*5);

            cout << "\n\n\n";
            cout << "\t\t\tDELETE TICKET Successful...";

        }
        else
        {
            system("cls");

            system("color C0");

            usleep(time1*5);

            cout << "\n\n\n\n\n";
            cout << "\t\t\tID did not match...";
        }

    }

    usleep(time1*5);

    cout << "\n\n\n";
    cout << "\t\t\tPress Enter To Continue...";

    fflush(stdin);
    getchar();
}

void insertion_sort_tickets()
{
    for (int i = 1; i < ticket_num; i++)
    {
        ticket key = ticket_arr[i];
        int j = i - 1;

        while (j >= 0 && ticket_arr[j].getT_ID() > key.getT_ID())
        {
            ticket_arr[j + 1] = ticket_arr[j];
            j = j - 1;
        }
        ticket_arr[j + 1] = key;
    }
}

///  Passenger [1]
void see_all_ticket()
{
    system("cls");

    system("color E4");

    read_ticket_info();

    cout << "\n\n\n";

    if(ticket_num == 0)
    {
        cout << "\t\t\tAdd TICKET first...";
    }
    else
    {
        insertion_sort_tickets();

        cout << "\t\t\t<-- ### SHOWING ALL TICKETS  ### -->\n" << endl;

        for(int i=0; i<ticket_num; i++)
        {
            cout << "\n\t\t\tTICKET #" << i+1 << endl;

            ticket_arr[i].show_ticket();

        }

    }

    usleep(time1*5);

    cout << "\n\n\n";
    cout << "\t\t\tPress Enter To Continue...";

    fflush(stdin);
    getchar();
}

///  Passenger [2]
void buy_ticket()
{
    system("cls");

    system("color E4");

    read_ticket_info();
    read_passenger_info();

    cout << "\n\n\n";

    if(ticket_num == 0)
    {
        cout << "\t\t\tAdd TICKET first...";
    }
    else
    {
        string ID, confirm;
        int index = -1, tickets;

        cout << "\t\t\t<-- ### TICKET BUYING PROCESS  ### -->\n" << endl;

        cout << "\t\t\tEnter Ticket ID : ";
        cin >> ID;

        for(int i=0; i<ticket_num; i++)
        {
            if(ID == ticket_arr[i].T_ID)
            {
                index = i;
            }
        }

        if(index != -1)
        {
            cout << "\n\n";
            ticket_arr[index].show_ticket();

            cout << "\n\n\t\t\tHow many tickets you want to buy : ";
            cin >> tickets;

            if(tickets > ticket_arr[index].available)
            {
                cout << "\n\n\t\t\tSorry, Not enough tickets available";
            }
            else
            {
                int payment;
                string P_ID, name, mobile;

                cout << "\n\t\t\tID      : ";
                cin >> P_ID;

                cout << "\t\t\tNAME    : ";
                cin.ignore();
                getline(cin, name);

                cout << "\t\t\tMOBILE  : ";
                getline(cin, mobile);


                payment = tickets * ticket_arr[index].price;
                cout << "\n\n\t\t\tYour TOTAL Payment is : " << payment;


                cout << "\n\n\t\t\tConfirm to buy Ticket (Y/N) : ";
                cin >> confirm;

                if(confirm == "Y" || confirm == "y")
                {
                    ticket_arr[index].available -= tickets;

                    write_ticket_info();


                    passenger_arr[passenger_num] = passenger(P_ID, name, mobile, tickets, payment);

                    passenger_num++;

                    write_passenger_info();


                    usleep(time1*5);
                    cout << "\n\n\t\t\tTICKET BUYING Successful...";
                }
                else
                {
                    usleep(time1*5);
                    cout << "\n\n\t\t\tTICKET BUYING Canceled...";
                }
            }
        }
        else
        {
            system("cls");

            system("color C0");

            usleep(time1*5);

            cout << "\n\n\n\n\n";
            cout << "\t\t\tID did not match...";
        }

    }

    usleep(time1*5);

    cout << "\n\n\n";
    cout << "\t\t\tPress Enter To Continue...";

    fflush(stdin);
    getchar();

}

///  Passenger [3]
void search_passenger()
{
    system("cls");

    system("color E4");

    read_passenger_info();

    cout << "\n\n\n";

    if(passenger_num == 0)
    {
        cout << "\t\t\tNo tickets bought yet...";
    }
    else
    {
        string ID;
        int index = -1;

        cout << "\t\t\tEnter Passenger ID to SEARCH : ";
        cin >> ID;

        for(int i=0; i<passenger_num; i++)
        {
            if(ID == passenger_arr[i].P_ID)
            {
                index = i;
            }
        }

        if(index != -1)
        {
            cout << "\n\n";
            passenger_arr[index].show_passenger();
        }
        else
        {
            system("cls");

            system("color C0");

            usleep(time1*5);

            cout << "\n\n\n\n\n";
            cout << "\t\t\tID not found...";
        }
    }

    usleep(time1*5);

    cout << "\n\n\n";
    cout << "\t\t\tPress Enter To Continue...";

    fflush(stdin);
    getchar();
}


int main()
{
    /// Opening a file for Passenger.
    ifstream check_passenger_file("passenger.txt");
    if(!check_passenger_file)
    {
        fstream open_passenger_file("passenger.txt", ios::app);
        {
            open_passenger_file << 0 << endl;
        }
    }

    /// Opening a file for Ticket.
    ifstream check_ticket_file("ticket.txt");
    if(!check_ticket_file)
    {
        fstream open_ticket_file("ticket.txt", ios::app);
        {
            open_ticket_file << 0 << endl;
        }
    }


    while(1)
    {
        HOME:

        system("cls");

        system("color E4");

        cout << "\n\n\n\n";
        cout << "\t\t\t <==  PROJECT AIRLINE  ==>\n" << endl;
        cout << "\t\t\t  -------------------------" << endl;
        cout << "\t\t\t |                         |" << endl;
        cout << "\t\t\t | MANAGER         [1]     |" << endl;
        cout << "\t\t\t | PASSENGER       [2]     |" << endl;
        cout << "\t\t\t | EXIT            [0]     |" << endl;
        cout << "\t\t\t |                         |" << endl;
        cout << "\t\t\t  -------------------------" << endl;

        cout << "\n\t\t\t  ==>ENTER OPTION : ";

        string option;
        cin >> option;

        screen_cls();

        if(option == "1")
        {
            system("cls");

            system("color E4");

            cout << "\n\n\n\n\t\t\tENTER PASSWORD : " ;

            string pass;
            cin >> pass;

            if(pass != "rifah")
            {
                system("cls");

                system("color C0");

                cout << "\n\n\n\n\n";
                cout << "\t\t\tPASSWORD INCORRECT" << endl;

                usleep(time1*5);

                cout << "\n\n\n";
                cout << "\t\t\tPress Enter To Continue...";

                fflush(stdin);
                getchar();

                goto HOME;
            }

            while(1)
            {
                system("cls");

                system("color E4");

                cout << "\n\n\n\n";
                cout << "\t\t\t <==       MANAGER PANEL       ==>\n" << endl;

                cout << "\t\t\t  -----------------------------------" << endl;
                cout << "\t\t\t |                                   |" << endl;
                cout << "\t\t\t | Add TICKET (New Route)    [1]     |" << endl;
                cout << "\t\t\t | Add TICKET (Existing)     [2]     |" << endl;
                cout << "\t\t\t | Edit TICKET               [3]     |" << endl;
                cout << "\t\t\t | Update TICKET Price       [4]     |" << endl;
                cout << "\t\t\t | Delete TICKET             [5]     |" << endl;
                cout << "\t\t\t | Return HOME               [0]     |" << endl;
                cout << "\t\t\t |                                   |" << endl;
                cout << "\t\t\t  -----------------------------------" << endl;

                cout << "\n\t\t\t  ==>ENTER OPTION : ";

                string manager_option;
                cin >> manager_option;

                screen_cls();

                if(manager_option == "1")
                {
                    add_ticket_new();
                }
                else if(manager_option == "2")
                {
                    add_ticket_existing();
                }
                else if(manager_option == "3")
                {
                    edit_ticket();
                }
                else if(manager_option == "4")
                {
                    update_price();
                }
                else if(manager_option == "5")
                {
                    delete_ticket();
                }
                else if(manager_option == "0")
                {
                    goto HOME;
                }
                else
                {
                    system("cls");

                    system("color C0");

                    cout << "\n\n\n\n\n";
                    cout << "\t\t\tENTER VALID OPTION" << endl;

                    usleep(time1*5);

                    cout << "\n\n\n";
                    cout << "\t\t\tPress Enter To Continue...";

                    fflush(stdin);
                    getchar();

                }

            }

        }
        else if(option == "2")
        {
            while(1)
            {
                system("cls");

                system("color E4");

                cout << "\n\n\n\n";
                cout << "\t\t\t <==     PASSENGER PANEL     ==>\n" << endl;

                cout << "\t\t\t  ------------------------------" << endl;
                cout << "\t\t\t |                              |" << endl;
                cout << "\t\t\t | See All Ticket       [1]     |" << endl;
                cout << "\t\t\t | Buy Ticket           [2]     |" << endl;
                cout << "\t\t\t | Search Passenger     [3]     |" << endl;
                cout << "\t\t\t | Return HOME          [0]     |" << endl;
                cout << "\t\t\t |                              |" << endl;
                cout << "\t\t\t  ------------------------------" << endl;

                cout << "\n\t\t\t  ==>ENTER OPTION : ";

                string passenger_option;
                cin >> passenger_option;

                screen_cls();

                if(passenger_option == "1")
                {
                    see_all_ticket();
                }
                else if(passenger_option == "2")
                {
                    buy_ticket();
                }
                else if(passenger_option == "3")
                {
                    search_passenger();
                }
                else if(passenger_option == "0")
                {
                    goto HOME;
                }
                else
                {
                    system("cls");

                    system("color C0");

                    cout << "\n\n\n\n\n";
                    cout << "\t\t\tENTER VALID OPTION" << endl;

                    usleep(time1*5);

                    cout << "\n\n\n";
                    cout << "\t\t\tPress Enter To Continue...";

                    fflush(stdin);
                    getchar();

                }

            }


        }
        else if(option == "0")
        {
            break;
        }
        else
        {
            system("cls");

            system("color C0");

            cout << "\n\n\n\n\n";
            cout << "\t\t\tENTER VALID OPTION" << endl;

            usleep(time1*5);

            cout << "\n\n\n";
            cout << "\t\t\tPress Enter To Continue...";

            fflush(stdin);
            getchar();

        }

    }

}

