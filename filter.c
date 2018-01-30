/**
 ----------------------------------
| Program created by Tushar Sharma.|
| CS30200 Homework 1               |
| Email: sharm191@pnw.edu          |
| File Info: filter.c			   |
 ----------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // scanf(), fscanf(), fprintf(), fopen()
#include <stdlib.h> // atoi(), getenv()
int main(int argc, char* argv[])
{
//Open Configuration file with the name 'filter.cfg'
	FILE* myFile = fopen("filter.cfg", "r");
// Default Variables.
	int n = 0;
	int column = 3;
	double scannedNum; //inputted data
	int precision = 13;
//Check if config file exists and change precision to config file value 1.
	if (myFile != NULL) {
		fscanf(myFile, "%d", &precision);
		fscanf(myFile, "%d", &column);
	}
//Variable that determines width.
	int max = precision + 5;
// Environment Variables.
	if (getenv("CS302HW1COLUMNS") != NULL) {
		column = atoi(getenv("CS302HW1COLUMNS"));
	}
	if (getenv("CS302HW1PRECISION") != NULL)
	{
		precision = atoi(getenv("CS302HW1PRECISION"));
	}
// Command Line Arguments
	if (argc > 1)
	{
		precision = atoi(argv[1]);
		if (argv[2] != NULL)
		{
			column = atoi(argv[2]);
		}
	}
//Get the column and print numbers accordingly.
	while (scanf("%lf", &scannedNum) != EOF && scannedNum < 10000)
	{
		if (n < column)
		{
			printf("%*.*f""  ", max, precision, scannedNum);
			n++;
		}
		else
		{
			printf("\n%*.*f""  ", max, precision, scannedNum);
			n = 1;
		}

	}
	return 0;
}