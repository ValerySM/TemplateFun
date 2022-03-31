// Autor: Valery Sokolov Morgenshteyn ID: 336424221
#include "Fraction.h"




//CCtor:
Fraction::Fraction(int num/* = 0*/, int denom/* = DEFAULT_DENO*/) : m_iNom(num), m_iDenom(denom) {
             if (m_iDenom == 0) //illigal value!!
                m_iDenom = DEFAULT_DENO;
             reduce ();
}



//Aritmetic:
//-------------
const Fraction Fraction::operator+(const Fraction &f1) const {
	int nn = m_iNom * f1.m_iDenom + m_iDenom * f1.m_iNom;
	int dd = m_iDenom * f1.m_iDenom;
	return Fraction (nn, dd);
}
const Fraction Fraction::operator-(const Fraction &f1) const {
	int nn = m_iNom * f1.m_iDenom - 			m_iDenom * f1.m_iNom;
	int dd = m_iDenom * f1.m_iDenom;
	return Fraction (nn, dd);
}
const Fraction Fraction::operator*(const Fraction &f1) const {
	int nn = m_iNom * f1.m_iNom;
	int dd = m_iDenom * f1.m_iDenom;
	return Fraction (nn, dd);
}
const Fraction Fraction::operator/(const Fraction &f1) const {
	int nn = m_iNom * f1.m_iDenom;
	int dd = m_iDenom * f1.m_iNom;
	return Fraction (nn, dd);
}


Fraction& Fraction::operator+=(const Fraction &f) {
	(*this) = (*this) + f;
	return *this;
}
Fraction& Fraction::operator-=(const Fraction &f) {
	(*this) = (*this) - f;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction &f) {
	(*this) = (*this) * f;
	return *this;
}
Fraction& Fraction::operator/=(const Fraction &f) {
	(*this) = (*this) / f;
	return *this;
}


Fraction& Fraction::operator++() {  // prefix:  ++a
	m_iNom += m_iDenom;
	reduce ();
	return *this;
}

const Fraction Fraction::operator++(int) {  // postfix:  a++ 
	int nn = m_iNom;
	int dd = m_iDenom;
	m_iNom += m_iDenom;
	reduce ();
	return Fraction (nn, dd);
}

//Conversions:
//-------------
Fraction::operator const double() const{ 
	return ((double) m_iNom) / m_iDenom; 
}

Fraction::operator const int() const{ 
	return (m_iNom / m_iDenom); 
}

//comparing:
//-----------

bool Fraction::operator==(const Fraction& f)const {
     return ((m_iNom == f.m_iNom) && (m_iDenom == f.m_iDenom));
}

bool Fraction::operator!=(const Fraction& f)const {
     return (!(*this == f));
}

bool Fraction::operator>(const Fraction& f)const {
     return (((double)(*this)) > ((double)f));
}

bool Fraction::operator<(const Fraction& f)const {
     return f>(*this);
}     

bool Fraction::operator>=(const Fraction& f)const {
     return ((*this > f) || (*this == f));//return (!(*this<f));
}     

bool Fraction::operator<=(const Fraction& f)const{
     return ((*this < f) || (*this == f));//return (!(*this>f));     
}                


/////////////////   Private Methods:       //////////////////////
int Fraction::gcd (int i, int j) {
	if ((i == 0) || (j == 0))
		return i + j;
	while (i %= j) {
		int t = i;
		i = j;
		j = t;
	}
	return j;
}

void Fraction::reduce() {
	int g = gcd (m_iNom, m_iDenom);
	m_iNom /= g;
	m_iDenom /= g;
}

/////////////   Gloabal Function:          /////////////////////////////

const Fraction operator+(int val, const Fraction & f){
      int nn = val * f.m_iDenom + f.m_iNom;
      return Fraction (nn, f.m_iDenom);
}


istream& operator>>(istream& is, Fraction& frac) {
	char divSign;
	is >> frac.m_iNom >> divSign >> frac.m_iDenom;
	if (frac.m_iDenom == 0)
		frac.m_iDenom = DEFAULT_DENO;
	frac.reduce ();
	return is;
}

ostream& operator<<(ostream& os, const Fraction& frac) {
	return os << frac.m_iNom << "/" << frac.m_iDenom;
}

