#include "StringHelper.h"
/**
 * @brief A class to perform various operations on a string.
 */

 /**
  * @brief Builds a new string by replacing the existing string with a new one.
  *
  * @param newString The new string to be set as the mutableString.
  */
void StringHelper::buildNewString(std::string newString)
{
    this->mutableString = newString;
}

/**
 * @brief Replaces spaces in the mutableString with a custom identifier character.
 *
 * @param customIdentifier The character to replace spaces with.
 */
void StringHelper::addInSpaces(char customIdentifier)
{
    for (auto it = this->mutableString.begin(); it != this->mutableString.end(); ++it)
        if (*it == ' ') *it = customIdentifier;
}

/**
 * @brief Replaces spaces in a given string with a custom identifier character.
 *
 * @param tomod The string to modify.
 * @param customIdentifier The character to replace spaces with.
 */
void StringHelper::addInSpaces(std::string& tomod, char customIdentifier)
{
    for (auto it = tomod.begin(); it != tomod.end(); ++it)
        if (*it == ' ') *it = customIdentifier;
}

/**
 * @brief Replaces spaces in the mutableString with the default identifier character (~).
 */
void StringHelper::addInSpaces()
{
    for (auto it = this->mutableString.begin(); it != this->mutableString.end(); ++it)
        if (*it == ' ') *it = '~';
}

/**
 * @brief Replaces custom identifier characters in the mutableString with spaces.
 *
 * @param customIdentifier The character to replace with a space.
 */
void StringHelper::undoAddInSpaces(char customIdentifier) {
    for (auto it = this->mutableString.begin(); it != this->mutableString.end(); ++it)
        if (*it == customIdentifier) *it = ' ';
}

/**
 * @brief Replaces the default identifier character (~) in the mutableString with spaces.
 */
void StringHelper::undoAddInSpaces() {
    for (auto it = this->mutableString.begin(); it != this->mutableString.end(); ++it)
        if (*it == '~') *it = ' ';
}

/**
 * @brief Returns the mutableString.
 *
 * @return The mutableString.
 */
std::string StringHelper::get() const { return this->mutableString; }

/**
 * @brief Removes spaces in the mutableString that occur more than a specified amount of times consecutively.
 *
 * @param amount The maximum amount of consecutive spaces to allow.
 */
void StringHelper::removeMultipleSpaces(int amount) {
    std::string temp;
    for (auto it = this->mutableString.begin(); it != this->mutableString.end(); ++it) {
        if (*it == ' ') {
            int spaces = 0;
            while (it != this->mutableString.end() && *it == ' ') {
                ++it;
                ++spaces;
            }
            if (spaces < amount) {
                temp.append(spaces, '\0');
            }
        }
        else {
            temp += *it;
        }
    }
    this->mutableString = temp;
}

/**
 * @brief Replaces the default identifier character (~) in a given string with spaces.
 *
 * @param other The string to be modified.
 * @return The modified string.
 */
std::string StringHelper::undoAddInSpaces(std::string& other) {
    std::string temp = other;
    other = "";
    for (char c : temp) {
        c == '~' ? other += " " : other += c;
    }
    return other;
}
/**
 @brief Removes all instances of a given character from the string
 @param c The character to remove from the string
 */
void StringHelper::removeAll(char c) {
    std::string temp = this->mutableString;
    this->mutableString = "";
    for (char in : temp) {
        if (!(in == c)) { this->mutableString += in; }
    }
}
/**
 @brief Delimits the string up to the first instance of the given character
 @param c The delimiter character
 @return The portion of the string before the delimiter
 */
std::string StringHelper::deliminate(char c) {
    std::string toReturn;
    for (char in : this->mutableString) {
        if (in != c) toReturn += in;
        else return toReturn;
    }
    return this->mutableString;
}
/**
 @brief Delimits the given string up to the first instance of the given character
 @param toDeliminate The string to delimit
 @param toCheck The delimiter character
 @return The portion of the string before the delimiter
 */
std::string StringHelper::deliminate(std::string toDeliminate, char toCheck) {
    std::string toReturn;
    for (char in : toDeliminate) {
        if (in != toCheck) toReturn += in;
        else return toReturn;
    }
    return toDeliminate;
}
/**
 @brief Separates the string into individual words, delimited by spaces
 @return A vector of all the words in the string
 */
std::vector<std::string> StringHelper::getAllWords() {
    std::vector<std::string> strings;
    std::string fill;
    for (char c : this->mutableString) {
        if (c == ' ') {
            strings.push_back(fill);
            fill = "";
        }
        else {
            fill += c;
        }
    }
    strings.push_back(fill);
    return strings;
}
/**
 @brief Separates the string into individual values, delimited by the tilde character (~)
 @return A vector of all the values in the string
 */
std::vector<std::string> StringHelper::getCSValues() {
    std::vector<std::string> string;
    std::string str;
    for (char c : this->mutableString) {
        if (c == '~') {
            string.push_back(str);
            str = "";
        }
        else {
            str += c;
        }
    }
    string.push_back(str);
    return string;
}
/**
 @brief Separates the string into individual values, delimited by the tilde character (~)
 @return A std::string array/pointer of all the values in the current mutableString
 */
std::string* StringHelper::getCSValues2() {
    std::string* str_array = new std::string[21]; // Allocate memory for string array
    int index = 0;
    std::string str;
    for (char c : this->mutableString) {
        if (c == '~') {
            str_array[index++] = str;
            str = "";
        }
        else {
            str += c;
        }
    }
    str_array[index] = str; // Add the last substring to the string array
    return str_array;
}
void StringHelper::toLower() {
    std::transform(this->mutableString.begin(), this->mutableString.end(), this->mutableString.begin(), [](unsigned char c) { return std::tolower(c); });

}
std::string StringHelper::toLower(std::string& toLower) {
    std::transform(toLower.begin(), toLower.end(), toLower.begin(), [](unsigned char c) { return std::tolower(c); });
    return toLower;
}

std::string StringHelper::addCommasToNumber(long num) {
    std::string numStr = std::to_string(num);
    int n = (int)numStr.size();
    int numCommas = (n - 1) / 3;
    for (int i = 0; i < numCommas; i++) {
        int pos = n - (i + 1) * 3;
        numStr.insert(pos, ",");
    }
    return numStr;
}

std::string StringHelper::doubleToString(double value, int precision) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << value;
    std::string result = stream.str();
    // add trailing zeros if necessary
    int decimalPos = (int)result.find('.');
    if (decimalPos != std::string::npos && result.size() - decimalPos - 1 < precision) {
        result.append(precision - (result.size() - decimalPos - 1), '0');
    }
    else if (decimalPos == std::string::npos && precision > 0) {
        result += '.';
        result.append(precision, '0');
    }
    return result;
}
