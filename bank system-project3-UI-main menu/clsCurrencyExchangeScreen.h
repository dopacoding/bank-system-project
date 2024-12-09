#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculator.h"



class clsCurrencyExchangeScreen: protected clsScreen
{

private:
	enum enCurrencyExchangeOptions{eListCurrencies=1,eFindCurrency=2,eUpdateRate=3,eCurrencyCalculator=4,eMainMenue=5};
	static short _ReadCurrencyExchangeMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}
	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Exchange Menue...\n";
		system("pause>0");
		ShowCurrencyExchangeMenue();

	}

	static void _ShowListCurrenciesScreen()
	{
		/*cout << "\nList Currencies Screen will be soon!";*/
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		/*cout << "\nFind Currency Screen will be soon"*/;
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		/*cout << "\nUpdate Rate Screen will be soon!";*/
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		/*cout << "\nCurrency Calculator Screen will be soon!";*/
		clsCurrencyCalculator::ShowCurrencyCalculator();
	}

	static void _ShowMainMenueScreen()
	{
		cout << "\nShow main Menue Screen will be soon!";
	}

	static void _PerformCurrencyExchangeOptions(enCurrencyExchangeOptions CurrencyExchangeMenue)
	{
		switch (CurrencyExchangeMenue)
		{
		case enCurrencyExchangeOptions::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case enCurrencyExchangeOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case enCurrencyExchangeOptions::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case enCurrencyExchangeOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case enCurrencyExchangeOptions::eMainMenue:
		{
			// No code
		}


		}
   }


public:
	static void ShowCurrencyExchangeMenue()
	{
		if (!CheckAccessRights(clsUser::enPermission::pManageUsers))
		{
			return;// this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("\t\tCurrency Exchange Screen");
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		_PerformCurrencyExchangeOptions((enCurrencyExchangeOptions)_ReadCurrencyExchangeMenueOption());
	}
	
};

