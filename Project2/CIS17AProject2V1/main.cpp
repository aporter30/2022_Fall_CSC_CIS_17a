/* 
 * File:   main.cpp
 * Author: Alejandro Porter
 * Created on Oct 24, 2022, 10:22 AM
 * Purpose: Project 2 - Version 1 - CandyLand
 */

//System Libraries - ALL HAVE TO BE USED
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>  //File Input------------used
using namespace std;

#include "Game.h"
#include "Players.h"

bool openFile(fstream &, string);
void showcont(fstream &);
void dsplyhd();     //Display Heading

//Execution starts here
int main(int argc, char** argv){
    //Declare Variables
    int plays;
    int c;
    bool vp = false;
    fstream myFile;
    //Display welcome message
    cout<<"-----  ---  \\     | |\\  \\     /  |      ---  \\     | |\\ "<<endl;
    cout<<"|     |   | |\\    | | \\  \\   /   |     |   | |\\    | | \\ "<<endl;
    cout<<"|     |   | | \\   | |  \\  \\ /    |     |   | | \\   | |  \\ "<<endl;
    cout<<"|     |---| |  \\  | |  /   |     |     |---| |  \\  | |  / "<<endl;
    cout<<"|     |   | |   \\ | | /    |     |     |   | |   \\ | | / "<<endl;
    cout<<"|____ |   | |    \\| |/     |     |____ |   | |    \\| |/ "<<endl;
    cout<<"Welcome to the game of Candyland!"<<endl;
    //Display heading function
    dsplyhd();
    if(openFile(myFile, "M1GameRules.txt")){
        //Display Game Rules
        showcont(myFile);
        myFile.close();
    }
    else{
        cout<<"Could not open file!";
        exit(0);
    }
    //Starting game
    while(!vp){
        cout<<"How many players? Please enter a value between 2-4"<<endl;
        cin>>plays;
        //input validation
        if (!plays){
            cin.clear ();
            cin.ignore (10000, '\n');
            cout<< "Sorry, invalid input. Please enter a numerical value\n";
        }
        else if(plays<2||plays>4){
            cout<<"Sorry,value is out of range"<<endl;
        }       
        else{
            vp = true;
            break;
        }
    }
    cout << "players: " << plays << endl;
    Game game(plays);
    //flush buffered data
    fflush( stdout );
    do c = getchar(); while ((c != '\n') && (c != EOF));
    cout<<endl;
    while(!game.getWinnerPlayer()){
        game.playerTurn();
    }
    //Exit stage right
    return 0;
}
//Display Heading Function
void dsplyhd(){
    //PROMPT USER TO PRESS ENTER TO START GAME
    cout<<"\nObjective: Be the first player to reach the Candy Castle by "
            "making it to end of the path.\n\n";
    cout<<"Contents: 1 Colorful Gameboard with 130 spaces\n";
    cout<<setw(42)<<"1-4 Gingerbread Character Pawns\n";
    cout<<setw(80)<<"1 Deck of Cards Colored Red, Orange, Yellow, Green, Blue, and Purple\n\n";
    cout<<"Game Rules: When you draw a card with one color block (single), move your pawn\n";
    cout<<setw(78)<<" towards the castle to the first matching color space on the path.\n";
    cout<<setw(80)<<"When you draw a card with two color blocks (double), move your pawn\n";
    cout<<setw(80)<<"towards the castle to the second matching color space on the path.\n\n";
}
//Opening File Function
bool openFile(fstream &file, string name){
    file.open(name, ios::in);
    if(file.fail()){
        return false;
    }
    else{
        return true;
    }
}
//Displaying File Function
void showcont(fstream &file){
    string line;
    while(getline(file, line)){
        cout<<line<<endl;
    }
}
