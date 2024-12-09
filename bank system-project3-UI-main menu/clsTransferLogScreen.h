#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen 
{

private:
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLog)
	{

		cout << setw(4) << left << "" << " | " << setw(30) << left << TransferLog.DataTime;


		cout << " | " << setw(10) << left << TransferLog.SourceAccount;
		cout << " | " << setw(10) << left << TransferLog.DestinationAccount;
		cout << " | " << setw(10) << left << TransferLog.Amount;
		cout << " | " << setw(10) << left << TransferLog.SourceBalance;
		cout << " | " << setw(10) << left << TransferLog.DestinationBalance;
		cout << " | " << setw(10) << left << TransferLog.User;
		
	}


public:

	static void ShowTransferLogScreen()
	{

		
		vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();
		string Title = "\t\tTransfer Log List Screen";
		string SubTitle = "\t (" + to_string(vTransferLogRecord.size()) + ") Records";


		_DrawScreenHeader("\t\tTransferLogScreen");

		cout << setw(4) << left << "" << "\n__________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

		cout << setw(4) << left << "" << " | " << left << setw(30) << "Date / Time";
		cout << " | " << left << setw(10) << "S.Account";
		cout << " | " << left << setw(10) << "D.Account";
		cout << " | " << left << setw(10) << "Amount";
		cout << " | " << left << setw(10) << "S.Balance";
		cout << " | " << left << setw(10) << "D.Balance";
		cout << " | " << left << setw(10) << "User";
		cout << setw(4) << left << "" << "\n__________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

		if (vTransferLogRecord.size() == 0)
			cout << "\t\t\t\tNo Login Register Available In the System!";
		else

			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
			{

				_PrintTransferLogRecordLine(Record);
				cout << endl;
			}

		cout << setw(4) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}
};

