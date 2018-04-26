//course: CS216-00x
//Project: Lab Assignment 13
//Date: 04/21/2017
//Purpose: to apply bubble sorting algorithm to different types of objects 
//         and maintain a list of objects in "non-decreasing" order defined by each class.
//         Term class (from Project 2) defines the operator ">": the weight is greater than. 
//         Building class (from Lab10) defines the operator ">": the building name comes later(in dictionary) than 
//         Clock class (from Lecture slides) defines the operator ">": the later time is ">" the earlier time.
//Author: Jared Rigdon

/*
This will use the bubble sort aglthm to sort different type of objects
The main purpose is to show that we dont have to create a sorting aglthm for each different type of object
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include "Term.h"
#include "Building.h"
#include "Clock.h"
#include "SortingList.h"

using namespace std;

int main(int argc, char** argv) {
    
    ifstream in_file;
    string inputfile1 = "fortune.txt";
    string inputfile2 = "UKY_buildings.txt";

    // open the first input file to read the data for Pokemon objects
    in_file.open(inputfile1.c_str());
    if (!in_file.is_open())
    {
       cout << "Failure in opening file: " << inputfile1 << endl;
       return 1;
    }

    SortingList<Term> SL1;
    long weight;
    string query;
    while (!in_file.eof())
    {
        in_file >> weight >> ws;
        getline(in_file, query);
        if (query != "")
        {
            Term newterm(query, weight);
            SL1.insertAtTail(newterm);
        }
    }
    // close the file after finishing reading data from
    in_file.close();

    cout << endl;
    cout << "The sequence of objects before sorting: " <<endl;
    SL1.Print();
    SL1.bubble_sort();

    cout << endl;
    cout << "The sequence of objects after sorting: " <<endl;
    SL1.Print();

    // open the second input file to read data for Country objects
    in_file.open(inputfile2.c_str());
    if (!in_file.is_open())
    {
       cout << "Failure in opening file: " << inputfile2 << endl;
       return 2;
    }

    SortingList<Building> SL2;
    while (!in_file.eof())
    {
        string line;
        getline(in_file, line);
        string name, ID, position;
        istringstream iss(line);
        getline(iss, name, '\t');

        // separate the rest part into ID and coordinate in the map, and also extra white space
        iss >> ws >> ID >> ws >> position;

        if (name != "")
        {
            Building newbuilding(name, ID, position);
            SL2.insertAtTail(newbuilding);
        }
    }
    // close the file after finishing reading data from
    in_file.close();

    cout << endl;
    cout << "The sequence of objects before sorting: " <<endl;
    SL2.Print();
    SL2.bubble_sort();

    cout << endl;
    cout << "The sequence of objects after sorting: " <<endl;
    SL2.Print();

    // Use random number generator to generate the data for Clock objects
    srand(time(0));
    const int MAX = 100;
    const int NUM_CLOCK = 10; // the number of clock time in the list
    SortingList<Clock> SL3(NUM_CLOCK);
    for (int i = 0; i < NUM_CLOCK; i++)
    {
        int hours = rand() % MAX;
        int minutes = rand() % MAX;
        int seconds = rand() % MAX;
        Clock input_ck(hours, minutes, seconds);
        SL3.insertAtTail(input_ck);
    }

    cout << endl;
    cout << "The sequence of objects before sorting: " <<endl;
    SL3.Print();
    SL3.bubble_sort();

    cout << endl;
    cout << "The sequence of objects after sorting: " <<endl;
    SL3.Print();

    return 0;
}

