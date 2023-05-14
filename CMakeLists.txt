cmake_minimum_required(VERSION 3.26)
project(CvlJoint)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/bin/qmake6")
set(CMAKE_TOOLCHAIN_FILE "/mnt/Workspace/CLang/CvlJoint/src/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(Qt6 COMPONENTS
        Core
        HttpServer
        REQUIRED)

find_package(tomlplusplus CONFIG REQUIRED)
set(SRC src/main.cpp
        src/server.cpp
        src/server.h
        )
add_executable(CvlJoint ${SRC})

target_link_libraries(CvlJoint PUBLIC
        Qt::Core
        Qt6::HttpServer
        tomlplusplus::tomlplusplus
        )
target_compile_features(CvlJoint PUBLIC cxx_std_17)
target_compile_features(CvlJoint PUBLIC cxx_std_20)