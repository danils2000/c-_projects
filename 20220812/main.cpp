#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Game {
private:
    void generate_computer_choise();
    void show_choises();
    void results();
    int random;
    char computer_parametr;
public: 
    Game(int);
    ~Game();
    void menu();
    char user_parametr;
    void user_choise();
};

Game::Game(int a) {
    this -> user_parametr = a;
}

Game::~Game() {

}

void Game::user_choise() {
    cout << "Choose your option: " << endl << "(r): rock" << endl << "(p): paper" << endl << "(s): scissors" << endl;
    cout << "Your option: ";
    cin >> user_parametr;

    while (user_parametr!='r' && user_parametr!='p' && user_parametr!='s' ) {
        cout << "Please enter one of the following options only. " << endl;
        cout << "(r): rock" << endl << "(p): paper" << endl << "(s): scissors" << endl;
        cout << "Your option: ";
        cin >> user_parametr;
    }
    return generate_computer_choise();
}

void Game::generate_computer_choise() {
    srand(time(0));
    random = rand() % 3 + 1; 
    if (random == 1) {
        computer_parametr = 'r';
    }
    if (random == 2) {
        computer_parametr = 'p';
    }
    if (random == 3) {
        computer_parametr = 's';
    }
    return show_choises();
}

void Game::show_choises() {
    cout << "User: " << user_parametr << endl;
    cout << "Computer: " << computer_parametr << endl;
    return results();
}

void Game::results() {
    if (user_parametr == 'r' && computer_parametr == 'p') {
        cout << "Computer Wins!"<< endl;
    }
    else if (user_parametr == 'p' && computer_parametr == 's') {
        cout << "Computer Wins!"<< endl; 
    }
    else if (user_parametr == 's' && computer_parametr == 'r') {
        cout << "Computer Wins!"<< endl;
    }
    else if (user_parametr == computer_parametr) {
        cout << "Tie!"<< endl;
    }
    else {
        cout << "You Win!"<< endl; 
    }
}

int menu() {
    int menu_choise;
    cout << "Game menu" << endl;
    cout << "Type option:" << endl;
    cout << "1. Play" << endl;
    cout << "2. Exit" << endl;
    cout << "Your option: ";
    cin >> menu_choise;

    return menu_choise;
}

int main() {
    int menu_choise = menu();
    Game game(menu_choise);

    switch(menu_choise) {
        case 1:
            game.user_choise();
        case 2:
            return 0;
        default:
            cout << "ONLY 1 OR 2" << endl;
            menu();
    }
};
