#ifndef fraction_h
#define fraction_h

/*
 
 The Fraction class can be used to create objects that store
 fractions in numerator and denominator format. The following functions
 are available:
 
 Fraction();
    post: The calling object has been created and initialized to 0/1
 
 Fraction(int inNumerator, int inDenominator);
    post: The calling object has been created and initialized so that the
        numerator is inNumerator and the denominator is inDenominator.
 
 void print() const;
    post: The calling object has been printed to the console window in the
         format numerator/denominator.
 
 Fraction multipliedBy(const Fraction &f2) const;
    post: Returns the Fraction determined by multiplying the calling
         object by the Fraction provided in the argument.
 
 Fraction dividedBy(const Fraction &f2) const;
    post: Returns the Fraction determined by dividing the calling
         object by the Fraction provided in the argument.
 
 Fraction addedTo(const Fraction &f2) const;
    post: Returns the Fraction determined by adding the calling
         object by the Fraction provided in the argument.
 
 Fraction subtract(const Fraction &f2) const;
    post: Returns the Fraction determined by subtracting the calling
         object by the Fraction provided in the argument.
 
 bool isEqualTo(const Fraction &f2) const;
    post: Returns true if the calling object is equal to parameter
        "f2". Otherwise returns false.
 
 */


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

/*
 
 Program output:
 
 The result starts off at 0/1
 The product of 9/8 and 2/3 is 3/4
 The quotient of 9/8 and 2/3 is 27/16
 The sum of 9/8 and 2/3 is 43/24
 The difference of 9/8 and 2/3 is 11/24
 The two Fractions are not equal.
 The product of 3/2 and 2/3 is 1/1
 Program ended with exit code: 0
 
 */
