// Autor: Valery Sokolov Morgenshteyn ID: 336424221
#include<iostream>
#include "List.h"
#include "Fraction.h"
#include "TemplateFuctions.h"
int main() {

	
	List<int> listI;
	List<Fraction> listF, listF2;
	List<double> listD;
	listI += 3;
	listI += 2;
	listI += 1;
	listI += -3;

	listF += Fraction(3, 7);
	listF += Fraction(7, 5);
	listF += Fraction(5, 6);
	listF += Fraction(7, 8);

	listD += 5 / 4.0;
	listD += 7 / 8.0;
	listD += 7 / 4.0;

	listF2 += Fraction(132, 7);
	listF2 += Fraction(7, 5);
	listF2 += Fraction(5, 6);
	listF2 += Fraction(7, 8);
	//std::cout << greaterThen(listF, 1);
	//std::cout << hasCommon(listF, listD);
	//std::cout<<listF.UNION(listF2);
	std::cout<<listF.INTERSECT(listF2);
	//std::cout << list1.INTERSECT(list2);
	return 0;
}