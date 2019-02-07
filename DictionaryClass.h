//
//  DictionaryClass.h
//  DictionarySet
//
//  Created by Joshua Peckham on 2/20/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

#ifndef DictionaryClass_h
#define DictionaryClass_h

class Dictionary{
private:
    struct CheckNode{
        CheckNode* Next[MAX];
        bool Flag[MAX];
    };
    CheckNode* root;
    CheckNode* navi;
    int numWords;
public:
    Dictionary();
    Dictionary(string file);
    void addWord(string word);
    bool isWord(string word);
    bool isPrefix(string word);
    int wordCount();
};
Dictionary::Di
#endif /* DictionaryClass_h */
