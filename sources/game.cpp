#include "player.hpp"
#include "card.hpp"
#include "game.hpp"
#include "deck.hpp"
#include <vector>
#include <string>
#include <map>

namespace ariel{

    Game::Game(Player &p1, Player &p2) : p1(p1), p2(p2)
    {
        this->p1 = p1;
        this->p2 = p2;
        reset();
        setMaps();
        this->turns = 0;
        this->isGameOver = false;

    }

    void Game:: reset() {
        this->logString.clear();
        this->sideCards.clear();
        Deck deck = Deck();
        for(int i = 0; i < 26; i++){
            this->p1.addCard(deck.draw());
            this->p2.addCard(deck.draw());
        }
        this->isGameOver = false;
        this->turns = 0;

    }

    void Game :: playTurn() {
        // cout << "play turn  : "<<this->turns << endl;
        if(this->isGameOver == true){
            throw std::runtime_error ("Game is over!");
        }

        if (this->p1.name == this->p2.name)
        {
            throw std::runtime_error ("Player can't play against himself!");
        }
        if(this->turns == 26){
            cout << "Game is over! throh error by me" << endl;
            p1.myCards.clear();
            p2.myCards.clear();
            throw std::runtime_error ("Game is over!");
        }
        if(this->p1.myCards.empty() || this->p2.myCards.empty()){
            throw std::runtime_error ("Game is over!");
        };
        Card card1 = this->p1.getCard();
        Card card2 = this->p2.getCard();
        
        int winner = highestCard(card1, card2);
        if(winner == 1){
            this->p1.addCard(card1);
            this->p1.addCard(card2);
            this->p1.cardsWon += 2 + this->sideCards.size();
            this->p1.win++;
            giveCardsToWinner(this->p1);
        } else if (winner == -1){
            this->p2.addCard(card1);
            this->p2.addCard(card2);
            this->p2.cardsWon += 2 + this->sideCards.size();
            this->p2.win++;
            giveCardsToWinner(this->p2);
        } else {
            this->sideCards.push_back(card1);
            this->sideCards.push_back(card2);
        }
        this->turns++;
        string message = logStringMessage(winner);
        logString.push_back(message);
    }
    void Game :: printWiner() {
        string winner;
        if (p1.cardesTaken() > p2.cardesTaken())
        {
            winner += "The winner is " + p1.name;
        }
        else if (p1.cardesTaken() < p2.cardesTaken())
        {
            winner += "The winner is " + p2.name;
        }
        else
        {
            winner += "Draw!, there is no winner";
        }
        cout << winner << endl;
    }
    void Game :: printStats() {
        cout <<p1.name<< " has " << this->p1.stacksize() << " cards" << endl;
        cout <<p2.name<< " has " << this->p2.stacksize() << " cards" << endl;
    }
    void Game :: printLog() {
        for(string message : this->logString){
            cout << message << endl;
        }
    }
    void Game :: playAll() {
        // cout << "Game started! :"<<this->turns << endl;
        while(!this->p1.myCards.empty() && !this->p2.myCards.empty()){
            playTurn();
        }
        p1.myCards.clear();
        p2.myCards.clear();
        // cout << "Game over!" << endl;
        this->isGameOver = true;
    }
    void Game :: printLastTurn() {
        cout << p1.name << " played " << valueMap[p1.lastCard.value] << " of " << suitsMap[p1.lastCard.suits];
        cout <<" "<< p2.name << " played " << valueMap[p2.lastCard.value] << " of " << suitsMap[p2.lastCard.suits] <<"." <<endl;
    }

    int Game::highestCard(Card &card1, Card &card2)
    {
        //in case of Player 1 has Ace
        if(card1.value == 1){
            if(card2.value == 1) return 0;
            if(card2.value == 2) return -1;
            return 1;
        } 

        //in case of Player 2 has Ace
        if(card2.value == 1){
            if(card1.value == 1) return 0;
            if(card1.value == 2) return 1;
            return -1;
            
        }

        //if first card is bigger return 1
        //if second card is bigger return -1
        //if equal return 0
        if (card1.value < card2.value) return 1;
        if (card1.value > card2.value) return -1;
        return 0;
    }

    void Game::giveCardsToWinner(Player winner)
    {
        for (int i = 0; i < this->sideCards.size(); i++)
        {
            winner.addCard(this->sideCards[static_cast<std::vector<Card>::size_type>(i)]);

        }
        this->sideCards.clear();
    }

    void Game::setMaps(){
        
        this->suitsMap[0] = "Clubs";
        this->suitsMap[1] = "Diamonds";
        this->suitsMap[2] = "Spades";
        this->suitsMap[3] = "Hearts";
        
        this->valueMap[1] = "Ace";
        this->valueMap[11] = "Jack";
        this->valueMap[12] = "Queen";
        this->valueMap[13] = "King";
        for(int i = 2; i < 11; i++){
            valueMap[i] = to_string(i);
        }

    }

    string Game:: logStringMessage(int winner){
        string winnerM;
        if(winner == 1){
            winnerM = p1.name + " wins.";
        } 
        else if(winner == -1){
            winnerM = p2.name + " wins.";
        }
        else{
            winnerM = " draw.";
        }
        string message = p1.name + " played " + valueMap[p1.lastCard.value] + " of " + suitsMap[p1.lastCard.suits] + ". ";
        message += p2.name + " played " + valueMap[p2.lastCard.value] + " of " + suitsMap[p2.lastCard.suits] + ".";
        message += winnerM;
        return message;
    }   

};