/*
 * MetroSim.cpp
 * 
 * COMP 15 homework 2
 * by Vanessa Venkataraman, February 2021
 *
 * Creates and runs a MetroSim
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "MetroSim.h"
#include "Passenger.h"
#include "PassengerQueue.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 3 or argc > 4){
		cout <<"Usage: MetroSim stationsFile outputFile [commandsFile]" 
				<< endl;
	}
	else{
		string infile = argv[1];
		ifstream station_file;
		station_file.open(infile);
	
		string outfile = argv[2];
		ofstream output_file;
		output_file.open(outfile);
	
		if (!station_file){
			cerr << "ERROR: could not open file " << infile << endl;
			exit(EXIT_FAILURE);
		}
		if (!output_file){
			cerr << "ERROR: could not open file " << outfile << endl;
			exit(EXIT_FAILURE);
		}
		MetroSim M = MetroSim(station_file);
		station_file.close();
	
		if (argc == 3){
			M.run_command(cin, output_file);
		}
		else{
			M.run_command_file(argv, output_file);
		}
		output_file.close();
	}
	return 0;
}