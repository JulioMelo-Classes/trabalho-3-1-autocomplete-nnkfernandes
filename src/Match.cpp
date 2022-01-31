#include "Match.hpp"

Match::Match(){};

/**
*@brief Do a binary search checking in an vector of pair for a string that initialize with another string.
*@param vector vector of pairs of int and string.
*@param l Initial position to search.
*@param r Final position to search.
*@param search String to search inside the vector.
*@return Returns the founded itens of vector that starts with the passed sentence.
*/
std::pair<std::pair<long long int, std::string>, int> binarySearch(std::vector<std::pair<long long int, std::string>> vector, int l, int r, std::string search)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        std::string middleString = vector[mid].second;
        std::string searchLowed = search;
        std::for_each(middleString.begin(), middleString.end(), [](char &c)
                      { c = ::tolower(c); });
        std::for_each(searchLowed.begin(), searchLowed.end(), [](char &c)
                      { c = ::tolower(c); });

        if (middleString.rfind(searchLowed, 0) == 0)
            return std::make_pair(vector[mid], mid);

        if (middleString > searchLowed)
            return binarySearch(vector, l, mid - 1, search);

        return binarySearch(vector, mid + 1, r, search);
    }
    return std::make_pair(vector[0], -1);
}


std::vector<std::string> Match::findMatch(std::string sentence, std::vector<std::pair<long long int, std::string>> data)
{

    std::pair<std::pair<long long int, std::string>, int> result = binarySearch(data, 0, data.size() - 1, sentence);
    if (result.second == -1)
        return final_result;

    matched_result.push_back(result.first);
    int positionToSearchMore = result.second;

    std::string lowedSentence = sentence;
    std::for_each(lowedSentence.begin(), lowedSentence.end(), [](char &c)
                  { c = ::tolower(c); });
    bool aux = true;
    while (aux)
    {
        std::string stringToCompare = data[positionToSearchMore + 1].second;
        std::for_each(stringToCompare.begin(), stringToCompare.end(), [](char &c)
                      { c = ::tolower(c); });

        if (stringToCompare.rfind(lowedSentence, 0) == 0)
        {
            matched_result.push_back(data[positionToSearchMore + 1]);
            positionToSearchMore++;
        }
        else
            aux = false;
    }
    positionToSearchMore = result.second;
    aux = true;
    while (aux)
    {
        std::string stringToCompare = data[positionToSearchMore - 1].second;
        std::for_each(stringToCompare.begin(), stringToCompare.end(), [](char &c)
                      { c = ::tolower(c); });
        if (stringToCompare.rfind(lowedSentence, 0) == 0)
        {
            matched_result.push_back(data[positionToSearchMore - 1]);
            positionToSearchMore--;
        }
        else
            aux = false;
    }

    Match::orderMatchResult();

    for (int i = 0; i < ordered_result.size(); i++)
    {
        final_result.push_back(ordered_result[i].second);
    }

    return final_result;
};



bool comparePair(const std::pair<int, std::string> &a,
                 const std::pair<int, std::string> &b)
{
    return (a.first > b.first);
};

void Match::orderMatchResult()
{

    std::sort(matched_result.begin(), matched_result.end(), comparePair);
    ordered_result = matched_result;
};
