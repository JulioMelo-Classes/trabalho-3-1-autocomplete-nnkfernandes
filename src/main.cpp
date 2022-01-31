#include <iostream>
#include "File.hpp"
#include "DataBase.hpp"
#include "Interface.hpp"
#include "Sentence.hpp"
#include <fstream>

/**
*@brief Verify if the path of file exists on the user system.
*@param path String containing the path of a file.
*@return Returns a boolean true if the file exists, or false if not.
*/
inline bool verify_file_exists(const std::string &name)
{
    std::ifstream f(name.c_str());
    return f.good();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Please provide the database file path. Ex: autocomplete ./filepath/file.txt";
        return -1;
    }

    std::string path = argv[1];
    if (!verify_file_exists(path))
    {
        std::cout << "Please provide a valide database file path.";
        return -1;
    }

    File file;

    std::vector<std::string> file_lines = file.loadFile(path);

    DataBase data_base;

    data_base.setFileLines(file_lines);
    std::vector<std::pair<long long int, std::string>> ordered_data = data_base.getOrderedData();

    Interface interface;

    interface.startInterface(ordered_data);

    return 0;
}
