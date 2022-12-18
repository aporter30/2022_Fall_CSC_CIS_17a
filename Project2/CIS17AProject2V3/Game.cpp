/*
 /* 
 * File:   Game.cpp
 * Author: ajporter
 * 
 * Created on December 17, 2022, 8:56 PM
 */

#include "Game.h"

Game::Game(int numberOfPlayers) {
    winnerPlayer=false;
    initGame(numberOfPlayers);
}

Game::~Game() {
    delete[] players;
    delete[] availableColors;
}

//determine player turn
void Game::playerTurn(){
    outOfCards();
    if(turn==numberOfPlayers){
        turn = 0;
    }
    cout<<"Pick a card for player "<<players[turn].getPlayer()<<endl;
    cout<<"---------------------------------------------------------";
    pressAnyKey();
    this->card = deck.getCard();
    if(board.ifSpecialCard(card)){
        cardColor = card;
    }
    else{
        convertCardColor();
        dos();
    }
    players[turn].setLocationColor(cardColor);
    players[turn].setLocationNumber(board.getLocation(cardColor, players[turn].getLocationNum(), doubleOrSingle));
    //If winner is true
    if(winner()){
        cout<<"Card: "<<card<<endl;
        cout<<"Congratulations Player "<<players[turn].getPlayer()<<" you have won!"<<endl;
        winnerPlayer=true;
    }
    else{
        outputTurn();
    }
    this->turn++;
}

bool Game::winner(){
    int location = players[turn].getLocationNum();
    //win condition
    if(board.getCastleDistance(location)== 0 || board.getCastleDistance(location)< 0){
        return true;
    }
    else{
        return false;
    }
}

void Game::initGame(int numberOfPlayers){
    board.setBoard();
    turn = 0;
    winnerPlayer=false;
    this->numberOfPlayers = numberOfPlayers;
    this->colorsAvailable = 4;
    this->availableColors = new string[colorsAvailable];
    availableColors[0] = "Red";
    availableColors[1] = "Blue";
    availableColors[2] = "Green";
    availableColors[3] = "Yellow";
    players = new Players[numberOfPlayers];
    for(int i=0; i<numberOfPlayers; i++){
        players[i].setActivePlayer(colorsAvailable, availableColors);
        colorsAvailable--;
        removeColor(players[i].getColorTaken(), players[i].getPlayerVal());
    }
}

void Game::outOfCards(){
    deck.ifEmpty();
}

void Game::outputTurn(){
    cout<<"Card: "<<card<<endl;
    cout<<"Distance from castle: "<<board.getCastleDistance(players[turn].getLocationNum())<<endl;
    cout<<"---------------------------------------------------------\n";
    cout<<"\n\n\n";
}

//When choosing Player color
void Game::removeColor(string color, int location){
    string *newArray = new string[colorsAvailable];
    for(int i=0; i<location; i++){
        newArray[i] = availableColors[i];
    }
    for(int i=location; i<colorsAvailable; i++){
        newArray[i] = availableColors[i+1];
    }
    //deallocate
    delete[] availableColors;
    this->availableColors = new string[colorsAvailable];
    for(int i=0; i<colorsAvailable; i++){
        availableColors[i] = newArray[i];
    }
    //deallocate
    delete[] newArray;
}

bool Game::getWinnerPlayer(){
    return winnerPlayer;
}

void Game::convertCardColor(){
    string colors[6];
    colors[0] = "Red";
    colors[1] = "Purple";
    colors[2] = "Blue";
    colors[3] = "Yellow";
    colors[4] = "Green";
    colors[5] = "Orange";
    size_t found = card.find(colors[0]); 
    if (found != string::npos){
        cardColor = colors[0];
    }  
    found = card.find(colors[1]); 
    if (found != string::npos){
        cardColor = colors[1];
    }
    found = card.find(colors[2]); 
    if (found != string::npos){
        cardColor = colors[2];
    }   
    found = card.find(colors[3]); 
    if (found != string::npos){
        cardColor = colors[3];
    }
    found = card.find(colors[4]); 
    if (found != string::npos){
        cardColor = colors[4];
    }
    found = card.find(colors[5]); 
    if (found != string::npos){
        cardColor = colors[5];
    }
}

void Game::pressAnyKey(){
  int c;
  printf( "Press ENTER to continue... " );
  fflush( stdout );
  do c = getchar(); while ((c != '\n') && (c != EOF));
}

void Game::dos(){
    string value[2];
    value[0] = "Double";
    value[1] = "Single";

    size_t found = card.find(value[0]); 
    if (found != string::npos){
        doubleOrSingle = value[0];
    }
    
    found = card.find(value[1]); 
    if (found != string::npos){
        doubleOrSingle = value[1];
    }
}
