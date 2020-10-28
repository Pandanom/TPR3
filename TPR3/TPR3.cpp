// TPR3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Electre.h"

int main()
{
	double ** d;
	d = new double*[4];
	d[0] = new double[5]{ 9,8,1,3,7 };
	d[1] = new double[5] {3,7,3,6,5,};
	d[2] = new double[5] {1,2,5,1,3};
	d[3] = new double[5] {2,5,1,7,5};
	auto w = new double[5]{ 9,5,3,1,5 };
	Electre e(5, 4, 0.8, 0.5);
	e.SetMatrix(d, w);
	e.CalculateAB();
	e.PrintAnswer();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
