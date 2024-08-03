#include <vector>
#include <string>



namespace Elevator {
    // Constants
    const int TRAVEL_TIME = 10;
    
    class ElevactorEngineStrategy {
        public:
            virtual int operate(int current_floor, const std::vector<int> &floor_requests) const = 0;
            virtual ~ElevactorEngineStrategy() = default;
    };

    class ModernEngineStrategy : public ElevactorEngineStrategy {
        public:
            int operate(int current_floor, const std::vector<int> &floor_requests)  const override;
    };


    class ReturnEngineStrategy : public ElevactorEngineStrategy {
        public:
            int operate(int current_floor, const std::vector<int> &floor_requests)  const override;
    };

     class PeopleMover {
        private:
            std::unique_ptr<ElevactorEngineStrategy> engine;

        public:
            PeopleMover(std::unique_ptr<ElevactorEngineStrategy> strategy) : engine(std::move(strategy)) {}
            int calculate_travel_time(int current_floor, const std::vector<int> &floor_requests) const;
    };
    
    std::unique_ptr<PeopleMover> build(std::string_view type);    

}