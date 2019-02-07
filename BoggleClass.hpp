//
//  BoggleClass.hpp
//  DictionarySet
//
//  Created by Joshua Peckham on 2/25/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

#ifndef BoggleClass_hpp
#define BoggleClass_hpp
#include <stdio.h>
#include <string>
#include <fstream>


int const BBMAX = 4;

class BoggleClass : public Dictionary{
protected:
    char BoggleBoard[BBMAX][BBMAX];
    int tempBoard[BBMAX][BBMAX];
    string userWord[400];
    int userCorrectWords = 0;
    int amountWords = 0;
public:
    BoggleClass( );
    // Functions: create boggle board by choice of user
    // Precondition: must insert 16 characters
    // Postconditions: boggleboard will be set up
    BoggleClass(Dictionary);
    // Functions: tester of boggle
    // Precondition: n/a
    // Postconditions: demenstrates boggle works
    void choice();
    // Functions: asks if you want to set the board
    // Precondition: must be one character: Y/y means yes everything else means no
    // Postconditions: you either set the board or roll the dice
    void setBBoard();
    // Functions: Manually input letters
    // Precondition: must be single letter for each location
    // Postconditions: boggle board will be set up
    void randBoard();
    // Functions: rolls dice
    // Precondition: n/a
    // Postconditions: Sets Boggle Board
    void printBBoard(ofstream &outFile) const;
    // Functions: prints boggle board
    // Precondition: board must be initilized correctly
    // Postconditions: prints boggle board
    void printGBoard(ofstream &outFile) const;
    // Functions: prints game board (boggle board and tracking board)
    // Precondition: board must be initilized correctly
    // Postconditions: prints both boards
    void testSetBB();
    // Functions: predesignated board for testing perposes
    // Precondition: n/a
    // Postconditions: sets board
    void solveBoggle(Dictionary start, int table[][BBMAX], string word, int n, int m, int i, char choice, ofstream &outFile);
    // Functions: solves boggle board
    // Precondition: must initilized correctly
    // Postconditions: creates all solutions
    void SearchForWord(Dictionary start, char choice, ofstream &outFile);
    // Functions: accessor to solveBoggle
    // Precondition: must initilize board correctly and choice corecctly
    // Postconditions: solves boggle
    void StartGame(Dictionary start, ofstream& outFile);
    // Functions: play game of boggle
    // Precondition: dictionary must be loaded
    // Postconditions: play game
    void storeUserWord(ofstream&);
    // Functions: tracks user words
    // Precondition: board must be set up correctly
    // Postconditions: stores all user input words
    void checkUserWord(ofstream&);
    // Functions: checks for correct solutions
    // Precondition:board must be set up correctly
    // Postconditions: gives resultof how you did
};


#endif /* BoggleClass_hpp */
