cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(travel_reservation_test TravelReservation.c TravelReservationTest.c)