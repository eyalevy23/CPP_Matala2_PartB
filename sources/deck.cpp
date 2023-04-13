
#include "deck.hpp"
#include "card.hpp"
#include <random>

using namespace std;

namespace ariel{
    Deck::Deck(){
        this->cards = vector<Card>();
        initDeck();
    }

    void Deck::initDeck(){
        for(int i = 1; i <= 13; i++){
            for(int j = 0; j < 4; j++){
                this->cards.push_back(Card(i, j));
            }
        }
    }

    Card Deck::draw(){
        int deckSize = this->cards.size();
        int randomIndex = rand() % deckSize;
        Card card = this->cards[static_cast<std::vector<Card>::size_type>(randomIndex)];
        this->cards.erase(this->cards.begin() + randomIndex);
        return card;
    }


}