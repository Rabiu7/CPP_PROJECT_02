#include <iostream>
#include <vector>
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}
int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOver = false;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (!gameOver) {
        displayBoard(board);
        std::cout << "Player " << currentPlayer << ", enter your move (row column): ";
        int row, col;
        std::cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameOver = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "It's a draw!" << std::endl;
                gameOver = true;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }
    std::cout << "Game over. Would you like to play again? (Y/N): ";
    char playAgain;
    std::cin >> playAgain;
    if (playAgain == 'Y' || playAgain == 'y') {
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
        gameOver = false;
        main();
    } else {
        std::cout << "Thank you for playing!" << std::endl;
    }
    return 0;
}
