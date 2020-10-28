#pragma once
#include <iostream>
#include <math.h>
class Electre
{
	int kNum, aNum;
	double a0, b0;
	double * w;
	double ** d, **a, **b;


public:

	Electre(int _kNum, int _aNum, double _a0, double _b0)
	{
		a0 = _a0;
		b0 = _b0;
		kNum = _kNum;
		aNum = _aNum;	
		w = new double[_kNum];
		d = new double*[_aNum];
		for (int i = 0; i < _aNum; i++)
			d[i] = new double[_kNum];
		a = new double*[_aNum];
		for (int i = 0; i < _aNum; i++)
			a[i] = new double[_aNum];
		b = new double*[_aNum];
		for (int i = 0; i < _aNum; i++)
			b[i] = new double[_aNum];
	}

	void SetMatrix(double ** _d, double * _w)
	{
		for (int i = 0; i < aNum; i++)
			for (int j = 0; j < kNum; j++)
				d[i][j] = _d[i][j];
		for (int j = 0; j < kNum; j++)
			w[j] = _w[j];
	}

	void CalculateAB()
	{
		int * I = new int[kNum];
		double wSum =0, wIsum=0;		
		for (int i = 0; i < aNum; i++)					
			for (int j = 0; j < aNum; j++)
			{
				b[i][j] = 0;
				for (int k = 0; k < kNum; k++)
				{
					if (d[i][k] > d[j][k])
						I[k] = 1;
					else if (d[i][k] == d[j][k])
						I[k] = 0;
					else
						I[k] = -1;
				}
				for (int k = 0; k < kNum; k++)
				{
					wSum += w[k];
					if (I[k] >= 0)
						wIsum += w[k];
					else
					{						
						auto temp = abs((d[i][k] - d[j][k]) / 8);
						if (temp > b[i][j])
							b[i][j] = temp;
					}
				}
				a[i][j] = wIsum / wSum;
				wSum = 0;
				wIsum = 0;
			}
		std::cout <<"A:"<<std::endl;
		for (int i = 0; i < aNum; i++)
		{
			for (int j = 0; j < aNum; j++)
			{
				std::cout << a[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout <<"B:"<<std::endl;
		for (int i = 0; i < aNum; i++)
		{
			for (int j = 0; j < aNum; j++)
			{
				std::cout << b[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}


	void PrintAnswer()
	{
		int * ans = new int[aNum];
		std::cout << std::endl;
		std::cout << "X  ";
		for (int i = 0; i < aNum; i++)
		{
			std::cout << "A" << i << " ";
		}
		std::cout << std::endl;
		int max = 0;
		for (int i = 0; i < aNum; i++)
		{
			ans[i] = 0;
			std::cout << "A" << i << " ";
			for (int j = 0; j < aNum; j++)
			{
				if(i == j)
					std::cout << "*  ";
				else if (a[i][j] >= a0 && b[i][j] <= b0)
				{
					ans[i] += 1;
					std::cout << ">  ";
				}
				else
					std::cout << "<  ";
			}
			max = max < ans[i] ? ans[i] : max;
			std::cout << std::endl;
		}
		std::cout << "kernel: ";
		for (int i = 0; i < aNum; i++)
			if (ans[i] == max)
				std::cout << "A" << i << " ";

	}
};

