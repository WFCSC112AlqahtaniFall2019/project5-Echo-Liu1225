//*Echo Liu
//*Oct.24th.2019
//Lab 5 Blind Man's Bluff
//Using different method to design the playcard game
#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {

    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    //define all the variable that we are going to use
    bool player;
    bool invalid;
    bool guess;
    string response;
    int nWin = 0, nLoss = 0, nTie = 0;
    player = true;
    //get the function from card
    Card comChoice;
    Card userChoice;
    //get the function from deck
    Deck deck;
    deck.shuffle();
    deck.populateCard();
    Deck discard;

    int count = 1;
    //use the while loop to show up the computer's choice
    while(player == true && count < 27) {
        //remove the card from both user and computer
        comChoice = deck.removeCard();
        userChoice = deck.removeCard();

        //discard the cards that have been chosen
        discard.addCard(comChoice);
        discard.addCard(userChoice);

        cout << count << " times try:" << endl;
        cout << " Computer's value is:" << comChoice.Name()  << endl;

        invalid = true;
       //get user's bet
        while(invalid) {
            cout << " Please guess your card is higher or lower? (H/L)  " ;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                guess = true;
                invalid = false;
            }
            else if (toupper(response.at(0)) == 'L') {
                guess = false;
                invalid = false;
            }
            else {
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
        //to decide whether the choice is correct or not
        if((comChoice < userChoice && guess) || (userChoice < comChoice && !guess)) {
            cout << "Great! You're right." << endl;
            nWin++;
        }
        else if((userChoice < comChoice && guess) || (comChoice < userChoice && !guess)) {
            cout << "Sorry, you're wrong." << endl;
            nLoss++;
        }
        else {
            cout << "It's a tie:" << endl;
            nTie++;
        }

        cout << "Your card is:" << userChoice.Name() << endl ;

        if (count > 20 && count < 27){
            cout << " YOU HAVE " << 27 - count << "TURNS Left." << endl;
        }
        invalid = true;

        while(invalid) {
            cout << " Play again? (Y/N)  " ;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                player = true;
                invalid = false;
            }


            else if (toupper(response.at(0)) == 'N') {
                player = false;
                invalid = false;
            }

            else {
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        count++;
        cout << endl;
    }

    //show the case that the card is empty
    if (count == 27){
        cout<<"Empty Cards!"<<endl;
    }

        //ends of the game and check the detail of the player information
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl << endl;

    return 0;
}