#include "Deck.h"
#include <string>
#include <iostream>

using namespace std;

// default constructor
Deck :: Deck() {
    thiscard = 0;
    arraySize = 52;
    cards = new Card[arraySize];
    cardsLeft = 52;
}


// copy constructor
Deck :: Deck (const Deck& deckClass ){
    arraySize = deckClass.arraySize;
    cards = new Card[arraySize];
    for (int i = 0; i < arraySize;i ++){
        cards[i] = deckClass.cards[i];
    }
    thiscard = deckClass.thiscard;
    cardsLeft = deckClass.cardsLeft;
}


//define the operator
Deck& Deck::operator=(const Deck& deckToCopy) {
    Deck temp(deckToCopy);
    swap(cards, temp.cards);
    return *this;
}


//define the populateCard
void Deck :: populateCard(){
    int numCards = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            Card card = Card(i, j);
            cards[numCards] = Card(i, j);
            numCards ++;
        }
        if (numCards > 50){
            break;
        }
    }
}

//delete the card that have already been existed
Deck :: ~ Deck() {
    delete [] cards;
}

//remove the card that already been existed
Card Deck :: removeCard() {
    if (thiscard < arraySize) {
        cardsLeft--;
        return (cards[thiscard++]);
    }
    else {
        cout << "No cards left." << endl;
    }
}

//shuffle the card
void Deck :: shuffle() {
    for (int j = 0; j < cardsLeft * cardsLeft; j++) {

        // get two random number from
        int shuffle1 = rand() % cardsLeft;
        int shuffle2 = rand() % cardsLeft;
        swap (cards[shuffle1], cards[shuffle2]);

    }
}

//add card into the group
bool Deck :: addCard(Card card){
    if (cardsLeft != 0){
        cards[thiscard] = card;
        thiscard++;
        return true;
    }
    else{
        return false;
    }
}