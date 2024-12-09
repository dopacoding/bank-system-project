#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "Global.h"
#include<iomanip>


using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOptions{eListClients=1,eAddNewClient=2,eDeleteClient=3,eUpdateClient=4,eFindClient=5,eShowTransactionsMenue=6,
	                         eManageUsers=7,eLoginRegister=8,eCurrencyExchange=9,eExit=10 };

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
		return Choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}
	static void _ShowAllClientsScreen()
	{
	
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		/*cout << "\nthis page ShowAddNewClientsScreen will be soon...";*/
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeletClientScreen()
	{
		/*cout << "\nthis page ShowDeletClientsScreen will be soon...";*/
		clsDeleteClientScreen::ShowDeletClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		/*cout << "\nthis page ShowUpdateClientsScreen will be soon...";*/
		clsUpdateClientScreen::ShowUpdateClientScreen();

	}

	static void _ShowFindClientScreen()
	{
		/*cout << "\nthis page ShowFindClientsScreen will be soon...";*/
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen()
	{
		/*cout << "\nthis page ShowTransactionsScreen will be soon...";*/
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersScreen()
	{
		//cout << "\nthis page ShowManageUsersScreen will be soon...";
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowRegisterLoginScreen()
	{
		/*cout << "this page will be soon\n";*/
		clsLoginRegisterScreen::ShowLoginRegisterList();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		/*cout << "this page Currency Exchange Screen will be soon\n";*/
		clsCurrencyExchangeScreen::ShowCurrencyExchangeMenue();
	}

	/*static void _ShowExitScreen()
	{
		cout << "\nthis page ShowExitScreen will be soon...";
	}*/

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}


	static void _PerformMainMenueOption(enMainMenueOptions MainMenueOptions)
	{
		switch (MainMenueOptions)
		{
		case enMainMenueOptions::eListClients:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eDeleteClient:
			system("cls");
			_ShowDeletClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eShowTransactionsMenue:
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eLoginRegister:
			system("cls");
			_ShowRegisterLoginScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;


		case enMainMenueOptions::eExit:
			system("cls");
			_Logout();
			
			break;
		
		}
	}
public:
	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client\n";
		cout << setw(37) << left << "" << "\t[4] Update Client\n";
		cout << setw(37) << left << "" << "\t[5] Find Client\n";
		cout << setw(37) << left << "" << "\t[6] Transactions\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users\n";
		cout << setw(37) << left << "" << "\t[8] Show Login Register List\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange\n";
		cout << setw(37) << left << "" << "\t[10] Logout\n";
		cout << setw(37) << left << "" << "=============================================\n";
		_PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());




}
};

