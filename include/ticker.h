#ifndef TICKER_H
#define TICKER_H

#include <string>

struct Ticker {
    std::string symbol;
    int resolution;
    // Add any other ticker-specific properties here
    
    Ticker(std::string sym, int res) : symbol(sym), resolution(res) {}
    Ticker(std::string sym) : symbol(sym) {}
    bool operator<(const Ticker& other) const;
    bool operator==(const Ticker& other) const;
    friend struct std::hash<Ticker>;
};

namespace std {
    template<>
    struct hash<Ticker> {
        size_t operator()(const Ticker& t) const {
            size_t h1 = std::hash<std::string>{}(t.symbol);
            size_t h2 = std::hash<int>{}(t.resolution);
            return h1 ^ (h2 << 1);
        }
    };
}
#endif // TICKER_H