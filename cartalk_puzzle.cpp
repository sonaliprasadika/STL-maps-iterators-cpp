/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of 
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<StringTriple> cartalk_puzzle(PronounceDict d, const string& word_list_fname)
{
    vector<StringTriple> solutions;

    ifstream words(word_list_fname);
    string word;

    while (getline(words, word))
    {
        // Check if the word has at least 5 characters
        if (word.size() >= 5)
        {
            // Check if removing the first and second characters results in homophones
            string word1 = word.substr(1); // Remove the first character
            string word2 = word.substr(0, 1) + word.substr(2); // Remove the second character

            // Check if all variations are homophones
            if (d.homophones(word, word1) && d.homophones(word, word2) && d.homophones(word1, word2))
            {
                // If all variations are homophones, add the StringTriple to the solutions vector
                solutions.push_back(make_tuple(word, word1, word2));
            }
        }
    }

    return solutions;
}
