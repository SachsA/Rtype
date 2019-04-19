cmake_minimum_required(VERSION 3.11)
project(CPP_rtype_2018)

set(CMAKE_BUILD_TYPE Release)

#include_directories(.)

add_library(alienEtaClient SHARED
        ../../AEntity.cpp
        ../../AEntity.hpp
		../../../../Errors/Errors.hpp
		../../../../Errors/Errors.cpp
		../../ErrorsEntityClient.hpp
		../../ErrorsEntityClient.cpp

        AlienEta.cpp
        AlienEta.hpp
        )

#install(TARGETS alienEta DESTINATION ../{folder})
