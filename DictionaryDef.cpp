//
//  DictionaryDef.cpp
//  DictionarySet
//
//  Created by Joshua Peckham on 2/20/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

#include "DictionaryDef.hpp"
Dictionary::Dictionary(){
    CheckNode* newNode = new CheckNode;
    for( int i = 0; i < MAX; i++){
        newNode->Flag[i] = false;
        newNode->Next[i] = NULL;
    }
    root = navi = newNode;
    numWords = 0;
}
Dictionary::Dictionary(string file){
    CheckNode* newNode = new CheckNode;
    for( int i = 0; i < MAX; i++){
        newNode->Next[i] = nullptr;
        newNode->Flag[i] = false;
    }
    root = navi = newNode;
    numWords = 0;
    string word;
    ifstream inFile;
    
    inFile.open(file);
    if (inFile.is_open())
        cout << "Successfully Opended" << endl;
    
    while(!inFile.eof()){
        inFile >> word;

        addWord(word);
    }
    inFile.close();
}

void Dictionary::addWord(string word){
    char letter;
    navi = root;
    int location = 0;
    
    for (int i = 0; i < word.length(); i++){
        letter = word[i];
        location = (int)letter - (int)'a';
        
        if(navi->Next[location] == NULL){
            CheckNode* newNode = new CheckNode;
            for ( int m = 0; m < 26; m++){
                newNode->Flag[m] = false;
                newNode->Next[m] = NULL;
            }
            navi->Next[location] = newNode;
        }
        navi = navi->Next[location];
    }
    navi->Flag[location] = true;
    numWords++;
}
bool Dictionary::isWord(string word){
    char letter;
    navi = root;
    int location = 0;
    for(int i = 0; i < word.length(); i++){
        letter = word[i];
        location = (int)letter - (int)'a';
        if(navi->Next[location] == nullptr)
            return false;
        navi = navi->Next[location];
    }
    return navi->Flag[location];
}
bool Dictionary::isPrefix(string word){
    char letter;
    navi = root;
    int location = 0;
    for(int i = 0; i < word.length(); i++){
        letter = word[i];
        location = (int)letter - (int)'a';
        if (navi->Next[location] == NULL)
            return false;
        navi = navi->Next[location];
    }
    return true;
}
int Dictionary::getNumCount(){
    return numWords;
}
void Dictionary::dictionaryTest(){
    string command;
    cout << "Please insert a word in all lowercase to verify if the it has a prefix and is an actual word, to quit, please put a 0. \n Word: " << endl;
    cin >> command;
    while(command != "0"){
        if (isPrefix(command))
            cout << command << " is a Prefix. " << endl;
        else
            cout << command << " is not a Prefix. " << endl;
        if (isWord(command))
            cout << command << " is a Word." << endl;
        else
            cout << command << " is not a Word. " << endl;
        cout << "Word: ";
        cin >> command;
        cout << endl;
    }
}

