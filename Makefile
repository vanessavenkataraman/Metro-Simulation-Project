#########################################################
#             HOMEWORK 2: MetroSim Makefile             #
#########################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

# This rule builds Passenger.o
Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(CXXFLAGS) -c Passenger.cpp

# This rule builds MetroSim.o
MetroSim.o: MetroSim.cpp MetroSim.h PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c MetroSim.cpp

# This rule builds main.o
main.o: main.cpp MetroSim.h PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c main.cpp
	
MetroSim: main.o MetroSim.o PassengerQueue.o Passenger.o
	$(CXX) $(CXXFLAGS) -o MetroSim main.o MetroSim.o PassengerQueue.o \
	Passenger.o

# This rule builds PassengerQueue.o
PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp
	
	
# The below rules are used by unit_test
# This rule will be used by unit_test to build the tests for the 
# PassengerQueue class. 
# please add any other .o files that are needed by Passenger Queue.
unit_test: unit_test_driver.o PassengerQueue.o PassengerQueue_tests.o \
	Passenger.o
	$(CXX) $(CXXFLAGS) unit_test_driver.o PassengerQueue.o \
	PassengerQueue_tests.o Passenger.o

# This rule builds the unit_test_driver.o file 
# unit_test_driver.cpp will be copied for you when running unit_test.
# This driver will contain main()
unit_test_driver.o: unit_test_driver.cpp
	$(CXX) $(CXXFLAGS) -c unit_test_driver.cpp

# This rule builds PassengerQueue_tests.o
PassengerQueue_tests.o: PassengerQueue_tests.cpp PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c PassengerQueue_tests.cpp 

# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	rm *.o *~ a.out
