/**
* @brief Sentence class to store the user request
* @author Anny K. Fernandes
*/

#ifndef SENTENCE_HPP
#define SENTENCE_HPP
#include <iostream>
#include <string>
class Sentence
{
    private:

    std::string sentence;
        
    public:

    /**
    * @brief Default constructor
    * @details Simple constructor that creates a trivial Sentence object
    */
    Sentence();

    /**
    *@brief Get the sentence value.
    *@return Retuns the value of attribute sentence.
    */
    std::string getSentence(); 


    /**
    *@brief Set the attribute of classe sentence to the new sentence.
    *@param new_sentence String containing the value of new sentence.
    */
    void setSentence(std::string new_sentence);  

    
    /**
    *@brief Verify if the sentence is valid.
    *@return Returns true if validated or false if not.
    */
    bool isValid();
};

#endif // SENTENCE_HPP