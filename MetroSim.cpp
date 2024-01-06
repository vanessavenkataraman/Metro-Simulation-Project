/*
 * MetroSim.cpp
 * 
 * COMP 15 homework 2
 * by Vanessa Venkataraman, February 2021
 *
 * Function definitions for the MetroSim class
 */

#include "MetroSim.h"
#include "Passenger.h"
#include "PassengerQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const string MM = "m m";
const string MF = "m f";
const string P = "p";

/* default constructor
 * Purpose: initializes variables, creates station list, prints map
 * Parameters: ifstream &station_file
 * Returns: none
 */
MetroSim::MetroSim(ifstream &station_file){
    train_location = 0;
    num_passengers = 0;
    makeStations(station_file);
    num_stations = stationList.size();
    stationList[0].train_here = true;
    
    print();
}

/* makePassenger
 * Purpose: makes Passengers with given info
 * Parameters: int on, int off
 * Returns: Passenger
 */
Passenger MetroSim::makePassenger(int on, int off){
    Passenger new_passenger;
    num_passengers++;
    new_passenger.id = num_passengers;
    new_passenger.from = on;
    new_passenger.to = off;
    
    return new_passenger;
}

/* passenger_arrival
 * Purpose: puts passengers into the station queues
 * Parameters: int arrival, int departure
 * Returns: none
 */
void MetroSim::passenger_arrival(int arrival, int departure){
    
    Passenger new_p = makePassenger(arrival, departure);
    int index = new_p.from - 1;
    stationList[index].queue.enqueue(new_p);
    
    print();
}


/* makeStations
 * Purpose: makes stations and adds them to stationList
 * Parameters: ifstream &station_file
 * Returns: none
 */
void MetroSim::makeStations(ifstream &station_file){
    string s_name;
    int s_num = 1;
    // loops through each line of the file until it reaches the end
    while (!(station_file.eof())){
        getline(station_file, s_name);
        if (s_name != ""){
            Station new_station;
            new_station.station_name = s_name;
            new_station.station_num = s_num;
            new_station.train_here = false;
            stationList.push_back(new_station);
            s_num++;
            PassengerQueue car;
            Train.push_back(car);
        }
    }
}

/* moveTrain
 * Purpose: moves passengers on and off train, moves train, prints map
 * Parameters: ostream &output
 * Returns: none
 */
void MetroSim::moveTrain(ofstream &output){
    // loops through the passenger queue of the station until it is empty
    while (stationList[train_location].queue.size() != 0){
        int temp_index = ((stationList[train_location].queue.front().to) - 1);
        Train[temp_index].enqueue(stationList[train_location].queue.front());
        stationList[train_location].queue.dequeue();
    }
    
    stationList[train_location].train_here = false;
    int temp = stationList.size();
    // update train location
    if (train_location == (temp - 1)){
        train_location = 0;
    }
    else{
        train_location++;
    }
    stationList[train_location].train_here = true;
    
    passenger_depart(train_location, output, \
        stationList[train_location].station_name);
    print();
}
/* print
 * Purpose: prints map
 * Parameters: none
 * Returns: none
 */
void MetroSim::print(){
    cout << "Passengers on the train: {";
    int temp = Train.size();
    // loops through all indexes of the train vector
    for (int i = 0; i < temp; i++){
        Train[i].print(cout);
    }
    cout << "}" << endl;
    // iterates through the vector of station structs
    for (int i = 0; i < num_stations; i++){
        if (stationList[i].train_here == false){
            cout << "       [";
        }
        else{
            cout << "TRAIN: [";
        }
        cout << stationList[i].station_num << "] " 
                << stationList[i].station_name << " {";
        stationList[i].queue.print(cout);
        cout << "}" << endl;
    }
}

/* finish
 * Purpose: clears the vector and prints end message
 * Parameters: none
 * Returns: none
 */
void MetroSim::finish(){
    stationList.clear();
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
 }
 
 /* passenger_depart
  * Purpose: removes Passengers from queue when they reach destination
  * Parameters: int train, string station, ofstream &output
  * Returns: none
  */
 void MetroSim::passenger_depart(int train, ofstream &output, string \
                         station)
     {
         // loops through the passenger queue of the train car until empty
         while (Train[train].size() != 0){
                 output << "Passenger " << Train[train].front().id 
                            << " left train at station " << station << endl;
                 Train[train].dequeue();
     }
}

/* call_func
 * Purpose: calls function based on command given
 * Parameters: string command ostream &output
 * Returns: boolean
 */
bool MetroSim::call_func(string command, ofstream &output){
    string c;
	stringstream ss(command);
	ss >> c;
	if (c == "m"){
        ss >> c;
        if (c == "f"){
            finish();
            return true;
        }
        else if (c == "m"){
            moveTrain(output);
        }
        else{
            cout << "invalid input" << endl;
        }
	}
	else if (c == P){
		int on, off;
		ss >> on >> off;
		passenger_arrival(on,off);
	}
	else{
		cout << "invalid input" << endl;
	}
	return false;
}

/* run_command
 * Purpose: runs call_func using given commands until end of file or quit
 * Parameters: istream &infile, ofstream &output
 * Returns: none
 */
void MetroSim::run_command(istream &infile, ofstream &output){
	string com;
	bool quit = false;
    // loops until end of file is reached or quit is called
	while (!infile.eof() and !quit){
			cout << "Command? ";
		getline(infile, com);
		quit = call_func(com, output);
	}
}

/* run_command_file
 * Purpose: opens command file and runs run_command with it
 * Parameters: char *argv[] and ofstream &output
 * Returns: none
 */
void MetroSim::run_command_file(char *argv[], ofstream &output){
	string file = argv[3];
	ifstream command;
	command.open(file);
	if (!command){
		cerr << "ERROR: could not open file " << file << endl;
		exit(EXIT_FAILURE);
	}
	else{
		run_command(command, output);
		command.close();
	}
}