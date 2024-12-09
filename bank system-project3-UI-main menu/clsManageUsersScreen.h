#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include<iomanip>

class clsManageUsersScreen: protected clsScreen
{
private:
	enum enManageUsersOptions { eListUsers = 1,eAddNewUser=2,eDeleteUser=3,eUpdateUser=4,eFindUser=5,eMainMenue=6 };

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
	static void _GoBackToManageUsersMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to ManageUsers Menue...\n";
		system("pause>0");
		ShowManageUsersMenue();

	}
	
	static void _ShowListUsersScreen()
	{
		/*cout << "\nList users screen soon ...";*/
		clsListUsersScreen::ShowUsersList();

	}
	
	static void _ShowAddNewUserScreen()
	{
		/*cout << "\nList Add New User soon ...";*/
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		/*cout << "\nList Delete User soon ...";*/
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		/*cout << "\nList Update User soon ...";*/
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
		{
			/*cout << "\nList Find User soon ...";*/
		clsFindUserScreen::ShowFindUserScreen();
		}

	static void _ShowMainMenueScreen()
	{
		cout << "\nmain menue  soon ...";
	}

	static void _PerformManageUsersOption(enManageUsersOptions ManageUsersMenue)
	{
		switch (ManageUsersMenue)
		{
		case enManageUsersOptions::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersOptions::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersOptions::eMainMenue:
		{
			//no code
		}
			
			break;
		
		}
	}
	

public:
	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermission::pManageUsers))
		{
			return;// this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("\t\tManage Users Screen");

		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users\n";
		cout << setw(37) << left << "" << "\t[2] Add New User\n";
		cout << setw(37) << left << "" << "\t[3] Delete User\n";
		cout << setw(37) << left << "" << "\t[4] Update User\n";
		cout << setw(37) << left << "" << "\t[5] Find User\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		_PerformManageUsersOption((enManageUsersOptions)_ReadManageUsersMenueOption());



	}
};

