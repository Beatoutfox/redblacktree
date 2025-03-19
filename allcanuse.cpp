#include "Allcanuse.h"

void clearconsol()
{
	// Clear console
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");
#endif
}

int getanumber(string s)
{
	int value;
	while (true)//loop until valid input
	{
		cout << s;
		cin >> value;
		if (cin.fail())
		{
			cin.clear(); // Clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << "Invalid input. Please enter a number.\n";
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any extra input
			return value;
		}
	}
}

double getanumberD(string s)
{
	double value;
	while (true)//loop until valid input
	{
		cout << s;
		cin >> value;
		if (cin.fail())
		{
			cin.clear(); // Clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << "Invalid input. Please enter a number.\n";
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any extra input
			return value;
		}
	}
}

int rethowmanyTtoI(vector<bool>& v, int index)
{
	int n = 0;
	for (int i = 0; i <= index && i < v.size(); i++)
	{
		if (v[i])
		{
			n++;
		}
	}
	return n;
}

bool isinvectorS(string s, vector<string>& v)
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

bool isinvectorVS(vector<string>& s, vector<string>& v)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (isinvectorS(s[i], v) == false)
		{
			return false;
		}
	}
	return true;
}

void displaywithtab(vector<string> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (i == 0)
		{
			cout << v[i] << endl;
		}
		else
		{
			cout << "\t" << v[i] << endl;
		}
	}
	if(v.size()==0)
	{
		cout << endl;
	}
}

void removefromvectorS(string s, vector<string>& v)
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

void removefromvectorVS(vector<string>& s, vector<string>& v)
{
	for (int i = 0; i < s.size(); i++)
	{
		removefromvectorS(s[i], v);
	}
}

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

Date::~Date()
{
}

Date::Date(int n)
{

	time_t t = time(0);
	tm now;
	localtime_s(&now, &t);
	day = now.tm_mday;
	month = now.tm_mon + 1;
	year = now.tm_year + 1900;
}

void Date::printDate()
{
	cout << day << "/" << month << "/" << year;
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::setDay(int d)
{
	day = d;
}

void Date::setMonth(int m)
{
	month = m;
}

void Date::setYear(int y)
{
	year = y;
}

bool Date::operator<(Date d)
{
	if (year < d.year)
	{
		return true;
	}
	else if (year == d.year)
	{
		if (month < d.month)
		{
			return true;
		}
		else if (month == d.month)
		{
			if (day < d.day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator>(Date d)
{
	if (year > d.year)
	{
		return true;
	}
	else if (year == d.year)
	{
		if (month > d.month)
		{
			return true;
		}
		else if (month == d.month)
		{
			if (day > d.day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator==(Date d)
{
	if (year == d.year && month == d.month && day == d.day)
	{
		return true;
	}
	return false;
}

bool Date::operator<=(Date d)
{
	if (*this < d || *this == d)
	{
		return true;
	}
	return false;
}

bool Date::operator>=(Date d)
{
	if (*this > d || *this == d)
	{
		return true;
	}
	return false;
}

bool Date::operator!=(Date d)
{
	if (!(*this == d))
	{
		return true;
	}
	return false;
}

bool Date::between(Date d1, Date d2)
{
	if (*this >= d1 && *this <= d2)
	{
		return true;
	}
	return false;
}

int Date::age()
{
	time_t t = time(0);
	tm now;
	localtime_s(&now, &t);

	Date today(now.tm_mday, now.tm_mon + 1, now.tm_year + 1900);
	int age = today.year - year;
	if (today < Date(day, month, today.year))
	{
		age--;
	}
	return age;
}


ostream& operator<<(ostream& os, const Date& e)
{
	os << e.day << "/" << e.month << "/" << e.year;
	return os;
}