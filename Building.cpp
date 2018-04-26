/* 
 * File:   Building.cpp
 * Purpose; provide the implementation of the member functions for the class Building
 * Author: pike
 *
 */
#include "Building.h"

Building::Building()
{
}

Building::Building(string name, string ID, string coordinate)
{
   this->name = name;
   this->ID = ID;
   this->coordinate = coordinate;
}

string Building::get_Name() const
{
   return name;
}

string Building::get_ID() const
{
   return ID;
}

string Building::get_Coordinate() const
{
   return coordinate;
}

int Building::compareByName(Building B1, Building B2)
{
    if (B1.name < B2.name)
	return 1;
    if (B1.name == B2.name)
	    return 0;
    else 
		return -1;
}

int Building::compareByID(Building B1, Building B2)
{
    if (B1.ID < B2.ID)
        return 1;
    if (B1.ID == B2.ID)
        return 0;
    else 
        return -1;
}

int Building::compareByReverseCoordinate(Building B1, Building B2)
{
    if (B1.coordinate < B2.coordinate)
        return -1;
    if (B1.coordinate == B2.coordinate)
        return 0;
    else 
        return 1;
}

ostream &operator<<(ostream &out, const Building &B)
{
   return (out << B.name << "\t( ID: " << B.ID << " ) ---> " << B.coordinate); 
}

bool operator>(const Building & B1, const Building & B2)
{
	if (B1.name > B2.name) {
		return true;
	}
	else {
		return false;
	}
}

