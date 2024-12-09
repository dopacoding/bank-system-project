#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include<iomanip>


class clsTotalBalanceScreen : protected clsScreen
{
private:
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << " | " << left << setw(15) << Client.AccountNumber();
		cout << " | " << left << setw(40) << Client.FullName();
		cout << " | " << left << setw(10) << Client.AccountBalance;
	}


public:
	static void ShowTotalBalance()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t\tBalances List Screen";
		string Subtitle = "\n\t\t\t\t\t\t  (" + to_string(vClients.size()) + ") Clients. ";
		_DrawScreenHeader(Title,Subtitle);

		
		cout << "\n__________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

		cout << " | " << left << setw(15) << "Account Number";
		cout << " | " << left << setw(40) << "Client Name";
		cout << " | " << left << setw(10) << "Account Balance";
		cout << "\n__________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
		{
			cout << "\n\t\t\tno clients available in system!";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		}
		cout << "\n__________________________________________________________";
		cout << "____________________________________________________________\n" << endl;
		cout << "\t\t\t\t\t\tTotal Balances : " << TotalBalances << endl;
		cout << "\t\t\t\t(" << clsUtil::NumberToText(TotalBalances) << ")" << endl;
	}
};
