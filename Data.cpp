#include "Data.h"

Data::Data(int place, int pop2023, double growthRate, double area, std::string country, std::string cca3,
    std::string cca2, std::string ccn3, std::string region, std::string subregion, double landAreaKm, double density, double densityMi, int rank, double epi2022, double epi2020, double tenYrChange,
    int usn2022rank, int ints2020rank, int overallRank)
    : place(place), pop2023(pop2023), growthRate(growthRate), area(area), country(country), cca3(cca3),
    cca2(cca2), ccn3(ccn3), region(region), subregion(subregion), landAreaKm(landAreaKm), density(density),
    densityMi(densityMi), rank(rank), epi2022(epi2022), epi2020(epi2020), tenYrChange(tenYrChange),
    usn2022rank(usn2022rank), ints2020rank(ints2020rank), overallRank(overallRank) {}

int Data::getPlace() const {
    return place;
}


int Data::getPop2023() const {
    return pop2023;
}

double Data::getGrowthRate() const {
    return growthRate;
}


double Data::getArea() const {
    return area;
}


std::string Data::getCountry() const {
    return country;
}

std::string Data::getCca3() const {
    return cca3;
}


std::string Data::getCca2() const {
    return cca2;
}

std::string Data::getCcn3() const {
    return ccn3;
}


std::string Data::getRegion() const {
    return region;
}


std::string Data::getSubregion() const {
    return subregion;
}


double Data::getLandAreaKm() const {
    return landAreaKm;
}


double Data::getDensity() const {
    return density;
}

double Data::getDensityMi() const {
    return densityMi;
}


int Data::getRank() const {
    return rank;
}


double Data::getEpi2022() const {
    return epi2022;
}

double Data::getEpi2020() const {
    return epi2020;
}

double Data::getTenYrChange() const {
    return tenYrChange;
}

int Data::getUsn2022Rank() const {
    return usn2022rank;
}


int Data::getInts2020Rank() const {
    return ints2020rank;
}


int Data::getOverallRank() const {
    return overallRank;
}

std::ostream& operator<<(std::ostream& os, const Data& data) {
    std::string x = data.getInts2020Rank() == -1 ? "No Rank" : std::to_string(data.getInts2020Rank());
    os << std::fixed << std::setprecision(3) << "Place: " << data.getPlace() << std::endl
        << "Population in 2023: " << data.getPop2023() << std::endl
        << "Growth Rate: " << data.getGrowthRate() << std::endl
        << "Area: " << data.getArea() << std::endl
        << "Country: " << data.getCountry() << std::endl
        << "CCA3: " << data.getCca3() << std::endl
        << "CCA2: " << data.getCca2() << std::endl
        << "CCN3: " << data.getCcn3() << std::endl
        << "Region: " << data.getRegion() << std::endl
        << "Subregion: " << data.getSubregion() << std::endl
        << "Land Area (km²): " << data.getLandAreaKm() << std::endl
        << "Population Density (/km²): " << data.getDensity() << std::endl
        << "Population Density (/mi²): " << data.getDensityMi() << std::endl
        << "Rank: " << data.getRank() << std::endl
        << "EPI 2022: " << data.getEpi2022() << std::endl
        << "EPI 2020: " << data.getEpi2020() << std::endl
        << "Ten-year Change in EPI: " << data.getTenYrChange() << std::endl
        << "USN 2022 Rank: " << data.getUsn2022Rank() << std::endl
        << "INTS 2020 Rank: " << x << std::endl
        << "Overall Rank: " << data.getOverallRank() << std::endl;
    return os;
}
