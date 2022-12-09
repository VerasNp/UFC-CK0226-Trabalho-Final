cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(../ListaVoos)
include_directories(../ListaPassageiros)
include_directories(../Utils)

add_executable(
        testa_data
        ../Utils/Enums.h
        ../Utils/Headers.h
        Data.h
        Data.c
        TestaData.c
)

add_executable(
        testa_reserva
        ../Utils/Validacoes.h
        ../Utils/Validacoes.c
        ../ListaVoos/Voos.h
        ../ListaVoos/Voos.c
        ../ListaPassageiros/Passageiro.h
        ../ListaPassageiros/Passageiro.c
        Data.h
        Data.c
        Agenda.h
        Agenda.c
        Reserva.h
        Reserva.c
        TestaReserva.c)

add_executable(
        testa_agenda
        ../Utils/Validacoes.h
        ../Utils/Validacoes.c
        ../ListaVoos/Voos.h
        ../ListaVoos/Voos.c
        ../ListaPassageiros/Passageiro.h
        ../ListaPassageiros/Passageiro.c
        Data.h
        Data.c
        Reserva.h
        Reserva.c
        Agenda.h
        Agenda.c
        TestaAgenda.c)
