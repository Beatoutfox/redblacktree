#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int d, int m, int y);
	Date(int n);
	~Date();
	void printDate();
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	bool operator<(Date d);
	bool operator>(Date d);
	bool operator==(Date d);
	bool operator<=(Date d);
	bool operator>=(Date d);
	bool operator!=(Date d);
	bool between(Date d1, Date d2);
	int age();

	friend ostream& operator<<(ostream& os, const Date& e);
};

void clearconsol();

int getanumber(string s);

double getanumberD(string s);

int rethowmanyTtoI(vector<bool>& v, int index);

bool isinvectorS(string s, vector<string>& v);

template<class T>
bool isinvectorC(T s, vector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == s)
		{
			return true;
		}
	}
	return false;
}

bool isinvectorVS(vector<string>& s, vector<string>& v);

template<class T>
bool isinvectorVC(vector<T>& s, vector<T>& v)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (isinvectorC(s[i], v) == false)
		{
			return false;
		}
	}
	return true;
}

void displaywithtab(vector<string> v);

void removefromvectorS(string s, vector<string>& v);

template<class T>
void removefromvectorC(T s, vector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == s)
		{
			v.erase(v.begin() + i);
			return;
		}
	}
}

void removefromvectorVS(vector<string>& s, vector<string>& v);

template<class T>
void removefromvectorVC(vector<T>& s, vector<T>& v)
{
	for (int i = 0; i < s.size(); i++)
	{
		removefromvectorC(s[i], v);
	}
}
