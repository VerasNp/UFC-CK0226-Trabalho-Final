cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(../ListaPassageiros)
include_directories(../Utils)


add_executable(
        testa_tabela_passageiros
        ../ListaPassageiros/Passageiro.c
        ../ListaPassageiros/Passageiro.h
        ../Utils/Utils.h
        ../Utils/Utils.c
        TabelaPassageiros.h
        TabelaPassageiros.c
        TestaTabelaPassageiros.c
)