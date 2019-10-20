/*
 
 Henry Choi - W78250701
 City College of San Francisco
 CS110B - Fundamentals of Programming: C++
 Professor David Harden
 File Name: a3_1.cpp
 Homework Assignment #3
 Due Date: Septemeber 23, 2019
 
 This program plays a number guessing game with a Human user. The user thinks of a number between 1 and 100 and
 the computer will make a guess. If the computer is wrong, the user will be asked if the number is higher
 or lower than the current guess. Based on the user's response, the computer will calculate another guess using
 a midpoint formula. This process will repeat itself until the computer guesses the correct number.
 
 */

#include <iostream>
using namespace std;

void playOneGame();
void getUserResponseToGuess(int guess, char &result);
int getMidpoint(int low, int high);

int main() {
    char response;          // User input response to activate the game
    
    cout << "Ready to play (y/n)? ";
    cin >> response;
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
}






// The function below plays the game described in the first comment.

void playOneGame()
{
    int low = 1;            // Lower boundary of the possible numbers, with initial value of 1
    int high = 100;         // Upper boundary of the possible numbers, with initial value of 100
    int guess;              // Computer's guess which is calculated as the midpoint of the lower and upper boundary values
    char result = ' ';      // Variable used to determine whether the computer's guess is correct or if it should be higher/lower
    
    cout << "Think of a number between " << low << " and " << high << "." << endl;
    
    while (result != 'c')
    {
        guess = getMidpoint(low, high);
        
        getUserResponseToGuess(guess, result);
        
        if (result == 'l') {
            high = guess - 1;
        } else if (result == 'h') {
            low = guess + 1;
        }
    }
}






// The function below prints the computer's guess and returns user's input to calling function

void getUserResponseToGuess(int guess, char &result)
{
    cout << "My guess is " << guess << ". Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
    cin >> result;
}






// The function below calculates the midpoint value of the lower and upper boundaries. If two midpoint number exists, it returns the lesser number.

int getMidpoint(int low, int high)
{
    int result = 1;

    result = (low + high) / 2;
    return result;
}






/*

 Program output:
 
 Ready to play (y/n)? y
 Think of a number between 1 and 100.
 My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
 My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
 My guess is 88. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
 My guess is 81. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
 Great! Do you want to play again (y/n)? y
 Think of a number between 1 and 100.
 My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
 My guess is 25. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
 My guess is 37. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
 Great! Do you want to play again (y/n)? y
 Think of a number between 1 and 100.
 My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
 My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
 My guess is 62. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
 My guess is 56. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
 Great! Do you want to play again (y/n)? n
 Program ended with exit code: 0
 
 
 */
