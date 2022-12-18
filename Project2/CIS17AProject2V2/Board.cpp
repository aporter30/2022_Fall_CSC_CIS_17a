#include "Board.h"

Board::Board(){
    location = 0;
    boardSize = 130;
}

Board::~Board(){}

void Board::setSpecialCards(){
    specialCards.insert(pair<string, int>("Mr. Peppermint", 8));
    specialCards.insert(pair<string, int>("Mr. Mint",19));
    specialCards.insert(pair<string, int>("Grandma Toffee",68));
    specialCards.insert(pair<string, int>("Frosty Queen", 101));
    specialCards.insert(pair<string, int>("Jolly Prince", 41));
    specialCards.insert(pair<string, int>("Princess Lollypop", 91));
}

void Board::setBoard(){
    setSpecialCards();
    colors[0] = "Red";
    colors[1] = "Purple";
    colors[2] = "Yellow";
    colors[3] = "Blue";
    colors[4] = "Orange";
    colors[5] = "Green";
    int colorCount =0;
    for(int i=0; i<boardSize; i++){
        board[i] = "";
    }
    for(int i=0; i<boardSize; i++){
        map<string, int>::iterator itr; 
        for (itr = specialCards.begin(); itr != specialCards.end(); ++itr) { 
            if(itr->second == i){
                board[i] = itr->first;
            }
        }
        if(board[i] == ""){
            board[i] = colors[colorCount];
            colorCount++;
            if(colorCount == 6){
                colorCount = 0;
            }
        }      
    }
}

void Board::outputBoard()
{
    for(int i=0; i<boardSize; i++)
    {
        cout<<board[i]<<endl;
    }
}


int Board::getboardSize()
{
    return boardSize;
}

int Board::getLocation(string card, int prevLocation, string doubleOrSingle)
{
    //cout<<"Previous Location: "<<prevLocation<<endl;
    int location = 0; 
    if(winner(card, prevLocation)&& !ifSpecialCard(card))
    {
        //since there are 134 spots on the board
        location = 133;
        return location;
    }
    if(ifSpecialCard(card))
    {
        location = this->location;
    }
    
    else
    {
        if(doubleOrSingle == "Double")
        {
            location = doub(card, prevLocation);
        }
        if(doubleOrSingle == "Single")
        {
            location = sing(card, prevLocation);
        }
    }
    
    return location;
}

int Board::getCastleDistance(int location)
{
    return (boardSize-1)-location;
}

bool Board::ifSpecialCard(string card){
    map<string, int>::iterator itr; 
    for (itr = specialCards.begin(); itr != specialCards.end(); ++itr) { 
        if(itr->first == card)
        {
            location = itr->second;
            return true;
        }
    }
    
    return false;
}

bool Board::winner(string card, int prevLocation){
    //for win condition
    bool win = true;       
    for(int i=prevLocation; i<boardSize; i++){ 
        if(board[i] == card){
            win = false;
            break;
        }
    }
    return win;
}

int Board::doub(string card, int prevLocation){
    int location1 = 0;
    int count = 0;
    for(int i=prevLocation+1; i<boardSize; i++){
        if(card == board[i]){
            location1 = i;
            break;
        }
    }   
    for(int i=location1+1; i<boardSize; i++){
        if(card == board[i]){
            location1 = i;
            break;
        }
    }
    return location1;
}

int Board::sing(string card, int prevLocation){
    int location1 = 0;
    for(int i=prevLocation+1; i<boardSize; i++){
            if(card == board[i]){
                location1 = i;
                break;
            }
        }
    return location1;
}
