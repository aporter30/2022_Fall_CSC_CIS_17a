#include "Deck.h"

Deck::Deck() {
    fillDeck();
    reshuffle();
}

void Deck::fillDeck(){
    for(int i=0; i<6; i++){
       ogDeck.push_back("Single Red");
       ogDeck.push_back("Single Orange");
       ogDeck.push_back("Single Yellow");
       ogDeck.push_back("Single Green");
       ogDeck.push_back("Single Blue");
       ogDeck.push_back("Single Purple");
    }
    //double space card
    for(int i=0; i<4; i++){
       ogDeck.push_back("Double Red");
       ogDeck.push_back("Double Orange");
       ogDeck.push_back("Double Yellow");
       ogDeck.push_back("Double Green");
       ogDeck.push_back("Double Blue");
       ogDeck.push_back("Double Purple");
    }
    //specialty cards
    ogDeck.push_back("Mr. Peppermint");
    ogDeck.push_back("Mr. Mint");
    ogDeck.push_back("Grandma Toffee");
    ogDeck.push_back("Frosty Queen");
    ogDeck.push_back("Jolly Prince");
    ogDeck.push_back("Princess Lolly");
    //how many cards are in the deck
    this->deckSize = ogDeck.size();
}

void Deck::reshuffle(){
    srand(static_cast<unsigned int>(time(0)));
    //shuffle
    random_shuffle(ogDeck.begin(), ogDeck.end());
    //copy the values over into a queue
    for(int i=0; i<deckSize; i++){
        shuffledDeck.push(ogDeck.front());
        ogDeck.pop_front();
    }
    fillDeck();   
}

void Deck::ifEmpty(){
    if(shuffledDeck.size() == 0){
        reshuffle();
    }
}

int Deck::getDeckSize(){
    return shuffledDeck.size();
}

string Deck::getCard(){
    string card = shuffledDeck.front();
    shuffledDeck.pop();
    return card;
}

void Deck::outputMove(string card){
    cout<<card<<endl;
}
