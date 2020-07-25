/******************************************************************************
DANIL SISOV
GUEESS NUMBER GAME
2K20
                          
*******************************************************************************/
#include <iostream>
#include <string> // for using string


class game : public start {
    private:
        int sum;              //sum of money
        std::string playerName;    //player name
        int user_num;         // user choice from 1 to 10
        int bet;              // bet amount
        int random;           // random number
        char choice;          // choice in the end to continue or end of the game

    public:
        void start();
        void deposit();
        void startPlay_logo();
        void startPlay();
        void again();
        void end();
};
