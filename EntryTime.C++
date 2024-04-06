#include <iostream>
using namespace std;

class Time
{
	int h, m, s;
public:
	Time(int = 0, int = 0, int = 0);
	void input();
	void output();
	void show();
	Time operator-(Time);
	Time overwork();
	friend int main();
};

Time::Time(int a, int b, int c)
{
	h = a;
	m = b;
	s = c;
}

void Time::input()
{
	cout << "Enter your time : " << endl;
	cin >> this->h >> m >> s;
}

void Time::output()
{
	cout << "\t" << h << " : " << m << " : " << s << "\t";
	Time temp = overwork();
	temp.show();
}

Time Time:: operator-(Time op2)
{
	Time temp;
	temp.h = this->h - op2.h;
	temp.m = m - op2.m;
	temp.s = s - op2.s;
	return temp;
}

Time Time::overwork()
{
	Time start, temp;
	start.h = 8 , start.m = 30 , start.s = 0 ; // instead of these numbers, enter the operator's time for entrance
	if (start.h < h)
	{
		temp.h = start.h - h;
		if (start.m <= m)
		{
			temp.m = start.m - m;
			if (start.s <= s)
				temp.s = start.s - s;
			if (start.s > s)
			{
				temp.m = temp.m + 1;
				temp.s = s - start.s;
			}
		}
		if (start.m > m)
		{ 
			temp.h = temp.h + 1;
			temp.m = m - start.m;
			if (start.s <= s)
				temp.s = start.s - s;
			if (start.s > s)
			{
				temp.m = temp.m + 1;
				temp.s = s - start.s;
			}
		}
	}
	if (start.h >= h)
	{
		temp.h = start.h - h;
		if (start.m < m)
		{
			temp.h = temp.h - 1;
			temp.m = 60 - start.m + (start.m - m);
			if (start.s < s)
			{
				temp.m = temp.m - 1;
				temp.s = 60 - start.s + (start.s - s);
			}
			if (start.s >= s)
				temp.s = start.s - s;
		}
		if (start.m >= m)
		{
			temp.m = start.m - m;
			if (start.s < s)
				temp.s = s - start.s;
			if (start.s >= s)
				temp.s = start.s - s;
		}
	}
	return temp;
}

void Time::show()
{
	cout << h << " : " << m << " : " << s << endl;
}

int main()
{
	Time t1[3][2], t2[3][2]; //intead of 3, write the number of operators and intead of 2, write number of days that you want to have a record of them (until the end of the code)
	for (int i = 0; i < 3; i++) //intead of 3, write the number of operators
	{
		cout << endl << "'Operator number " << i + 1 << " '" << endl;
		cout << "=====================" << endl;
		for (int j = 0; j < 2; j++) //intead of 2, write number of days
		{
			cout << "Day number " << j + 1 << endl;
			t1[i][j].input();
		}
	}
	cout << "Operator\tDay\tEnter time\tOvertime" << endl;
	cout << "========\t===\t==========\t========" << endl;
	for (int i = 0; i < 3; i++) //intead of 3, write the number of operators
	{
		cout << i + 1;
		for (int j = 0; j < 2; j++) //intead of 2, write number of days
		{
			Time temp = t1[i][j].overwork();
			cout << "\t\t " << j + 1;
			t1[i][j].output();
		}
		cout << endl;
	}
	return 0;
}
