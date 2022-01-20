/*
    This is a simulation program inspired by The Oregon Trail. 
    The user will pick a user name.
    You have the ability to add items to your pack of your choosing to survive and the quantity.
    You have a limited number of items so choose carefully!
    There are some activities that you will choose from to keep surviving.
    There are also animal encounters that could harm you.
    You have the option to go back to the activity and inventory menu to try new things
    You can restart the game if you wish
    Good luck and stay alive!
*/

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;


//Base class 1
class GameStart
{
private:
    string username;
    time_t current_time;
    struct tm  local_time;

public:
    

    void startRpg()
    {
        //Local date and time settings
        time(&current_time);
        localtime_s(&local_time, &current_time);

        int Year = local_time.tm_year + 1900;
        int Month = local_time.tm_mon + 1;
        int Day = local_time.tm_mday;

        int Hour = local_time.tm_hour;
        int Min = local_time.tm_min;

        //start simulator
        cout << "Wilderness Survival Simulator Starting..." << endl;
        cout << "\nThe wind blows through the leaves, rustling the forrest.";
        cout << "\nBranches bend and snap, falling to the ground covered in moss, vines, and soil.";
        cout << "\nThe air is dry right at the beginning of " << Month << "/" << Day << "/" << Year << endl;
        cout << "You awoke at " << Hour << ":" << Min << endl;

        //user input
        cout << "\nEnter your username: ";
        cin >> username;
        cout << username << " It's time to get up!\n" << endl;

        system("pause");
        system("CLS");
    }

};

//Base class 2
class LifeLine 
{
public:
    int lives = 5;

    void lifeDisp()
    {
        //Lives
        cout << "\nYou look up at the sky and breathe in the fresh air. " << endl;
        cout << "You feel strong and ready to begin a new journey into the wilderness. " << endl;
        cout << "As you go on your journey, you prepare yourself, gathering items and preparing for the unknown." << endl;
        cout << "Days will pass, but you will learn how to sustain and preserve." << endl;
        cout << "It's time to begin...\n" << endl;
        cout << "You have " << lives << " lives left.\n" << endl;
        system("pause");
        system("CLS");
    }
    
};

//Child class
class Bear : public LifeLine
{
public:
    int loseLife = 1;

    void bearEncounter()
    {
        cout << "You've encountered a Bear!" << endl;
        cout << "He looks like he's hungary..." << endl;
        cout << "The bear growls and attacks - " << endl;
        cout << "You have " << lives - loseLife << " lives left!\n" << endl; //inheritance
    }
    
};


///////////////////////////////////////////////////////////

//Inventory Menu

struct Inventory
{
    string name;   // inventory item name
    int qty;       // how many are in stock
};

// const for the max size of the record array
const int MAX_SIZE = 10;

// function prototypes
void addItem(Inventory list[], int& size);
void dispItem(const Inventory list[], int size);
char getMenuResponse();

//menu input
char getMenuResponse()
{
    char response;
    cout << endl << "Make your selection" << endl << "(A)dd Items, (D)isplay Items, (Q)uit Items Menu" << endl << "> ";
    cin >> response;
    cin.ignore(256, '\n');
    return toupper(response);

}

//adds item to inventory
void addItem(Inventory list[], int& size)
{
    Inventory tmp; // declare a temp item that we will load before putting in the array
    char response;
    char str[256]; //char array input for cin.getline
    if (size < MAX_SIZE) {
        system("cls");
        cout << "Please enter an items to add to your pack. " << endl;
        cout << "Enter item: " << endl << endl;
        cout << "Name: ";
        cin.getline(str, 256, '\n');
        tmp.name = str;
        cout << "Quantity: ";
        cin >> tmp.qty;
        cout << endl;
        // see if item should be added
        cout << "Add to inventory? (y/n) ";
        cin >> response;
        if (toupper(response) == 'Y')
            list[size++] = tmp;
    }
    else {
        cout << "Inventory is full; cannot enter more units." << endl;
        system("pause");
    }
    system("cls");
}

//displays item in inventory
void dispItem(const Inventory list[], int size)
{
    system("cls");

    if (size < 1) {
        cout << "Nothing to display" << endl;
    }
    else {
        cout << "All Items in your Pack" << endl << endl;
        cout << fixed << setprecision(2);
        cout << "Item Name              Qty     " << endl;
        cout << "~~~~~~~~~~~~~~~~~~" << endl;

        cout << left;
        for (int i = 0; i < size; i++) {
            cout << setw(21) << list[i].name << right
                << setw(4) << list[i].qty << left << endl;
        }

        cout << "~~~~~~~~~~~~~~~~~~~" << endl;
        cout << right << setw(3) << size;
        cout << " items listed";
    }

    system("PAUSE");
    system("cls");
}

///////////////////////////////////////////////////////////

//Activity Menu

char getMenu();

char getMenu()
{
    char respond;
    cout << "What would you like to do? [F]orage, [S]tart a fire, [C]ollect water, [B]uild Shelter, [Q]uit " << endl << "> ";
    cin >> respond;
    cin.ignore(256, '\n');
    return toupper(respond);

}

//Activity functions
void forage(Inventory list[], int& size);
void fire(Inventory list[], int& size);
void water(Inventory list[], int& size);
void build(Inventory list[], int& size);

void forage(Inventory list[], int& size)
{
    cout << "You began to forage." << endl;
    cout << "While you were foraging, you found some items." << endl;
    system("pause");
    return addItem(list, size);
}

void fire(Inventory list[], int& size)
{
    cout << "You began to start a fire." << endl;
    cout << "You used items from your pack to start a fire." << endl;
    for (int i = 0; i < size; i++)
    {
        list[i].name;
        list[i].qty;
    }
}

void water(Inventory list[], int& size)
{
    cout << "You found a running stream and collected water." << endl;
    cout << "Items have been added to your pack." << endl;
    system("pause");
    return addItem(list, size);
}

void build(Inventory list[], int& size)
{
    cout << "You organized materials and built a shelter." << endl;
    cout << "You used items from your pack." << endl;
    for (int i = 0; i < size; i++)
    {
        list[i].name;
        list[i].qty;
    }
}
