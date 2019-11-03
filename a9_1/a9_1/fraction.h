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
        Fraction();
        Fraction(int inNumerator, int inDenominator);
        void print() const;
        Fraction multipliedBy(const Fraction &f2) const;
        Fraction dividedBy(const Fraction &f2) const;
        Fraction addedTo(const Fraction &f2) const;
        Fraction subtract(const Fraction &f2) const;
        bool isEqualTo(const Fraction &f2) const;
    private:
        int numerator;
        int denominator;
        void simplify();
};


#endif /* fraction_h */
