/**
* @brief Interface class that contains all the cins and couts of the project
* @author Anny K. Fernandes
*/

#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <vector>
#include<string>

class Interface
{
    public:
    /**
    * @brief Default constructor
    * @details Simple constructor that creates a trivial Interface object
    */
    Interface();

    /**
    *@brief Do the main loop of the app, asking the user words to search in the databases.
    *@param ordered_data Vector of pairs of int and string containing the data of file ordered by name.
    */
    void startInterface(std::vector<std::pair<long long int, std::string>> ordered_data);

    /**
    *@brief Print on console the vector of results received by params.
    *@param result that is a vector of string.
    */
    void showResult(std::vector<std::string> result);
};

#endif // INTERFACE_HPP