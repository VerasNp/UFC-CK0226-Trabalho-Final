cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(../Utils)
include_directories(../ReservaViagem)
include_directories(../ListaVoos)
include_directories(../ListaPassageiros)
include_directories(../TabelaPassageiros)
include_directories(.)

add_executable(
        testa_tabela_viagens
        ../Utils/Utils.h
        ../Utils/Utils.c
        ../ReservaViagem/Agenda.h
        ../ReservaViagem/Agenda.c
        ../ReservaViagem/Data.h
        ../ReservaViagem/Data.c
        ../ReservaViagem/Reserva.h
        ../ReservaViagem/Reserva.c
        ../ListaPassageiros/Passageiro.h
        ../ListaPassageiros/Passageiro.c
        ../ListaVoos/Voos.h
        ../ListaVoos/Voos.c
        ../Utils/Headers.h
        ../Utils/Enums.h
        ../Utils/Enums.c
        ../TabelaPassageiros/TabelaPassageiros.c
        ../TabelaPassageiros/TabelaPassageiros.h
        TabelaViagens.h
        TabelaViagens.c
        TestaTabelaViagens.c)