#include "../include/ticker.h"

bool Ticker::operator<(const Ticker& other) const {
    if (symbol != other.symbol)
        return symbol < other.symbol;
    return resolution < other.resolution;
}
bool Ticker::operator==(const Ticker& other) const {
    return symbol == other.symbol && resolution == other.resolution;
} // End of Ticker::operator== function
