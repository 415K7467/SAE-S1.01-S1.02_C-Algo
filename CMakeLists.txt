cmake_minimum_required(VERSION 3.20)
project(SAE_S1_01_S1_02_C_Algo C)

set(CMAKE_C_STANDARD 11)

add_executable(SAE_S1_01_S1_02_C_Algo
        main.c  fonctions.h ajouter_modifier_supprimer.c tri_recherche.c other.c test.c)
