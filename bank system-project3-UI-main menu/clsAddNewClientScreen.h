#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include<iomanip>

class clsAddNewClientScreen : protected clsScreen
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
	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermission::pAddNewClient))
		{
			return;// this will exit the function and it will not continue
		}
		_DrawScreenHeader("\t\tAdd New Client Screen");

		string AccountNumber = "";
		cout << "\nPlease enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThe account number Already used, please choose another one:  ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult)
		{

		case clsBankClient::svSucceded:
		{
			cout << "\nAccount Saved Saccessfully :) .";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::svFailedEmptyObject:
		{
			cout << "\nError Account was not saved because its empty";
			break;
		}
		case clsBankClient::svFaildAccountNumberExists:
		{
			cout << "\nError Account is in use";
			break;
		}



		}
	};

};