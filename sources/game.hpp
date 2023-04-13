#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <iostream>
#include "player.hpp"

namespace ariel{

    class Game{
        Player &p1;
        Player &p2;

    public:
        Game(Player &p1, Player &p2);
        void reset();
        void playTurn();
        void printWiner();
        void printStats();
        void printLog();
        void playAll();
        void printLastTurn();
        string logStringMessage(int winner);

    private:
        int highestCard(Card &card1, Card &card2);
        vector<Card> sideCards;
        vector<string> logString;
        void giveCardsToWinner(Player winner);
        void setMaps();
        map<int, string> suitsMap;
        map<int, string> valueMap;
    };

}

#endif