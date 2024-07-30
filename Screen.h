// This class provides utility functions for input and output.
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <iomanip>
#include "List.h"
#include "Node.h"
#include "Data.h"
#include "StringHelper.h"

class Screen
{
public:
    /**
     @brief Gets a answer given by user to verify it
     @param prompt the message you want to give to the user
     @return bool
     */
    static bool getLetterAnswer(std::string prompt)
    {
        std::string in;
        std::cout << prompt << ": "; // Prompts the user with the given message.
        std::cin >> in; // Reads the user's input.
        while (in != "Y" && in != "y" && in != "N" && in != "n") // Validates the input to ensure it's a yes or no answer.
        {
            std::cout << "That answer was not recognized.\nTry again: "; // Prompts the user to try again if the input is invalid.
            std::cin >> in; // Reads the user's input again.
        }
        return in == "y" || in == "Y"; // Returns true if the user entered "y" or "Y", false otherwise.
    }
    /**
     @brief This static method prompts the user to choose between two options and returns the chosen option.
     @param prompt the message you want to give to the user
     @param c1 the first custom value to check
     @param c2 the second custom value to check.
     @return std::string
     */
    static std::string getLetterAnswer(std::string prompt, std::string c1, std::string c2)
    {
        std::string in;
        std::cout << prompt << ": "; // Prompts the user with the given message.
        std::cin >> in; // Reads the user's input.
        while (in != c1 && in != c2) // Validates the input to ensure it's one of the two specified options.
        {
            std::cout << "That answer was not recognized.\nTry again: "; // Prompts the user to try again if the input is invalid.
            std::cin >> in; // Reads the user's input again.
        }
        return in; // Returns the user's chosen option.
    }
    /**
     @brief This static method prompts the user to choose from a list of options and returns the chosen option.
     @param prompt the message you want to give to the user
     @param strings an array of strings that are OK answers to the prompt
     @param stringLength the length of the strings array
     @return std::string
     */
    static std::string getLetterAnswer(std::string prompt, std::string* strings, int stringLength)
    {
        bool it = false; // Flag to indicate if a valid input has been received.
        std::string in;
        std::cout << prompt << ": "; // Prompts the user with the given message.
        std::cin >> in; // Reads the user's input.
        for (int i = 0; i < stringLength; i++) // Iterates through the list of options.
        {
            if (in == strings[i]) { it = true; break; } // If the input matches one of the options, set the flag and exit the loop.
        }
        if (!it) { getLetterAnswer(prompt, strings, stringLength); } // If no valid input was received, prompts the user to try again.
        return in; // Returns the user's chosen option.
    }

    /**
     @brief This template method prompts the user to enter input of the given type and saves it to the given variable.
     @param prompt the message you want to give to the user
     @param toSave the template type of object to save the data
     */
    template <typename T>
    static void getProtectedInput(std::string prompt, T& toSave)
    {
        while (std::cin.fail()) // Loops while the input stream is in a fail state.
        {
            clear(); // Clears the input stream and any remaining input.
            std::cout << prompt << ": "; // Prompts the user with the given message.
            std::cin >> toSave; // Reads the user's input.
        }
    }

    /**
     @brief This static method clears the input stream and any remaining input.
     */
    static void clear()
    {
        std::cin.clear(); // Clears the fail state of the input stream
        std::string toClear;
        std::getline(std::cin, toClear); // Reads and discards any remaining input
    }

    /**
     @brief This static method displays a selection screen with options and returns the user's selection.
     */
    static std::string greetAndSelectionScreen(bool reRun)
    {
        std::string get = "NULL";
        if (reRun || Screen::getLetterAnswer("Welcome to my sorting program, would you like to try it? (Y or N)")) {
            std::string str[2] = { "1", "2" }; // An array of valid choices
            std::cout << "\nPlease choose an option from below (1 or 2): " << std::endl;
            std::cout << "1. Selection sort on the data." << std::endl;
            //std::cout << "2. Merge sort on the data." << std::endl;
            std::cout << "2. Quit." << std::endl;
            get = Screen::getLetterAnswer("Please choose either 1 or 2", str, 2); // Calls the getLetterAnswer method to get the user's choice
        }
        return get == "2" ? "NULL" : get;
    }

    static std::string sortingCriteria() {
        std::string get;
        std::string str[12] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" }; // An array of valid choices
        std::cout << "\nPlease choose a sorting critera from below (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12): " << std::endl;
        std::cout << "1. Sort by place." << std::endl;
        std::cout << "2. Sort by population." << std::endl;
        std::cout << "3. Sort by growth rate." << std::endl;
        std::cout << "4. Sort by country(alphabetically)." << std::endl;
        std::cout << "5. Sort by region(alphabetically)." << std::endl;
        std::cout << "6. Sort by rank." << std::endl;
        std::cout << "7. Sort by 2022 EPI ranking." << std::endl;
        std::cout << "8. Sort by 2020 EPI ranking." << std::endl;
        std::cout << "9. Sort by 2022 US News rank." << std::endl;
        std::cout << "10. Sort by 2020 Internations rank." << std::endl;
        std::cout << "11. Sort by overall rank." << std::endl;
        std::cout << "12. Quit." << std::endl;
        get = Screen::getLetterAnswer("Please choose a number between 1-12", str, 12); // Calls the getLetterAnswer method to get the user's choice
        return get == "12" ? "NULL" : get;
    }

