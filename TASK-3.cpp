#include <iostream>
using namespace std;

const int SIZE = 3;

class TicTacToe {
private:
    char Board[SIZE][SIZE];
    char CPlayer;

public:
    TicTacToe() {
        initializeBoard();
        CPlayer = 'X';
    }

    void initializeBoard() {
        char count = '1';
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                Board[i][j] = count++;
            }
        }
    }

    void DrawBoard() {
    cout << "====== Tic-Tac-Toe Game ======" << '\n';
    for (int i = 0; i < SIZE; i++) {
        cout << '\t';
        for (int j = 0; j < SIZE; j++) {
            cout << " " << Board[i][j];
            if (j < SIZE - 1) cout << " |";
        }
        cout << '\n';
        if (i < SIZE - 1) cout << "\t---|---|---\n";
    }
    cout << '\n';
}


    void placeMarker(int slot) {
        int row = (slot - 1) / SIZE;
        int col = (slot - 1) % SIZE;
        Board[row][col] = CPlayer;
    }

    bool checkWin() {
        for (int i = 0; i < SIZE; i++) {
            if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2]) return true;
            if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i]) return true;
        }
        if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2]) return true;
        if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0]) return true;
        return false;
    }

    bool checkTie() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (Board[i][j] != 'X' && Board[i][j] != 'O') {
                    return false;
                }

            }
        }
        return true;
    }

    void switchPlayer() {
        CPlayer = (CPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int slot;
        bool gameOver = false;

        while (!gameOver) {
            DrawBoard();
            cout << "PLAYER " << CPlayer << ", ENTER A NUMBER (1-9): ";
            cin >> slot;

            placeMarker(slot);

            if (checkWin()) {
                DrawBoard();
                cout << " Congratulation !!..."<< "PLAYER " << CPlayer << " ... wins!\n";
                gameOver = true;
            } else if (checkTie()) {
                DrawBoard();
                cout << "It's a tie! Play Again\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.play();

    return 0;
}
