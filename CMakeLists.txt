cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Utils)
include_directories(ListaPassageiros)
include_directories(ListaVoos) 
include_directories(ReservaViagem)
include_directories(TabelaViagem)

add_executable(
testa_integracao 
Utils/Enums.h
Utils/Headers.h
Utils/Utils.h
ListaPassageiros/ListaPassageiros.h
ListaVoos/ListaVoos.h
ReservaViagem/Data.h 
ReservaViagem/Reserva.h 
ReservaViagem/Agenda.h 
TabelaViagens/TabelaViagens.h 
TestaTravelBooking.c
)