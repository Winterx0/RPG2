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

#include "rpg2header.h"


using namespace std;

int main(int argc, char* argv[])
{

	GameStart gameStarting;
	gameStarting.startRpg();

	///////////////////////////////////////////////////////

	LifeLine lifeLine;
	lifeLine.lifeDisp();

	///////////////////////////////////////////////////////

	//Inventory Menu

	Inventory packlist[MAX_SIZE];
	int numItems = 0;
	bool run = true;
	LOOP1: do
	{
		cout << "User Inventory - " << numItems << " items in your pack." << endl;
		switch (getMenuResponse())
		{
			case 'A': addItem(packlist, numItems); break;
			case 'D': dispItem(packlist, numItems); break;
			case 'Q': run = false; break;
			default: cout << "That is NOT a valid choice" << endl;
		}
	} while (run);

	// Program exits immediatly upon "Q" if entered
	system("pause");
	system("CLS");

	/////////////////////////////////////////////////////

	//Activity Menu;

	cout << "\nPick an acctivity to keep surviving." << endl;
	bool runTwo = true;
	LOOP2: do
	{
		switch (getMenu())
		{
			case 'F': forage(packlist, numItems); break;
			case 'S': fire(packlist, numItems); break;
			case 'C': water(packlist, numItems); break;
			case 'B': build(packlist, numItems); break;
			case 'Q': runTwo = false; break;
		}
	} while (run);

	system("pause");
	system("CLS");


	/////////////////////////////////////////////////////

	Bear bear;
	bear.bearEncounter();

	/////////////////////////////////////////////////////

	//Pick Another Activity
	string choice;

	cout << "\nWould you like to pick another activity? [y/n]\n";
	cin >> choice;
	while (choice == "y")
	{
		cout << "\n\n";
		system("pause");
		system("CLS");
		goto LOOP2;
	}
	if (choice == "n")
	{

		system("pause");
		system("cls");
	}

	/////////////////////////////////////////////////////

	//Return to items menu
	string answer;

	cout << "\nWould you like to go back to the items menu? [y/n]\n";
	cin >> answer;
	while (answer == "y")
	{
		cout << "\n\n";
		system("pause");
		system("CLS");
		goto LOOP1;
	}
	if (answer == "n")
	{

		system("pause");
		system("cls");
	}

	/////////////////////////////////////////////////////

	//restart game
	string input;

	cout << "\nWould you like to restart the game? [y/n]\n";
	cin >> input;
	while (input == "y")
	{
		cout << "\n\n";
		system("pause");
		system("CLS");
		return main(argc, argv);
	}
	if (input == "n")
	{

		system("pause");
		return 0;
	}

}