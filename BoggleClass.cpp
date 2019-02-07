//
//  BoggleClass.cpp
//  DictionarySet
//
//  Created by Joshua Peckham on 2/25/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

#include "DictionaryDef.hpp"
#include "BoggleClass.hpp"
#include <ctime>
#include <iomanip>


BoggleClass::BoggleClass(){
    choice();
}
BoggleClass::BoggleClass(Dictionary test){
    testSetBB();
}
void BoggleClass::choice(){
    char n;
    cout << "Do you want to insert values yourself(y/n)?" << endl;
    cin >> n;
    if (n == 'y' || n == 'Y')
        setBBoard();
    else{
        cout << "Rolling Dice..." << endl;
        randBoard();
    }
    
}
void BoggleClass::randBoard(){
    srand(time(0));
    string diBoard[BBMAX][BBMAX];
    diBoard[0][0] = "aaeegn";
    diBoard[0][1] = "abbjoo";
    diBoard[0][2] = "achpos";
    diBoard[0][3] = "affkps";
    diBoard[1][0] = "aoottw";
    diBoard[1][1] = "cimotu";
    diBoard[1][2] = "deilrx";
    diBoard[1][3] = "delrvy";
    diBoard[2][0] = "distty";
    diBoard[2][1] = "eeghnw";
    diBoard[2][2] = "eeinsu";
    diBoard[2][3] = "ehrtvw";
    diBoard[3][0] = "eiosst";
    diBoard[3][1] = "elrtty";
    diBoard[3][2] = "himnuq";
    diBoard[3][3] = "hlnnrz";
    string tempWord;
    for(int n = 0; n < BBMAX; n++){
        for (int m = 0; m < BBMAX; m++){
            int choice = (int)rand() % 6;
            tempWord = diBoard[n][m];
            BoggleBoard[n][m] = tempWord[choice];
            tempBoard[n][m] = 0;
        }
    }

}
void BoggleClass::setBBoard(){
    for( int n = 0; n < BBMAX; n++){
        cout << "Row " << n << ":";
        for ( int m = 0; m < BBMAX; m++){
            cin >> BoggleBoard[n][m];
            tempBoard[n][m] = 0;
        }
    }
}
void BoggleClass::printBBoard(ofstream &outFile)const{
    cout << "Enter Board: \n" << "------------" << endl;
    outFile << "Enter Board: \n" << "------------" << endl;
    for( int n = 0; n < BBMAX; n++){
        for ( int m = 0; m < BBMAX; m++){
            cout << BoggleBoard[n][m] << " ";
            outFile << BoggleBoard[n][m] << " ";
        }
        cout << endl;
        outFile << endl;
    }
}
void BoggleClass::printGBoard(ofstream& outFile)const{
    for( int n = 0; n < BBMAX; n++){
        cout << BoggleBoard[n][0] << " " << BoggleBoard[n][1] << " " << BoggleBoard[n][2] << " " << BoggleBoard[n][3] << "\t\t" << tempBoard[n][0] << " " << tempBoard[n][1] << " " << tempBoard[n][2] << " " << tempBoard[n][3];
        cout << endl;
    }
    for( int n = 0; n < BBMAX; n++){
        for( int m = 0; m < BBMAX; m++){
            if(tempBoard[n][m] >0){
                outFile << setw(3) << " '" << BoggleBoard[n][m] << "'";
            }
            else{
                outFile << setw(4) << BoggleBoard[n][m] ;
            }
        }
        outFile << endl;
    }
    for( int n = 0; n < BBMAX; n++){
        for( int m = 0; m < BBMAX; m++){
            outFile << setw(3) << tempBoard[n][m];
        }
        outFile << endl;
    }

}

