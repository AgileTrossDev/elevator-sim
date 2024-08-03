

#include "elevator.h"


namespace Elevator {
    using std::vector;
    using std::string_view;


    std::unique_ptr<PeopleMover> build(string_view engine_type) {

        std::unique_ptr<ElevactorEngineStrategy> strategy;

        if (engine_type == "M") {
            strategy = std::make_unique<ModernEngineStrategy>();
        } else if (engine_type == "R") {
            strategy = std::make_unique<ReturnEngineStrategy>();
        } else {
            throw std::invalid_argument("Unknown type");
        }

        return std::make_unique<PeopleMover>(std::move(strategy));
    }


// Perform the travel time calculation
//
// NOTE: This is intentionally not reliant on the Job Request.
int ModernEngineStrategy::operate(int current_floor, const vector<int> &floor_requests) const {
    int total_time = 0;

    for (auto floor_request : floor_requests) {
        total_time += abs(current_floor - floor_request) * TRAVEL_TIME;
        current_floor = floor_request;
    }

    return total_time;
}

// Perform the travel time calculation
//
// NOTE: This is intentionally not reliant on the Job Request.
int ReturnEngineStrategy::operate(int current_floor, const vector<int> &floor_requests) const {
    int total_time = 0;

    for (auto floor_request : floor_requests) {
        total_time += abs(current_floor - floor_request) * TRAVEL_TIME;
        current_floor = floor_request;
    }

    return total_time;
}


int PeopleMover::calculate_travel_time(int current_floor, const std::vector<int> &floor_requests) const {
            return engine->operate(current_floor, floor_requests);
        }

}