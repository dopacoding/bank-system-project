#pragma once
#include "clsMainScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "Global.h"




class clsLoginScreen : protected clsScreen
{

private:


	
	static bool _Login()
	{
		bool LoginFaild = false;
		short FaildLoginCount = 0;
		string UserName, Password;

		do
		{
			if (LoginFaild) 
			{
				FaildLoginCount++;
				
				cout << "\ninvalid username/password! ";
				cout << "\nyou have " << (3 - FaildLoginCount) << " trials to login\n\n";
				
			}
			if (FaildLoginCount == 3)
			{
				cout << "\nyou are locked after 3 faild trials\n ";
				return false;
			}

			cout << "enter UserName: ";
			cin >> UserName;
			cout << "enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}

	

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\t    Login Screen");
		return _Login();
	}

};

