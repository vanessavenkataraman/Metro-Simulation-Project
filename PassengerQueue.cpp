/*
 * PassengerQueue.cpp
 * 
 * COMP 15 homework 2
 * by Vanessa Venkataraman, February 2021
 *
 * Function definitions for the PassengerQueue class
 */


#include <vector>
#include "PassengerQueue.h"
#include "Passenger.h"
#include <iostream>

using namespace std;

/* front
 * Purpose: returns Passenger at the front of the queue
 * Parameters: none
 * Returns: first Passenger
 */
Passenger PassengerQueue::front(){
    return queue.front();
}

/* dequeue
 * Purpose: removes Passenger at the front of the queue
 * Parameters: none
 * Returns: none
 */
void PassengerQueue::dequeue(){
    queue.erase(queue.begin());
}

/* enqueue
 * Purpose: inserts new Passenger at end of queue
 * Parameters: Passenger passenger
 * Returns: none
 */
void PassengerQueue::enqueue(const Passenger &passenger){
    queue.push_back(passenger);
}

/* size
 * Purpose: returns the number of Passengers in the queue
 * Parameters: none
 * Returns: none
 */
int PassengerQueue::size(){
    return queue.size();
}

/* print
 * Purpose: prints each passenger in the queue to the output stream
 * Parameters: ostream &output
 * Returns: none
 */
void PassengerQueue::print(ostream &output){
    int temp = queue.size();
    // iterates through each passenger in the queue
    for (int i = 0; i < temp; i++){
        queue.at(i).print(output);
    }
}