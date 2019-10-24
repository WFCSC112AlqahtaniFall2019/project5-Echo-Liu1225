#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"
#include <string>

using namespace std;

class Deck {
public:

    // default constructor
    Deck();
    // copy constructor
    Deck (const Deck& deckClass);
    // copy assignment operator
    Deck& operator = (const Deck& deckToCopy) ;
    // destructor
    ~ Deck();
    void populateCard();
    void shuffle();
    Card removeCard();
    bool addCard(Card v);

private:
    Card* cards;
    int arraySize;
    int cardsLeft;
    int thiscard;
};



#endif //BLINDMANSBLUFF_DECK_H