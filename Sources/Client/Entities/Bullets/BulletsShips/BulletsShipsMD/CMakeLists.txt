cmake_minimum_required(VERSION 3.11)
project(CPP_rtype_2018)

set(CMAKE_BUILD_TYPE Release)

#include_directories(.)

add_library(bulletsShipsMDClient SHARED
        ../../../AEntity.cpp
        ../../../AEntity.hpp
		../../../../../Errors/Errors.hpp
		../../../../../Errors/Errors.cpp
		../../../ErrorsEntityClient.hpp
		../../../ErrorsEntityClient.cpp

        BulletsShipsMD.cpp
        BulletsShipsMD.hpp
        )

#install(TARGETS bulletsShipsMD DESTINATION ../{folder})
