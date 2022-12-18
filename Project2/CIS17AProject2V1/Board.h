#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <iterator>
#include <string>
#include "Deck.h"
using namespace std;

class Board {
    public:
        Board();
        virtual ~Board();
        void setSpecialCards();
        void setBoard();
        void outputBoard();
        int getboardSize();
        int getCastleDistance(int location);
        int getLocation(string card, int prevLocation, string);
        bool ifSpecialCard(string card);
        bool winner(string, int);
        int doub(string, int);
        int sing(string, int);
    private:
        int boardSize;  //how many spaces there are on the board
        string board[134];    //holds the varying positions on the board
        int castleDistance; //subtracts the players
        string colors[6];   //colors for cards
        map<string, int>specialCards;
        int location;
};

#endif /* BOARD_H */
