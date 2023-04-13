#include <string>
#pragma once 
#include "card.hpp"
#include <vector>
using namespace std; 
namespace ariel{
class Player {
    public:
    int stackSize; 
    int cardsTaken; 
    string name;
    vector<Card>cards;  
    vector<Card>playerCard; 
    
    // Player(string name){
    //     this->stackSize=0; 
    //     this->cardsTaken=0; 
    //     this->name=name; 
    // }
    Player(string name); 
    int stacksize(); 
    int cardesTaken(); 
    void addCardToPlayer(Card card); 
    void removePlayerCard(); 
    void AddCardsTaken(); 
    Card GetPlayerCard(); 



};
}