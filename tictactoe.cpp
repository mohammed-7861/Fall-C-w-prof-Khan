#include <iostream>
#include <string>
using namespace std;

// Represents a player in the TicTacToe game
class Player {
private:
    string playerName;
    char playerSymbol;

public:
    Player(string name, char symbol) : playerName(name), playerSymbol(symbol) {}

    string getName() const { return playerName; }
    char getSymbol() const { return playerSymbol; }
};

// Represents the TicTacToe game logic and board
class TicTacToe {
private:
    char gameBoard[3][3];
    int totalMoves;
    Player* activePlayer;
    Player* playerX;
    Player* playerO;

public:
    TicTacToe(Player* xPlayer, Player* oPlayer)
        : totalMoves(0), playerX(xPlayer), playerO(oPlayer), activePlayer(xPlayer) {
        for (int row = 0; row < 3; ++row)
            for (int col = 0; col < 3; ++col)
                gameBoard[row][col] = ' ';
    }

    void displayBoard() const {
        cout << "\n   0   1   2\n";
        for (int row = 0; row < 3; ++row) {
            cout << row << "  ";
            for (int col = 0; col < 3; ++col) {
                cout << gameBoard[row][col];
                if (col < 2) cout << " | ";
            }
            cout << "\n";
            if (row < 2) cout << "  ---+---+---\n";
        }
    }

    bool isMoveValid(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && gameBoard[row][col] == ' ');
    }

    void placeMove(int row, int col) {
        gameBoard[row][col] = activePlayer->getSymbol();
        totalMoves++;
    }

    bool hasWinner() const {
        char symbol = activePlayer->getSymbol();
        for (int i = 0; i < 3; ++i) {
            if ((gameBoard[i][0] == symbol && gameBoard[i][1] == symbol && gameBoard[i][2] == symbol) ||
                (gameBoard[0][i] == symbol && gameBoard[1][i] == symbol && gameBoard[2][i] == symbol))
                return true;
        }
        if ((gameBoard[0][0] == symbol && gameBoard[1][1] == symbol && gameBoard[2][2] == symbol) ||
            (gameBoard[0][2] == symbol && gameBoard[1][1] == symbol && gameBoard[2][0] == symbol))
            return true;

        return false;
    }

    bool isGameDraw() const { return totalMoves == 9; }

    void toggleActivePlayer() {
        activePlayer = (activePlayer == playerX) ? playerO : playerX;
    }

    void startGame() {
        while (true) {
            displayBoard();
            cout << "\n" << activePlayer->getName() << " (" << activePlayer->getSymbol()
                 << "), enter row and column (0-2) or type EXIT to quit: ";

            string rowInput, colInput;
            cin >> rowInput;

            if (rowInput == "EXIT") {
                cout << "\nGame exited by " << activePlayer->getName() << ".\n";
                return;
            }

            cin >> colInput;
            if (colInput == "EXIT") {
                cout << "\nGame exited by " << activePlayer->getName() << ".\n";
                return;
            }

            int row = stoi(rowInput);
            int col = stoi(colInput);

            if (isMoveValid(row, col)) {
                placeMove(row, col);

                if (hasWinner()) {
                    displayBoard();
                    cout << "\n" << activePlayer->getName() << " wins!\n";
                    break;
                } else if (isGameDraw()) {
                    displayBoard();
                    cout << "\nIt's a draw!\n";
                    break;
                }
                toggleActivePlayer();
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }
    }
};

int main() {
    string nameX, nameO;

    cout << "Enter name for Player 1 (X): ";
    getline(cin, nameX);
    cout << "Enter name for Player 2 (O): ";
    getline(cin, nameO);

    Player playerX(nameX, 'X');
    Player playerO(nameO, 'O');

    TicTacToe game(&playerX, &playerO);
    game.startGame();

    cout << "\nGame over.\n";
    return 0;
}
