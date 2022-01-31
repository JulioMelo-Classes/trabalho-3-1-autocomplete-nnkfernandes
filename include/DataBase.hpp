/**
* @brief DataBase to read the data from the data base and store it apropriately
* @author Anny K. Fernandes
*/

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <regex>

class DataBase
{
    private:
    
    std::vector<std::string> file_lines;
    std::vector<std::pair<long long int, std::string>> data_pairs;
    std::vector<std::pair<long long int, std::string>> ordered_data;

    /**
    *@brief Receive the array of strings and separate the lines in pairs of numbers and string and return.
    */
    void generatePairs();

    /**
    *@brief Call the generate pairs, order the generated data  and pass the data to the ordered_data.
    */
    void orderData();

    public:

    /**
    * @brief Default constructor
    * @details Simple constructor that creates a trivial DataBase object
    */
    DataBase();


    /**
    *@brief function to give access to ordered pairs generated
    *@return vector of pairs ordered alphabeticaly
    */
    std::vector<std::pair<long long int, std::string>> getOrderedData();


    /**
    *@brief Compare a pair of int and string, and returns if the first item string is less in alphabetic orderd than the second item string.
    *@param lines Vector of strings.
    *@return Returns if a string is smaller than b string.
    */
    void setFileLines(std::vector<std::string> lines);
};

#endif // DATABASE_HPP