#include "anagram_dict.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <unordered_set> // Include unordered_set for efficient duplicate removal

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::unordered_set; // Alias unordered_set for easier usage

// Helper function to sort characters in a string
string sort_string(const string& str) {
    string sorted_str = str;
    std::sort(sorted_str.begin(), sorted_str.end());
    return sorted_str;
}

/** 
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */ 
AnagramDict::AnagramDict(const string& filename)
{
    ifstream words(filename);
    string word;
    unordered_set<string> unique_words; // Use unordered_set to store unique words
    if (words.is_open()) {
        while (getline(words, word)) {
            // Remove duplicates from the input file
            unique_words.insert(word);
        }
    }
    // Now process unique words
    for (const auto& unique_word : unique_words) {
        // Sort the word to use as a key in the dict map
        string key = sort_string(unique_word);
        // Add the word to the corresponding anagram vector
        dict[key].push_back(unique_word);
    }
}

// Rest of your code remains the same...


/** 
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */ 
AnagramDict::AnagramDict(const vector< string >& words)
{
    for (const auto& word : words) {
        string key = sort_string(word);
        dict[key].push_back(word);
    }
}

/**
 * @param word The word to find anagrams of. 
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the 
 * word list.
 */
vector< string > AnagramDict::get_anagrams(const string& word) const
{
    string key = sort_string(word);
    auto it = dict.find(key);
    if (it != dict.end()) {
        return it->second;
    } else {
        return vector<string>();
    }
}       

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector< vector< string > > AnagramDict::get_all_anagrams() const
{
    vector< vector< string > > all_anagrams;
    for (const auto& pair : dict) {
        if (pair.second.size() > 1) {
            all_anagrams.push_back(pair.second);
        }
    }
    return all_anagrams;
}
