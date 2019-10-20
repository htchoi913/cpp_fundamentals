/*
 
 Henry Choi - W78250701
 City College of San Francisco
 CS110B - Fundamentals of Programming: C++
 Professor David Harden
 File Name: a2_1.cpp
 Homework Assignment #2
 Due Date: Septemeber 16, 2019
 
 This program plays a simple version of blackjack using the command line. The program starts by randomly generating
 two cards, each card with an equal chance of having a value from 1 to 10. After the first two initial cards, a running
 sum is provided and the program asks the player if another card is desired. This question is repeated until the player
 either reaches 21 exactly which will generate "Congratulations!" or if the player exceeds 21, then the program will
 generate "Bust." The program then asks the player wants to play again. If the player chooses to stop receiving cards
 before hitting 21 exactly or exceeding 21, the program simply asks if the player wants to play again.
 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int BLACKJACK = 21;                               // Global constant that indicates whether or not the player has reached the winning value of 21

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));        // Generates different sequence of random numbers for each progam run (Lesson 7.3)
    
    int firstCard;                                      // First card of the initial pair, randomly generated
    int secondCard;                                     // Second card of the initial pair, randomly generated
    int newCard;                                        // Additional 'hit' card, if requested
    int cardsTotal;                                     // Running total of cards in the player's current hand
    char gameResponse;                                  // Response variable used to keep the game on via while loop
    char cardResponse;                                  // Response variable used to ask and determine if the player wants an additional card
    
    gameResponse = 'y';                                 // Set gameResponse variable to 'y' to activate the game on loop
    cardResponse = 'y';                                 // Set cardResponse variable to 'y' to activate the additional card loop

    do {
        
        firstCard = (rand() % (10)) + 1;                // Randomly generates a first initial card value between 1-10 using math algorithm (Lesson 7.3)
        secondCard = (rand() % (10)) + 1;               // Randomly generates a second initial card value between 1-10 using math algorithm (Lesson 7.3)
        cardsTotal = firstCard + secondCard;
        
        cout << "First cards: " << firstCard << ", " << secondCard << endl;
        cout << "Total: " << cardsTotal << endl;
        
        while (cardsTotal < BLACKJACK && cardResponse == 'y') {    // While loop that checks to see if the running total is less than 21 and if the player wants another card
            
            cout << "Do you want another card? (y/n): ";
            cin >> cardResponse;
            
            if (cardResponse == 'y') {
                    newCard = (rand() % (10)) + 1;      // Randomly generates a new card value between 1-10 using math algorithm (Lesson 7.3)
                    cardsTotal = cardsTotal + newCard;
                
                    cout << "Card: " << newCard << endl;
                    cout << "Total: " << cardsTotal << endl;
            }
        }
            
        if (cardsTotal > BLACKJACK) {
            cout << "Bust." << endl;
        } else if (cardsTotal == BLACKJACK) {
            cout << "Congratulations!" << endl;
        }
            
        cout << "Would you like to play again? (y/n): ";
        cin >> gameResponse;
            
        if (gameResponse == 'y') {
            cardsTotal = 0;                             // Resets the running total for the next game
            cardResponse = 'y';                         // Resets the variable that enables additional cards after the initial two
        }
        
    } while (gameResponse == 'y');                      // While loop that repeats/resets the game if the user enters 'y' when prompted above
}

/*
 
 Program Output:
 
 First cards: 2, 10
 Total: 12
 Do you want another card? (y/n): y
 Card: 7
 Total: 19
 Do you want another card? (y/n): n
 Would you like to play again? (y/n): y
 First cards: 8, 8
 Total: 16
 Do you want another card? (y/n): y
 Card: 7
 Total: 23
 Bust.
 Would you like to play again? (y/n): y
 First cards: 8, 10
 Total: 18
 Do you want another card? (y/n): y
 Card: 2
 Total: 20
 Do you want another card? (y/n): y
 Card: 3
 Total: 23
 Bust.
 Would you like to play again? (y/n): y
 First cards: 8, 5
 Total: 13
 Do you want another card? (y/n): y
 Card: 6
 Total: 19
 Do you want another card? (y/n): y
 Card: 8
 Total: 27
 Bust.
 Would you like to play again? (y/n): y
 First cards: 9, 8
 Total: 17
 Do you want another card? (y/n): y
 Card: 1
 Total: 18
 Do you want another card? (y/n): y
 Card: 10
 Total: 28
 Bust.
 Would you like to play again? (y/n): y
 First cards: 3, 5
 Total: 8
 Do you want another card? (y/n): y
 Card: 7
 Total: 15
 Do you want another card? (y/n): y
 Card: 4
 Total: 19
 Do you want another card? (y/n): y
 Card: 2
 Total: 21
 Congratulations!
 Would you like to play again? (y/n): n
 Program ended with exit code: 0
 
 */
