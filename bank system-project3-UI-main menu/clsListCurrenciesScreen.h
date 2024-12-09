#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>

class clsListCurrenciesScreen: protected clsScreen
{

private:
	static void _PrintCurrenciesRecordLine(clsCurrency Currencies)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << Currencies.Country();
		cout << "| " << setw(10) << left << Currencies.CurrencyCode();
		cout << "| " << setw(40) << left << Currencies.CurrencyName();
		cout << "| " << setw(10) << left << Currencies.Rate();
		
	}

public:
	static void ShowListCurrenciesScreen()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t  Currncies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);
        
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(10) << "Rate(1$)";
        
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsCurrency Currencies : vCurrencies)
            {

                _PrintCurrenciesRecordLine(Currencies);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }


	
};

