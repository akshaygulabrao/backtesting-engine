#include <iostream>
#include "../include/world.h"
#include <string>

int main(){
    World world({"AAPL", "GOOG"}, {1, 5});

    world.print();

    world.run();
    return 0;
}