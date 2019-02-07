//
//  main.cpp
//  DictionarySet
//
//  Created by Joshua Peckham on 2/16/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//
#include "DictionaryDef.hpp"
#include "BoggleClass.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile;
    string name;
    cout << "What is the file name you want to store the results in?" << endl;
    cin >> name;
    
    outFile.open(name);
    if(outFile.is_open())
        cout << "Success" << endl;
    else
        cout << "Fail" << endl;
    Dictionary tester("Dictionary.txt");
    BoggleClass test(tester);
    cout << "Test Plan" << endl;
    test.testSetBB();
    test.printBBoard(outFile);
    cout << "Expected Words: al, all, ally, la" << endl;
    test.SearchForWord(tester, 'y', outFile);
    char choice;
    cout << "Amount loaded: " << tester.getNumCount() << endl << "Want to test the dictionary?(y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
        tester.dictionaryTest();
    BoggleClass Start;
    Start.StartGame(tester, outFile);
    cout << endl << endl;
    
    return 0;
}
