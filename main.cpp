#include <iostream> 
#include <iomanip>
#include <fstream>
#include "StringHelper.h"
#include "Helper.h"
#include "Screen.h"
#include "Sorting.h"
#include "List.h"
#include "Node.h"

void freeMemory(List<Data*>);//no idea what this does
void getStuff(std::string&, std::string&, bool&);
int main() {
    std::string choose, sorting;
    bool reRun = false;
    getStuff(choose, sorting, reRun);
    Pair<List<Data*>, int> data;
    do {
        data = Helper::getData();
        if (reRun) { getStuff(choose, sorting, reRun); }
        Helper::runTimedSorting(data.first, data.second, std::stoi(sorting), std::stoi(choose));
    } while ((reRun = Screen::getLetterAnswer("\nWould you like to go again?(Y or N)")));
    std::cout << "\nGoodbye!" << std::endl;
    freeMemory(data.first);
    return 0;
}

void getStuff(std::string& choose, std::string& sorting, bool& r) {
    ((choose = Screen::greetAndSelectionScreen(r)) == "NULL" || (sorting = Screen::sortingCriteria()) == "NULL")
        ? (static_cast<void>(std::cout << "Ok! Have a great day!" << std::endl), exit(0)) : void();
}
void freeMemory(List<Data*> data) {
    int i = 0;
    for (Iterator<Data*> iter = data.begin(); !iter.equals(data.end()); iter.next()) {
        if (iter.get() != nullptr)
            delete iter.get();
    }
}

