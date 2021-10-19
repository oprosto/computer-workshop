#include <stdio.h>
#include <math.h> // Стандартная математическая библиотека
#include <stdlib.h>
#include <time.h>
#include "functions.h"



/* ДЗ на 1-й модуль */

int RNG(const int _min, const int _max)
{
	return rand() % (_max - _min + 1) + _min;
}

void First(double x, double c, double a)
{
	double L;
	L = (sqrt(exp(x) - pow(cos(x*x*pow(a, 5)),4))+pow(atan(a-pow(x,5)),4))/(exp(1)*sqrt(abs(a+x*pow(c,4))));
	printf_s("%f", L);
}
void Second(double t)
{
	double S;
	S = 3 * t * t - 6 * t + 2;
	printf_s("%f", S);
}
void Third(double a, double b, double c)
{
	double x1, x2;
	double D;
	D = b * b - 4 * a * c;
	if (D > 0)
	{
		x1 = (-b - sqrt(D)) / (2 * a);
		x2 = (-b + sqrt(D)) / (2 * a);
		printf_s("x1 = %f, x2 = %f", x1, x2);
	}
	if (D == 0)
	{	
		x1 = -b / (2 * a);
		printf_s("x = %f", x1);
	}
	else
		printf_s("No results");

}
double Fourth(int code, double time)
{
	switch (code)
	{
	case 48:
		return 15 * time;
	case 44:
		return 18 * time;
	case 46:
		return 13 * time;
	case 45:
		return 11 * time;
	default:
		break;
	}

}
void Fifth() 
{
	int temp;
	int copy;
	for (int i = 1000; i < 10000; i++)
	{
		copy = i;
		temp = 0;
		for (int j = 0; j < 4; j++)
		{			
			temp += pow(copy % 10, 4);
			//printf_s("%d ", temp);
			copy /= 10;
		}
		//printf_s("i = %d, temp = %d ", i, temp);
		if (temp == i)
			printf_s("%d ", i);
		
	}
}
void Sixth(int* t, int N) 
{
	int i = N - 1;
	int c = pow(10, i);
	int res = 0;
	while (i >= 0)
	{	
		int c = pow(2, i);
		res += t[i] * c;
		i--;
	}
	printf_s("%d", res);

}
void Seventh(int I, int J)
{
	srand(time(NULL));
	int* a;
	a = malloc(I * J * sizeof(int));
	for (int i = 0; i < I*J; i++)
	{
		a[i] = -RNG(-10, 10) * 3;
		
	}
	for (int i = 0; i < I; i++)
	{
		
		for (int j = 0; j < J; j++)
		{
			printf_s("%d ", a[i * J + j]);
		}
		printf_s("\n");
	}
}


//////////////////////