// TPR3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Electre.h"
using namespace std;
struct TaskIn 
{
private:
	void getNums()
	{
		cout << "Кiлькiсть альтернатив: ";
		cin >> aNum;
		cout << "Кiлькiсть критерiїв: ";
		cin >> kNum;
		cout << "Порогове значення iндексу згоди: ";
		cin >> a0;
		cout << "Порогове значення iндексу незгоди: ";
		cin >> b0;
	}

	void getW()
	{
		w = new double[kNum];
		cout << "Введiть ваги критерiїв w" << endl;
		for (int i = 0; i < kNum; i++)
			cin >> w[i];
	}
	void getD()
	{
		d = new double*[aNum];
		for (int i = 0; i < aNum; i++)
			d[i] = new double[kNum];
		for (int i = 0; i < aNum; i++)
		{
			cout << endl;
			cout << "A" << i << " ";
			for (int j = 0; j < kNum; j++)
				cin >> d[i][j];
		}
	
	
	}
public:
	double ** d;
	double *w;
	int kNum, aNum;
	double a0, b0;




	void GetValue()
	{
		getNums();
		getW();
		getD();
	}
};




int main()
{
	system("chcp 1251");
	
	TaskIn t;
	t.GetValue();
	Electre e(t.kNum, t.aNum, t.a0, t.b0);
	e.SetMatrix(t.d, t.w);
	e.CalculateAB();
	e.PrintAnswer();

}

