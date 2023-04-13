#ifndef DECK_HPP
#define DECK_HPP

// #include "deck.hpp"

namespace ariel{

    class Deck{
        vector<Card> cards;

    public:
        Deck();
        void initDeck();
        Card draw();
    };

}

#endif