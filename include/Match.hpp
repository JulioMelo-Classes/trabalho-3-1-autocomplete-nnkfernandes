/**
* @brief Match class to provide the matches algoright using binary seach and all the
* process to find what autocompletes the sentence
* @author Anny K. Fernandes
*/
#ifndef MATCH_HPP
#define MATCH_HPP
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Match
{
    private:
    std::vector<std::pair<long long int, std::string>> matched_result; 
    std::vector<std::pair<long long int, std::string>> ordered_result;
    std::vector<std::string> final_result;
    
    /**
    *@brief Order the matched_results from class and pass the ordered value to ordered_result.
    */
    void orderMatchResult();


    public:
    /**
    * @brief Default constructor
    * @details Simple constructor that creates a trivial Match object
    */
    Match();

    /**
    *@brief Receives a string and a vector of pairs, and search in the vector for all strings that starts with the passed string.
    *@param sentence String to search in vector.
    *@param data vector of a pair of iten and string.
    *@return Returns the founded itens of vector that starts with the passed sentence.
    */
    std::vector<std::string> findMatch (std::string senteces, std::vector<std::pair<long long int, std::string>> data);

};

#endif // MATCH_HPP