#include <iostream>
#include <iomanip> 
#include <tchar.h>
#include "Combi4.h"
#define N (sizeof(AA)/2)
#define M 3
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	char  AA[][2] = { "A", "B", "C", "D" };
	std::cout << "\t\tГенератор размещений\n";
	std::cout << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < N; i++)
		std::cout << AA[i] << ((i < N - 1) ? ", " : " ");
	std::cout << "}\n";
	std::cout << "Генерация размещений  из  " << N << " по " << M;
	combi4::accomodation s(N, M);
	int  n = s.getfirst();
	while (n >= 0) {
		std::cout << std::endl << std::setw(2) << s.na << ": { ";
		for (int i = 0; i < 3; i++)
			std::cout << AA[s.ntx(i)] << ((i < n - 1) ? ", " : " ");
		std::cout << "}";
		n = s.getnext();
	};
	std::cout << std::endl << "\tВсего: " << s.count() << std::endl;
	system("pause");
	return 0;
}
