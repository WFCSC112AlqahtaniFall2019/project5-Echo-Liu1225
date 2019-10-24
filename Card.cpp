#include "Card.h"
using namespace std;

//default constructor
Card :: Card(){
    rank = 0;
    suit = 0;

}

//alternate constructor
Card :: Card(int rank1, int suit1){
    this -> rank = rank1;
    this -> suit = suit1;
}


// overloaded comparison operator
bool Card :: operator<(Card card){
    if (this->rank < card.rank){
        return true;
    }
    else if (this->rank == card.rank){
        return this->suit < card.suit;
    }
    else if (this->rank > card.rank){
        return false;
    }
}


string Card ::Name() {
    name = ranks[rank]+ " of "+ suits[suit];
    return name;
}