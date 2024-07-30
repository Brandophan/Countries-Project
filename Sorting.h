#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <chrono>
#include "Data.h"
#include "List.h"
#include "StringHelper.h"
class Sorting {
public:
    class SelectionSort {
    public:
        template<typename T>
        static Node<T>* minPosition(int from, int to, int sortingCriteria, Iterator<T> iter);

        template<typename T>
        static void selectionSort(List<T>& data, int upTo, int sortingCriteria);//edit data to list  idk how to put in List as a parameter

        template<typename T>
        static long double timedSelectionSort(List<T>& data, int upTo, int sortingCriteria);
    };
};
#endif
