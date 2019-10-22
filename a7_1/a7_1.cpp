/*
 
 Henry Choi - W78250701
 City College of San Francisco
 CS110B - Fundamentals of Programming: C++
 Professor David Harden
 File Name: a7_1.cpp
 Homework Assignment #7
 Due Date: October 21, 2019
 
 This program records high-score data for a fictitious game. The program
 asks a user to enter the amount of names/scores to be entered, then asks
 the user to enter the name followed by the score until all the data is
 entered. Once the data entry is complete, the program will display data
 in sorted by descending order of the score.
 
 */

#include <iostream>
using namespace std;

struct Highscore
{
    int score;
    char name[];
}


int indexOfLargest(const int list[], int startingIndex, int numItems);
void readData(Highschore scores[], int size);
void sortData(Highscore scores[], int size);
void displayData(const Highscore scores[], int size);


int main()
{
    
    int size;
    cout << "How many scores will you enter?:";
    cin >> size;
    
    Highschore scores;
    

}


void readData(Highschore scores[], int size)
{
    for (int count = 0; count < size; count++) {
        cout << "Enter the name for score #" << count + 1 << ": ";
        cin >> scores.name[count];
        cout << "Enter the score for score #" << count + 1 << ": ";
        cin >> scores.score[count];
    }
}
