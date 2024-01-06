/*
 * PassengerQueue_tests.cpp
 * 
 * COMP 15 homework 2
 * by Vanessa Venkataraman, February 2021
 *
 * Testing file for the PassengerQueue functions
 */
 
 #include <cassert>
 #include <iostream>
 #include <vector>
 #include "PassengerQueue.h"
 #include "Passenger.h"

 using namespace std;
 
 /* front function test
  * Run the front function to ensure that the first passenger is returned
  */
 void front_test(){
     PassengerQueue test_queue;
     Passenger Elka(1,1,3);
     test_queue.enqueue(Elka);
     cout << "This should be 1: " << (test_queue.front()).id << endl;;
 }
 
 /* dequeue function test
  * Runs the dequeue function to ensure that the first passenger is removed
  */
 void dequeue_test(){
     PassengerQueue test_queue;
     Passenger Elka(1,1,3);
     Passenger Nicole(2,2,7);
     Passenger Jeff(4,5,6);
     test_queue.enqueue(Elka);
     test_queue.enqueue(Nicole);
     test_queue.enqueue(Jeff);
     test_queue.dequeue();
     cout << "This should print 2, 2->7 first: ";
     test_queue.print(cout);
 }
 
 /* enqueue function test
  * Runs the enqueue function to ensure that the passenger is added to the back
  * of the queue
  */
  void enqueue_test(){
     PassengerQueue test_queue;
     Passenger Elka(1,1,3);
     Passenger Nicole(2,2,7);
     Passenger Jeff(4,5,6);
     test_queue.enqueue(Elka);
     test_queue.enqueue(Nicole);
     test_queue.enqueue(Jeff);
     test_queue.print(cout);
 }
  
 /* size function test
  * Runs the size function to ensure that the correct size is returned
  */
  void size_test(){
     PassengerQueue test_queue;
     Passenger Elka(1,1,3);
     Passenger Nicole(2,2,7);
     Passenger Jeff(4,5,6);
     test_queue.enqueue(Elka);
     test_queue.enqueue(Nicole);
     test_queue.enqueue(Jeff);
     cout << "This should be 3: " << test_queue.size() << endl;
 }
   
 /* print function test
  * Runs the print function to ensure that the passengers are printed in 
  * the correct format
  */
  void print_test(){
     PassengerQueue test_queue;
     Passenger Elka(1,1,3);
     Passenger Nicole(2,2,7);
     Passenger Jeff(4,5,6);
     test_queue.enqueue(Elka);
     test_queue.enqueue(Nicole);
     test_queue.enqueue(Jeff);
     test_queue.print(cout);
 }