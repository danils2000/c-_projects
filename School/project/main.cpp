//Personal money manager project for C++ programing course in Metropolia University Of Applied Scientist
//Author: Danil Sisov
//Year: 2020
//Month: December
//Platform: Linux(Ubuntu)
//Code editor: Visual Studio Code
//Compiler: gcc 9.3.0
#include"memory.h"
#include"template.h"


int main() {

    PersonalFinance PersonalFinance;
    Memory memory;
    PersonalFinance.author();
    int option;

    while(true) {   
        cout<<"\n\n\t\t\t\t  MAIN MENU"; 
		cout<<"\n\n\t01| ⊚ INCOME WITH DETAILS";
        cout<<"\n\n\t02| ⊚ EXPENSE WITH DETAILS"; 
        cout<<"\n\n\t03| ⊚ AMOUT";
		cout<<"\n\n\t04| ⊚ ALL DATA LIST"; 
        cout<<"\n\n\t05| ⊚ INCOME WITHOUT DETAILS"; 
		cout<<"\n\n\t06| ⊚ EXPENSE WITHOUT DETAILS";  
		cout<<"\n\n\t07| ⊚ SERACH INCOME BY SERIATIM"; 
        cout<<"\n\n\t08| ⊚ SERACH EXPENSE BY SERIATIM"; 
		cout<<"\n\n\t09| ⊚ DELETE INCOME BY SERIATIM";
        cout<<"\n\n\t10| ⊚ DELETE EXPENSE BY SERIATIM";
        cout<<"\n\n\t11| ⊚ EDIT INCOME DETAILS BY SERIATIM";
        cout<<"\n\n\t12| ⊚ EDIT EXPENSE DETAILS BY SERIATIM";
		cout<<"\n\n\t13| ⊚ EXIT";
        cout<<"\n\n\tSelect Your Option (1-13)⇨ ";
        cin >> option;

        switch(option) {
        case 1:
            memory.depositeWriteInFile();
            memory.depositeRepeat();
            break;
        case 2:
            memory.withdrawWriteInFile();
            memory.withdrawRepeat();
            break;
        case 3:
            memory.amout();
            break;
        case 4:
            memory.readAll();
            break;
        case 5:
            memory.depositeWithoutDetails();
            break;
        case 6:
            memory.withdrawWithouDetails();
            break;
        case 7:
            memory.searchDep();
            break;
        case 8:
            memory.searchWith();
            break;
        case 9:
            memory.deleteIncome();
            break;
        case 10:
            memory.deleteWithdraw();
            break;
        case 11:
            memory.editDepositeDetails();
            break;
        case 12:
            memory.editWithdrawDetails();
            break;
        case 13:
            cout << "\n\nThank you for using your personal finance application. Have a nice day ☻☺\n\n" << endl;
            exit(0);
            break;
        default:
            cout<<"\nIncorrect number, please type number from 1 to 7 " << endl;
            cin.get();
            return main();
        }
    }
    system("pause");
    return 0;
}
