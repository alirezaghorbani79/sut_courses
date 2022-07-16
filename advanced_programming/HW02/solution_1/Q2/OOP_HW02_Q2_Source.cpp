#include <iostream>
#include <exception>

#include "OOP_HW02_Q2_Header.h"

using namespace std;



int main()
{
	int numScore;
	cout << "Please Enter Number of Scors: ";
	try
	{
		cin >> numScore;
		if (numScore <= 0)
			throw invalid_argument("Enter Positive Integer Number!");
		
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
		return 0;
	}
	
	float* scores = new float[numScore];
	for (size_t i = 0; i < numScore; i++)
	{
		cout << "Enter Score " << i+1 << ": ";
		cin >> scores[i];
		if (scores[i] > 20 || scores[i] < 0)
			scores[i] = 0;
	}

	cout << endl;

	CStats<float, int> c1(scores, numScore);
	
	c1.print();
	cout << endl;
	c1.update().print();

	cout << endl;

	CStats<int, long> c2(nullptr, 50);
	c2.randFill(0, 20).update().print();
}