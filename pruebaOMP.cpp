// pruebaOMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define N 1000
#define chunk 10;
#define mostrar 10;

void imprimeArreglo(float* d);

int main()
{
	std::cout << "Sumando arreglo en paralelo \n";
	float a[N], b[N], c[N];
	int i;

	for (i = 0; i < N; i++) {
		a[i] = i * 10;
		b[i] = (i + 3) * 3.7;
	}

	int pedazos = chunk;

	#pragma omp parallel for \
	shared (a,b,c, pedazos) private (i) \
	schedule(static, pedazos)

	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];


	std::cout << "imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);
	std::cout << "imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);
	std::cout << "imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);

}

void imprimeArreglo(float* d) {
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
}