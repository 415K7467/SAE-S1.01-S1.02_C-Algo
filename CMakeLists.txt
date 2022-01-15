cmake_minimum_required(VERSION 3.20)
project(SAE_S1_01_S1_02_C_Algo C)

set(CMAKE_C_STANDARD 11)

add_executable(SAE_S1_01_S1_02_C_Algo
        fonctions.h main.c tri.c ajouter_modifier_supprimer.c recherche.c other.c)
