cmake_minimum_required(VERSION 3.26)
project(CvlJoint)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/bin/qmake6")

find_package(Qt6 COMPONENTS
        Core
        HttpServer
        REQUIRED)

set(SRC src/main.cpp src/server.cpp src/server.h)
add_executable(CvlJoint ${SRC})
include_directories(./src/tomlplusplus/include)


target_link_libraries(CvlJoint
        Qt::Core
        Qt6::HttpServer
        )

target_compile_features(CvlJoint PRIVATE cxx_std_20)