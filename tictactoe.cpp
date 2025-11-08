#include <iostream>
#include <string>
using namespace std;

// This class represents a player in the game
class Player {
private:
    string playerName;  // stores the name of the player
    char playerSymbol;  // stores X or O

public:
    // constructor to make a player
    Player(string name, char symbol) : playerName(name), playerSymbol(symbol) {}

    // getter for player name
    string getName() const { return playerName; }

    // getter for player symbol
    char getSymbol() const { return playerSymbol; }
};

// This class represents the whole TicTacToe game
class TicTacToe {
private:
    char gameBoard[3][3];  // 3x3 board for the game
    int totalMoves;        // keeps track of how many moves have been made
    Player* activePlayer;  // pointer to the player whose turn it is
    Player* playerX;       // pointer to player X
    Player* playerO;       // pointer to player O

public:
    // constructor initializes board and sets first player
    TicTacToe(Player* xPlayer, Player* oPlayer)
        : totalMoves(0), playerX(xPlayer), playerO(oPlayer), activePlayer(xPlayer) {
        // fill the board with spaces
        for (int row = 0; row < 3; ++row)
            for (int col = 0; col < 3; ++col)
                gameBoard[row][col] = ' ';
    }

    // prints the board to the screen
    void displayBoard() const {
        cout << "\n   0   1   2\n";  // column numbers
        for (int row = 0; row < 3; ++row) {
            cout << row << "  ";  // row number
            for (int col = 0; col < 3; ++col) {
                cout << gameBoard[row][col];  // print cell
                if (col < 2) cout << " | ";  // separator
            }
            cout << "\n";
            if (row < 2) cout << "  -----------\n";  // row divider
        }
    }

    // check if a move is valid
    bool isMoveValid(int row, int col) const {
        // has to be inside board and empty
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && gameBoard[row][col] == ' ');
    }

    // put a move on the board
    void placeMove(int row, int col) {
        gameBoard[row][col] = activePlayer->getSymbol();  // put X or O
        totalMoves++;  // increment total moves
    }

    // check if the active player won
    bool hasWinner() const {
        char symbol = activePlayer->getSymbol();  // get current player's symbol
        // check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((gameBoard[i][0] == symbol && gameBoard[i][1] == symbol && gameBoard[i][2] == symbol) ||
                (gameBoard[0][i] == symbol && gameBoard[1][i] == symbol && gameBoard[2][i] == symbol))
                return true;  // winner found
        }
        // check diagonals
        if ((gameBoard[0][0] == symbol && gameBoard[1][1] == symbol && gameBoard[2][2] == symbol) ||
            (gameBoard[0][2] == symbol && gameBoard[1][1] == symbol && gameBoard[2][0] == symbol))
            return true;  // winner found

        return false;  // no winner yet
    }

    // check if all cells are filled = draw
    bool isGameDraw() const { return totalMoves == 9; }

    // switch turn to the other player
    void toggleActivePlayer() {
        activePlayer = (activePlayer == playerX) ? playerO : playerX;
    }

    // main game loop
    void startGame() {
        while (true) {
            displayBoard();  // show current board

            // ask current player for move
            cout << "\n" << activePlayer->getName() << " (" << activePlayer->getSymbol()
                 << "), enter row and column (0-2) or type EXIT to quit: ";

            string rowInput, colInput;
            cin >> rowInput;

            // check if player wants to quit
            if (rowInput == "EXIT") {
                cout << "\nGame exited by " << activePlayer->getName() << ".\n";
                return;  // end game
            }

            cin >> colInput;
            if (colInput == "EXIT") {
                cout << "\nGame exited by " << activePlayer->getName() << ".\n";
                return;  // end game
            }

            // convert input from string to int
            int row = stoi(rowInput);
            int col = stoi(colInput);

            if (isMoveValid(row, col)) {  // check if move is valid
                placeMove(row, col);       // put it on board

                // check if current player won
                if (hasWinner()) {
                    displayBoard();
                    cout << "\n" << activePlayer->getName() << " wins!\n";
                    break;  // game over
                } 
                // check if game is draw
                else if (isGameDraw()) {
                    displayBoard();
                    cout << "\nIt's a draw!\n";
                    break;  // game over
                }

                toggleActivePlayer();  // switch turn
            } else {
                cout << "Invalid move. Try again.\n";  // spot taken or out of bounds
            }
        }
    }
};

int main() {
    string nameX, nameO;

    // get player names
    cout << "Enter name for Player 1 (X): ";
    getline(cin, nameX);
    cout << "Enter name for Player 2 (O): ";
    getline(cin, nameO);

    Player playerX(nameX, 'X');  // make X player
    Player playerO(nameO, 'O');  // make O player

    TicTacToe game(&playerX, &playerO);  // create game object
    game.startGame();                     // start game loop

    cout << "\nGame over.\n";  // finished
    return 0;
}
