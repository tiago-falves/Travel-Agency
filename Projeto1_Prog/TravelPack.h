#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "StringManipulator.h"
#include "defs.h"
#include "Date.h"

using namespace std;

class TravelPack{
private:
	unsigned id; // TravelPack unique identifier
	int lastPackIdentifier;
	vector<string> touristicSpots; // touristic touristicSpots to visit
	Date begin;  // begin date
	Date end;  // end date
	double pricePerPerson; // price per person
	unsigned maxPersons; // number of persons still available in the TravelPack (updated whenever the TravelPack is sold to a new client)
	int soldTicketsNumber;
  
 public:
	 TravelPack();
	 TravelPack(string fileName, vector<TravelPack> &travelPacksVector);
	 TravelPack(int identifier, vector<string> touristicSpots, Date begin, Date end, double pricePerPerson, unsigned maxPersons, int soldTicketsNumber);

	 // GET methods
	 unsigned getId() const;
	 vector<string> getTouristicSpots() const;
	 Date getBeginDate() const;
	 Date getEndDate() const;
	 double getPricePerPerson() const;
	 unsigned getMaxPersons() const;
	 int getSoldTicketsNumber() const;

	 // SET methods
	 void setId(unsigned id);  // to set negatve if "deprecated"
	 void setTouristicSpots(vector<string> touristicSpots);
	 void setBeginDate(Date begin);
	 void setEndDate(Date end);
	 void setPricePerPerson(double pricePerPerson);
	 void setMaxPersons(unsigned maxPersons);
	 void setSoldTicketsNumber(int soldTicketsNumber);
	 void setLastPackIdentifier(int lastPackIdentifier);

	 // other methods

	 //Reads the Travel Pack file and puts its information into a vector
	 static void readTravelPacks(string fileName, vector<TravelPack> &travelPacksVector);

	 // Add a Travel Pack to travelPackVector
	 static void addTravelPack(vector<TravelPack> &travelPackVector, TravelPack travelPack);

	 //Removes travelPackRemove from travelPackVector
	 static void removeTravelPack(TravelPack travelPackToRemove, vector<TravelPack> &travelPackVector);

	 //Substitute travelPackToModify for travelPack
	 static void modifyTravelPack(TravelPack travelPackToModify, vector<TravelPack> &travelPackVector, TravelPack travelPack);
	  
	 //True if TravelPack is in vector 
	 bool travelPackInVector(vector<TravelPack> travelPackVector, TravelPack travelPack);

	 //Separate the touristic spots in a vector, the first element being the city
	 vector<string> separatedDestination(string destinations);		  

	 //True if Travel Packs are equal
	 static bool equalTravelPacks(TravelPack travelPack1, TravelPack travelPack2); //Substituir por overide do ==

	 void showTravelPack() const; // displays the travelpacks in a nice format

	 friend bool operator==(const TravelPack& travelpack1, const TravelPack& travelpack2);
	 friend ostream& operator<<(ostream& out, const TravelPack & TravelPack);
	 friend ostream& operator<<(ostream& out, const vector<string>& touristicSpots);
};
