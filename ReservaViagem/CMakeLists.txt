cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        testa_data
        Data.h
        Data.c
        TestaData.c
)

add_executable(
        testa_reserva
        Data.h
        Data.c
        Agenda.h
        Agenda.c
        Reserva.h
        Reserva.c
        ../ListaPassageiros/Passageiro.h
        ../ListaPassageiros/Passageiro.c
        ../ListaVoos/Voos.c
        ../ListaVoos/Voos.h
        TestaReserva.c)

add_executable(
        testa_agenda
        Data.h
        Data.c
        Reserva.h
        Reserva.c
        Agenda.h
        Agenda.c
        TestaAgenda.c)
