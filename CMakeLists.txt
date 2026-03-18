cmake_minimum_required(VERSION 3.16)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

project(ObjectTracker)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")

add_executable(object_tracker src/main.cpp)
target_link_libraries(object_tracker PRIVATE ${OpenCV_LIBS})
target_include_directories(object_tracker PRIVATE ${OpenCV_INCLUDE_DIRS})