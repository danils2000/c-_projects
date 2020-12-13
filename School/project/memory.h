//Personal money manager project for C++ programing course in Metropolia University Of Applied Scientist
//Author: Danil Sisov
//Year: 2020
//Month: December
//Platform: Linux(Ubuntu)
//Code editor: Visual Studio Code
//Compiler: gcc 9.3.0


#ifndef __MEMORY__H__
#define __MEMORY__H__

#include "template.h"

class Memory : PersonalFinance {
private:
    char date[20]; // transaction date
    char description[20]; // user name
    char location[20]; // user lastname
    float sum; // user balance
    int balance = 0;
    float a;
    unsigned x; // income or expence
    
public:
    void depositeRepeat();  // write to amout.txt. Checking current balance as this calculate all income and expense 
    void withdrawRepeat(); // write to amout.txt. Checking current balance as this calculate all income and expense 
    void depositeWithoutDetails(); // Add income without details
    void withdrawWithouDetails(); // Add expense without details
    void amout(); // Cheking current balance 
    void editDepositeDetails(); // income + to file
    void editWithdrawDetails(); // expense - to file
    void depositeWriteInFile(); // new income to file
    void withdrawWriteInFile(); // new expense to file
    void readAll(); //show all accounts from file with template
    void searchDep(); // search account in file
    void searchWith(); // search account in file
    void deleteIncome(); // delete account from file
    void deleteWithdraw(); // delete account from file
};

#endif // !MEMORY_H_INCLUDED
