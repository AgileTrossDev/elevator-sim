# Elevator Simulation
Written in C++.  

### Compile
```g++ --std=c++17 -o elevator main.cpp job.cpp elevator.cpp```

### Usage:
```./elevator start=-42 floor=-99,1,-5,100```

## Problemn Description:

Provide code that simulates an elevator. You are free to use any language. Upload the completed project to GitHub for discussion during interview.  Document all assumptions and any features that weren’t implemented.

The result should be an executable, or script, that can be run with the following inputs and generate the following outputs.
- Inputs: [list of floors to visit] (e.g. elevator start=12 floor=2,9,1,32)
- Outputs: [total travel time, floors visited in order] (e.g. 560 12,2,9,1,32)
- Program Constants: Single floor travel time: 10


## Work In Progress Update 1
This program started out as a simple demo for a discussion which touched on inheritance.   This kind of discussion commonly leads to what if there are different types of Elevators that have different operating times between floors.  The classical answer to this is to use inheritance and override the business logic function in a sub-class.  In this case, that is the caculate travel time function.  However, this is hardly the only way to solve this problem.  I suggested that the Elevator class could also be composed during run-time using a Strategy Design Pattern with the necessary business logic, eliminating the need of inheritance for sub-classed Elevators.   This update refactors the original implementation to use a Factory to construct an Elevator with a specific Engine type. Under the hood, the Engine type is implemented as a Strategy pattern.  Inheritance is still used for the basic Strategy.  If I really wanted to, that could be eliminated, however I'm fine with the inheritance isolated to just the Strategy.  

So why would do this?   It could be argued that the sub-class of an elevator is good enough in this situation to adhere to the SOLID Open/Close principle.  However, I personally have my mind on how do we test this logic.  The long game is avoding a trap in the future.  Isolating the business logic into a Strategy allows for easier testing, forming simple inputs and outputs.  Down the road I don't have to worry about creating a complex Elevator Object that may introduce dependancies just to test a new elevator engine.  Also, re-using the business logic now becomes an option for other types. Granted this example is overly simplified, but it is possible to use the Elevator Engine Strategy in a different object other than an Elevator.  Again, this is all about the long game.  Object Oriented Programming and Design Patterns are about building for a better future.  So yes, at the start of a conversation like this, or at a start of Design, In-heritance might be your first Refactor, however if you played the game long enough, you might just want to jump right to using Strategies instead because building that up Framework promotes flexibility, resusability, easy code maintance(test), and avoid code duplication in the future.

NOTE: The CLI was not updated to support this feature yet.  Maybe down the road, but this is just a academic experiment at this point.  Not trying to solve al the world's problems.


## Assumptions

- We can use default values if they are not provided at time of execution.  The job request defaults to starting at the first floor, with no requested floors.
- Assume that basement floors are represented by negative numbers
- CLI arguments can come in any order.touch ~/.ssh/config
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


