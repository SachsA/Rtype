cmake_minimum_required(VERSION 3.11)
project(CPP_rtype_2018)

set(CMAKE_BUILD_TYPE Release)

#include_directories(.)

add_library(alienThetaServer SHARED
        ../../AEntity.cpp
        ../../AEntity.hpp

        AlienTheta.cpp
        AlienTheta.hpp
        )

#install(TARGETS ship DESTINATION ../EntitiesLib)