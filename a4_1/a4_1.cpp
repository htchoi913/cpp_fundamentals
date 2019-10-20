/*
 
 Henry Choi - W78250701
 City College of San Francisco
 CS110B - Fundamentals of Programming: C++
 Professor David Harden
 File Name: a4_1.cpp
 Homework Assignment #3
 Due Date: Septemeber 30, 2019
 
 This program takes in user inputs of card values between 2 and 9. The prorgram will then analyze the five card hand and determine
 whether or not that hand contains a Four of a Kind, Full House, Straight, Three of a Kind, Two Pair, Pair, or only a High Card.

 
 */

#include <iostream>
using namespace std;

const int HAND_SIZE = 5;    // Determines the amount of cards a play receives
const int PAIRS = 1;        // Determines how many double numbers are in a hand
const int TRIPLES = 2;      // Used to determine how many triple numbers are in a hand
const int QUADS = 3;        // Global constant used to determine how many quadruple numbers are in a hand

void readCards(int hand[]);                                 // Used to store user input as a player's hand
int countMatching(const int hand[], int index);             // This function counts how cards match a specified card
int pairsTriplesOrQuads(const int hand[], int type);        // This function determines how many pairs, doubles, triples a player's hand has
int findMax(const int hand[]);                              // This function determines the highest card number
bool NotChecked(const int hand[], const int cardsChecked[], int index); // Determines whether or not a number has already been checked in a player's hand
bool checkPlusOne(const int hand[], int index);             // Evaluates a card to see if another card in the hand is one number higher
bool checkMinusOne(const int hand[], int index);            // Evaluates a card to see if another card in the hand is one number lower

bool containsPair(const int hand[]);                        // Returns true if the player's hand contains a pair
bool containsTwoPair(const int hand[]);                     // Returns true if the player's hand contains a two pair
bool containsThreeOfaKind(const int hand[]);                // Returns true if the player's hand contains three of a kind
bool containsStraight(const int hand[]);                    // Returns true if the player's hand contains a straight
bool containsFullHouse(const int hand[]);                   // Returns true if the player's hand contains a full house
bool containsFourOfaKind(const int hand[]);                 // Returns true if the player's hand contains a four of a kind

int main()
{
    int hand[HAND_SIZE];
    
    readCards(hand);
    
    if (containsFourOfaKind(hand)) {
        cout << "Four of a Kind!" << endl;
    } else if (containsFullHouse(hand)) {
        cout << "Full House!" << endl;
    } else if (containsStraight(hand)) {
        cout << "Straight!" << endl;
    } else if (containsThreeOfaKind(hand)) {
        cout << "Three of a Kind!" << endl;
    } else if (containsTwoPair(hand)) {
        cout << "Two Pair!" << endl;
    } else if (containsPair(hand)) {
        cout << "Pair!" << endl;
    } else {
        cout << "High Card!" << endl;
    }
    
}






bool containsPair(const int hand[])
{
    if (pairsTriplesOrQuads(hand, PAIRS) == 1){
        return true;
    } else {
        return false;
    }
}






bool containsTwoPair(const int hand[])
{
    if (pairsTriplesOrQuads(hand, PAIRS) == 2) {
        return true;
    } else {
        return false;
    }
}






bool containsThreeOfaKind(const int hand[])
{
    if (pairsTriplesOrQuads(hand, TRIPLES) == 1) {
        return true;
    } else {
        return false;
    }
}






bool containsFullHouse(const int hand[])
{
    if (containsPair(hand) && containsThreeOfaKind(hand)) {
        return true;
    } else {
        return false;
    }
}







bool containsFourOfaKind(const int hand[])
{
    if (pairsTriplesOrQuads(hand, QUADS) == 1) {
        return true;
    }
    
    return false;
}






int pairsTriplesOrQuads(const int hand[], int type)
{
    int amount = 0;
    int cardsChecked[HAND_SIZE];
    
    for (int count = 0; count < HAND_SIZE; count++) {
        if (NotChecked(hand, cardsChecked, count)) {
            if (countMatching(hand, count) == type) {
                amount++;
            }
        cardsChecked[count] = hand[count];
        }
    }
    
    return amount;
}






bool NotChecked(const int hand[], const int cardsChecked[], int index)
{
    for (int count = 0; count < HAND_SIZE; count++) {
        if (hand[index] == cardsChecked[count]){
            return false;
        }
    }
    
    return true;
}






int countMatching(const int cards[], int index)
{
    int matches = 0;
    
    for (int count = 0; count < HAND_SIZE; count++){
        if (index != count && cards[index] == cards[count] ) {
            matches++;
        }
    }
    
    return matches;
}






void readCards(int cards[])
{
    int number = 0;
    
    cout << "Enter five numeric cards, no face cards. Use 2-9." << endl;
    for (int count = 0; count < HAND_SIZE; count++) {
        cout << "Card " << count + 1 << ": ";
        cin >> number;
        cards[count] = number;
    }
}






int findMax(const int cards[])
{
    int maxValue = cards[0];
    
    for (int count = 0; count < HAND_SIZE; count++) {
        if(maxValue < cards[count]) {
            maxValue = cards[count];
        }
    }
    
    return maxValue;
}






bool containsStraight(const int hand[])
{
    int matches = 0;
    
    for (int count = 0; count < HAND_SIZE; count++) {
        if (checkPlusOne(hand, count)) {
            matches++;
        } else if (checkMinusOne(hand, count)) {
            matches++;
        }
    }

        if (matches == 5) {
            return true;
        } else {
            return false;
        }
}






bool checkPlusOne(const int hand[], int index)
{
    int matches = 0;
    
    for (int count = 0; count < HAND_SIZE; count++) {
        if (hand[index] + 1 == hand[count]) {
            matches ++;
        }
    }
    
    if (matches == 1) {
        return true;
    } else {
        return false;
    }
}






bool checkMinusOne(const int hand[], int index)
{
    int matches = 0;
    
    for (int count = 0; count < HAND_SIZE; count++) {
        if (hand[index] == findMax(hand) && hand[index] - 1 == hand[count]) {
            matches++;
        }
    }
    
    if (matches == 1) {
        return true;
    } else {
        return false;
    }
}


/* Program Output:
 
 
 Enter five numeric cards, no face cards. Use 2-9.
 Card 1: 9
 Card 2: 8
 Card 3: 7
 Card 4: 6
 Card 5: 5
 Straight!
 Program ended with exit code: 0
 
 
 
 Enter five numeric cards, no face cards. Use 2-9.
 Card 1: 3
 Card 2: 3
 Card 3: 3
 Card 4: 7
 Card 5: 8
 Three of a Kind!
 Program ended with exit code: 0
 
 
 Enter five numeric cards, no face cards. Use 2-9.
 Card 1: 9
 Card 2: 9
 Card 3: 9
 Card 4: 9
 Card 5: 2
 Four of a Kind!
 Program ended with exit code: 0
 
 
 
 Enter five numeric cards, no face cards. Use 2-9.
 Card 1: 1
 Card 2: 3
 Card 3: 5
 Card 4: 7
 Card 5: 9
 High Card!
 Program ended with exit code: 0
 
 */
