cmake_minimum_required(VERSION 3.13)
project(UFC-CK0226-Trabalho-Final C)

set(CMAKE_CXX_STANDARD 14)

include_directories(../Utils)
include_directories(.)

add_executable(
    testa_tabela_viagens
    TabelaViagens.h
    TabelaViagens.c
    ../Utils/Utils.c
    ../Utils/Utils.h
    TestaTabelaViagens.c
)