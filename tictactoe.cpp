#include <iostream>
#include <string>
using namespace std;

// Function to get valid integer input between 1 and 3 for row/column
// Validates that input is a number and within the valid range, and reprompts if not
int isValidMove(const string &prompt)
{
    int coordinate;

    while (true)
    {
        cout << prompt;
        cin >> coordinate;

        // Check if input failed (user entered non-integer)
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a whole number between 1 and 3.\n";
        }
        // Check if number is out of range
        else if (coordinate < 1 || coordinate > 3)
        {
            cin.ignore(1000, '\n');
            cout << "Out of range. Please enter a number between 1 and 3.\n";
        }
        // Valid input!
        else
        {
            cin.ignore(1000, '\n');
            return coordinate;
        }
    }
}

// TicTacToe class represents the entire game
// Manages the board, players, and game logic
class TicTacToe
{
private:
    char board[3][3];   // 3x3 game board storing 'X, O, " "'
    char currentPlayer; // Tracks whose turn it is
    int moveCount;      // Counts total moves made (used to detect if there was a draw)

public:
    // Constructor initializes the game
    // Sets up empty board, starts with player X, and resets move count
    TicTacToe() : currentPlayer('X'), moveCount(0)
    {
        // Initialize all board positions to empty spaces
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                board[row][col] = ' ';
            }
        }
    }

    // Display the current state of the game board
    // Shows column numbers and row numbers for easy reference
    void displayBoard()
    {
        cout << "\n   1   2   3\n"; // Column headers
        for (int row = 0; row < 3; ++row)
        {
            cout << (row + 1) << "  "; // Row number (1-3)
            for (int col = 0; col < 3; ++col)
            {
                cout << board[row][col];
                if (col < 2)
                    cout << " | "; // Column separators
            }
            cout << "\n";
            if (row < 2)
                cout << "  -----------\n"; // Row separator
        }
        cout << "\n";
    }

    // Check if a move to the specified position is valid
    // Position must be within bounds and the space must be empty
    bool isValidMove(int row, int col)
    {
        // Convert from 1-based, which is user input, to 0-based, which is array indices
        row--;
        col--;

        // Check bounds and if space is empty
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    // Places the current player's symbol on the board
    // Updates the board and move count
    void makeMove(int row, int col)
    {
        // Convert from 1-based to 0-based indices
        board[row - 1][col - 1] = currentPlayer;
        moveCount++;
    }

    // Check if the current player has won the game
    // Checks all rows, columns, and diagonals for three in a row
    bool checkWinner()
    {
        // Check all rows for a win
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == currentPlayer &&
                board[i][1] == currentPlayer &&
                board[i][2] == currentPlayer)
            {
                return true;
            }
        }

        // Check all columns for a win
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == currentPlayer &&
                board[1][i] == currentPlayer &&
                board[2][i] == currentPlayer)
            {
                return true;
            }
        }

        // Check diagonal (top-left to bottom-right)
        if (board[0][0] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][2] == currentPlayer)
        {
            return true;
        }

        // Check diagonal (top-right to bottom-left)
        if (board[0][2] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][0] == currentPlayer)
        {
            return true;
        }

        return false; // No winner found
    }

    // Check if the game is a draw
    // Game is a draw when all 9 spaces are filled with no winner
    bool isDraw()
    {
        return moveCount == 9;
    }

    // Switch to the other player
    // Alternates between 'X' and 'O'
    void switchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Main game loop that runs the entire Tic-Tac-Toe game
    // Handles turn taking, input validation, and game ending conditions
    void playGame()
    {
        cout << "Tic-Tac-Toe Game!\n";
        cout << "Player 1: X | Player 2: O  (Do rock paper scissors, winner is player X)\n";
        cout << "Enter row and column numbers (1-3)\n";

        // Main game loop continues until someone wins or it's a draw
        while (true)
        {
            displayBoard();

            // Display whose turn it is
            cout << "Player " << currentPlayer << "'s turn\n";

            // Get valid row input from player
            int row = ::isValidMove("Enter row (1-3): ");

            // Get valid column input from player
            int col = ::isValidMove("Enter column (1-3): ");

            // Check if the chosen position is available
            if (isValidMove(row, col))
            {
                makeMove(row, col); // Place the move on the board

                // Check if current player won
                if (checkWinner())
                {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins! WOOHOO!!!\n";
                    break; // End game
                }

                // Check if game is a draw
                if (isDraw())
                {
                    displayBoard();
                    cout << "It's a draw!\n";
                    break; // End game
                }

                // No winner or draw yet, switch to other player
                switchPlayer();
            }
            else
            {
                // Position already taken, prompt player to try again
                cout << "That spot is already taken. Please try again.\n";
            }
        }
    }
};

// Main function, this is the entry point of the program
// Creates a TicTacToe game object and starts the game
int main()
{
    // Create a new Tic-Tac-Toe game
    TicTacToe game;

    // Start the game
    game.playGame();

    // Game over message
    cout << "\nThank you for playing!\n";

    return 0;
}