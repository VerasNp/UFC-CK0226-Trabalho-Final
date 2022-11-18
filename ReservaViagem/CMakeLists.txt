cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        testa_reserva
        Reserva.c
        TestaReserva.c)

add_executable(
        testa_agenda
        Agenda.c
        TestaAgenda.c)
