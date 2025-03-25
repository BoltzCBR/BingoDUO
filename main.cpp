#include "bingo.h"

int main() {
    BingoCard playerCard;
    BingoGame game;
    char option;
    do {
        int number = game.drawNumber();
        cout << "Número sorteado: " << number << endl;
        playerCard.markNumber(number);
        playerCard.displayCard();
        game.displayDrawnNumbers();

        if (playerCard.checkWin()) {
            cout << "BINGO! Você venceu!" << endl;
            break;
        }
        cout << "Continuar? (s/n): ";
        cin >> option;
    } while (option == 's');

    return 0;
}
