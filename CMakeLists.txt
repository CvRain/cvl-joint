cmake_minimum_required(VERSION 3.26)
project(CvlJoint)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

find_package(oatpp CONFIG REQUIRED)

set(SRC src/app.cpp
        src/component.hpp
        src/dto/any_dto.hpp
        src/controller/hello_controller.hpp)

include_directories(src
        src/dto
        src/controller)

add_executable(CvlJoint ${SRC})

target_link_libraries(CvlJoint PRIVATE oatpp::oatpp oatpp::oatpp-test)

target_compile_features(CvlJoint PUBLIC cxx_std_17)
target_compile_features(CvlJoint PUBLIC cxx_std_20)