#include "stdafx.h"
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenstein.h"
#include "MultyMatrix.h"
using namespace std;

#define N 6
#define L1 13
#define L2 15

char* Task1(int size)
{
	char* str = new char[size];

	for (int i = 0; i < size; i++) str[i] = rand() % 26 + 'a';
	return str;
}

void Task5() 
{
	srand(time(NULL));
	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	int Mc[N + 1] = { 8, 11, 19, 22, 29, 39, 50 }, Ms[N][N], r = 0, rd = 0;
	memset(Ms, 0, sizeof(int) * N * N);
	t1 = clock();
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	t2 = clock();

	std::cout << std::endl << "-- расстановка скобок (рекурсивное решение) " << std::endl;
	std::cout << std::endl << "затраченное время(сек):  " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl << "размерности матриц: ";
	for (int i = 1; i <= N; i++)
		std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "минимальное количество операций умножения: " << r;
	std::cout << std::endl << "\nматрица S";
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl;

	memset(Ms, 0, sizeof(int) * N * N);
	t3 = clock();
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	t4 = clock();
	std::cout << std::endl
		<< "-- расстановка скобок (динамическое программирование) " << std::endl;
	std::cout << std::endl << "затраченное время(сек):  " << ((double)(t4 - t3)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl << "размерности матриц: ";
	for (int i = 1; i <= N; i++)
		std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "минимальное количество операций умножения: " << rd;
	std::cout << std::endl << "\nматрица S";
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	char* x = Task1(L1);
	cout << "String s1: " << endl;
	for (int i = 0; i < 13; i++) cout << x[i];
	cout << endl << endl;

	char* y = Task1(L2);
	cout << "String s2: " << endl;
	for (int i = 0; i < 15; i++) cout << y[i];
	cout << endl << endl;

	clock_t t1 = 0, t2 = 0, t3, t4;
	int  lx = L1, ly = L2;
	std::cout << std::endl;
	std::cout << std::endl << "-- расстояние Левенштейна -----" << std::endl;
	std::cout << std::endl << "--длина --- рекурсия -- дин.програм. ---"
		<< std::endl;
	for (int i = 6; i < std::min(lx, ly); i++)
	{
		t1 = clock(); levenshtein_r(i, x, i - 2, y); t2 = clock();
		t3 = clock(); levenshtein(i, x, i - 2, y); t4 = clock();
		std::cout << std::right << std::setw(2) << i - 2 << "/" << std::setw(2) << i
			<< "        " << std::left << std::setw(10) << (t2 - t1)
			<< "   " << std::setw(10) << (t4 - t3) << std::endl;
	}

	Task5();
	system("pause");
	return 0;
}