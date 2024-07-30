#ifndef StringHelper_H
#define StringHelper_H
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
/**
 @brief A template structure to hold two data members.
 @tparam T the first data member
 @tparam U the second data member
 */
template<typename T, typename U>
struct Pair {
    Pair<T, U>() {}
    Pair<T, U>(T data, U data2) : first(data), second(data2) {}
    T first;
    U second;
};
class StringHelper
{
public:
    StringHelper() {}
    StringHelper(std::string str) : mutableString(str) {}

    // Makes a new string (used to make or reset the current mutableString)
    void buildNewString(std::string);

    // Adds ~ into all spaces
    void addInSpaces();
    void addInSpaces(char);
    static void addInSpaces(std::string&);

    // Removes all ~ in the mutable string
    void undoAddInSpaces();
    void undoAddInSpaces(char);
    static std::string undoAddInSpaces(std::string&);

    // Returns the mutableString
    std::string get() const;

    // Insert -1 to remove all spaces at the end of a string
    // Or any number to remove that many amout of spaces
    void removeMultipleSpaces(int);

    std::string deliminate(char);
    static std::string deliminate(std::string, char);

    std::vector<std::string> getCSValues();
    std::string* getCSValues2();

    static void addInSpaces(std::string&, char);

    std::vector<std::string> getAllWords();

    void removeAll(char);

    static std::string toLower(std::string&);
    void toLower();

    static std::string addCommasToNumber(long);
    static std::string doubleToString(double, int);


    friend std::ostream& operator<<(std::ostream& os, const StringHelper& string)
    {
        os << string.mutableString;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, StringHelper& sh)
    {
        is >> sh.mutableString;
        return is;
    }

private:
    std::string mutableString;
};
#endif
