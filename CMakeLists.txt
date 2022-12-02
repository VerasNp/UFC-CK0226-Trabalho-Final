cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(ListaPassageiros)
include_directories(ListaVoos)
include_directories(ReservaViagem)
include_directories(TabelaViagens)
include_directories(Utils)

add_executable(
        testa_integracao
        Utils/Utils.c
        ListaPassageiros/Passageiro.h
        ListaPassageiros/Passageiro.c
        ListaPassageiros/ListaPassageiros.h
        ListaPassageiros/ListaPassageiros.c
        ListaVoos/Voos.h
        ListaVoos/Voos.c
        ListaVoos/ListaVoos.h
        ListaVoos/ListaVoos.c
        ReservaViagem/Data.h
        ReservaViagem/Data.c
        ReservaViagem/Reserva.h
        ReservaViagem/Reserva.c
        ReservaViagem/Agenda.h
        ReservaViagem/Agenda.c
        TabelaViagens/TabelaViagens.h
        TabelaViagens/TabelaViagens.c
        TestaTravelBooking.c
)