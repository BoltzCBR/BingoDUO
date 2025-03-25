#include "bingo.h"

BingoCard::BingoCard() {
    generateCard();
}

void BingoCard::generateCard() {
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card[i][j] = rand() % 75 + 1;
        }
    }
    card[2][2] = 0; // Espaço livre no centro
}

void BingoCard::displayCard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card[i][j] == 0)
                cout << " * ";
            else
                cout << card[i][j] << " ";
        }
        cout << endl;
    }
}

bool BingoCard::markNumber(int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card[i][j] == number) {
                card[i][j] = 0; // Marca como chamado
                return true;
            }
        }
    }
    return false;
}

bool BingoCard::checkWin() {
    for (int i = 0; i < 5; i++) {
        bool win = true;
        for (int j = 0; j < 5; j++) {
            if (card[i][j] != 0) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }
    return false;
}

BingoGame::BingoGame() {
    srand(time(0));
}

int BingoGame::drawNumber() {
    int number;
    do {
        number = rand() % 75 + 1;
    } while (find(drawnNumbers.begin(), drawnNumbers.end(), number) != drawnNumbers.end());
    drawnNumbers.push_back(number);
    return number;
}

void BingoGame::displayDrawnNumbers() {
    cout << "Números sorteados: ";
    for (int num : drawnNumbers) {
        cout << num << " ";
    }
    cout << endl;
}
