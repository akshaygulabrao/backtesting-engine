cmake_minimum_required(VERSION 3.10)
project(sensor_fusion)

set(CMAKE_CXX_STANDARD 23)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)


file(GLOB LIB_SOURCES src/*.cpp)
file(GLOB LIB_HEADERS src/*.hpp )
# Add your main executable
add_executable(world ${LIB_SOURCES})

# Add test executable
add_executable(world_test 
    tests/world_tests.cpp
    ${LIB_SOURCES}
)
target_link_libraries(world_test GTest::GTest GTest::Main)

# Enable testing
enable_testing()
add_test(NAME world_test COMMAND world_test)
