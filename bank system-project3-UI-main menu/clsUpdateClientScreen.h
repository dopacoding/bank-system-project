#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include<iomanip>
class clsUpdateClientScreen: protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nenter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nenter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nenter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nenter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nenter Pincode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nenter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();


	}

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

public:
	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermission::pUpdateClients))
		{
			return;// this will exit the function and it will not continue
		}
		_DrawScreenHeader("\t\tUpdate Client Screen");

		string AccountNumber = "";

		cout << "\nplease enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nNumber Account is not Found, choose another one:";
			AccountNumber = clsInputValidate::ReadString();


		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\nUpdate Data Client: ";
		cout << "\n------------------------";
		_ReadClientInfo(Client1);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client1.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceded:
			cout << "\nAccount Updated Saccessfully";
			_PrintClient(Client1);
			break;
		case clsBankClient::enSaveResults::svFailedEmptyObject:
			cout << "\nAccount failed Updated because its empty ";
			break;

		}
	}
};

