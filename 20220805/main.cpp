#include <iostream>  
using namespace std; 

class Game {
    private:
        int menuChoise = 0, userInput = 0, row = 0, column = 0;
        char turn = 'X';
        char board[3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
        bool check();
        void playerTurn();
    public:
        void displayBoard();
        void menu();
};

void Game::menu() {
    cout << "Menu" << "\n" << "Options: 1-2" << "\n";
    cout << "1. VS Real player" << "\n" << "2. Exit" << "\n";

    cout << "Choise: ";
    cin >> menuChoise;

    switch(menuChoise) {
        case 1:
            cout << "Player1 = (X)"  << "\n";
            cout << "Player2 = (O)" << "\n\n";
            displayBoard();
            return playerTurn();
        case 2: 
            return;
        default:
            cout << "Wrong Input" << "\n";
    }
}

void Game::displayBoard() {
    cout << "     |     |     " << "\n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";

    cout << "_____|_____|_____" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";

    cout << "_____|_____|_____" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2]<< "\n";

    cout << "     |     |     " << "\n" << "\n";
}

void Game::playerTurn() {
    if (turn == 'X') {
        cout << "1 Player move: ";
    }
    else if (turn == 'O') {
        cout << "2 Player move: ";
    }

    cin >> userInput;

    switch (userInput) {
    case 1:
        row = 0; column = 0;
        break;
    case 2:
        row = 0; column = 1;
        break;
    case 3:
        row = 0; column = 2;
        break;
    case 4:
        row = 1; column = 0;
        break;
    case 5:
        row = 1; column = 1;
        break;
    case 6:
        row = 1; column = 2;
        break;
    case 7:
        row = 2; column = 0;
        break;
    case 8:
        row = 2; column = 1;
        break;
    case 9:
        row = 2; column = 2;
        break;
    default:
        cout << "Wrong Input" << "\n";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'X';
        turn = 'O';
    } 
    else if (turn == 'O' && board[row][column] != 'O' && board[row][column] != 'X') {
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        cout << "Square is already used" << '\n'; 
        playerTurn();
    }

    if(check()) {
        displayBoard();
        playerTurn();
    }
    else {
        if(turn == 'X') {
            cout << "Player 1 wins" << endl;
        }
        else {
            cout << "Player 2 wins" << endl;
        }
        
        displayBoard();
        menu();
    }
 }

bool Game::check() {
    for (int i = 0; i < 3; i++) {
        //rows and columns
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false;
        }
        //Diagonal
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return false;
        }
    }
    return true;
}

int main() {
    Game test;

    cout << "\t" << "Tic-tac-toe Game" << "\n";

    test.menu();
}
