#include <iostream>
#include <ctime>
using namespace std;

void map(char* position) {
    cout << "\n     |     |     \n";
    cout << "  " << position[0] << "  |  " << position[1] << "  |  " << position[2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << position[3] << "  |  " << position[4] << "  |  " << position[5] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << position[6] << "  |  " << position[7] << "  |  " << position[8] << "  \n";
    cout << "     |     |     \n\n";
}

void botMove(char* position, char bot) {
    int num;
    do {num = rand() % 9;
    } while (position[num] != ' ');
    position[num] = bot;
}

bool checkWinner(char* pos, char player) {
    int winCombos[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (int i = 0; i < 8; i++) {
        if (pos[winCombos[i][0]] == player &&
            pos[winCombos[i][1]] == player &&
            pos[winCombos[i][2]] == player) {
            return true;
        }
    }

    return false;
}

bool isBoardFull(char* pos) {
    for (int i = 0; i < 9; i++) {
        if (pos[i] == ' ') {return false;}
    }
    return true;
}

int main() {
    srand(time(NULL));

    const int simNum = 10000;
    int bot1Wins = 0;
    int bot2Wins = 0;
    int ties = 0;

    for (int sim = 0; sim < simNum; sim++) {
        char position[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
        bool gameOver = false;
        char bot1 = 'X';
        char bot2 = 'O';

        while (!gameOver) {
            botMove(position, bot1);
            if (checkWinner(position, bot1)) {
                bot1Wins++;
                gameOver = true;
                break;
            }
            if (isBoardFull(position)) {
                ties++;
                gameOver = true;
                break;
            }

            botMove(position, bot2);
            if (checkWinner(position, bot2)) {
                bot2Wins++;
                gameOver = true;
                break;
            }
            if (isBoardFull(position)) {
                ties++;
                gameOver = true;
                break;
            }
        }
    }

    cout << "\nAfter " << simNum << " games:\n";
    cout << "X's Won: " << bot1Wins << " (" << (bot1Wins * 100.0 /simNum) << "%)\n";
    cout << "O's Won: " << bot2Wins << " (" << (bot2Wins * 100.0 /simNum) << "%)\n";
    cout << "Ties: " << ties << " (" << (ties * 100.0 / simNum) << "%)\n";

    return 0;
}
