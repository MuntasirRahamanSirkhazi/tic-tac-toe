#include <iostream>
#include <string>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    int turn; // 0 represents Player-2 who plays with O, 1 represents Player-1 who plays with X
    
    bool win_game_row() {
        // Checks Horizontal Win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
        }
        return false;
    }

    bool win_game_col() {
        // Checks Vertical Win
        for (int i = 0; i < 3; i++) {
            if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        return false;
    }

    bool win_game_diag1() {
        // Checks Diagonal Win
        return (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]);
    }

    bool win_game_diag2() {
        // Checks Diagonal Win
        return (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]);
    }

    bool completelyFilled() {
        // Checks if the board is completely filled
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-')
                    return false;
            }
        }
        return true;
    }

public:
    TicTacToe() {
        // Constructor to initialize the board
        fill_n(&board[0][0], 9, '-');
        turn = 1; // Player-1 starts the game
    }

    void display() {
        // Displays the board
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool filled(int row, int col) {
        // Checks if a cell is filled
        return (board[row][col] != '-');
    }

    void change(int row, int col) {
        // Changes the cell with the player's symbol
        if (turn == 0) {
            board[row][col] = 'O';
        } else {
            board[row][col] = 'X';
        }
        turn = (turn + 1) % 2; // Switch turns
    }

    bool game_over() {
        // Checks if the game is over (win or tie)
        return win_game_row() || win_game_col() || win_game_diag1() || win_game_diag2() || completelyFilled();
    }

    int getTurn() {
        // Returns the current turn
        return turn;
    }
};

int main() {
    TicTacToe game;
    int row, col;

    cout << "Player-1 will play with 'X'\n";
    cout << "Player-2 will play with 'O'\n\n";

    while (true) {
        game.display();

        cout << "Player-" << (game.getTurn() == 1 ? "1" : "2") << "'s turn.\n";
        cout << "Enter a row number (1-3): ";
        cin >> row;
        cout << "Enter a column number (1-3): ";
        cin >> col;

        row--; // Adjusting to array index (0-based)
        col--;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || game.filled(row, col)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        game.change(row, col);

        if (game.game_over()) {
            game.display();
            if (game.getTurn() == 1) {
                cout << "Player-2 won the game!\n";
            } else {
                cout << "Player-1 won the game!\n";
            }
            break;
        }
    }

    return 0;
}
