cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(ListaPassageiros)
include_directories(ListaVoos)
include_directories(ReservaViagem)
include_directories(TabelaViagens)
include_directories(Utils)
include_directories(Menus)

add_executable(
        testa_integracao
        Utils/Utils.c
        Utils/Enums.h
        Utils/Enums.c
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
        TabelaPassageiros/TabelaPassageiros.h
        TabelaPassageiros/TabelaPassageiros.c
        TestaTravelBooking.c
)

add_executable(
        testa_travel_boobking
        Utils/Utils.h
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
        Utils/Validacoes.h
        Utils/Validacoes.c
        Menus/PassageirosMenu.h
        Menus/PassageirosMenu.c
        Menus/VoosMenu.h
        Menus/VoosMenu.c
        Menus/ReservasMenu.h
        Menus/ReservasMenu.c
        TravelBooking.h
        TravelBooking.c
)