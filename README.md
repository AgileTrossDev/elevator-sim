# Elevator Simulation
Written in C++.  

### Compile
```g++ --std=c++17 -o elevator main.cpp```

### Usage:
```./elevator start=-42 floor=-99,1,-5,100```

## Problemn Description:

Provide code that simulates an elevator. You are free to use any language. Upload the completed project to GitHub for discussion during interview.  Document all assumptions and any features that weren’t implemented.

The result should be an executable, or script, that can be run with the following inputs and generate the following outputs.
- Inputs: [list of floors to visit] (e.g. elevator start=12 floor=2,9,1,32)
- Outputs: [total travel time, floors visited in order] (e.g. 560 12,2,9,1,32)
- Program Constants: Single floor travel time: 10

## Assumptions

- We can use default values if they are not provided at time of execution.  The job request defaults to starting at the first floor, with no requested floors.
- Assume that basement floors are represented by negative numbers
- CLI arguments can come in any order.
- CLI arguments use a space deliminater to separate the arguments
- Unknown CLI arguments should be treated as an error.
- If you request your current floor, the travel time is 0 and it should be listed in the output as a separate request.  `elevator start=12 floor=12` results in `0 12,12`  

## Future Work
- Use a CLI library or make the CLI adhere to the standardized CLI options
- Consider making the application a service/daemon that can handle multiple TCP/IP socket clients, supporting a custom binary protocol.  Maintaining state between requests/
- Consider streaming the calculated output to a Time Series DB/Grafana or dynamic webpage via Websockets so that the elevator usage can be more accurately tracked.
- Make application config driven, so that travel time, and min/max floors can be defined.   Possibly use JSON/YAML/XML or use 12-Factor Container Environment injection.
- Add Unit Tests and Functional Tests
- Use CMake or at least define a Makefile


