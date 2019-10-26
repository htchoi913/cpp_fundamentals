/*



*/

#include <iostream>
using namespace std;


class Fraction {
    public:
        void set(int inNumerator, int inDemoninator);
        void print();
        Fraction multipliedBy(Fraction f2);
        Fraction dividedBy(Fraction f2);
    private:
        int numerator;
        int denominator;
};



void Fraction::set(int inNumerator, int inDenominator)
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
    Fraction tempFraction;
    int tempNumerator;
    int tempDenominator;
    
    tempNumerator = numerator * f2.numerator;
    tempDenominator = denominator * f2.denominator;
    tempFraction.set(tempNumerator, tempDenominator);
    
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


int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;
    
    f1.set(9, 8);
    f2.set(2,3);
    
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
    
}
