#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>

namespace ariel{

    class Card{
        

    public:
        int value;
        int suits;
        Card(int val, int suits); // Constructor defined
        int highestCard(const Card & card2) const;
    }; // Semicolon added after the class definition

}


#endif