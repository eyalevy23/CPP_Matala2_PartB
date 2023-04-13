#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <iostream>
#include "card.hpp"
using namespace std;

namespace ariel{

    class Player{
        
        

    public:
        Player(string name);
        int cardsWon;
        int win;
        string name;     
        vector<Card> myCards;
        int stacksize();
        int cardesTaken();
        void addCard(Card card);
        Card getCard();
        Card lastCard;
    };

  
  

}



#endif