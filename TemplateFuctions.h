// Autor: Valery Sokolov Morgenshteyn ID: 336424221
#ifndef _TEMPLATEFUCTIONS_H
#define _TEMPLATEFUCTIONS_H
#include "List.h"
#include <stdlib.h>
#define EPSILON 0.0000001

template<class T1, class T2>
int greaterThen(List<T1> list, T2 elem)
{
	int counter = 0;
	list.get_next(true);//restart of iteretor
	for (int i = 0; i < list.get_size(); i++)
	{
		if ((double)list.get_next() > (double)elem)
			counter++;
	}
	return counter;
}

template<class T1, class T2>
bool hasCommon(List<T1> list1, List<T2> list2)
{
	list1.get_next(true);//restart of iteretor
	for (int i = 0; i < list1.get_size(); i++)
	{
		list2.get_next(true);//restart of iteretor
		for (int j = 0; j < list2.get_size(); j++)
			if (abs((double)list1.get_next() - (double)list2.get_next()) < EPSILON)
				return true;
	}
	return false;
}
#endif


