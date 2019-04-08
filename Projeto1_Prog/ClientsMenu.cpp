#include "ClientsMenu.h"
#include "Clients.h"
using namespace std;

void runClientsMenu() {
	int option;


	cout << "Welcome to the Clients Menu! Please choose what you want to do: ";
	cout << endl << endl;
	cout << "0. Create a new client." << endl;
	cout << "1. Change a client information." << endl;
	cout << "2. Remove a client" << endl;
	cout << "3. See informaion from all clients. " << endl << endl;
	cout << "Insert the number correspondent to your option: ";
	cin >> option;
	

	while (cin.fail() || (option != 0 && option != 1 && option != 2 && option != 3))
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
	menuSeparator();

	if (option == 0) { createClientOption();}
}

void createClientOption() {
	Client client;
	
	string name;
	int nif;
	int familyNumber;
	string addressText;
	string touristicPacksBought;

	cout << "Please insert the data of your new client" << endl << endl;
	cout << "Name: ";
	cin >> name;
	cout << "NIF: ";
	cin >> nif;
	validCin(nif);
	cout << "Number of people in the family: ";
	cin >> familyNumber;
	validCin(familyNumber);
	cout << "Address (Street / Door Number / Floor Number / Postal Code / Locality): ";
	cin >> addressText;
	/*while (!validAddressText(addressText))
	{
		cout << "Invalid address, please insert again: ";
		cin >> addressText;
	}*/
	

}