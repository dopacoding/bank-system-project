#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include<iomanip>

class clsTransactionsScreen : protected clsScreen 

{
private:
	enum enTransactionsOptions{eDeposite=1,eWithdraw=2,eTotalBalance=3,eTransfer=4,eTransferLog=5, eShowMainMenue =6};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";
		system("pause>0");
		ShowTransactionsMenue();
		
	}

	static void _ShowDepositeScreen()
	{
		/*cout << "\ndeposite screen will be soon...";*/
		clsDepositeScreen::ShowDepositeScreen();
	}

	static void _ShowWithdrawScreen()
	{
		/*cout << "\nwithdraw screen will be soon...";*/
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		//cout << "\ntotal balance screen will be soon...";
		clsTotalBalanceScreen::ShowTotalBalance();
	}

	static void _ShowTransferScreen()
	{
		/*cout << "sooooon...";*/
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _ShowExitScreen()
	{
		cout << "\nExit screen will be soon...";
	}

	static void _PerformMainMenueOption(enTransactionsOptions TransactionsMenue)
	{
		switch (TransactionsMenue)
		{
		case enTransactionsOptions::eDeposite:
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsOptions::eTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsOptions::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
         
		case enTransactionsOptions::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsOptions::eShowMainMenue:
			
		{

		}
		
		
		}
	}

public:
	static void ShowTransactionsMenue()
	{


		if (!CheckAccessRights(clsUser::enPermission::pTransactions))
		{
			return;// this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("\t\tTransactions Screen");

		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances\n";
		cout << setw(37) << left << "" << "\t[4] Transfer\n";
		cout << setw(37) << left << "" << "\t[5] TransferLog\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		_PerformMainMenueOption((enTransactionsOptions)_ReadTransactionsMenueOption());



   }
};

