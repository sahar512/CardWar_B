#include "stdio.h" 
#include "game.hpp"
#include "player.hpp"
#include <iostream> 
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
using namespace std; 

namespace ariel{


 Game::Game (Player& player1 , Player& player2 ): p1(player1), p2(player2) {
    TurnsNum=0; 
    DrowsNum=0; 
    P1turnswon=0; 
    P2turnswon=0; 
    // creat the cards 
    for(int i=0; i <=13; i++){
        cards.push_back(Card((number)i,Clubs));
        cards.push_back(Card((number)i,Hearts));
        cards.push_back(Card((number)i,Diamonds));
        cards.push_back(Card((number)i,Spades));
    }
    //shuffel the cards 
    shuffle(cards.begin(), cards.end(), default_random_engine((unsigned)time(NULL))); 
    //give the cards to the players
    for( int i=0; i<26; i++){
        player1.addCardToPlayer(cards[(unsigned int)i]); 
        player2.addCardToPlayer(cards[(unsigned int)i]); 
    }

}

 //play one turn.
 void Game::playTurn() {
    if(&p1==&p2){
        throw invalid_argument ("cant play with the same player!!"); 
    }
    if(p1.stacksize()==0){
        throw invalid_argument ("the game is over!!");
    }

    Card p1C=p1.GetPlayerCard(); 
    Card p2C=p2.GetPlayerCard(); 
    p1.removePlayerCard(); 
    p2.removePlayerCard(); 
    int CardsOn =2; 
    //this->LastTurn=
    while(p1C.getNumber()==p2C.getNumber()){
        this->DrowsNum++; 
        this->LastTurn +="Draw"; 
        if(p1.stacksize()<2 ||p2.stacksize()<2){
            while(CardsOn !=0){
                p1.AddCardsTaken(); 
                p2.AddCardsTaken(); 
                CardsOn -=2; 
            }
            break;

        }
        p1.removePlayerCard(); 
        p2.removePlayerCard(); 
        //play new cards 
        Card p1C=p1.GetPlayerCard(); 
        Card p2C=p2.GetPlayerCard(); 
        p1.removePlayerCard(); 
        p2.removePlayerCard(); 
        CardsOn+=4; 
        if(p1C.getNumber()>p2C.getNumber()){
            P1turnswon++; 
        
        while(CardsOn!=0){
            p1.AddCardsTaken(); 
            CardsOn--; 
        }
        }
        
        else if(p1C.getNumber()<p2C.getNumber()){
            P2turnswon++; 
            while(CardsOn!=0){
            p2.AddCardsTaken(); 
            CardsOn--; 
        }
        }
        else{
            this->DrowsNum++; 
            this->LastTurn+="Draw"; 
        }

        // string TheWinnerIs=""; 
        // if(p1C.getNumber()>p2C.getNumber()){
        //     if(p1C.getNumber()==1 && p2C.getNumber()!=2){
        //     TheWinnerIs = "player1"; 
        //     P1turnswon++; 
        //     }
        //     else{
        //         TheWinnerIs ="player2"; 
        //         P2turnswon++; 
        //     }

        // }
        // else {
        //     if(p2C.getNumber()==1 && p1C.getNumber()!=2){
        //         TheWinnerIs ="player2"; 
        //         P2turnswon++; 
        //     }
        //     else{
        //         TheWinnerIs = "player1"; 
        //         P1turnswon++; 

        //     }


        // }




    }

    
}

 // print the last turn stats.
 void Game::printLastTurn(){
    cout<<LastTurn<<endl; 
}

 // play the game untill the end. 
 void Game::playAll(){
    while ( p1.stacksize() !=0 && p2.stacksize() !=0){
        playTurn(); 
    }
}

 //print the name of the winnig player. 
 void Game::printWiner(){
    if(p1.cardesTaken()-p2.cardesTaken()==0){
        cout << "Tie!!, no one wins"<< endl ; 
    }
    else if(p1.cardesTaken()-p2.cardesTaken()>0){
        cout << "player1 wins the game"<< endl; 
    }
    else{
        cout << "player2 wins the game" << endl;  
    }
}

 //prints all the turns played one line per turn. 
 void Game::printLog(){
    cout << log << endl; 
}

 //for each player prints basic statistics: 
 //win rate, cards won, <other stats you want to print>. 
 //Also print the draw rate and amount of draws that happand. 
 void Game::printStats(){
    cout <<"Cards won :"<< endl;
    cout <<"player1:"<<p1.cardesTaken()<< endl; 
    cout <<"player2:"<<p2.cardesTaken()<<endl; 
    cout <<"Won rate:"<< endl; 
    cout <<"player1:"<<(P1turnswon)/(TurnsNum)<<endl; 
    cout <<"player2:"<<(P2turnswon)/(TurnsNum)<<endl;  
    cout <<"Total Draws:"<<DrowsNum<<endl; 
    cout <<"Draw rate : "<< (DrowsNum)/(TurnsNum)<<endl; 
}
}