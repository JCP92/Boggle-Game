//
//  DictionaryDef.hpp
//  DictionarySet
//
//  Created by Joshua Peckham on 2/20/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

#ifndef DictionaryDef_hpp
#define DictionaryDef_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int MAX = 26;
class Dictionary{
protected:
    struct CheckNode{
        CheckNode* Next[MAX];
        bool Flag[MAX];
    };
    CheckNode* root;
    CheckNode* navi;
    int numWords;
public:
    Dictionary();
    // Function: Initialize the class and create the first node
    // Precondition: n/a
    // Postcondition: First node activated
    Dictionary(string file);
    // Function: Initialize node and develope the dicitionary tree
    // Precondition: must have a file to upload in tree
    // Postcondition: The tree is created with all words
    void addWord(string word);
    // Function: add a word to the dictionary
    // Precondition: word must not exist in tree
    // Postcondition: add word to tree
    bool isWord(string word);
    // Function: verify that it is a word
    // Precondition: n/a
    // Postcondition: will verify if the word is there
    bool isPrefix(string word);
    // Function: determines if their is more words based on what is given
    // Precondition: n/a
    // Postcondition: tells if it is a prefix
    int getNumCount();
    // Function: keep track of words
    // Precondition: n/a
    // Postcondition: will return amount of words
    void dictionaryTest();
    // Functions: test dictionary class
    // Precondition: n/a
    // Postconditions: n/a
};

#endif /* DictionaryDef_hpp */
