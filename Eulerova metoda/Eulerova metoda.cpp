// Eulerova metoda.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

//napisane vo Visual Studio 2015 - (kompilátor: Visual C++ 14.0)

double funkcia(double x)
{
	return sin(x) / 3.0;
}

int main()
{
	double h = 0.2;
	const int n = 50;
	double riesenia[4][n + 1] = {0};
	int i, j;

	//naplnanie prveho a posledneho riadku matice
	//v prvom su body x=h*i
	//v poslednom su funkcne hodnoty presneho riesenia v bodoch x=h*i
	for (i = 0; i < n + 1; i++)
	{
		riesenia[0][i] = i*h;
		riesenia[3][i] = -exp((1.0 / 3.0) - (cos(i*h) / 3.0));
	}

	//pociatocna podmienka
	riesenia[1][0] = -1;
	
	// euler dopredny
	for (i = 0; i < n; i++)
	{
		riesenia[1][i + 1] = riesenia[1][i] + h*riesenia[1][i]*funkcia(double(riesenia[0][i]));
	}

	//pociatocna podmienka
	riesenia[2][0] = -1;

	//euler spätny
	for (i = 0; i < n; i++)
	{
		riesenia[2][i + 1] = riesenia[2][i] / (1.0 - h*funkcia(double(riesenia[0][i+1])));
	}

	ofstream outfile1; //zápis do suboru csv na odovzdanie ulohy
	outfile1.open("priloha1.csv");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < n+1 ; j++)
		{
			if(j<n) outfile1 << fixed << setprecision(13) << riesenia[i][j] << ",";
			else outfile1 << fixed << setprecision(13) << riesenia[i][j];
		}
		outfile1 << "\n";
	}
	outfile1.close();

	ofstream outfile2; //zápis do suboru txt - prehladny vypis na citanie
	outfile2.open("rozdelenie.txt");
	for (i = 0; i < n + 1; i++)
	{
		for (j = 0; j < 4; j++)
		{
			outfile2 << fixed << setprecision(5) << riesenia[j][i] << "\t";
		}
		outfile2 << endl;
	}
	outfile2.close();

	//system("notepad.exe rozdelenie.dat");

	//system("PAUSE");

    return 0;
}

