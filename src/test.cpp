#include <iostream>
#include <fstream>
#include <filesystem>
#include "File.hpp"
#include "DataBase.hpp"
#include "Sentence.hpp"
#include "Match.hpp"

#include "test_manager.h"

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

int main()
{
  std::string path = "test.txt";

  File file;

  std::vector<std::string> file_lines = file.loadFile(path);

  DataBase data_base;

  data_base.setFileLines(file_lines);
  std::vector<std::pair<long long int, std::string>> ordered_data = data_base.getOrderedData();

  TestManager tm{"Interator Template Tests"};

  std::cout << "running tests" << std::endl;

  {
    Match match;
    BEGIN_TEST(tm, "Test em", "Input: em; test if returns the right suggestions;");
    auto result = match.findMatch("em", ordered_data);
    std::vector<std::string> expected_result;
    expected_result.push_back("embroidered");
    expected_result.push_back("emerson");

    EXPECT_TRUE(std::equal(result.begin(), result.begin() + 2, expected_result.begin()), "At main.cpp line " + std::to_string(__LINE__));
  }

  {
    Match match;
    BEGIN_TEST(tm, "Test th", "Input: th; test if returns the right suggestions;");

    auto result = match.findMatch("th", ordered_data);
    std::vector<std::string> expected_result;
    expected_result.push_back("the");
    expected_result.push_back("that");

    EXPECT_TRUE(std::equal(result.begin(), result.begin() + 2, expected_result.begin()), "At main.cpp line " + std::to_string(__LINE__));
  }

  tm.summary();
  return 0;
}
