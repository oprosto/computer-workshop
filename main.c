#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>

void WrongPlaces(int _field[10][10], int _shipCordsX[4], int _shipCordsY[4], int _shipLen)
{
	for (int i = 0; i < _shipLen; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			for (int k = -1; k <= 1; k++)
			{
				if (_field[_shipCordsX[i] + j][_shipCordsY[i] + k] != 1)
					_field[_shipCordsX[i] + j][_shipCordsY[i] + k] = 2;
				
			}
		}
	}
}


int ShipGenerator(int _field[10][10], int _x, int _y, int _shipLen)
{	
	int direction; // От 1 по 4
	int shipCordsX[4];
	int shipCordsY[4];
	
	shipCordsX[0] = _x;
	shipCordsY[0] = _y;
	
	direction = RNG(1, 4);
	//printf_s("RNG = %d ", RNG);
	//printf_s("%d", direction);
	switch (direction)
	{
	case 1:	//Up
		for (int i = 1; i < _shipLen; i++)
		{
			if (_field[_x][_y + 1] == 0)
			{
				shipCordsX[i] = _x;
				shipCordsY[i] = _y + 1;
				_y++;
			}
			else
				return 0;
		}
		for (int i = 0; i < _shipLen; i++)
		{
			//printf_s("Ship with len = %d was constructed \n", _shipLen);
			
			_field[shipCordsX[i]][shipCordsY[i]] = 1;
		}
		WrongPlaces(_field, shipCordsX, shipCordsY, _shipLen);
		return -1;
	case 2:	//Down
		for (int i = 1; i < _shipLen; i++)
		{
			if (_field[_x][_y - 1] == 0)
			{
				shipCordsX[i] = _x;
				shipCordsY[i] = _y - 1;
				_y--;
			}
			else
				return 0;
		}
		for (int i = 0; i < _shipLen; i++)
		{
			//printf_s("Ship with len = %d was constructed \n", _shipLen);
			_field[shipCordsX[i]][shipCordsY[i]] = 1;
		}
		WrongPlaces(_field, shipCordsX, shipCordsY, _shipLen);
		return -1;
		
	case 3:	//Right
		for (int i = 1; i < _shipLen; i++)
		{
			if (_field[_x + 1][_y] == 0)
			{
				shipCordsX[i] = _x + 1;
				shipCordsY[i] = _y;
				_x++;
			}
			else
				return 0;
		}
		for (int i = 0; i < _shipLen; i++)
		{
			//printf_s("Ship with len = %d was constructed \n", _shipLen);
			_field[shipCordsX[i]][shipCordsY[i]] = 1;
		}
		WrongPlaces(_field, shipCordsX, shipCordsY, _shipLen);
		return -1;
	case 4:	//Left
		for (int i = 1; i < _shipLen; i++)
		{
			if (_field[_x - 1][_y] == 0)
			{
				shipCordsX[i] = _x - 1;
				shipCordsY[i] = _y;
				_x--;
			}
			else
				return 0;
		}
		for (int i = 0; i < _shipLen; i++)
		{
			//printf_s("Ship with len = %d was constructed \n", _shipLen);
			_field[shipCordsX[i]][shipCordsY[i]] = 1;
		}
		WrongPlaces(_field, shipCordsX, shipCordsY, _shipLen);
		return -1;
	default:
		break;
	}

	
}

int RNG(const int _min, const int _max)
{	
	
	return rand() % (_max - _min + 1) + _min;
}

void MapGenerator(int _field[10][10])
{
	int ships[11] = {4,4,3,3,2,2,2,1,1,1,1}; //Длины кораблей
	srand(time(NULL));	
	int X, Y; // Принимает значения от 1 по 10	
	int freeShip = 10; //Кол-во оставшихся кораблей
	int j = 0;

	while (freeShip > 0)
	{		
		X = RNG(1, 10);
		Y = RNG(1, 10);
		if (_field[X][Y] == 0) //Выбор стартовой точки
		{			
			freeShip += ShipGenerator(_field, X, Y, ships[freeShip]);
		}
		else
			j = 0;
		j++;		
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf_s("%d ", _field[i][j]);			
		}
		printf("\n");
	}



}


void Warships()
{
	int warField[10][10];
	int input;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			warField[i][j] = 0;
			//printf_s("%d ", warField[i][j]);
		}
		//printf("\n");
	}
	
	//scanf_s("%d", Input);
	//if (Input == 0)
	MapGenerator(warField);
	//else
		//SelfConstruction(warField);
}

int Prime(unsigned long long int number)
{
	unsigned long long int Sqrt = ceil(sqrt(number));
	for (unsigned long long int i = 2; i < Sqrt; i++)
	{
		if (number % i == 0)
			return 0;
	}
	return 1;
}

int Homework()
{
	unsigned long long int number = 600851475143;
	unsigned long long int del;
	for (unsigned long long int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{			
			del = number / i;			
			if (Prime(del) == 1)
				return del;
		}
	}

}



void Array2()
{
	int rows, cols;
	int* arrayl;
	printf("Rows pls:");
	scanf_s("%d", &rows);
	printf("columns pls:");
	scanf_s("%d", &cols);
	arrayl = (int*)malloc(rows * cols * sizeof(int));

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("arrayl (%d)(%d) = ", i, j);
			scanf_s("%d", &arrayl[i * cols + j]);
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%5d ", arrayl[i * cols + j]);
		}
		printf("\n");
	}
}
int main()
{
	//printf("res = %d", Ei1());
	//Warships();
	printf_s("res = %I64d", Homework());


}

int Ei1()
{
	int number;
	int res = 0;
	scanf_s("%d", &number);
	for (int i = 2; i < number; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0 && number % j == 0)
				break;
			else
				if (j == i)
					res++;
		}
	}
	return res;
}



