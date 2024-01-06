/*
 * PassengerQueue.h
 * 
 * COMP 15 homework 2
 * by Vanessa Venkataraman, February 2021
 *
 * This is a class declaration for a PassengerQueue
 */

#ifndef __PASSENGER_QUEUE_H__
#define __PASSENGER_QUEUE_H__

#include <vector>
#include <iostream>
#include "Passenger.h"

using namespace std;

class PassengerQueue {
    public: 
        Passenger front();
        void dequeue();
        void enqueue(const Passenger &passenger);
        int size();
        void print(ostream &output);
        
    private:
        vector<Passenger> queue;
};

#endif