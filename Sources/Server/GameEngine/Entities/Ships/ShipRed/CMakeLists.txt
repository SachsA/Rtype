cmake_minimum_required(VERSION 3.11)
project(CPP_rtype_2018)

set(CMAKE_BUILD_TYPE Release)

add_library(shipRedServer SHARED
        ../../AEntity.cpp
        ../../AEntity.hpp

        ../Ship.cpp
        ../Ship.hpp

        ShipRed.cpp
        ShipRed.hpp
        )

#install(TARGETS ship DESTINATION ../EntitiesLib)