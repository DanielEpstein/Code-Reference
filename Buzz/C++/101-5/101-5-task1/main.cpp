// Dec, Jan, Feb = Winter

// create a month enum
// create a season enum
// create a function that takes in a month and returns the correct season value
// create a function that takes in a season and returns the projected temerature for that season (makes stuff up)
// write code that converts January into a temeratrure in main

#include <iostream>

using namespace std;

enum Month : char
{
	January,February,March,April,May,June,July,August,Spetember,October,November,December
};

enum Season : char
{
	Summer,Autumn,Winter,Spring
};

Season DisplaySeason(Month month);
int DisplaySeasonTemperature(Season season);

int main()
{
	cout << "The temp for January will be " << DisplaySeasonTemperature(DisplaySeason(January));

	cin.ignore();
	cin.get();
	return 0;
}

Season DisplaySeason(Month month)
{
	if (month == December || January || February)
	{
		return Summer;
	}
	else if (month == March || April || May)
	{
		return Autumn;
	}
	else if (month == June || July || August)
	{
		return Winter;
	}
	else if (month == Spetember || October || November)
	{
		return Spring;
	}
}

int DisplaySeasonTemperature(Season season)
{
	if (season == Summer)
	{
		return 40;
	}
	else if (season == Autumn)
	{
		return 26;
	}
	else if (season == Winter)
	{
		return 15;
	}
	else if (season == Spring)
	{
		return 25;
	}
}