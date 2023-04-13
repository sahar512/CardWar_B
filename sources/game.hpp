#include "player.hpp"
#include <iostream>
#include "card.hpp"
#include <vector>
using namespace std; 

namespace ariel{
    class Game {
        private :
        Player& p1;
        Player& p2; 
        string log; 
        string LastTurn; 
        double TurnsNum;
        double P1turnswon; 
        double P2turnswon;   
        double DrowsNum; 
        vector<Card> cards; 

        public:
        Game(Player& player1, Player& player2); 
        void playTurn(); 
        void printLastTurn();
        void playAll();
        void printWiner(); 
        void printLog(); 
        void printStats();  
    };
    //ariel::Game::Game (Player p1 , Player p2 ) {}

}
