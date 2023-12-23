#include <stdio.h>


void displayBoard(char board[3][3]) 
{
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}


int checkWin(char board[3][3], char player) 
{
    
    for (int i = 0; i < 3; i++) 
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1; 
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0; 

}
int checkDraw(char board[3][3])  
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1; 
}

int main() {
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

    char currentPlayer = 'X';
    int row, col;
    int gameOver = 0;

    while (!gameOver) {
        displayBoard(board);
        printf("Player %c's turn. Enter row and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') 
        {
            board[row][col] = currentPlayer;

            
            if (checkWin(board, currentPlayer)) 
            {
                displayBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                gameOver = 1;
            } else if (checkDraw(board)) {
                displayBoard(board);
                printf("It's a draw!\n");
                gameOver = 1;
            } 
            else 
            {
                
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  
            }
        } 
    
        else 
        {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}