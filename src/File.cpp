#include "File.hpp"

File::File()
{
    file_lines.push_back("");
};

std::vector<std::string> File::loadFile(std::string path)
{
    std::ifstream file(path);
    std::string line;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            file_lines.push_back(line);
        }
        file.close();
    }

    return file_lines;
};
