cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(../Utils)
include_directories(.)

add_executable(
    testa_passageiro 
    Passageiro.h
    Passageiro.c
    ../Utils/Utils.h
    ../Utils/Utils.c
    TestaPassageiro.c
)

add_executable(
    testa_lista_passageiros
    Passageiro.h
    Passageiro.c 
    ListaPassageiros.h 
    ListaPassageiros.c 
    ../Utils/Utils.h
    ../Utils/Utils.c 
    TestaListaPassageiros.c
)