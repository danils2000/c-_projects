#include<fstream>
#include<cstdlib>
#include<cctype>
#include<iomanip>
#include<string>
#include"memory.h"

using std::cout;
using std::endl;
using std::cin;

//income to amout.txt
void Memory::depositeRepeat() {
    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
    }

    while (inFile >> value) {
        if (value > 0) {
            cout << value;
        }
    }
    inFile.close();

    cout << "Please, confirm amout:+ ";
    cin >> a;
    sum = value + a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    out.close();
}


//write expense to amout.txt
void Memory::withdrawRepeat() {
    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
    }

    while (inFile >> value) {
        if (value > 0) {
            cout << value;
        }
    }
    inFile.close();

    cout << "Please, confirm amout:- ";
    cin >> a;
    sum = value - a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    out.close();
}

//deposite without details
void Memory::depositeWithoutDetails() {
    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
    }

    while (inFile >> value) {
        if (value > 0) {
            cout << value;
        }
    }
    inFile.close();
    
    cout << "NOTE! YOU WILL NOT HAVE ANY DETAILS IN YOUR LIST ABOUT THIS INCOME" << endl;
    cout << "Please, enter income:+ ";
    cin >> a;
    sum = value + a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    out.close();
}

//withdraw whitout details
void Memory::withdrawWithouDetails() {
    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
    }

    while (inFile >> value) {
        if (value > 0) {
            cout << value;
        }
    }
    inFile.close();

    cout << "NOTE! YOU WILL NOT HAVE ANY DETAILS IN YOUR LIST ABOUT THIS EXPENSE" << endl;
    cout << "Please, enter amout for expense:- ";
    cin >> a;
    sum = value - a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    std::cout << "End of program" << endl;
    out.close();
}

// add and save deposite to file deposite.txt
void Memory::depositeWriteInFile() {
    ofstream outfile;
    outfile.open("deposite.txt", ios::app| ios::binary);
    depositeWithDetails();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}

// add and save expense to file withdraw.txt
void Memory::withdrawWriteInFile() {
    ofstream outfile;
    outfile.open("withdraw.txt", ios::app| ios::binary);
    withdrawWithDetails();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}

//check currecnt balance
void Memory::amout() {
    int sum = 0;
    int x;
    ifstream inFile;
    
    inFile.open("amout.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (inFile >> x) {
        sum = sum + x;
    }
    
    inFile.close();
    cout << "Your Balance is = " << sum << endl; 
    inFile.close();

    cin.get();
    cout << "Press any key ☺" << endl;
    cin.get();
}

// Read all data
void Memory::readAll() {
//Deposite data---------------------------------------------------------------------------------------------------
    ifstream dep; // Stream class to read from files
    dep.open("deposite.txt", ios::binary);// open file (deposite.txt) in binary mode to write and read from file

    //If file can not to open
    if(!dep) {
        cout << "Error in deposite file! Try again" << endl;
        return;
    }

    // file open
    decorativeLine(); 
    cout <<"\n\n\t\t\tDEPOSITE DATA" << endl;

    while(!dep.eof()) { //read while file have symbols
        if(dep.read(reinterpret_cast<char*>(this), sizeof(*this))) { // read and show all symblos in file 
            depositeAll(); // template for show all accounts
        }
    }
    cout << endl;
    cin.get();
    dep.close(); // close file
    cout << endl;


//Withdraw data-----------------------------------------------------------------------------------------------------
    ifstream withdra; // Stream class to read from files
    withdra.open("withdraw.txt", ios::binary);// open file (withdraw.txt) in binary mode to write and read from file

    //If file can not to open
    if(!withdra) {
        cout << "Error in withdraw file! Try again" << endl;
        return;
    }

    // file open
    decorativeLine(); 
    cout <<"\n\n\t\t\tWithdraw date" << endl;

    while(!withdra.eof()) { //read while file have symbols
        if(withdra.read(reinterpret_cast<char*>(this), sizeof(*this))) { // read and show all symblos in file 
            withdrawAll(); // template for show all accounts
        }
    }
    cout << endl;
    cin.get(); // freeze
    withdra.close(); // close file

    cout << "Press any key ☺" << endl;
    cin.get();
}

// Search needed data in deposite.txt
void Memory::searchDep() {
    decorativeLine();
    cout <<"\n\n\t\t\tFind your income since 1" << endl;
    int choise; // choose account 
    ifstream search; // Stream class to read from files
    search.open("deposite.txt", ios::binary); // open file (deposite.txt) in binary mode to write and read from file

    //ERROR
    if(!search) {
        cout << "\nError in opening! Try again" << endl;
        return;
    }
    search.seekg (0,ios::end); //Sets the position of the next character to be extracted from the input stream.
    int c = search.tellg()/sizeof(*this); // Returns the position of the current character in the input stream.
    cout << "\n Your income list have " << c << " record in the system";
    cout << "\n Write the number of income that you want to see: ";
    cin >> choise;
    search.seekg((choise-1)*sizeof(*this)); // find data what user need
    search.read(reinterpret_cast<char*>(this), sizeof(*this)); // read and show all symblos that user need
    depositeAll(); // tempalte for accounts
    cout << endl;
    cin.get();
    cout << "Press any key ☺" << endl;
    cin.get();
}

