#include "card.hpp"



using namespace std;

namespace ariel{

    // dictionary --> int to suits  {
    //     0 : "clubs",
    //     1 : "diamonds",
    //     2 : "spades"
    //     3 : "hearts" ,  
    // }
    Card::Card(int value, int suits){
        this->value = value; // int between 1-13
        this->suits = suits; //int between 0-3
    }



};