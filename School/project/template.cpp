#include "template.h"

//decorative line
void PersonalFinance::decorativeLine() {
    int amount = 80;
    char symb = '-';
    for (int i = 0; i < amount; i++) {
    cout << symb;
    }
}

//start screen with author name and name of the game
void PersonalFinance::author() {
    decorativeLine();
    cout << "\n\n\t\t\t Personal finance programm" << endl;
    cout << "\t\t\t\t     by" << endl;
    cout << "\t\t\t\t©Danil Sisov\n" << endl;
    cout << "\t\t  ______________________________________"<<endl;
    cout << "\t\t  |     _       _|__|_                 |"<< endl;
    cout << "\t\t  | /| / \\     / |  | \\                |"<< endl;
    cout << "\t\t  |  | \\_/     \\_|__|_                 |"<< endl;
    cout << "\t\t  |              |  | \\             _  |"<< endl;
    cout << "\t\t  |            __|__|_/         /| / \\ |"<< endl;
    cout << "\t\t  |              |  |            | \\_/ |"<< endl;
    cout << "\t\t  |____________________________________|"<<endl;
 
    decorativeLine(); //line
    cin.get(); //freeze
}

// template for depositeRepeat
    void PersonalFinance::depositeWithDetails() {
    decorativeLine();

    cout << "\nEnter date: ";
    cin  >> date;
    cout << "Description: ";
    cin  >> description;
    cout << "Location: ";
    cin  >> location;
    cout << "Income: $";
    cin  >> x;
    cout << endl;
}

//template for withdrawRepeat
void PersonalFinance::withdrawWithDetails() {
    decorativeLine();

    cout << "\nEnter date: ";
    cin  >> date;
    cout << "Description: ";
    cin  >> description;
    cout << "Location: ";
    cin  >> location;
    cout << "Withdraw: $";
    cin  >> x;
    cout << endl;
}


//all accounts list
void PersonalFinance::depositeAll() {
    cout << endl;
    cout << "Date: "<< date << endl;
    cout << "Decription: " << description << endl;
    cout << "Location: " << location << endl;
    cout << "Deposite: $" << x << endl;
    decorativeLine();
}

//all accounts list
void PersonalFinance::withdrawAll() {
    cout << endl;
    cout << "Date: "<< date << endl;
    cout << "Decription: " << description << endl;
    cout << "Location: " << location << endl;
    cout << "Withdraw: $" << x << endl;
    decorativeLine();
}

//deposite +
void PersonalFinance::deposit() {
    cout << endl;
    cout << "Enter data to income: +$ ";
    cin >> x;
    sum+=x;
}

//withdraw -
void PersonalFinance::withdraw() {
    cout << endl;
    cout << "Enter data to expense: -$ ";
    cin >> x;
    sum-=x;
}
