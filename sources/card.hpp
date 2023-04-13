#include <iostream>
#pragma once 
using namespace std; 


enum number{
    Ace,Jack,Queen,King,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten  
};
enum shape{
    Hearts,Diamonds,Spades,Clubs
};

namespace ariel{
    class Card {
     int shape; 
     int number;
     public:
     Card(int shape =0, int number =0); 
     int getShape(); 
     int getNumber(); 
     string toString(); 


     };


}
