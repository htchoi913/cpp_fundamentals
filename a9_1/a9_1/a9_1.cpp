/*
 
 Henry Choi - W78250701
 City College of San Francisco
 CS110B - Fundamentals of Programming: C++
 Professor David Harden
 File Name: a8_1.cpp
 Homework Assignment #8
 Due Date: October 28, 2019
 
 This program uses the class Function to set and print fractions.
 Additionally, the program can be used to output mathematic
 calculations between two fractions. These calculations include
 addition, subtraction, multiplication, and division. Lastly, the
 program will also compare to fractions to see if they are equal
 or not.
 
 */

#include <iostream>
#include "fraction.h"
using namespace std;


Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}



Fraction::Fraction(int inNumerator, int inDenominator)
{
    numerator = inNumerator;
    denominator = inDenominator;
}




void Fraction::print()
{
    cout << numerator << "/" << denominator;
}






Fraction Fraction::multipliedBy(Fraction f2)
{
    int tempNumerator;
    int tempDenominator;
    
    tempNumerator = numerator * f2.numerator;
    tempDenominator = denominator * f2.denominator;
    
    Fraction tempFraction(tempNumerator, tempDenominator);
    
    return tempFraction;
}






Fraction Fraction::dividedBy(Fraction f2)
{
    Fraction tempFraction;
    int tempNumerator;
    int tempDenominator;
    
    tempNumerator = numerator * f2.denominator;
    tempDenominator = denominator * f2.numerator;
    tempFraction.set(tempNumerator, tempDenominator);
    
    return tempFraction;
}






Fraction Fraction::addedTo(Fraction f2)
{
    Fraction tempFraction;
    int tempNumerator;
    int tempDenominator;
    
    tempNumerator = (numerator * f2.denominator) + (denominator * f2.numerator);
    tempDenominator = (denominator * f2.denominator);
    tempFraction.set(tempNumerator, tempDenominator);
    
    return tempFraction;
}






Fraction Fraction::subtract(Fraction f2)
{
    Fraction tempFraction;
    int tempNumerator;
    int tempDenominator;
    
    tempNumerator = (numerator * f2.denominator) - (denominator * f2.numerator);
    tempDenominator = (denominator *f2.denominator);
    tempFraction.set(tempNumerator, tempDenominator);
    
    return tempFraction;
}






bool Fraction::isEqualTo(Fraction f2)
{
    return numerator * f2.denominator == denominator * f2.numerator;
}






int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;
    
    f1.set(9, 8);
    f2.set(2, 3);
    
    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;
    
    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;
    
    
    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;
    
    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;
    
    if (f1.isEqualTo(f2)) {
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}






/*
 
 Program Output:
 
 The product of 9/8 and 2/3 is 18/24
 The quotient of 9/8 and 2/3 is 27/16
 The sum of 9/8 and 2/3 is 43/24
 The difference of 9/8 and 2/3 is 11/24
 The two Fractions are not equal.
 Program ended with exit code: 0
 
 */

