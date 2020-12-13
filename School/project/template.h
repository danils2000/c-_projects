//Personal money manager project for C++ programing course in Metropolia University Of Applied Scientist
//Author: Danil Sisov
//Year: 2020
//Month: December
//Platform: Linux(Ubuntu)
//Code editor: Visual Studio Code
//Compiler: gcc 9.3.0

#ifndef __TEMPLATE__H__
#define __TEMPLATE__H__

#include<iostream>
using namespace std;

class PersonalFinance {
private:
    char date[20]; // transaction date
    char description[20]; // user name
    char location[20]; // user lastname
    float sum; // user balance
    int balance = 0;
    float a;
    unsigned x; // income or expence

public:
    void decorativeLine(); // line painting just for decoration
    void author(); // welcome page with author name
    void depositeWithDetails(); // template for income with all needed incformation detailt to deposite.txt
    void withdrawWithDetails(); // template for expense with all needed incformation to withdraw.txt
    void deposit(); // income template
    void withdraw(); // expense template
    void depositeAll(); // accounts template
    void withdrawAll(); // accounts template
};

#endif // TEMPLATE_H
