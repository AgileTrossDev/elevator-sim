
#include <iostream>
#include <string>

#include "job.h"

// Using
using std::cout;
using std::endl;
using std::string;
using std::vector;



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