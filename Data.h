#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>
#include <iomanip>
#include "StringHelper.h"
class Data {
public:
    Data(int place, int pop2023, double growthRate, double area, std::string country, std::string cca3,
        std::string cca2, std::string ccn3, std::string region, std::string subregion, double landAreaKm,
        double density, double densityMi, int rank, double epi2022, double epi2020, double tenYrChange,
        int usn2022rank, int ints2020rank, int overallRank);

    int getPlace() const;
    int getPop2023() const;
    double getGrowthRate() const;
    double getArea() const;
    std::string getCountry() const;
    std::string getCca3() const;
    std::string getCca2() const;
    std::string getCcn3() const;
    std::string getRegion() const;
    std::string getSubregion() const;
    double getLandAreaKm() const;
    double getDensity() const;
    double getDensityMi() const;
    int getRank() const;
    double getEpi2022() const;
    double getEpi2020() const;
    double getTenYrChange() const;
    int getUsn2022Rank() const;
    int getInts2020Rank() const;
    int getOverallRank() const;

    friend std::ostream& operator<<(std::ostream& os, const Data& data);
private:
    int place;
    int pop2023;
    double growthRate;
    double area;
    std::string country;
    std::string cca3;
    std::string cca2;
    std::string ccn3;
    std::string region;
    std::string subregion;
    double landAreaKm;
    double density;
    double densityMi;
    int rank;
    double epi2022;
    double epi2020;
    double tenYrChange;
    int usn2022rank;
    int ints2020rank;
    int overallRank;
};

#endif