//Search needded data in withdraw.txt
void Memory::searchWith() {
    decorativeLine();
    cout <<"\n\n\t\t\tFind your expense since 1" << endl;
    int choise; // choose account 
    ifstream search; // Stream class to read from files
    search.open("deposite.txt", ios::binary); // open file (deposite.txt) in binary mode to write and read from file

    //ERROR
    if(!search) {
        cout << "\nError in opening! Try again" << endl;
        return;
    }
    search.seekg (0,ios::end); //Sets the position of the next character to be extracted from the input stream.
    int c = search.tellg()/sizeof(*this); // Returns the position of the current character in the input stream.
    cout << "\n Your expense list have " << c << " record in the system";
    cout << "\n Write the number of expense that you want to see: ";
    cin >> choise;
    search.seekg((choise-1)*sizeof(*this)); // find account what user need
    search.read(reinterpret_cast<char*>(this), sizeof(*this)); // read and show all symblos that user need
    withdrawAll(); // tempalte FOR expense
    cout << endl;
    cin.get();
    search.close();

    cout << "Press any key ☺" << endl;
    cin.get();
}

//edit deposite data
void Memory::editDepositeDetails() {
    decorativeLine();
    cout <<"\n\n\t\t\tDeposite" << endl;
    int n;
    fstream indep;
    indep.open("deposite.txt", ios::in|ios::binary); // open file in binary mode and for input mode

    //ERROR
    if(!indep) {
        cout << "\nError in opening! Try again" << endl;
        return;
    }
    indep.seekg(0, ios::end); // Go to end of input file
    int c = indep.tellg()/sizeof(*this);  //Returns the position of the current character in the input stream.
    cout << "\n Your deposite list have " << c << " record in the system";
    cout << "\n Type your id number: ";
    cin >> n;
    indep.seekg((n-1)*sizeof(*this)); // find account what user need
    indep.read(reinterpret_cast<char*>(this), sizeof(*this)); // read and show all symblos that user need
    cout << "Record " << n << " has following data" << endl;
    depositeAll();
    indep.close();
    indep.open("deposite.txt", ios::out|ios::in|ios::binary); // // open file in binary mode, for input mode and reading mode
    indep.seekp((n-1)*sizeof(*this)); //Sets the position where the next character is to be inserted into the output stream

    // open void deposite() for income
    deposit();
    indep.write(reinterpret_cast<char*>(this), sizeof(*this));
    indep.close();

    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
    }

    while (inFile >> value) {
        if (value > 0) {
            cout << value;
        }
    }
    inFile.close();

    cout << "Please, confirm amout: ";
    cin >> a;
    sum = value + a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    std::cout << "End of program" << endl;
    out.close();
}

//edit withdraw data
void Memory::editWithdrawDetails() {
    decorativeLine();
    cout <<"\n\n\t\t\tWithdraw" << endl;
    int n;
    fstream inwithdr;
    inwithdr.open("withdraw.txt", ios::in|ios::binary);

    if(!inwithdr) {
        cout << "\nError in opening! File Not Found!!" << endl;
        return;
    }

    inwithdr.seekg(0, ios::end);
    int c = inwithdr.tellg()/sizeof(*this);
    cout << "\n Your withdraw list have " << c << " record in the system";
    cout << "\n Type your id number: ";
    cin >> n;
    inwithdr.seekg((n-1)*sizeof(*this));
    inwithdr.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout << "Record " << n << " has following data" << endl;
    withdrawAll();
    inwithdr.close();
    inwithdr.open("withdraw.txt", ios::out|ios::in|ios::binary);
    inwithdr.seekp((n-1)*sizeof(*this));
    withdrawAll();
    inwithdr.write(reinterpret_cast<char*>(this), sizeof(*this));
    inwithdr.close();

    ifstream inFile;
    float value;

    inFile.open("amout.txt");
    if (!inFile) {
        cout << "\nError opening file.\n";
    }

    while (inFile >> value) {
        if (value > 0) {
            cout << value;
        }
    }
    inFile.close();

    cout << "Please, confirm amout: ";
    cin >> a;
    sum = value - a;

    ofstream out;  
    out.open("amout.txt");
    if (out.is_open()) {
        out << sum << endl;
    }
     
    std::cout << "End of program" << endl;
    out.close();
}

//Delete Income data
void Memory::deleteIncome() {
    decorativeLine();
    cout <<"\n\n\t\t\tDELETE" << endl;
    int n;
    ifstream infile;
    infile.open("deposite.txt", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int c = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<< c <<" income record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("file.txt", ios::out|ios::binary);
    infile.seekg(0);
    for(int i = 0; i < c; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("deposite.txt");
    rename("file.txt", "deposite.txt");
}

//Delete 
void Memory::deleteWithdraw() {
    decorativeLine();
    cout <<"\n\n\t\t\tDELETE EXPENCE" << endl;
    int n;
    ifstream infile;
    infile.open("withdraw.txt", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int c = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<< c <<" expense record in the file";
    cout<<"\n Enter Record number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("file.txt", ios::out|ios::binary);
    infile.seekg(0);
    for(int i = 0; i < c; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i == (n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("withdraw.txt");
    rename("file.txt", "withdraw.txt");
}

