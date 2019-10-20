/*
 
 Henry Choi - W78250701
 City College of San Francisco
 CS110B - Fundamentals of Programming: C++
 Professor David Harden
 File Name: a5_2.cpp
 Homework Assignment #5
 Due Date: October 7, 2019
 
 This program records high-score data for a fictitious game. The program
 asks a user to enter the amount of names/scores to be entered, then asks
 the user to enter the name followed by the score until all the data is
 entered. Once the data entry is complete, the program will display data
 in sorted by descending order of the score.
 
 
 */

#include <iostream>
using namespace std;

int indexOfLargest(const int list[], int startingIndex, int numItems);
void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main()
{

    int size;
    
    cout << "How many scores will you enter?: ";
    cin >> size;
    
    string* names = new string[size];
    int* scores = new int[size];
    
    readData(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);

    delete [] names;
    delete [] scores;
}






/*
   This function returns the index of the largest number of an array
 */

int indexOfLargest(const int list[], int startingIndex, int numItems)
{
    int targetIndex = startingIndex;
    
    for (int count = startingIndex + 1; count < numItems; count++){
        if (list[count] > list[targetIndex]){
            targetIndex = count;
        }
    }
    
    return targetIndex;
}






/*
   This function asks the user to enter names and scores which
   will be stored in two separate arrays.
 */

void readData(string names[], int scores[], int size)
{
    for (int count = 0; count < size; count++) {
        cout << "Enter the name for score #" << count + 1 << ": ";
        cin >> names[count];
        cout << "Enter the score for score #" << count + 1 << ": ";
        cin >> scores[count];
    }
}






/*
   This function sorts the names array and scores array in descending
   order based on the scores input.
 */

void sortData(string names[], int scores[], int size)
{
    for (int count = 0; count < size - 1; count++) {
        swap(names[indexOfLargest(scores, count, size)], names[count]);
        swap(scores[indexOfLargest(scores, count, size)], scores[count]);
    }
    
}







/*
   This function displays all the names and respective scores.
 */

void displayData(const string names[], const int scores[], int size)
{
    cout << endl << "Top Scorers:" << endl;
    for (int count = 0; count < size; count++) {
        cout << names[count] << ": " << scores[count] << endl;
    }
}







/*

 Program Output:
 
 How many scores will you enter?: 4
 Enter the name for score #1: Suzy
 Enter the score for score #1: 600
 Enter the name for score #2: Kim
 Enter the score for score #2: 9900
 Enter the name for score #3: Armando
 Enter the score for score #3: 8000
 Enter the name for score #4: Tim
 Enter the score for score #4: 514
 
 Top Scorers:
 Kim: 9900
 Armando: 8000
 Suzy: 600
 Tim: 514
 Program ended with exit code: 0
 
*/
