
#include "fraction_16law13.h"
using namespace std;

// constructors

Fraction::Fraction(int a, int b){
	int gcd;
	int flipA = 1;

	if(b == 0){
		throw FractionException("Error: Zero cannot be supplied as the denominator");
	}

	if((a<0 && b<0)){
		// turns them positive
		a = a*-1;
		b = b*-1;

	}
	else if(a<0){
		a*= -1;
		flipA = -1;
	}

	else if(b<0){
		// makes a negative, makes b positive
		b *= -1;
		flipA = -1;
	}

	gcd = GCD(a,b);
	if(b == 0){
		// throw dividebyzero exception
	}
	num = flipA*a/gcd;
	den= b/gcd;
	// check for equal signs, errors etc ...
}

Fraction::Fraction(int a){
    num = a;
    den = 1;
}

Fraction::Fraction(){
    num = 0;
    den = 1;

}

//GREATEST COMMON DIVISOR

int Fraction::GCD(int a,int b){
	if((b <= a) && ((a%b) == 0))
		return b;
	else if(a<b)
		return GCD(b,a);
	else
		return GCD(b,a%b);
}

int Fraction::numerator() const{
	return num;
}

int Fraction::denominator() const{
	return den;
}



//additions

Fraction operator+(const Fraction& fracOne, const Fraction& fracTwo){
	Fraction addEm(fracOne.numerator()*fracTwo.denominator()+fracTwo.numerator()*fracOne.denominator(),fracTwo.denominator()*fracOne.denominator());
	return addEm;
}

Fraction operator+(const Fraction & fracOne, const int aNum){
	Fraction newFrac(aNum);
    return fracOne + newFrac;
}

Fraction operator+(const int aNum, const Fraction & fracOne){
    Fraction newFrac(aNum);
    return fracOne + aNum;
}

//subtractions

Fraction operator-(const Fraction& fracOne, const Fraction& fracTwo){
	Fraction addEm(fracOne.numerator()*fracTwo.denominator()-fracTwo.numerator()*fracOne.denominator(),fracTwo.denominator()*fracOne.denominator());
	return addEm;
}

Fraction operator-(const Fraction & fracOne, const int aNum){
	Fraction newFrac(aNum);
    return fracOne - newFrac;
}

Fraction operator-(const int aNum, const Fraction & fracOne){
    Fraction newFrac(aNum);
    return newFrac - fracOne;
}

//Multiplications

Fraction operator*(const Fraction& fracOne, const Fraction& fracTwo){
	Fraction mult(fracOne.numerator()*fracTwo.numerator(),fracOne.denominator()*fracTwo.denominator());
	return mult;
}

Fraction operator*(const Fraction & fracOne, const int aNum){
	Fraction newFrac(aNum);
    return fracOne*newFrac;
}

Fraction operator*(const int aNum, const Fraction & fracOne){
    Fraction newFrac(aNum);
    return newFrac*fracOne;
}

//Divisions
Fraction operator/(const Fraction& fracOne, const Fraction& fracTwo){
	Fraction mult(fracOne.numerator()*fracTwo.denominator(),fracOne.denominator()*fracTwo.numerator());
	return mult;
}

Fraction operator/(const Fraction & fracOne, const int aNum){
	Fraction newFrac(aNum);
    return fracOne/newFrac;
}

Fraction operator/(const int aNum, const Fraction & fracOne){
    Fraction newFrac(aNum);
    return newFrac/fracOne;
}

// INCREMENT

Fraction operator++(Fraction & frac){
    Fraction newFrac(1);
    frac = frac + newFrac;
    return frac;
}

Fraction operator++(Fraction & frac, int aNum){
    Fraction newFrac(1);
    Fraction temp = frac;
    frac = frac + newFrac;
    return temp;
}

// plus equals assignment 
Fraction operator+=(Fraction& fracOne, const Fraction& fracTwo){
	fracOne = fracOne + fracTwo;
	return fracOne;
}

Fraction operator+=(Fraction& fracOne, const int aNum){
	Fraction newFrac(aNum);
    fracOne = fracOne + newFrac;
    return fracOne;
}

/*
COMPARSON OPERATORS:
*/

