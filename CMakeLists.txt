cmake_minimum_required(VERSION 3.26)
project(CvlJoint)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

find_package(oatpp CONFIG REQUIRED)
find_package(tomlplusplus CONFIG REQUIRED)

set(SRC src/app.cpp
        src/component.hpp
        src/dto/any_dto.hpp
        src/controller/hello_controller.hpp
        src/controller/system_info.hpp
        src/dto/server_dto.hpp
        src/service/system_info_service.cpp src/service/system_info_service.hpp)

include_directories(src
        src/dto
        src/controller
        src/service)

add_executable(CvlJoint ${SRC})

target_link_libraries(CvlJoint PRIVATE oatpp::oatpp oatpp::oatpp-test)
target_link_libraries(CvlJoint PRIVATE tomlplusplus::tomlplusplus)

target_compile_features(CvlJoint PUBLIC cxx_std_17)
target_compile_features(CvlJoint PUBLIC cxx_std_20)