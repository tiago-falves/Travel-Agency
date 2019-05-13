#include "ClientsMenu.h"
#include "Client.h"
using namespace std;

//Asks all information and asks the user what option to choose
void runClientsMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector,Agency agency){
	int option;

	cout << "Welcome to the Clients Menu! Please choose what you want to do: ";
	cout << endl << endl;
	cout << "1. Create a new client." << endl;
	cout << "2. Change a client information." << endl;
	cout << "3. Remove a client" << endl;
	cout << "4. See information from all clients. " << endl;
	cout << "5. See from a specific client. " << endl;
	cout << "6. Buy a touristic pack for a client" << endl << endl;
	cout << "Insert the number correspondent to your option: ";
	cin >> option;
	
	while (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6))
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}

	cin.clear();
	cin.ignore(10000, '\n');

	menuSeparator();

	if (option == 1) { createClientOption(clientsVector);}
	if (option == 2) { modifyClientOption(clientsVector);}
	if (option == 3) { removeClientOption(clientsVector);}
	if (option == 4) { showAllClients(clientsVector);}
	if (option == 5) { showClientOption(clientsVector);}
	if (option == 6) { buyTravelPack(clientsVector, travelPacksVector);}

	runMenu(clientsVector, travelPacksVector,agency);
}


void showClientOption(vector<Client> clientsVector) {
	showClient(askForNIF(clientsVector));
	menuSeparator();
}
//Returns a Client of the database by inserting a NIF
Client askForNIF(vector<Client> clientsVector){
	Client client;
	int nif;
	bool inDatabase = false;
	cout << "Insert Clients NIF: ";
	cin >> nif;
	validCin(nif);
	cin.clear();
	cin.ignore(10000, '\n');

	for (int i = 0; i < clientsVector.size(); i++)
	{
		if (clientsVector[i].getnif() == nif) { return clientsVector[i]; }
		
	}
	while (!inDatabase)
	{
		cout << "NIF not in the database, please insert again: ";
		cin >> nif;
		validCin(nif);
		cin.clear();
		cin.ignore(10000, '\n');
		for (int i = 0; i < clientsVector.size(); i++)
		{
			if (clientsVector[i].getnif() == nif) { return clientsVector[i]; }
		}
	}
	
}

//Adds the travel pack identiier to the client, alters the bought travelPack
void buyTravelPack(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector) {
	Client client;
	int getId();
	bool validgetId() = false;

	cout << "Insert the Clients information you want to buy the touristic pack: " << endl;
	client = askForNIF(clientsVector);
	
	cout << endl << "Insert the Touristic Pack getId() you want to buy: ";
	cin >> getId();
	validCin(getId());
	while (!validgetId())
	{
		for (int i = 0; i < travelPacksVector.size(); i++)
		{
			if (getId() == travelPacksVector[i].getId() && travelPacksVector[i].getId() > 0 && (travelPacksVector[i].getMaxPersons()-travelPacksVector[i].getSoldTicketsNumber()) > 0)
			{
				validgetId() = true;
				travelPacksVector[i].setSoldTicketsNumber(travelPacksVector[i].getSoldTicketsNumber() + 1);
				if ((travelPacksVector[i].getMaxPersons() - travelPacksVector[i].getSoldTicketsNumber()) <= 0) {
					travelPacksVector[i].setId( -travelPacksVector[i].getId());
				}
				cout << endl << "Touristic pack bought successfuly!" << endl;
				break;
			}
		}
		if (!validgetId())
		{
			cout << "getId() not in the database, please insert again: ";
			cin >> getId();
			validCin(getId());
		}
	}

	for (int i = 0; i < clientsVector.size(); i++)
	{
		if (client == clientsVector[i]) {
			//clientsVector[i].setgetTouristicPackgetId()()s( clientsVector[i].getgetTouristicPackgetId()()s().push_back(getId())); //Nao percebo o erro que da
		}
	}
	menuSeparator();
}

// Show information from all clients
void showAllClients(vector<Client> clientsVector){
	
	for (int i = 0; i < clientsVector.size(); i++)
	{
		cout << "Client " << i + 1 << ":" << endl;
		showClient(clientsVector[i]);
		cout << endl << endl;
	}
	menuSeparator();
}
//Show a certain client information
void showClient(Client client) {
	
	cout << "Name: " <<client.getName() << endl;
	cout << "NIF: " << client.getnif() << endl;
	cout << "Number of people in the family: " << client.getFamilySize() << endl;
	cout << "Address: " << client.getAddress().getStreet() << " / " << client.getAddress().getDoorNumber() << " / " << client.getAddress().getFloor() << " / " << client.getAddress().getPostalCode() << " / " << client.getAddress().getLocation() << endl;
	cout << "Tourist Packs bought: " << Client::travelPacksToString(client.getTravelPackgetId()s());
	
}

//Asks for Client information and returns a Client
Client askForClientsInformation() {
	Client client;

	string name;
	int nif;
	int familyNumber;
	string addressText;
	string touristicPacksBought;

	
	cout << "Name: ";
	getline(cin, name);

	cout << "NIF: ";
	cin >> nif;
	validCin(nif);
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Number of people in the family: ";
	cin >> familyNumber;
	validCin(familyNumber);
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Address (Street / Door Number / Floor Number / Postal Code / Locality): ";
	getline(cin, addressText);

	while (!Address::validAddressText(addressText) || addressText == "////")
	{
		cout << "Invalid address, please insert again: ";
		getline(cin, addressText);
	}

	cout << "Tourist Packs bought (separated by ';'): ";
	getline(cin, touristicPacksBought);

	while (!Client::validPacksBought(touristicPacksBought) || touristicPacksBought == "")
	{
		cout << "Invalid Touristic Pack, please insert again: ";
		getline(cin, touristicPacksBought);
	}

	client.setName(name);
	client.setNif( nif);
	client.setFamilySize(familyNumber);
	client.setAddress(Address::addressTextConverter(addressText));
	client.getTravelPackgetId()s() = separateCharacterInt(touristicPacksBought, ';');

	return client;
}

//Asks the user for data and adds a new client to clientsvector
void createClientOption(vector<Client> &clientsVector) {
	Client client;
	cout << "Please insert the data of your new client" << endl << endl;
	client = askForClientsInformation();
	Client::addClient(clientsVector, client);
	cout << endl << endl << "Client created successfully!";
	menuSeparator();
}

//Asks the user which client he wants to modify, and changes it
void modifyClientOption(vector<Client> &clientsVector) {
	Client clientToModify;
	Client modifiedClient;

	cout << "Please insert the data of the client you want to modify" << endl << endl;
	clientToModify = askForNIF(clientsVector);

	cout << endl << endl << "Insert the new informations about the client: " << endl << endl;
	modifiedClient = askForClientsInformation();
	//Perguntar porque que Ele aqui pergunta o name duas vezes
	Client::modifyClient(clientToModify, clientsVector, modifiedClient);
	cout << endl << endl << "Client modified successfully!";
	menuSeparator();
}

//Asks the user the nif of the client it wants to removes, and removes it from clientsVector
void removeClientOption(vector<Client> &clientsVector) {
	Client client;
	cout << "Please insert the data of the client you want to remove" << endl << endl;
	(client = askForNIF(clientsVector));
	
	Client::removeClient(client, clientsVector);
	cout << endl << endl << "Client removed successfully!";
	menuSeparator();
}