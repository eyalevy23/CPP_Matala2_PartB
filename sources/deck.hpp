#ifndef DECK_HPP
#define DECK_HPP

#include "card.hpp"
#include <vector>

namespace ariel{

    class Deck{
        std::vector<Card> cards;

    public:
        Deck();
        void initDeck();
        Card draw();
    };

}

#endif