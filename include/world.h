#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <string>
#include <chrono>
#include <unordered_set>
#include "ticker.h"
/**
 * @class World
 * @brief A class to represent the world of tickers and their resolutions.
 *
 * The World class is responsible for managing a collection of tickers and their resolutions,
 * validating them, and providing functionalities to print, prepare, and run the world.
 */
class World {
    std::vector<Ticker> tickers; ///< A vector of Ticker objects.
    std::vector<int> resolution; ///< A vector of resolutions corresponding to the tickers.
    std::chrono::system_clock::time_point start_time; ///< The start time of the world.
    std::chrono::system_clock::time_point end_time; ///< The end time of the world.

public:
    /**
     * @brief Constructs a World object with the given tickers, resolutions, start time, and end time.
     * @param tickers A vector of ticker symbols.
     * @param resolutions A vector of resolutions corresponding to the tickers.
     * @param start The start time of the world.
     * @param end The end time of the world.
     * @throws std::invalid_argument if the tickers vector is empty, the sizes of tickers and resolutions do not match, or end time is before start time.
     */
    World(const std::vector<std::string>& tickers, 
          const std::vector<int>& resolutions,
          std::chrono::system_clock::time_point start,
          std::chrono::system_clock::time_point end);

    /**
     * @brief Constructs a World object with the given tickers and resolutions.
     * @param tickers A vector of ticker symbols.
     * @param resolutions A vector of resolutions corresponding to the tickers.
     * @throws std::invalid_argument if the sizes of tickers and resolutions do not match.
     */
    World(std::vector<std::string> tickers, std::vector<int> resolutions);

    /**
     * @brief Prints the tickers and their resolutions.
     */
    void print();

    /**
     * @brief Prepares the world for running.
     */
    void prepare();

    /**
     * @brief Runs the world, simulating ticks.
     */
    void run();

private:
    /**
     * @brief Validates the given tickers.
     * @param tickers A vector of ticker symbols to validate.
     * @throws std::invalid_argument if there are duplicate tickers.
     */
    void validate_tickers(const std::vector<std::string>& tickers);

    /**
     * @brief Validates the given resolutions.
     * @param resolutions A vector of resolutions to validate.
     * @throws std::invalid_argument if any resolution is less than -1.
     */
    void validate_resolution(const std::vector<int>& resolutions);
};

#endif // WORLD_H