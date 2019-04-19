cmake_minimum_required(VERSION 3.11)
project(CPP_rtype_2018)

set(CMAKE_BUILD_TYPE Release)

#include_directories(.)

add_library(alienRhoClient SHARED
        ../../AEntity.hpp
        ../../AEntity.cpp
		../../../../Errors/Errors.hpp
		../../../../Errors/Errors.cpp
		../../ErrorsEntityClient.hpp
		../../ErrorsEntityClient.cpp

        AlienRho.cpp
        AlienRho.hpp
        )

#install(TARGETS alien DESTINATION ../{folder})
