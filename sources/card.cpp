#include "card.hpp"
using namespace std; 

namespace ariel{
    Card::Card(int shape, int number){
    this->shape=shape; 
    this->number=number; 

}
string Card::toString(){
    string num, shapee; 
    switch(this->number){
    case King:
        num = "king"; 
        break;
    case Queen:
        num="Queen"; 
        break;
    case Jack:
        num="Jack"; 
    case Ace : 
        num="Ace"; 

    }
    switch(this->shape){
        case Clubs:
        shapee = "Clubs"; 
        break;
    case Diamonds:
        shapee="Diiamonds"; 
        break;
    case Hearts:
        shapee="Hearts"; 
    case Spades : 
        shapee="Spades"; 

    }
    return (num +"of"+shapee); 
}
int Card::getShape(){
    return this->shape; 
}
int Card::getNumber(){
    return this->number; 
}


}


