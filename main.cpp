// Scott Jackson - elevator-sim application

// Includes
#include <exception>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

// Using
using std::abs;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::stringstream;
using std::vector;

// Constants
const int TRAVEL_TIME = 10;

// JobRequest - Maintains the state of the job being executed
//
// ASSUMPTION: Defaults to starting at the first floor, with no requested floors.
struct JobRequest {

    // Attributes
    int start = 1;
    vector<int> floors = {};
    int total_travel_time = -1;
    
    // Operations
    void display();      
    bool is_valid();

};

// Returns whether Job Request is in a valid state
// 
// ASSUMPTION: No additional validation is needed, until business rules are defined.  Either the default values or the inputed integers will surfice.  
// If default values should not be used, then we would check if the job was correctly initialized here.
bool JobRequest::is_valid() { 
    return true; 
}

// Displays the current job request state
void JobRequest::display() { 
    cout << total_travel_time << " " << start;
    for (const auto& floor : floors) { cout << ", " << floor; }
    cout << endl;
}

// Refactored helper function that splits a comma-separated string of integer values and populates a vector of integers
//
// NOTE: Uses String Stream to split the floor string and populate floor vector with ints 
//
// NOTE: Potential to raise an exception if string is invalid.
void populate_floor_vector(const string& floor_string, vector<int> &floors) {   
    if (floor_string.empty()) return;
    
    stringstream ss(floor_string);
    string floor;    
    while (getline(ss, floor, ',')) { 
        floors.push_back(stoi(floor)); }    
}

// Process the Command Line Arguments and populates the Job Request.  Basic error handling is in place to return false if unsuccessful.
//
// ASSUMPTION:  Arguments can come in any order.  They must use a space deliminater.  Unknown arguments should be treated as an error.  
bool process_arguments(int argc, char* argv[], JobRequest& job) {
        
    for (int i = 1; i < argc; ++i) {
        string arg(argv[i]);
        try {
            if (arg.substr(0, 6) == "start=") {
                job.start = std::stoi(arg.substr(6));           
            } else if (arg.substr(0, 6) == "floor=") {
                populate_floor_vector(arg.substr(6),job.floors);           
            } else {
                cerr << "Invalid argument: " << arg << endl;
                return false;
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Execption Caught(process_arguments): " <<  e.what() << endl;
            return false;
        } catch (const std::out_of_range& e) {
            cerr << "Execption Caught(process_arguments): " << e.what() << endl;
            return false;
        } 
    }      

    return job.is_valid();
}


// Displays usage
void display_usage(int argc, char* argv[]) {
    cerr << "Usage: " << argv[0] << " start=<start floor #> floor=<floor #,floor #,...>\n  example: elevator start=12 floor=2,9,1,32" << endl;
    cerr << "Command line: ";
    for (int j = 0; j < argc; ++j) { 
        std::cerr << argv[j] << " "; 
    }
}

// Perform the travel time calculation
//
// NOTE: This is intentionally not reliant on the Job Request.
int calculate_travel_time(int current_floor, const vector<int> &floor_requests){
    int total_time = 0;

    for (auto floor_request : floor_requests) {
        total_time += abs(current_floor - floor_request) * TRAVEL_TIME;
        current_floor = floor_request;
    }

    return total_time;
}


// Main Execution
int main(int argc, char* argv[]) {
   
    // Job being processed
    JobRequest job;

    // Process the command-line arguments to initialize the job request
    if (!process_arguments(argc, argv, job)) { 
        display_usage(argc, argv);
        return 1; 
    }

    // Perform Calculation,  set the travel time and then display the Job Result
    job.total_travel_time = calculate_travel_time(job.start, job.floors);
    job.display();
       
    return 0;
}