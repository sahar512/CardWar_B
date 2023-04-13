#include "player.hpp"
using namespace std; 
namespace ariel{
Player::Player (string name):name(std::move(name)){
    cardsTaken=0;
    stackSize=0; 
}    
int Player::stacksize(){
    return this->stackSize; 
}
int Player::cardesTaken(){
    return this->cardsTaken; 
}
void Player::addCardToPlayer(Card card){
    cards.push_back(card); 
}
void Player::removePlayerCard(){
    this->playerCard.pop_back(); 
}
Card Player::GetPlayerCard(){
    playerCard.pop_back(); 
    return playerCard.back(); 
}
void Player::AddCardsTaken(){
    this->cardsTaken++; 
}}
