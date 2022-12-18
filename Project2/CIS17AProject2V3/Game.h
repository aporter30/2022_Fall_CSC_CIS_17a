/* 
 * File:   Game.h
 * Author: ajporter
 *
 * Created on December 17, 2022, 2:42 PM
 */

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Deck.h"
#include "Players.h"
#include <string>
#include <stdio.h>
using namespace std;

class Game {
    private:
        int turn; 
        int numberOfPlayers;
        Players* players; //holds the players who are active
        Deck deck;
        string card;
        string cardColor;
        Board board;
        bool winnerPlayer;
        int colorsAvailable;
        string* availableColors;
        string doubleOrSingle;
    public:
        Game(int);
        virtual ~Game();
        void initGame(int);
        void playerTurn();    //play true each turn
        void outOfCards(); //reshuffle the cards
        void outputTurn();
        bool winner();
        void removeColor(string, int);
        bool getWinnerPlayer();
        void convertCardColor();
        void pressAnyKey();
        void dos();
};

#endif /* GAME_H */
