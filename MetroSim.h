/*
 * MetroSim.h
 * 
 * COMP 15 homework 2
 * by Vanessa Venkataraman, February 2021
 *
 * This is a class declaration for a MetroSim
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Station{
    string station_name;
    int station_num;
    PassengerQueue queue;
    bool train_here;
};

class MetroSim
{
public:
    // default constructor
    MetroSim(ifstream &station_file);
    // command loop functions
    bool call_func(string command, ofstream &output);
    void run_command(istream &infile, ofstream &output);
    void run_command_file(char *argv[], ofstream &output);
    
private:
    // action functions
    Passenger makePassenger(int on, int off);
    void passenger_arrival(int arrival, int departure);
    void makeStations(ifstream &station_file);
    void moveTrain(ofstream &output);
    void print();
    void finish();
    void passenger_depart(int train, ofstream &output, string station);
    
    int train_location, num_stations, num_passengers;

    vector<Station> stationList;
    vector<PassengerQueue> Train;
};

#endif
