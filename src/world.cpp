#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <string>
#include <thread>
#include <stdexcept>
#include <unordered_set>
#include "../include/world.h"

void World::validate_tickers(const std::vector<std::string>& tickers) {
    std::unordered_set<std::string> unique_symbols;
    for (size_t i = 0; i < tickers.size(); i++) {
        if (!unique_symbols.insert(tickers[i]).second) {
            throw std::invalid_argument("Duplicate ticker");
        }
    }
}

void World::validate_resolution(const std::vector<int>& resolutions) {
    for (size_t i = 0; i < resolutions.size(); i++) {
        if (resolutions[i] < -1) {
            throw std::invalid_argument("Resolution must be greater or equal to -1");
        }
    }
}

void World::print() {
    std::cout << "Tickers and Resolutions:\n";
    for (const auto& ticker : tickers) {
        std::cout << ticker.symbol << ": " << ticker.resolution << "\n";
    }
}

World::World(const std::vector<std::string>& tickers, 
        const std::vector<int>& resolutions,
        std::chrono::system_clock::time_point start,
        std::chrono::system_clock::time_point end) 
{
    if (tickers.empty()) {
        throw std::invalid_argument("No tickers provided");
    }
    if (tickers.size() != resolutions.size()) {
        throw std::invalid_argument("Resolution vector must match ticker vector size");
    }
    if(end < start) {
        throw std::invalid_argument("End time must be greater than start time");
    }
    validate_tickers(tickers);
    validate_resolution(resolutions);
    for (size_t i = 0; i < tickers.size(); i++) {
        this->tickers.push_back(Ticker(tickers[i], resolutions[i]));
    }
    start_time = start;
    end_time = end;
}
World::World(std::vector<std::string> tickers, std::vector<int> resolutions) {
    validate_tickers(tickers);
    validate_resolution(resolutions);
    if (tickers.size() != resolutions.size()) {
        throw std::invalid_argument("Resolution vector must match ticker vector size");
    }
    for (size_t i = 0; i < tickers.size(); i++) {
        this->tickers.push_back(Ticker(tickers[i], resolutions[i]));
    }
}

void World::prepare() {
    std::cout << "Preparing" << std::endl;

}

void World::run() {
    std::cout << "Running" << std::endl;
    for(int i = 0; i < 10; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Tick" << std::endl;
    }
}