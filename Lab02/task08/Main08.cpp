#include "stdafx.h"
#include <iostream>
#include "Combi.h"
#include "Knapsack.h"
#include "Auxil.h"
#include <time.h>
#include <iomanip> 
#define NN 20
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    int V = 300,                // вместимость рюкзака              
        v[NN],     // размер предмета каждого типа  
        c[NN];     // стоимость предмета каждого типа 
    short m[NN];                // количество предметов каждого типа  {0,1}   

    auxil::start();

    for (int i = 0; i < NN; i++)
    {
        v[i] = auxil::iget(10, 300);
        c[i] = auxil::iget(5, 55);
    }
    int maxcc = 0;
    clock_t t1, t2;
    std::cout << std::endl << "-------- Задача о рюкзаке --------- ";
    std::cout << std::endl << "- вместимость рюкзака  : " << V;
    std::cout << std::endl << "-- количество ------ продолжительность -- ";
    std::cout << std::endl << "    предметов          вычисления  ";
    for (int i = 12; i <= NN; i++)
    {
        t1 = clock();
        maxcc = knapsack_s(V, i, v, c, m);
        t2 = clock();
        std::cout << std::endl << "       " << std::setw(2) << i
            << "               " << std::setw(5) << (t2 - t1);
    }
    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}
