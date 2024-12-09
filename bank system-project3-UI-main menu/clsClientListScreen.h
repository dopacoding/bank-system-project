#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>



class clsClientListScreen:protected clsScreen

{
private:
	static void PrintClientRecordLine(clsBankClient Client)
	{
		cout << setw(4) << left <<""<< " | " << left << setw(15) << Client.AccountNumber();
		cout << " | " << left << setw(20) << Client.FullName();
		cout << " | " << left << setw(15) << Client.Phone;
		cout << " | " << left << setw(20) << Client.Email;
		cout << " | " << left << setw(10) << Client.PinCode;
		cout << " | " << left << setw(10) << Client.AccountBalance;
	}
public:
	static void ShowClientsList()
	{

		if (!CheckAccessRights(clsUser::enPermission::pListClients))
		{
			return;// this will exit the function and it will not continue
		}
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t\tClients List Screen";
		string SubTitle = "\t ("+ to_string(vClients.size()) +") Clients";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(4) << left << "" << "\n__________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

		cout << setw(4)<<left<<""<<" | " << left << setw(15) << "Account Number";
		cout << " | " << left << setw(20) << "Client Name";
		cout << " | " << left << setw(15) << "Phone";
		cout << " | " << left << setw(20) << "Email";
		cout << " | " << left << setw(10) << "Pin Code";
		cout << " | " << left << setw(10) << "Account Balance";
		cout << setw(4) << left <<""<< "\n__________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

		if (vClients.size() == 0)

			cout << "\t\t\t\tNo Clients Available in the system ";
		else
			for (clsBankClient Client : vClients)
			{
				PrintClientRecordLine(Client);
				cout << endl;
			}
		cout << "__________________________________________________________";
		cout << "____________________________________________________________\n";
	}

};

