/*
 
 Class Invariant: A Fraction object has uses two int data numbers
 to store fractions. Numerator and denominator is used to store
 the appropriate fraction numbers. The assert function was used to
 prevent the client program from providing 0 as a denominator value
 in the parameterized constructor.
 
 */

#include <iostream>
#include <cassert>
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
    
    assert(denominator != 0);

    simplify();
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




// The private member function simplifies the calling object by
// dividing the numerator and denominator with the greatest common
// denominator.

void Fraction::simplify()
{
    int greatestComDen = 1;
    int lowerNum = numerator;
    
    if (lowerNum > denominator) {
        lowerNum = denominator;
    }
    
    for (int count = 1; count <= lowerNum; count++) {
        if (numerator % count == 0 && denominator % count == 0 ) {
            greatestComDen = count;
        }
    }
        
    numerator = numerator / greatestComDen;
    denominator = denominator / greatestComDen;
    
}
