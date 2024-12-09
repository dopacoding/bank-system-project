#pragma once
#include <iostream>
#include "clsUtil.h"


class clsInputValidate
{
public:
	

	static bool IsNumberBetween(int Value,int from,int to)
	{
		return (Value >= from && Value <= to);
    }

	static bool IsNumberBetween(double Value, double from, double to)
	{
		return (Value >= from && Value <= to) ;
	}

	static bool IsNumberBetween(float Value, float from, float to)
	{
		return (Value >= from && Value <= to) ;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		if ((Date.IsDate1BeforeDate2(Date, To) || Date.IsDate1EqualDate2(Date, To))
			&& (Date.IsDate1AfterDate2(Date, From) || Date.IsDate1EqualDate2(Date, From)))
		{
			return true;
		}

		if ((Date.IsDate1BeforeDate2(Date, From) || Date.IsDate1EqualDate2(Date, From))
			&& (Date.IsDate1AfterDate2(Date, To) || Date.IsDate1EqualDate2(Date, To)))
		{
			return true;
		}
		return false;




	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	
	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
    static int ReadIntNumber(string message="invalide number!,enter again:")
	{
		int Number;
		
		while (!(cin >> Number))
		{
			// if user didn't input a number 
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout <<message << endl;
			
		}
		return Number;
	}


	static float ReadFloatNumber(string message = "invalide number!,enter again:")
	{
		float Number;

		while (!(cin >> Number))
		{
			// if user didn't input a number 
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;

		}
		return Number;
	}

	static double ReadDblNumber(string message = "invalide number!,enter again:")
	{
		double Number;

		while (!(cin >> Number))
		{
			// if user didn't input a number 
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
			
		}
		return Number;
	}

	static int ReadIntNumberBetween(int from,int to, string message="Number is not within range, Enter again:\n")
	{

		
		int Number = ReadIntNumber();
		
		while (!IsNumberBetween(Number,from,to))
		{
			cout << message << endl;
			Number = ReadIntNumber();
		}

		
		return Number;
	

		
	}

	static double ReadDblNumberBetween(double from, double to, string message = "Number is not within range, Enter again:\n")
	{

		double Number = ReadIntNumber();

		while (!IsNumberBetween(Number, from, to))
		{
			cout << message << endl;
			Number = ReadIntNumber();
		}


		return Number;

	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S1="";
		getline(cin>>ws,S1);
		return S1;
	}

};


