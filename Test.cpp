#include "doctest.h"
// #include <sstream>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace ariel;

TEST_CASE("Test for card") 
{
    Card card1(3, 1);
    Card card2(12,2);
    Card card3(11,2);
    Card card4(11,1);
    Card card5(2,3);

    CHECK(card1.highestCard(card3) == 1);
    CHECK(card2.highestCard(card3) == -1);
    CHECK(card3.highestCard(card4) == 0);
    CHECK(card4.highestCard(card3) == 0);
    CHECK(card2.highestCard(card4) == -1);
    CHECK(card2.highestCard(card5) == -1);
    CHECK(card4.highestCard(card5) == -1);
    CHECK(card1.highestCard(card5) == -1);
    CHECK(card3.highestCard(card4) == -1);
    CHECK(card5.highestCard(card1) == 1);
    CHECK(card5.highestCard(card4) == 1);
    CHECK(card5.highestCard(card3) == 1);
    


}

TEST_CASE("Test fot player")
{
    Player p1("Alice");
    Player p2("Bob");

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);

}

TEST_CASE("Test for game")
{
    Player p1("Alice");
    Player p2("Bob");
    CHECK((p1.stacksize() + p2.stacksize()) == 52);
    Game g1(p1 , p1);
    CHECK_THROWS(g1.playAll());
    CHECK_THROWS(g1.printLastTurn());
    CHECK_THROWS(g1.playTurn());



}