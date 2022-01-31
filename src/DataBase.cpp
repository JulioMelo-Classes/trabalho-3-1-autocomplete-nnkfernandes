#include "../include/DataBase.hpp"

DataBase::DataBase(){};

std::vector<std::pair<long long int, std::string>> DataBase::getOrderedData()
{
    DataBase::orderData();
    return ordered_data;
};

void DataBase::setFileLines(std::vector<std::string> lines)
{
    file_lines = lines;
};

void DataBase::generatePairs()
{

    for (int i = 2; i < file_lines.size(); i++)
    {

        std::string current_line = file_lines[i];

        std::regex not_number_or_space("[^0-9 \t]+( |)[^0-9]+");

        std::sregex_iterator iterator_to_find_letter(current_line.begin(), current_line.end(), not_number_or_space);
        std::sregex_iterator last_match_to_letter;

        std::vector<std::string> word_vector;
        while (iterator_to_find_letter != last_match_to_letter)
        {
            std::smatch letter = *iterator_to_find_letter;
            word_vector.push_back(letter.str());
            iterator_to_find_letter++;
        }

        std::regex regex_to_number("[0-9]");

        std::sregex_iterator iterator_to_find_number(current_line.begin(), current_line.end(), regex_to_number);
        std::sregex_iterator last_match_to_number;

        std::vector<std::string> number_vector;
        while (iterator_to_find_number != last_match_to_number)
        {
            std::smatch number = *iterator_to_find_number;
            number_vector.push_back(number.str());
            iterator_to_find_number++;
        }

        std::ostringstream oss_word;
        for (std::string w : word_vector)
        {
            oss_word << w;
        }

        std::string word(oss_word.str());

        std::ostringstream oss_number;
        for (std::string n : number_vector)
        {
            oss_number << n;
        }
        std::string string_of_number(oss_number.str());
        std::stringstream ss_number;
        ss_number << string_of_number;
        int number;
        ss_number >> number;

        data_pairs.push_back(std::make_pair(number, word));
    }
};

/**
*@brief Compare a pair of int and string, and returns if the first item string is less in alphabetic orderd than the second item string.
*@param a Pair of int and string.
*@param b  Pair of int and string.
*@return Returns if a string is smaller than b string.
*/
bool comparePairOfStrings(const std::pair<int, std::string> &a,
                          const std::pair<int, std::string> &b)
{
    return (a.second < b.second);
};

void DataBase::orderData()
{
    DataBase::generatePairs();
    std::sort(data_pairs.begin(), data_pairs.end(), comparePairOfStrings);
    ordered_data = data_pairs;
};