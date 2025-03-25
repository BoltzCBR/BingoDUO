#ifndef BINGO_H
#define BINGO_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class BingoCard {
private:
    int card[5][5];
public:
    BingoCard();
    void generateCard();
    void displayCard();
    bool markNumber(int number);
    bool checkWin();
};

class BingoGame {
private:
    vector<int> drawnNumbers;
public:
    BingoGame();
    int drawNumber();
    void displayDrawnNumbers();
};

#endif
