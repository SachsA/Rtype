cmake_minimum_required(VERSION 3.11)
project(CPP_rtype_2018)

set(CMAKE_BUILD_TYPE Release)

#include_directories(.)

add_library(bulletsEnemiesMDClient SHARED
        ../../../AEntity.cpp
        ../../../AEntity.hpp
		../../../../../Errors/Errors.hpp
		../../../../../Errors/Errors.cpp
		../../../ErrorsEntityClient.hpp
		../../../ErrorsEntityClient.cpp

        BulletsEnemiesMD.cpp
        BulletsEnemiesMD.hpp
        )

#install(TARGETS bulletsEnemiesMD DESTINATION ../{folder})
