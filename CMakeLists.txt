cmake_minimum_required(VERSION 3.10)
project(sensor_fusion)

set(CMAKE_CXX_STANDARD 23)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

# Add your main executable
add_executable(sensor src/sensor.cpp)

# Add test executable
add_executable(sensor_test tests/sensor_tests.cpp)
target_link_libraries(sensor_test GTest::GTest GTest::Main)

# Enable testing
enable_testing()
add_test(NAME sensor_test COMMAND sensor_test)
