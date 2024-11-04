#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <string>
#include <chrono>
#include <unordered_set>
#include "ticker.h"
class World {
    std::vector<Ticker> tickers;
    std::vector<int> resolution;
    std::chrono::system_clock::time_point start_time;
    std::chrono::system_clock::time_point end_time;
public:
    // World();
    World(const std::vector<std::string>&, 
          const std::vector<int>&,
          std::chrono::system_clock::time_point,
          std::chrono::system_clock::time_point);
    World(std::vector<std::string>, std::vector<int>);
    void print();
    void run();
private:
    void validate_tickers(const std::vector<std::string>&);
    void validate_resolution(const std::vector<int>& resolution);
};

#endif // WORLD_H