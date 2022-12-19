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

// Candy is a class for different types of candies
class Candy {
    protected:
        string flavor_;  // protected member variable
    public:
        Candy(string flavor) : flavor_(flavor) {}
        virtual float getPrice() = 0;  // pure virtual function
        string getFlavor() const { return flavor_; }  // public member function
};

// Derived class for hard candies
class HardCandy : public Candy {
    public:
        HardCandy(string flavor, float pricePerPound) : Candy(flavor), pricePerPound_(pricePerPound) {}
        float getPrice() {      //override
            return pricePerPound_;
        }
    private:
        float pricePerPound_;
};

// Derived class for chocolate candies
class ChocolateCandy : public Candy {
    public:
        ChocolateCandy(string flavor, float pricePerPound, float cocoaPercentage)
            : Candy(flavor), pricePerPound_(pricePerPound), cocoaPercentage_(cocoaPercentage) {}
        float getPrice() {
        return pricePerPound_ + 0.1 * cocoaPercentage_;
    }
    private:
        float pricePerPound_;
        float cocoaPercentage_;
};
#endif /* GAME_H */
