#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>


class clsFindCurrencyScreen: protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card: \n";
		cout << "----------------------------------\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n-------------------------------\n";
	}
	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency was not Found :-(\n";
		}
	}
public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t\tFind Currency Screen");
		cout << "\nFind By: [1] Code or [2] Country ? :  ";
		short Answer;
		Answer = clsInputValidate::ReadShortNumberBetween(1, 2);
		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease enter Currency Code: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}

		else
		{
			string CurrencyCountry;
			cout << "\nPlease enter Currency Country: ";
			CurrencyCountry = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);

			_ShowResults(Currency);
		}
		
	}
};

