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
 
 This program is a re-write of Assignment 5.2 which produces the same
 output but uses structures to store the name and score information.
 
 */

#include <iostream>
using namespace std;

const int MAX_CHARACTER = 23;   // Global constant for maximum characters in name array

struct Highscore
{
    char name[MAX_CHARACTER];
    int score;
};

int indexOfLargest(Highscore scores[], int startingIndex, int numItems);
void readData(Highscore scores[], int size);
void sortData(Highscore scores[], int size);
void displayData(const Highscore scores[], int size);

int main()
{
    
    int size;
    
    cout << "How many scores will you enter?: ";
    cin >> size;
    
    Highscore* scores = new Highscore[size];
    
    readData(scores, size);
    sortData(scores, size);
    displayData(scores, size);
    
    delete [] scores;
}




/*
 This function returns the index of the largest number of an array
 
 Parameters.
 scores.            The struct array that contains information on names and scores.
 startingIndex.     The number that is evaluated for first.
 numItems.          The number of items in the list.
 
 */

int indexOfLargest(Highscore scores[], int startingIndex, int numItems)
{
    int targetIndex = startingIndex;
    
    for (int count = startingIndex + 1; count < numItems; count++){
        if (scores[count].score > scores[targetIndex].score){
            targetIndex = count;
        }
    }
    
    return targetIndex;
}





/*
 This function asks the user to enter names and scores which
 will be stored in two separate arrays.
 
 Parameters.
 scores.        The struct array that contains names and scores.
 size.          The size of the struct array
 
 */

void readData(Highscore scores[], int size)
{
    for (int count = 0; count < size; count++) {
        cout << "Enter the name for score #" << count + 1 << ": ";
        cin >> scores[count].name;
        cout << "Enter the score for score #" << count + 1 << ": ";
        cin >> scores[count].score;
    }
}





/*
 This function sorts the names array and scores array in descending
 order based on the scores input.
 
 Parameters.
 scores.        The struct array that contains names and scores.
 size.          The size of the struct array.
 
 */

void sortData(Highscore scores[], int size)
{
    for (int count = 0; count < size - 1; count++) {
        swap(scores[indexOfLargest(scores, count, size)], scores[count]);
    }
    
}





/*
 This function displays all the names and respective scores.
 
 Parameters.
 scores.        The struct array that contains names and scores.
 size.          The size of the struct array.
 
 */

void displayData(const Highscore scores[], int size)
{
    cout << endl << "Top Scorers:" << endl;
    for (int count = 0; count < size; count++) {
        cout << scores[count].name << ": " << scores[count].score << endl;
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
 
 
 How many scores will you enter?: 10
 Enter the name for score #1: jim
 Enter the score for score #1: 12345678
 Enter the name for score #2: jane
 Enter the score for score #2: 99999999
 Enter the name for score #3: joe
 Enter the score for score #3: 10
 Enter the name for score #4: oliver
 Enter the score for score #4: 531245
 Enter the name for score #5: henry
 Enter the score for score #5: 8357123
 Enter the name for score #6: jess
 Enter the score for score #6: 010
 Enter the name for score #7: tiff
 Enter the score for score #7: 200
 Enter the name for score #8: leslie
 Enter the score for score #8: 1
 Enter the name for score #9: angela
 Enter the score for score #9: 12345
 Enter the name for score #10: tim
 Enter the score for score #10: 0
 
 Top Scorers:
 jane: 99999999
 jim: 12345678
 henry: 8357123
 oliver: 531245
 angela: 12345
 tiff: 200
 jess: 10
 joe: 10
 leslie: 1
 tim: 0
 Program ended with exit code: 0
 
 */
