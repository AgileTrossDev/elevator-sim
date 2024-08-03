#include <vector>




// JobRequest - Maintains the state of the job being executed
//
// ASSUMPTION: Defaults to starting at the first floor, with no requested floors.

struct JobRequest {

    // Attributes
    int start = 1;
    std::vector<int> floors = {};
    int total_travel_time = -1;
    
    // Operations
    void display();      
    bool is_valid();

};