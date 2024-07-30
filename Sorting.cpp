#include "Sorting.h"
template<typename T>
bool sortCheck(Node<T>* i1, Node<T>* i2, int sortingCriteria)
{//this is basically a dictionary
    return sortingCriteria == 1 ? i1->data->getPlace() < i2->data->getPlace() :
        sortingCriteria == 2 ? i1->data->getPop2023() < i2->data->getPop2023() :
        sortingCriteria == 3 ? i1->data->getGrowthRate() > i2->data->getGrowthRate() :
        sortingCriteria == 4 ? i1->data->getCountry() < i2->data->getCountry() :
        sortingCriteria == 5 ? i1->data->getRegion() < i2->data->getRegion() :
        sortingCriteria == 6 ? i1->data->getRank() < i2->data->getRank() :
        sortingCriteria == 7 ? i1->data->getEpi2022() < i2->data->getEpi2022() :
        sortingCriteria == 8 ? i1->data->getEpi2020() < i2->data->getEpi2020() :
        sortingCriteria == 9 ? i1->data->getUsn2022Rank() < i2->data->getUsn2022Rank() :
        sortingCriteria == 10 ? i1->data->getInts2020Rank() < i2->data->getInts2020Rank() :
        i1->data->getOverallRank() < i2->data->getOverallRank();
}

template <typename T>
Node<T>* Sorting::SelectionSort::minPosition(int from, int to, int sortingCriteria, Iterator<T> iter)
{//return a pointer to the position may remove list
    Node<T>* min_pos = iter.getPosition();   //min position originally set to start of list
    Iterator<T> iter2(iter);
    while (iter2.getPosition()->next != nullptr)
    {
        iter2.next();
        if (sortCheck(iter2.getPosition(), min_pos, sortingCriteria)) //because min_position and iter.position are pointers to nodes
        {
            min_pos = iter2.getPosition();
        }

    }
    return min_pos;
}
//template<typename T>b
template <typename T>
void Sorting::SelectionSort::selectionSort(List<T>& data, int upTo, int sortingCriteria) {
    int next = 0;
    Iterator<T> iter = data.begin();
    while (iter.getPosition()->next != nullptr)
    {
        Node<T>* min_pos = minPosition(next, upTo, sortingCriteria, iter);
        Iterator<T> iter3(iter);
        iter.next();
        data.swap(min_pos, iter3.getPosition());

    }
}
template <typename T>
long double Sorting::SelectionSort::timedSelectionSort(List<T>& data, int upTo, int sortingCriteria) {
    using namespace std::chrono;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    Sorting::SelectionSort::selectionSort(data, upTo, sortingCriteria);
    high_resolution_clock::time_point finish = high_resolution_clock::now();
    return duration_cast<duration<long double>>(finish - start).count();
};
