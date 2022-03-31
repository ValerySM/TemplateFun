// Autor: Valery Sokolov Morgenshteyn ID: 336424221
#ifndef _FRACTION_H
#define _FRACTION_H
#include <iostream> //for the istream and ostream declaration
using namespace std;

#define DEFAULT_DENO 1

class Fraction {
      public:
             //default Ctor, conversion Ctor, 2 values Ctor:
             //NOTICE: in case of illigal denominator (zero) it will be set to the default value!
             Fraction(int num = 0, int denom = DEFAULT_DENO);
             
             //No need for Copy Ctor, Dtor or operation=
             
             
             //-- operators --//
             //aritmetic:
             Fraction& operator+=(const Fraction&);
             Fraction& operator-=(const Fraction&);
             Fraction& operator*=(const Fraction&);
             Fraction& operator/=(const Fraction&);
             
             const Fraction operator+(const Fraction&)const;
             const Fraction operator-(const Fraction&)const;
             const Fraction operator*(const Fraction&)const;
             const Fraction operator/(const Fraction&)const;
             
             Fraction& operator++();			// prefix operator returns by reference
	         const Fraction operator++(int);			// postix operator returns by value
             
             //compare:
     	     bool operator>(const Fraction&) const;
             bool operator<(const Fraction&) const;
             bool operator>=(const Fraction&) const;
             bool operator<=(const Fraction&) const;
             bool operator==(const Fraction&) const;
             bool operator!=(const Fraction&) const;

             //Conversion:
             operator const double()const;//const since it is a temp value!
             operator const int()const;
             //These operation might cuase ambiguity when working with Fraction and double or: Fraction+int.
             
             
                                                    
             //friend (global) operation:
             friend const Fraction operator+(int, const Fraction&);
             friend istream& operator>>(istream &, Fraction&);//input
             friend ostream& operator<<(ostream &, const Fraction&);//ouput     
               
             

      private:
              int m_iNom; //MONE
              int m_iDenom; //MECHANE
              
              // private methods:
              int gcd (int, int);//finds the greatest common divisior.
              void reduce();//reduce the fraction.

};


#endif //_FRACTION_H
