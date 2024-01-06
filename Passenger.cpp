/*
 * Passenger.cpp
 * 
 * COMP 15 homework 2
 * by Vanessa Venkataraman, February 2021
 *
 * Function definitions for the Passenger class
 */


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Passenger.h"

using namespace std;

/* print
 * Purpose: print passenger info to output stream
 * Parameters: output stream
 * Returns: none
 */
void Passenger::print(ostream &output)
{
    output << "[" << this->id << ", " << this->from << "->" << this->to
    << "]";
    
}
