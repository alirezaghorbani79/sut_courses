#include <iostream>
#include <exception>
#include <algorithm>

#include "OOP_HW03_Q1_Header.h"

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
		cout << "Enter Score " << i + 1 << ": ";
		cin >> scores[i];
		if (scores[i] > 20 || scores[i] < 0)
			scores[i] = 0;
	}
	cout << endl;

	CStatsEx<float, int>* c1 = new CStatsEx<float, int>(scores, numScore, "Student Scores");
	c1->print();
	c1->update().Sort().print();

	delete[] scores;

}