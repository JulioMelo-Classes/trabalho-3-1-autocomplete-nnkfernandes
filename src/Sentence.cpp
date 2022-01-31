#include "Sentence.hpp"

Sentence::Sentence(){};


std::string Sentence::getSentence()
{
    return sentence;
};


void Sentence::setSentence(std::string new_sentence)
{
    sentence = new_sentence;
};

bool Sentence::isValid()
{
    return sentence != "";
};
