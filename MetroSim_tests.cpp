/*
 * MetroSim_tests.cpp
 * 
 * COMP 15 homework 2
 * by Vanessa Venkataraman, February 2021
 *
 */
 
 #include <cassert>
 #include <iostream>
 #include <vector>
 #include "MetroSim.h"
 #include "PassengerQueue.h"
 #include "Passenger.h"

 using namespace std;
 
 void constructor_test(){
     string filename;
     cout << "enter filename: ";
     cin >> filename;
     MetroSim(filename) test_m;
     cout << "This should be 0" << test_m.train_location << endl;
     cout << "This should be 0" << test_m.num_passengers << endl;
 }