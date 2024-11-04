cmake_minimum_required(VERSION 3.10)
project(sensor_fusion)

set(CMAKE_CXX_STANDARD 23)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)
find_package(cppzmq REQUIRED)
find_package(Boost CONFIG REQUIRED COMPONENTS system filesystem)
find_package(Eigen3 REQUIRED)

set(CMAKE_DISABLE_FIND_PACKAGE_WrapVulkanHeaders TRUE)

if(TARGET Boost::system AND TARGET Boost::filesystem)
    message(STATUS "Boost found: ${Boost_VERSION}")
else()
    message(FATAL_ERROR "Required Boost components not found!")
endif()

# Specify Qt components needed
find_package(Qt6 REQUIRED COMPONENTS 
    Core
    Gui
    Widgets
    # Add other components as needed:
    # Network
    # Sql
    # Quick
)

# Tell CMake to handle Qt's MOC, UIC, and RCC automatically
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Add Doxygen
find_package(Doxygen REQUIRED)

# Configure Doxygen
set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/build/docs)

# Add a custom target for Doxygen
add_custom_target(doc
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
)

# Optionally, you can add a dependency to build documentation after the main target


file(GLOB LIB_SOURCES src/*.cpp)
file(GLOB LIB_HEADERS src/*.hpp )
# Add your main executable
add_library(world ${LIB_SOURCES})

# Add test executable
add_executable(world_test
    tests/world_tests.cpp
    ${LIB_SOURCES}
)
target_link_libraries(world_test GTest::GTest GTest::Main)

add_executable(example examples/main.cpp ${LIB_SOURCES})
target_link_libraries(example world)

# Enable testing
enable_testing()
add_test(NAME world_test COMMAND world_test)
