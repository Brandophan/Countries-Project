#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Data.h"
#include "StringHelper.h"
#include "Sorting.h"
#include "Sorting.cpp"
#include "Screen.h"
#include "List.h"
#include "Node.h"
class Helper {
public:
    static int canConvertToInt(const std::string& s) {
        try {
            if (s == "") return 0;
            std::stoi(s);
            return std::stoi(s);
        }
        catch (const std::invalid_argument&) {
            return -11234;
        }
    }
    static double canConvertToDouble(const std::string& s) {
        try {
            if (s == "") return 0.0;
            std::stod(s);
            return std::stod(s);
        }
        catch (const std::invalid_argument&) {
            return -12234.0;
        }
    }
    static std::string removeQuotes(const std::string& str) {
        std::string result;
        for (char c : str) {
            if (c != '\"') {
                result += c;
            }
        }
        return result;
    }

    static Pair<List<Data*>, int> getData() {
        List<Data*> dataList;
        std::ifstream stream("data.csv");
        int i = 0;
        std::string capture;
        while (std::getline(stream, capture) && i < 200) {
            StringHelper st(capture);
            std::string* g = st.getCSValues2();
            dataList.push_back(new Data(canConvertToInt(g[0]), canConvertToInt(g[1]), canConvertToDouble(g[2]),
                canConvertToDouble(g[3]), removeQuotes(g[4]), g[5], g[6], g[7], removeQuotes(g[8]),
                g[9], canConvertToDouble(g[10]), canConvertToDouble(g[11]), canConvertToDouble(g[12]), canConvertToInt(g[13]),
                canConvertToDouble(g[14]), canConvertToDouble(g[15]), canConvertToDouble(g[16]), canConvertToInt(g[17]),
                g[18] == "\"n/r\"" ? 9999 : canConvertToInt(g[18]), canConvertToInt(g[19])));
            i++;
            delete[] g;
        }
        return Pair<List<Data*>, int>(dataList, i);
    }

    static void runTimedSorting(List<Data*> data, int amount, int sorting, int selectionOrMerge) {
        int results;
        long double time = Sorting::SelectionSort::timedSelectionSort(data, amount - 1, sorting);
        std::cout << "\nFinished running " << (selectionOrMerge == 1 ? "selection sort" : "merge sort") << " algorithm on the dataset..." << std::endl;
        std::cout << std::fixed << std::setprecision(8) << "Total time taken to sort the entire dataset: " << time << std::endl;
        std::string get = Screen::getLetterAnswer("Would you like to see the top or bottom x amount (1 for top 2 for bottom)", "1", "2");
        std::cout << "\nHow many results would you like to see?(0 - " << amount << "): ";
        std::cin >> results;
        results = results > amount ? amount : (get == "1" ? results : -results);
        Screen::printData(data, amount, results, get);
        Helper::exportFile(data, amount, results, get);

    }
    static void exportFile(List<Data*>d, int amount, int numRows, std::string menu_option) { // List<Data*>*
        if (Screen::getLetterAnswer("Would you like to export the file?(Y or N)"))
        {
            if (menu_option == "1")
            {
                Iterator<Data*> iter = d.begin();
                std::ofstream ou;
                std::string l;
                std::cout << "What would you like to call the file? (without extenstion): ";
                std::cin >> l;
                ou.open(l + ".csv");
                int count = 0;

                while (iter.get() != nullptr && count < amount)
                {
                    ou << iter.get()->getPlace() << "~" << iter.get()->getPop2023() << "~" << iter.get()->getGrowthRate() << "~" << iter.get()->getArea() << "~" << iter.get()->getCountry() << "~" << iter.get()->getCca3() << "~" << iter.get()->getCca2() << "~" << iter.get()->getCcn3() << "~" << iter.get()->getRegion() << "~" << iter.get()->getSubregion() << "~" << iter.get()->getLandAreaKm() << "~" << iter.get()->getDensity() << "~" << iter.get()->getDensityMi() << "~" << iter.get()->getRank() << "~" << iter.get()->getEpi2022() << "~" << iter.get()->getEpi2020() << "~" << iter.get()->getTenYrChange() << "~" << iter.get()->getUsn2022Rank() << "~" << iter.get()->getInts2020Rank() << "~" << iter.get()->getOverallRank() << std::endl;
                    iter.next();
                    count++;
                }
                std::cout << "Succesfully exported file: " << l << ".csv" << std::endl;

            }
            if (menu_option == "2")
            {
                std::ofstream ou;
                std::string l;
                std::cout << "What would you like to call the file? (without extenstion): ";
                std::cin >> l;
                ou.open(l + ".csv");
                numRows = numRows * -1;
                Iterator<Data*> iter = d.end();
                int count = 0;
                for (int i = 0; i < numRows - 1; i++)
                {
                    iter.previous();
                }
                while (count < numRows)
                {
                    ou << iter.get()->getPlace() << "~" << iter.get()->getPop2023() << "~" << iter.get()->getGrowthRate() << "~" << iter.get()->getArea() << "~" << iter.get()->getCountry() << "~" << iter.get()->getCca3() << "~" << iter.get()->getCca2() << "~" << iter.get()->getCcn3() << "~" << iter.get()->getRegion() << "~" << iter.get()->getSubregion() << "~" << iter.get()->getLandAreaKm() << "~" << iter.get()->getDensity() << "~" << iter.get()->getDensityMi() << "~" << iter.get()->getRank() << "~" << iter.get()->getEpi2022() << "~" << iter.get()->getEpi2020() << "~" << iter.get()->getTenYrChange() << "~" << iter.get()->getUsn2022Rank() << "~" << iter.get()->getInts2020Rank() << "~" << iter.get()->getOverallRank() << std::endl;
                    iter.next();
                    count++;

                }
            }
        }
    }
};
#endif
