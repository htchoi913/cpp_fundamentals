//
//  fraction.h
//  a9_1
//
//  Created by Henry Choi on 11/2/19.
//  Copyright © 2019 Henry Choi. All rights reserved.
//

#ifndef fraction_h
#define fraction_h

class Fraction {
public:
    Fraction::Fraction();
    Fraction::Fraction(int inNumerator, int inDenominator);
    void print();
    Fraction multipliedBy(Fraction f2);
    Fraction dividedBy(Fraction f2);
    Fraction addedTo(Fraction f2);
    Fraction subtract(Fraction f2);
    bool isEqualTo(Fraction f2);
private:
    int numerator;
    int denominator;
};


#endif /* fraction_h */
