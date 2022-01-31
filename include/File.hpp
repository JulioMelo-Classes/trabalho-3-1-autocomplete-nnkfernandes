/**
* @brief File class to access the file that contains the data will be processed
* @author Anny K. Fernandes
*/

#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>

class File
{
    private:
    
    std::vector<std::string> file_lines; 

    public:
    /**
    * @brief Default constructor
    * @details Simple constructor that creates a trivial File object
    */
    File();

    /**
    *@brief Load a file from user computer, using the path passed by params.
    *@param path String containing the path of a file.
    *@return Returns a vector of strings that contains each line of file.
    */
    std::vector<std::string> loadFile(std::string path);
};
#endif // FILE_HPP