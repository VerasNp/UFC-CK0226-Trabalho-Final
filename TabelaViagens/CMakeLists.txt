cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(../Utils)
include_directories(../ReservaViagem)
include_directories(../ListaVoos)
include_directories(../ListaPassageiros)
include_directories(.)

add_executable(
    testa_tabela_viagens
    ../Utils/Utils.c
    ../Utils/Utils.h
    ../ReservaViagem/Agenda.c
    ../ReservaViagem/Agenda.h
    ../ReservaViagem/Data.c
    ../ReservaViagem/Data.h
    ../ReservaViagem/Reserva.c
    ../ReservaViagem/Reserva.h
    ../ListaPassageiros/Passageiro.c
    ../ListaPassageiros/Passageiro.h
    ../ListaVoos/Voos.c
    ../ListaVoos/Voos.h
    ../Utils/Headers.h
    TabelaViagens.h
    TabelaViagens.c
    TestaTabelaViagens.c
)