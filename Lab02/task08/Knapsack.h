// Knapsack.h      
#pragma once 
#include "Combi.h"

int knapsack_s(
    int V,         // [in]  вместимость рюкзака 
    short n,       // [in]  количество типов предметов 
    const int v[], // [in]  размер предмета каждого типа  
    const int c[], // [in]  стоимость предмета каждого типа     
    short m[]      // [out] количество предметов 
);