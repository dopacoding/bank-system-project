#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsWithdrawScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClientCard: ";
		cout << "\n------------------------------";
		cout << "\nFirst Name     : " << Client.FirstName;
		cout << "\nLast Name      : " << Client.LastName;
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nAccount Number : " << Client.AccountNumber();
		cout << "\nPin Code       : " << Client.PinCode;
		cout << "\nAccount Balance: " << Client.AccountBalance;
		cout << "\n------------------------------\n";
	}

	static string _ReaAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}



public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t\tWithdraw Screen");
		string AccountNumber = _ReaAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nthe Account Number [" << AccountNumber << "] not exist, choose another one";
			 _ReaAccountNumber();

		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nplease enter the Withdraw amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "are you sure want to Withdraw this amount [" << Amount << "]? y/n ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\nAmmount Withdraw Successfully";
				cout << "\nNew Balance is [ " << Client1.AccountBalance << " ]";
			}
			else
			
			{
				cout << "\ncannot withdraw, insuffecient Balance! ";
				cout << "\nAmmount to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client1.AccountBalance;
			}
			
		}
		

	}
};


