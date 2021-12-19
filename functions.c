#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include "functions.h"



int MatrixDeterminant(int* matrix, int size)
{	
	if (size == 2)
	{
		return matrix[0] * matrix[3] - matrix[1] * matrix[2];
	}
	else
	{
		int res = 0;
		for (int i = 0; i < size; i++)
		{
			if (i % 2 == 0)
			res += matrix[i] * MatrixDeterminant(MatrixMaker(matrix, i, size - 1), size - 1);
			else 
			res -= matrix[i] * MatrixDeterminant(MatrixMaker(matrix, i, size - 1), size - 1);
		}
		return res;
	}
	
}


int* MatrixMaker(int* matrix, int col, int size)
{
	int* newMatrix = malloc(size * size * sizeof(int));
	for (int i = 1; i < size + 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < size + 1; j++)
		{
			if (j != col)
			{
				newMatrix[(i - 1) * size + j - flag] = matrix[i * (size + 1) + j];
			}
			else 
			{
				flag = 1;
			}
			//matrix++;
		}
	}
	return newMatrix;
}

int* MatrixMakerV2(int* matrix,int row, int col, int size)
{
	int* newMatrix = malloc(size * size * sizeof(int));
	int flagR = 0;
	for (int i = 0; i < size + 1; i++)
	{
		int flagC = 0;
		for (int j = 0; j < size + 1; j++)
		{
			if (i != row) {
				if (j != col) {
					newMatrix[(i - flagR) * size + j - flagC] = matrix[i * (size + 1) + j];
				}
				else
					flagC = 1;
			}
			else
			{
				flagR = 1;
				break;
			}
			
			//matrix++;
		}
	}
	return newMatrix;
}



void var_16(char* name) 
{
	FILE* f = NULL;

	fopen_s(&f, name, "r");
	if (!f) 
	{
		printf("File not opened\n");
		return 0;
	}
	int sum = 0;
	char* t = f;
	int start = 0;
	int end = 0;
	for (char tmp; fscanf_s(f, "%c", &tmp) != EOF; end++)
		if (tmp == '?')
		{
			
			for (int i = start; i < end; i++) 
			{
				fprintf(f, "%c", t[i]);
			}
				
			start = end + 2;
		}
		else
			if(tmp == '!')
				start = end + 2;

		
	
	fclose(f);

	



}


/*                   ДЗ на 2-й модуль                             */
//1 Zadanie
int global;
char* wordChanger(char* str) 
{
	int len = strlen(str);

	char* res = malloc((len+1) * sizeof(char));
	
	int first;
	int last;
	int flag = 0;
	for (int i = 0; i < len; i++)	
	{
		if (flag == 0 && str[i] == ' ') 
		{
			first = i;
			flag = 1;
		}			
		if (str[i] == ' ')
			last = i;
	}
	global = 0;
	for (int i = last + 1; i < len; i++) {
		res[global] = str[i];
		global++;
	}
	res[global] = ' ';
	global++;
	for (int i = first + 1; i < last; i++) 
	{
		res[global] = str[i];
		global++;
	}
	res[global] = ' ';
	global++;
	for (int i = 0; i < first; i++)
	{
		res[global] = str[i];
		global++;
	}
	res[global] = '\0';
	str = res;
	
	return str;
	
	

	
	
	
	
}
//2 Zadanie
struct Humans
{
	char Surname[64];
	char Name[64];
	char Patronymic[64];
	char Gender[16];
	char Post[64];
	char HappyBirthday[12];
};

void Zad_2() 
{
	int N = 0;
	printf("Enter number of humans");
	scanf_s("%d", &N);

	struct Humans* arr = (struct Humans*)malloc(N * sizeof(struct Humans));

	for (int i = 0; i < N; i++)
	{
		printf("enter all info (Surname, Name, Patronymic, Gender, Post, Birthday)");
		scanf_s("%s", &arr[i].Surname);
		scanf_s("%s", &arr[i].Name);
		scanf_s("%s", &arr[i].Patronymic);
		scanf_s("%s", &arr[i].Gender);
		scanf_s("%s", &arr[i].Post);
		scanf_s("%s", &arr[i].HappyBirthday);
	}
	Engineers(N, arr);

}
void Engineers(int Number, struct Humans* hum) 
{
	for (int i = 0; i < Number; i++)
	{
		if (hum[i].Post == "Engineer") {
			int age = 0;
			for (int j = 0; j < 4; j++)
			{
				age = (age * 10) + (int)hum[i].HappyBirthday[6 + j];
			}
			if (hum[i].Gender == "Man" && (2021 - age) >= 65) {
				printf("%s %s %s is %s %s, born %s", hum[i].Surname, hum[i].Name, hum[i].Patronymic, hum[i].Gender, hum[i].Post, hum[i].HappyBirthday);
			}
			if (hum[i].Gender == "Woman" && (2021 - age) >= 60) {
				printf("%s %s %s is %s %s, born %s", hum[i].Surname, hum[i].Name, hum[i].Patronymic, hum[i].Gender, hum[i].Post, hum[i].HappyBirthday);
			}
		}
			
	}
}

void Zad_3(char* name)
{
	FILE* f = NULL;
	FILE* g = NULL;

	fopen_s(&f, name, "r");
	if (!f)
	{
		printf("File not opened\n");
		return 0;
	}
	fopen_s(&g, "g.txt", "a");
	if (!g)
	{
		printf("File not opened\n");
		return 0;
	}
	int counter = 1;
	for (char tmp; fscanf_s(f, "%c", &tmp) != EOF;)
	{
		if (tmp == 'П' || tmp == 'п' || counter % 4 == 0) 
		{
			counter++;
			while (tmp != ' ')
				fscanf_s(f, "%c", &tmp);
		}
		else
		{
			fprintf_s(g, "%c", tmp);
		}


	}
	fclose(f);
	fclose(g);
}

//////////////////////////////////////////////////////////////////////