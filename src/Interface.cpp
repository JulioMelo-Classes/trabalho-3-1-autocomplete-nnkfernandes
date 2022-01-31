#include "Interface.hpp"
#include "Sentence.hpp"
#include "Match.hpp"



Interface::Interface(){};


void Interface::showResult(std::vector<std::string> result)
{
  if(result.size()> 0)
  {
  std::cout << ">>> The matches are:" << std::endl;
  for (auto i : result)
    std::cout << i << std::endl;
  } 
  else
  {
    std::cout << "no match found" << std::endl;
  }
}

void Interface::startInterface(std::vector<std::pair<long long int, std::string>> ordered_data)
{
  std::string user_input;
  Sentence setence;
  Match match;
  std::cout << ">>> Type a word  and hit ENTER or <ctrl>+d to quit: ";
  while (std::getline(std::cin, user_input))
  {
    setence.setSentence(user_input);
    if (setence.isValid())
    {
      showResult(match.findMatch(setence.getSentence(), ordered_data));
    }
    else
    {
      std::cout << "Please insert a valid setence" << std::endl;
    }
    std::cout << ">>> Type a word  and hit ENTER or <ctrl>+d to quit: ";
  }
}