// EQUALS

bool operator==(const Fraction& fracOne, const Fraction& fracTwo){
	if(fracOne.numerator()==fracTwo.numerator() && fracOne.denominator() == fracTwo.denominator()){
		return true;
	}
	else
		return false;
}

bool operator==( const Fraction& fracOne, const int aNum){
	Fraction newFrac(aNum);
    return fracOne == newFrac;
}

bool operator==(const int aNum, const Fraction & fracOne){
	Fraction newFrac(aNum);
    return fracOne == newFrac;
}

// NOT EQUALS

bool operator!=(const Fraction& fracOne, const Fraction& fracTwo){
	if(fracOne.numerator()==fracTwo.numerator() && fracOne.denominator() == fracTwo.denominator()){
		return false;
	}
	else
		return true;
}

bool operator!=( const Fraction& fracOne, const int aNum){
	Fraction newFrac(aNum);
    return fracOne != newFrac;
}

bool operator!=(const int aNum, const Fraction & fracOne){
	Fraction newFrac(aNum);
    return fracOne != newFrac;
}


// LESS THAN

bool operator<(const Fraction& fracOne, const Fraction& fracTwo){
	double val1, val2;
	val1 = (double)fracOne.numerator()/(double)fracOne.denominator();
	val2 = (double)fracTwo.numerator()/(double)fracTwo.denominator();
	return val1<val2;

}

bool operator<( const Fraction& fracOne, const int aNum){
	Fraction newFrac(aNum);
    return fracOne < newFrac;
}

bool operator<(const int aNum, const Fraction & fracOne){
	Fraction newFrac(aNum);
    return newFrac < fracOne;
}

// GREATER THAN

bool operator>(const Fraction& fracOne, const Fraction& fracTwo){
	double val1, val2;
	val1 = (double)fracOne.numerator()/(double)fracOne.denominator();
	val2 = (double)fracTwo.numerator()/(double)fracTwo.denominator();
	return val1>val2;

}

bool operator>( const Fraction& fracOne, const int aNum){
	Fraction newFrac(aNum);
    return fracOne > newFrac;
}

bool operator>(const int aNum, const Fraction & fracOne){
	Fraction newFrac(aNum);
    return newFrac > fracOne;
}

// LESS THAN OR EQUALS

bool operator<=(const Fraction& fracOne, const Fraction& fracTwo){
	if(fracOne.numerator()==fracTwo.numerator() && fracOne.denominator() == fracTwo.denominator()){
		return true;
	}
	else if(fracOne < fracTwo)
		return true;
	else
		return false;
}

bool operator<=( const Fraction& fracOne, const int aNum){
	Fraction newFrac(aNum);
    return fracOne <= newFrac;
}

bool operator<=(const int aNum, const Fraction & fracOne){
	Fraction newFrac(aNum);
    return newFrac <= fracOne;
}

//GREATER THAN OR EQUALS

bool operator>=(const Fraction& fracOne, const Fraction& fracTwo){
	if(fracOne.numerator()==fracTwo.numerator() && fracOne.denominator() == fracTwo.denominator()){
		return true;
	}
	else if(fracOne > fracTwo)
		return true;
	else
		return false;
}

bool operator>=( const Fraction& fracOne, const int aNum){
	Fraction newFrac(aNum);
    return fracOne >= newFrac;
}

bool operator>=(const int aNum, const Fraction & fracOne){
	Fraction newFrac(aNum);
    return newFrac >= fracOne;
}

Fraction operator-(const Fraction & frac){
	Fraction newFrac(-frac.numerator(),frac.denominator());
	return newFrac;
}

ostream& operator<<(ostream& out, const Fraction& frac) {
   out << frac.numerator() << "/" << frac.denominator()<< " \n";
   return out;
}

istream& operator>>(istream& in, Fraction& myF){
	int a,b;
	char slash;

	cout << "Enter fraction in form \"a/b\"";
	in >> a >> slash >> b;

	// verifies format is right
	if (slash != '/'){
		throw FractionException("Incorrect input");
	}

	myF = Fraction(a,b);

	return in;
}

FractionException::FractionException(const string& message) : message(message) {}
string& FractionException::what() { return message; }