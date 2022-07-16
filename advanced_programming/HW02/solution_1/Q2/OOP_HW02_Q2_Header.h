#pragma once
#include <iostream>
#include <math.h>


using namespace std;

template <typename _T, typename _SZ>
class CStats
{
public:
	CStats()
	{
		this->data = nullptr;
		this->length = 0;
	}

	CStats(_T* data, _SZ length)
	{
		this->lastMean = 0;
		this->lastSTD = 0;
		this->length = length;

		if (data == nullptr)
		{
			this->data = new _T[length];
			for (size_t i = 0; i < length; i++)
				this->data[i] = 0;
		}
		else
		{
			this->data = data;
		}
	}
	~CStats()
	{
		if (length > 0 && data != nullptr)
		{
			delete[] data;
			data = nullptr;
			length = 0;
		}
	}

	CStats& update(void)
	{
		//Calculate Mean
		float sum = 0, STD = 0;
		for (int i = 0; i < this->length; i++)
		{
			sum += this->data[i];
		}
		this->lastMean = sum / this->length;

		//Calculate Standard Deviation
		for (size_t i = 0; i < this->length; i++)
		{
			STD += pow(this->data[i] - this->lastMean, 2);
		}
		this->lastSTD = sqrt(STD / this->length);

		return *this;
	}

	CStats& randFill(int min, int max)
	{
		for (size_t i = 0; i < this->length; i++)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
		return *this;
	}

	void print(void)
	{
		cout << "Array Contains: " << endl;
		for (size_t i = 0; i < this->length; i++)
		{
			cout << this->data[i] << endl;
		}
		cout << "---------------------" << endl;
		cout << "Length of Array: " << this->length << endl;
		cout << "Mean of Array: " << this->lastMean << endl;
		cout << "Standard Division of Array: " << this->lastSTD << endl;
	}

private:
	_T* data = nullptr;
	_SZ length = 0;
	float lastMean = 0, lastSTD;


};

template class CStats<int, int>;
template class CStats<float, int>;
template class CStats<int, long>;
template class CStats<float, long>;
template class CStats<long, long>;
