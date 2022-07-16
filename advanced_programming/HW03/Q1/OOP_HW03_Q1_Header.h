#pragma once
#include <iostream>
#include <math.h>
#include <algorithm>


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

	virtual CStats& update(void)
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

	virtual void print(void)
	{
		cout << "---------------------" << endl;
		cout << "Length of Array: " << this->length << endl;
		cout << "Mean of Array: " << this->lastMean << endl;
		cout << "Standard Division of Array: " << this->lastSTD << endl;
	}

protected:
	_T* data = nullptr;
	_SZ length = 0;
	float lastMean = 0, lastSTD;


};


template <typename _T, typename _SZ>
class CStatsEx : public CStats<_T, _SZ>
{

public:
	CStatsEx()
	{
		CStats<_T, _SZ>::CStats();
		this->name = "Object0";
	}

	CStatsEx(_T* data, _SZ length, string name) : CStats<_T, _SZ>(data, length), name(name) {}
	CStatsEx(_T* data, _SZ length) : CStats<_T, _SZ>(data, length)
	{
		this->name = "Object0";
	}

	~CStatsEx()
	{
		CStats<_T, _SZ>::~CStats();
	}

	CStatsEx& update(void)
	{
		CStats<_T, _SZ>::update();
		lastMin = *min_element(this->data, this->data + this->length);
		lastMax = *max_element(this->data, this->data + this->length);

		return *this;
	}

	CStatsEx& Sort(void)
	{
		sort(this->data, this->data + this->length);
		return *this;
	}

	void print(void)
	{
		CStats<_T, _SZ>::print();
		cout << "Object Name: " << name << endl;
		cout << "Min Element: " << lastMin << endl;
		cout << "Max Element: " << lastMax << endl;
	}

private:
	string name = nullptr;
	float lastMin, lastMax;

};