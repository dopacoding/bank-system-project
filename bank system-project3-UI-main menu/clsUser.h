#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson 
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permission;

	bool _MarkedForDelete = false;

	struct stLoginRegisterRecord;
	
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector<string>LoginRegisterDataLine = clsString::Split(Line, Seperator);
		LoginRegisterRecord.DataTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permission = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;



	}
	
	
	static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string>vUserData;
		vUserData = clsString::Split(Line, Seperator);
		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4]
			, clsUtil::DecryptText(vUserData[5]), stod(vUserData[6]));
	}
	

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsUser>_LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read only mode 
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}

	static vector <clsUser>_LoadLoginRegisterDataFromFile()
	{
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);//read only mode 
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}
	
	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& C : _vUsers)
		{
			if (C.UserName == UserName)
			{
				C = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
	}

	static string _convertUserObjectToLine(clsUser Client, string Seperator = "#//#")
	{
		string stUserRecord = "";

		stUserRecord += Client.FirstName + Seperator;
		stUserRecord += Client.LastName + Seperator;
		stUserRecord += Client.Email + Seperator;
		stUserRecord += Client.Phone + Seperator;
		stUserRecord += Client.UserName + Seperator;
		//here we encrypt store the encrypted password not the real one 
		stUserRecord += clsUtil::EncryptText(Client.Password) + Seperator;
		stUserRecord += to_string(Client.Permission);

		return stUserRecord;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsUser C : vUsers)
			{
				if (C.MarkedForDelete() == false)

				{
					DataLine = _convertUserObjectToLine(C);
					MyFile <<DataLine << endl;
				}

			}
			MyFile.close();
		}

	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	void _AddNew()
	{
		_AddDataLineToFile(_convertUserObjectToLine(*this));
	}

	string _PrepareLogInRecord(string Seperator="#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(Password) + Seperator;
		LoginRecord += to_string(Permission);
		return LoginRecord;
	}
public:

	enum enPermission {
		eAll=-1,pListClients=1,pAddNewClient=2,pDeleteClient=4,pUpdateClients=8,pFindClient=16,pTransactions=32,pManageUsers=64,pShowLoginRegister=128,
		pCurrencyExchange=156

	};



	struct stLoginRegisterRecord 
	{
		string DataTime;
		string UserName;
		string Password;
		int Permission;
	};

	
	clsUser(enMode Mode,string FirstName,string LastName,string Email,string Phone,string UserName,string Password,int Permission)
		:clsPerson(FirstName,LastName,Email,Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permission = Permission;

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	_declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	string GetPassword()
	{
		return _Password;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	_declspec(property(get = GetPassword, put = SetPassword)) string Password;

	int GetPermission()
	{
		return _Permission;
	}

	void SetPermission(int Permission)
	{
		_Permission = Permission;
	}

	_declspec(property(get = GetPermission, put = SetPermission)) int Permission;

	static clsUser Find(string UserName)
	{
		vector<clsUser> vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName ==UserName)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		vector<clsUser> vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName && User.GetPassword() == Password)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceded = 1, svFaildUserExists = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFailedEmptyObject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceded;
			break;
		}
		case enMode::AddNewMode:
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceded;
			}


		}
	}

	bool Delete()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();
		for (clsUser& C : _vUsers)
		{
			if (C.UserName == _UserName)
			{
				C._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);

	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord>vLoginRegisterRecord;
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);// read mode
		if (MyFile.is_open())
		{
			string Line;
			stLoginRegisterRecord LoginRegisterRecord;
			while (getline(MyFile,Line))
			{
				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);
				vLoginRegisterRecord.push_back(LoginRegisterRecord);
			}
			MyFile.close();
			}
		return vLoginRegisterRecord;
	}

	

	bool CheckAccessPermission(enPermission Permission)
	{
		if (this->Permission == enPermission::eAll)
			return true;

		if ((Permission & this->Permission) == Permission)
			return true;
		else
			return false;

	}

	void RegisterLogin()
	{
		string stDataLine = _PrepareLogInRecord();

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}

	}

};

