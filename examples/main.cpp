#include <iostream>
#include "../include/world.h"
#include <string>

int main(){
    // -1 means tick data
    World world({"AAPL", "GOOG"}, {-1, -1});

    world.print();

    world.run();
    return 0;
}