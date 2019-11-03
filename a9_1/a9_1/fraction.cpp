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
#include <cassert>
#include "fraction.h"
using namespace std;

const int STARTING_FACTOR = 2;


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




void Fraction::print() const
{
    cout << numerator << "/" << denominator;
}






Fraction Fraction::multipliedBy(const Fraction &f2) const
{
    int tempNumerator;
    int tempDenominator;
    
    tempNumerator = numerator * f2.numerator;
    tempDenominator = denominator * f2.denominator;
    
    Fraction tempFraction(tempNumerator, tempDenominator);
    
    tempFraction.simplify();
    
    return tempFraction;
}






Fraction Fraction::dividedBy(const Fraction &f2) const
{
    int tempNumerator;
    int tempDenominator;
    
    tempNumerator = numerator * f2.denominator;
    tempDenominator = denominator * f2.numerator;
    Fraction tempFraction(tempNumerator, tempDenominator);
    
    tempFraction.simplify();
    
    return tempFraction;
}






Fraction Fraction::addedTo(const Fraction &f2) const
{
    int tempNumerator;
    int tempDenominator;
    
    tempNumerator = (numerator * f2.denominator) + (denominator * f2.numerator);
    tempDenominator = (denominator * f2.denominator);
    Fraction tempFraction(tempNumerator, tempDenominator);
    
    tempFraction.simplify();
    
    return tempFraction;
}






Fraction Fraction::subtract(const Fraction &f2) const
{
    
    int tempNumerator;
    int tempDenominator;
    
    tempNumerator = (numerator * f2.denominator) - (denominator * f2.numerator);
    tempDenominator = (denominator *f2.denominator);
    
    Fraction tempFraction(tempNumerator, tempDenominator);
    
    tempFraction.simplify();
    
    return tempFraction;
}






bool Fraction::isEqualTo(const Fraction &f2) const
{
    return numerator * f2.denominator == denominator * f2.numerator;
}






void Fraction::simplify()
{
    int lowerNum = numerator;
    
    if (lowerNum > denominator) {
        lowerNum = denominator;
    }
    
    for (int count = STARTING_FACTOR; count < lowerNum; count++) {
        if (numerator % count == 0 && denominator % count == 0 ) {
                numerator = numerator / count;
                denominator = denominator / count;
        }
    }
}

