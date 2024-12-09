#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculator : protected clsScreen
{

private:

    static void _PrintCurrencyCard(clsCurrency Currency,string Title="Curency Card: ")
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Exchange: ";
        float Amount = 0;

        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static clsCurrency _GetCurrency(string message)
    {
        string CurrencyCode;
        cout << message << endl;
        
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }
    
    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {

        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

    }

public:
	static void ShowCurrencyCalculator()
	{

        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");
            _DrawScreenHeader("\t\tCurrency Calculator");

            clsCurrency CurrencyFrom = _GetCurrency("please enter Currency1 Code: ");
            clsCurrency CurrencyTo = _GetCurrency("please enter Currency2 Code: ");
            float Amount = _ReadAmount();


            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Continue;
        }
	}

};

