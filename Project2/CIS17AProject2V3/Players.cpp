/* 
 * File:   players.cpp
 * Author: Alejandro Porter
 * Created on Oct 24, 2022, 10:22 AM
 * Purpose: Project 2 - Version 3 - CandyLand
 */

#include "Players.h"

Players::Players() {}


void Players::setActivePlayer(int colorsAvailable, string *availableColors){
    this->colorsAvailable = colorsAvailable;
    this->availableColors = new string[colorsAvailable];
    for(int i=0; i<colorsAvailable; i++){
        this->availableColors[i] = availableColors[i];
    }
    int input = 0;
    cout<<"Choose a color:"<<endl;
    for(int i=0; i<colorsAvailable; i++){
        cout<<i+1<<". "<<availableColors[i]<<endl;
    }
    cin>>input;
    bool valid_input;
    valid_input = input;
    if (!valid_input){
        cin.clear();
        cin.ignore (10000, '\n');
        cout<< "Sorry, invalid input. Please enter a numerical value\n";
        cout<<"A default color was assigned"<<endl;
        input = 1;
    }
    if(input<1||input>4)
    {
        cout<<"Sorry,value is out of range"<<endl;
        cout<<"A default color was assigned"<<endl;
        input = 1;
    }
    colorTaken = availableColors[input-1];
    playerCol = input-1;
    setPlayer(colorTaken);
}

void Players::setPlayer(string player)
{
    this->player = player;
    this->locationCol = "Red";
    this->locationNum = 0;
    location.insert(pair<string, int>(locationCol, locationNum));
}

void Players::setLocationColor(string location)
{
    this->locationCol = location;
}

void Players::setLocation()
{
    location.insert(pair<string, int>(locationCol, locationNum));
}

void Players::setLocationNumber(int location)
{
    this->locationNum = location;
}

string Players::getColorTaken()
{
    return colorTaken;
}

int Players::getLocationNum()
{
    return locationNum;
}

string Players::getLocationCol()
{
    return locationCol;
}
string Players::getPlayer()
{
    return player;
}

Players::~Players()
{
    delete[] availableColors;
}
int Players::getPlayerVal()
{
    return playerCol;
}