    static std::string centerAlign(const std::string& s, int width) {
        if (s.length() >= width) {
            return s.substr(0, width);
        }

        int leftPadding = (int)(width - s.length()) / 2;
        int rightPadding = (int)(width - s.length() - leftPadding);

        std::string padded = std::string(leftPadding, ' ') + s + std::string(rightPadding, ' ');

        return padded;
    }

    static void printData(List<Data*> data, int amount, int numRows, std::string menu_Option) {
        const int WIDTH = 169, PLACE_WIDTH = 6,
            POP_WIDTH = 15, GROWTH_WIDTH = 13, COUNTRY_WIDTH = 24,
            REGION_WIDTH = 18, RANK_WIDTH = 9, EPI_WIDTH = 10,
            USN_WIDTH = 15, INTS_WIDTH = 15, OVERALL_WIDTH = 11;
        std::string get = numRows < 0 ? ("\nDisplaying the bottom " + std::to_string(-numRows) + " rows.") : ("\nDisplaying the top " + std::to_string(numRows) + " rows.");
        std::cout << get << std::endl;
        // print table header
        std::cout << std::string(WIDTH, '-') << std::endl;
        std::cout << "| " << centerAlign("Place", PLACE_WIDTH)
            << "| " << centerAlign("Population", POP_WIDTH)
            << "| " << centerAlign("Growth Rate", GROWTH_WIDTH)
            << "| " << centerAlign("Country", COUNTRY_WIDTH)
            << "| " << centerAlign("Region", REGION_WIDTH)
            << "| " << centerAlign("Rank", RANK_WIDTH)
            << "| " << centerAlign("EPI 2022", EPI_WIDTH)
            << "| " << centerAlign("EPI 2020", EPI_WIDTH)
            << "| " << centerAlign("USN 2022 Rank", USN_WIDTH)
            << "| " << centerAlign("INTS 2020 Rank", INTS_WIDTH)
            << "| " << centerAlign("Overall", OVERALL_WIDTH)
            << "|" << std::endl;
        std::cout << std::string(WIDTH, '-') << std::endl;
        if (menu_Option == "1")
        {
            Iterator<Data*> iter = data.begin();
            int count = 0;
            while (iter.get() != nullptr && count < numRows)
            {
                std::cout << "| " << centerAlign(std::to_string(iter.get()->getPlace()), PLACE_WIDTH)
                    << "| " << std::setw(15) << std::left << StringHelper::addCommasToNumber(iter.get()->getPop2023())
                    << "| " << centerAlign(StringHelper::doubleToString(iter.get()->getGrowthRate(), 5) + " %", GROWTH_WIDTH)
                    << "| " << centerAlign(iter.get()->getCountry(), COUNTRY_WIDTH)
                    << "| " << centerAlign(iter.get()->getRegion(), REGION_WIDTH)
                    << "| " << centerAlign(std::to_string(iter.get()->getRank()), RANK_WIDTH)
                    << "| " << centerAlign(StringHelper::doubleToString(iter.get()->getEpi2022(), 1), EPI_WIDTH)
                    << "| " << centerAlign(StringHelper::doubleToString(iter.get()->getEpi2020(), 1), EPI_WIDTH)
                    << "| " << centerAlign(std::to_string(iter.get()->getUsn2022Rank()), USN_WIDTH)
                    << "| " << centerAlign(iter.get()->getInts2020Rank() == 9999 ? "No Rank" : std::to_string(iter.get()->getInts2020Rank()), INTS_WIDTH)
                    << "| " << centerAlign(std::to_string(iter.get()->getOverallRank()), OVERALL_WIDTH)
                    << "|" << std::endl;
                iter.next();
                count++;
            }
            std::cout << std::string(WIDTH, '-') << std::endl;
        }
        if (menu_Option == "2")
        {// Reverse the linked list
            numRows = numRows * -1;
            Iterator<Data*> iter = data.end();
            int count = 0;
            for (int i = 0; i < numRows - 1; i++)
            {
                iter.previous();
            }
            while (count < numRows)
            {
                if (iter.get() != nullptr)
                {
                    std::cout << "| " << centerAlign(std::to_string(iter.get()->getPlace()), PLACE_WIDTH)
                        << "| " << std::setw(15) << std::left << StringHelper::addCommasToNumber(iter.get()->getPop2023())
                        << "| " << centerAlign(StringHelper::doubleToString(iter.get()->getGrowthRate(), 5) + " %", GROWTH_WIDTH)
                        << "| " << centerAlign(iter.get()->getCountry(), COUNTRY_WIDTH)
                        << "| " << centerAlign(iter.get()->getRegion(), REGION_WIDTH)
                        << "| " << centerAlign(std::to_string(iter.get()->getRank()), RANK_WIDTH)
                        << "| " << centerAlign(StringHelper::doubleToString(iter.get()->getEpi2022(), 1), EPI_WIDTH)
                        << "| " << centerAlign(StringHelper::doubleToString(iter.get()->getEpi2020(), 1), EPI_WIDTH)
                        << "| " << centerAlign(std::to_string(iter.get()->getUsn2022Rank()), USN_WIDTH)
                        << "| " << centerAlign(iter.get()->getInts2020Rank() == 9999 ? "No Rank" : std::to_string(iter.get()->getInts2020Rank()), INTS_WIDTH)
                        << "| " << centerAlign(std::to_string(iter.get()->getOverallRank()), OVERALL_WIDTH)
                        << "|" << std::endl;
                }
                iter.previous();
                count++;
            }
            std::cout << std::string(WIDTH, '-') << std::endl;
        }
    }

};
#endif