void BoggleClass::testSetBB(){
    BoggleBoard[0][0] = 'a';
    BoggleBoard[0][1] = 'q';
    BoggleBoard[0][2] = 'q';
    BoggleBoard[0][3] = 'q';
    BoggleBoard[1][0] = 'q';
    BoggleBoard[1][1] = 'l';
    BoggleBoard[1][2] = 'l';
    BoggleBoard[1][3] = 'q';
    BoggleBoard[2][0] = 'q';
    BoggleBoard[2][1] = 'q';
    BoggleBoard[2][2] = 'q';
    BoggleBoard[2][3] = 'y';
    BoggleBoard[3][0] = 'q';
    BoggleBoard[3][1] = 'q';
    BoggleBoard[3][2] = 'q';
    BoggleBoard[3][3] = 'q';
    
    for(int n = 0; n < BBMAX; n++){
        for (int m = 0; m < BBMAX; m++){
            tempBoard[n][m] = 0;
        }
    }
    
}
void BoggleClass::solveBoggle(Dictionary start, int tempBoard[][BBMAX], string word, int row, int col, int i, char choice, ofstream &outFile){
    word += BoggleBoard[row][col];
    
    if (row < 0 || row >= BBMAX || col < 0 || col >= BBMAX)
        return;
    if(tempBoard[row][col] > 0)
        return;
    if(!start.isPrefix(word))
        return;
    if(isWord(word))
        return;
    tempBoard[row][col] = i;
    if(start.isWord(word)){
        addWord(word);
        cout << "Word: " << word << "\n" << "Number of words: " << getNumCount() << endl;
        outFile  << "Word: " << word << "\n" << "Number of words: " << getNumCount() << endl;
        if(choice == 'y' || choice == 'Y'){
            printGBoard(outFile);
        }
    }
    solveBoggle(start, tempBoard, word, row-1, col, i+1, choice, outFile); //N
    solveBoggle(start, tempBoard, word, row, col+1, i+1, choice, outFile); //E
    solveBoggle(start, tempBoard, word, row+1, col, i+1, choice, outFile); //S
    solveBoggle(start, tempBoard, word, row, col-1, i+1, choice, outFile); //W
    solveBoggle(start, tempBoard, word, row-1, col+1, i+1, choice, outFile); //NE
    solveBoggle(start, tempBoard, word, row+1, col+1, i+1, choice, outFile); //SE
    solveBoggle(start, tempBoard, word, row-1, col-1, i+1, choice, outFile); //NW
    solveBoggle(start, tempBoard, word, row+1, col-1, i+1, choice, outFile); //SW
    
    tempBoard[row][col] = 0;
}
void BoggleClass::SearchForWord(Dictionary start, char choice, ofstream &outFile){
    
    for(int n = 0; n < BBMAX; n++){
        for ( int m = 0; m < BBMAX; m++){
            string word;
            int i = 1;
            solveBoggle(start, tempBoard, word, n, m, i, choice, outFile);
        }
    }
}
void BoggleClass::StartGame(Dictionary start, ofstream& outFile){
    char n;
    cout << "Rules: " << endl << "Please create a list of all the words you can create based on the Boggle Board. All words will be compared to all possible answers at the end of the game. You will get  a score saying how many correct out of the total possible solutions. When you are done wiht your word list, exit with 0." << endl;
    printBBoard(outFile);
    storeUserWord(outFile);
    cout << "Do you want to see the solutions with the board(y/n)?" << endl;
    cin >> n;
    SearchForWord(start, n, outFile);
    checkUserWord(outFile);
}
void BoggleClass::storeUserWord(ofstream& outFile){
    for (; ;amountWords++){
        cout << "Word " << amountWords << ":";
        outFile << "Word " << amountWords << ":";
        cin >> userWord[amountWords];
        if(userWord[amountWords] == "0")
            break;
    }
}
void BoggleClass::checkUserWord(ofstream& outFile){
    string check;
    for(int i = 0 ; i < amountWords ; i++){
        if(isWord(userWord[i])){
            userCorrectWords++;
        }
    }
    cout << "Correct amount of words found: " << userCorrectWords << "/" << getNumCount();
    outFile << "Correct amount of words found: " << userCorrectWords << "/" << getNumCount();
}
