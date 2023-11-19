#include <iostream>

using namespace std;

// Function prototypes
void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
bool makeMove(char board[3][3], char player, int row, int col);
bool checkWin(const char board[3][3], char player);
bool checkDraw(const char board[3][3]);
bool playAgain();

int main() {
    char currentPlayer = 'X';
    char board[3][3];

    do {
        initializeBoard(board);
        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw) {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): "<<endl;
            cout<<" The rows are 0,1 and 2 and coloums are 0,1 and 2"<<endl;
            cin >> row >> col;

            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            if (!makeMove(board, currentPlayer, row, col)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            gameWon = checkWin(board, currentPlayer);
            gameDraw = checkDraw(board);

            if (!gameWon && !gameDraw) {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        displayBoard(board);

        if (gameWon) {
            cout << "Player " << ((currentPlayer == 'X') ? 'O' : 'X') << " wins!\n";
        } else {
            cout << "It's a draw!\n";
        }
    } while (playAgain());

    cout << "Thanks for playing!\n";

    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool makeMove(char board[3][3], char player, int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    } else {
        return false;
    }
}

bool checkWin(const char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // If there is an empty space, the game is not a draw yet
            }
        }
    }
    return true; // All spaces are filled, indicating a draw
}

bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}


