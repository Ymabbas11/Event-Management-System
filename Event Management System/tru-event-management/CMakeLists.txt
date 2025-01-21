cmake_minimum_required(VERSION 3.10)
project(TRUEventManagement)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/src/core
    ${PROJECT_SOURCE_DIR}/src/managers
    ${PROJECT_SOURCE_DIR}/src/rooms
    ${PROJECT_SOURCE_DIR}/src/users
    ${PROJECT_SOURCE_DIR}/src/utils
)

# Add all source files
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})
