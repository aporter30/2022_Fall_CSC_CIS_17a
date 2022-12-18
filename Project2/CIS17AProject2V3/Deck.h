/* 
 * File:   Deck.h
 * Author: ajporter
 *
 * Created on December 17, 2022, 2:42 PM
 */

#ifndef DECK_H
#define DECK_H

#include <map>
#include <ctime>
#include <queue>
#include <iostream>
#include <deque>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;

#include "Players.h"

class Deck {
    private:
        int deckSize;   //how many cards in deck
        deque<string> ogDeck;
        queue<string> shuffledDeck;
    public:
        Deck();
        void reshuffle();
        void fillDeck();
        void ifEmpty();
        int getDeckSize();
        string getCard(); 
        void outputMove(string card);
};
#endif /* DECK_H */
