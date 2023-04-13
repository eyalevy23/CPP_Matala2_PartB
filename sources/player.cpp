#include "player.hpp"
#include "card.hpp"
#include <string>
#include <vector>


namespace ariel{
    
    Player::Player(std::string name) : name(name), myCards(vector<Card>()), lastCard(Card(0,0))
    {
        this->name = name;
        this->myCards = vector<Card>();
        this->lastCard = Card(0,0);
        this->cardsWon = 0;
        this->win=0;
    }

    void Player :: addCard(Card card) {
        this->myCards.push_back(card);
    }
    
    Card Player :: getCard() {
        Card card = this->myCards.back();
        this->myCards.pop_back();
        this->lastCard = card;
        return card;
    }

    int Player :: stacksize() {
        cout << this->myCards.size() << endl;
        } 



    int Player :: cardesTaken() {
        cout << this->cardsWon << endl;
    }
};