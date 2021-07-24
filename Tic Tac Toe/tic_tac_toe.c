// Tic Tac Toe Game


// Header File
#include <stdio.h>


char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Function to display Tic Tac Toe Board
void DisplayBoard()
{
    printf("  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf("--------------------\n");
    printf("  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf("--------------------\n");
    printf("  %c  |  %c  |  %c  \n\n", board[6], board[7], board[8]);
}

// Fucntion to check validity of choice
// Condition for a valid choice :
// 1. Choice should be between 1 and 9
// 2. Choices should not be repeated 
int ChoiceCheck(int n)
{
    if ((n >= 1) && (n <= 9)){
        if(board[n-1]=='X' || board[n-1]=='O'){
            printf("Duplicate choices are not allowed!\n");
            return 0;
        }
        
        return 1;
    }
        
    else
        return 0;
}


// Set function is used to set value "X" or "O" at a particular box
void Set(int n, char c)
{
    board[n - 1] = c;
}

// CheckWin function is used to check the win condition
int CheckWin()
{
    if (board[0] == board[1] && board[1] == board[2])
        return 1;
    else if (board[3] == board[4] && board[4] == board[5])
        return 1;
    else if (board[6] == board[7] && board[7] == board[8])
        return 1;
    else if (board[0] == board[3] && board[3] == board[6])
        return 1;
    else if (board[1] == board[4] && board[4] == board[7])
        return 1;
    else if (board[2] == board[5] && board[5] == board[8])
        return 1;
    else if (board[0] == board[4] && board[4] == board[8])
        return 1;
    else if (board[2] == board[4] && board[4] == board[6])
        return 1;
    else
        return 0;
}


int main(void)
{
    printf("----------------------------Tic Tac Toe----------------------------\n\n");
    printf("Palyer1 : X  and Player2 : O\n\n");
    DisplayBoard();
    int choice;

    while (1)
    {
    label1:
        printf("Player 1 , Enter Box no. : ");
        scanf("%d", &choice);

    if (ChoiceCheck(choice))
        Set(choice, 'X');
    else
    {
        printf("Enter Valid Choice!!!!\n");
        goto label1;
    }

    DisplayBoard();
    if (CheckWin())
    {
        printf("Hurray!! Player1 Won.");
        break;
    }

    label2:
        printf("Player 2 , Enter Box no. : ");
        scanf("%d", &choice);

    if (ChoiceCheck(choice))
         Set(choice, 'O');
    else
    {
        printf("Enter Valid Choice!!!!\n");
        goto label2;
    }

    DisplayBoard();
    if (CheckWin())
    {
        printf("Hurray!! Player2 Won.");
        break;
    }
    }

    return 0;
}
