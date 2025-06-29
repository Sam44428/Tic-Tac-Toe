#include <stdio.h>

char board[3][3];

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

void playGame() {
    initializeBoard();
    int move, player;
    char mark;

    for (int turn = 0; turn < 9; turn++) {
        printBoard();
        player = (turn % 2) + 1;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter your move (row and column: 1-3 1-3): ", player);
        int row, col;
        scanf("%d %d", &row, &col);

        row--; col--; // convert to 0-based index

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            turn--; // don’t count invalid turn
        } else {
            board[row][col] = mark;

            if (checkWinner()) {
                printBoard();
                printf("Player %d wins!\n", player);
                return;
            }
        }
    }

    printBoard();
    printf("It's a draw!\n");
}

int main() {
    char choice;

    do {
        playGame();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
