
#pragma once
#include "clsUser.h"
#include <iomanip>
#include "Global.h"
#include "clsScreen.h"

class clsLoginRegisterScreen : public clsScreen

{
private:
    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegister)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegister.DataTime;
    
 
        cout << "| " << setw(20) << left << LoginRegister.UserName;
        cout << "| " << setw(20) << left << LoginRegister.Password;
        cout << "| " << setw(10) << left << LoginRegister.Permission;

    }

    

public:

    static void ShowLoginRegisterList()
    {

        if (!CheckAccessRights(clsUser::enPermission::pShowLoginRegister))
        {
            return;// this will exit the function and it will not continue
        }
        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\t  Login Register List Screen";
        string SubTitle = "    (" + to_string(vLoginRegisterRecord.size()) + ") Login Register(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date / Time";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Login Register Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }


};

