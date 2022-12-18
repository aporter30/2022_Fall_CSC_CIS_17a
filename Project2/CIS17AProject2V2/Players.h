/* 
 * File:   Players.h
 * Author: ajporter
 *
 * Created on December 17, 2022, 2:42 PM
 */

#ifndef PLAYERS_H
#define PLAYERS_H

#include <stack>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>


using namespace std;

class Players {
    private:
        string player;    //holds the player color and its respective number
        map<string, int> location;  //holds the player and their location on the board
        stack<string> colorPosition;
        string* availableColors;
        int colorsAvailable;
        string colorTaken;
        int locationNum;
        string locationCol;
        int playerCol;
    public:
        Players();
        ~Players();
        void setLocationNumber(int location);
        void setLocationColor(string color);
        void setLocation();
        int getLocationNum();
        string getLocationCol(); //returns the color of the position
        void setPlayer(string);
        string getPlayer();
        //int getPlayer();
        void setActivePlayer(int, string*);
        string getColorTaken();
        int getPlayerVal(); 
//        friend void Game::removeColor(string,int);
};

#endif /* PLAYERS_H */
