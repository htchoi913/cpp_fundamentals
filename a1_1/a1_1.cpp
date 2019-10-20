/*
 
 Henry Choi - W78250701
 City College of San Francisco
 CS110B - Fundamentals of Programming: C++
 Professor David Harden
 File Name: a1_1.cpp
 Homework Assignment #1
 Due Date: Septemeber 9, 2019
 
 This program asks a user to input a date in the format month/day/2-digit-year.
 If the user enters a date where the numerical value of the 2-digit year is equal to the
 product of the month multiplied by the day, then the program will output "This is a magical date."
 Otherwise, the program will output "This is not a magical date."
 
 */

#include <iostream>
using namespace std;

int main() {
    int month;          // integer variable for month
    int day;            // integer variable for day
    int year;           // integer variable for year
    char slash;         // character variable for both slashes in user input date
    
    cout << "Enter a date in the format month/day/2-digit-year: ";
    cin >> month >> slash >> day >> slash >> year;

    if (month * day == year) {
        cout << "This is a magical date." << endl;
    } else {
        cout << "This is not a magical date." << endl;
    }
}

/*
 
 Program output for user input of date 6/10/60:
 
 Enter a date in the format month/day/2-digit-year: 6/10/60
 This is a magical date.
 Program ended with exit code: 0
 
 Program output for user input of date 9/13/90:
 
 Enter a date in the format month/day/2-digit-year: 9/13/90
 This is not a magical date.
 Program ended with exit code: 0
 
 */
