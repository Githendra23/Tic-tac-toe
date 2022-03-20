#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char square[10] = {'O', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char winColour[10] = {'?'};

enum ShouldGameContinue{Yes, No};
enum ShouldGameContinue shouldGameContinue = Yes;

void board();
int checkwin();

int player;

int main() {
    while(shouldGameContinue == Yes) {
        int choice;
        int isPlayersChoiceVerified = No;
        int mark = ((player % 2) == 0) ? 'X' : 'O';

        board();

        while(isPlayersChoiceVerified == No) {
            printf("player %d enter a number: ", ((player % 2) == 0) ? 1 : 2);
            scanf("%d", &choice);
            for(int i = 1; i <= 10; i++) {
                if(i == 10) {
                    board();
                    printf("Type a number between 1 and 9\n");
                    break;
                }
                else {
                    int playersChoice = 49; // value of the character "1"

                    if(choice == i && square[i] == ((playersChoice - 1) + i)) {     
                        square[i] = mark;
                        board();
                        isPlayersChoiceVerified = Yes;
                        break;
                    }
                    else if(choice == i && square[i] != ((playersChoice - 1) + i)) {
                        board();
                        printf("That square has already been picked, pick another square\n");
                        break;
                    }
                }
            }
        }
        checkwin();
        player++;
    }
    printf("Press Any Key to Exit...\n");  
    getch();
}

void board() {
    system("cls"); // clear screen
    printf("\n\n             Tic-Tac-Toe\n\n");
    printf("player 1: X               player 2: O\n\n");

    for(int i = 1; i <= 7; i++) {
        if(i == 1 || i == 4 || i == 7) {
            printf("\033[0m                |   |    \n");
            if(winColour[i + 0] == 'X' || winColour[i + 0] == 'O') printf("              \033[1;31m%c \033[0m|", square[i + 0]); 
            else printf("              \033[0m%c \033[0m|", square[i + 0]);
            
            if(winColour[i + 1] == 'X' || winColour[i + 1] == 'O') printf(" \033[1;31m%c \033[0m|", square[i + 1]);              
            else printf(" \033[0m%c \033[0m|", square[i + 1]);
            
            if(winColour[i + 2] == 'X' || winColour[i + 2] == 'O') printf(" \033[1;31m%c \n", square[i + 2]);                    
            else printf(" \033[0m%c \n", square[i + 2]);
            
            if(i == 7) printf("\033[0m                |   |    \n\n"); 
            else printf("\033[0m             ___|___|___\n");
        }
    }
}

int checkwin() {
    for(int i = 1; i <= 8; i++) {
        if(i == 2 || i == 5 || i == 8) {
            if(square[i - 1] == square[i + 0] && square[i + 1] == square[i + 0]) {                // horizontal
                winColour[i - 1] = square[i - 1];
                winColour[i + 0] = square[i + 0];
                winColour[i + 1] = square[i + 1];
                board();
                printf("Player %d is the winner\n", ((player % 2) == 0) ? 1 : 2);
                shouldGameContinue = No;
                break;
            }
        }

        if(i == 4 || i == 5 || i == 6) {
            if(square[i - 3] == square[i + 0] && square[i + 3] == square[i + 0]) {                // vertical
                winColour[i - 3] = square[i - 3];
                winColour[i + 0] = square[i + 0];
                winColour[i + 3] = square[i + 3];
                board();
                printf("Player %d is the winner\n", ((player % 2) == 0) ? 1 : 2);
                shouldGameContinue = No;
                break;
            }
        }

        if(i == 1 || i == 3) {
            if(square[i + 0] == square[5] && square[((i % 3) == 0) ? 7 : 9] == square[5]) {       // cross
                winColour[i + 0] = square[i + 0];
                winColour[5] = square[5];
                winColour[((i % 3) == 0) ? 7 : 9] = square[((i % 3) == 0) ? 7 : 9];
                board();
                printf("Player %d is the winner\n", ((player % 2) == 0) ? 1 : 2);
                shouldGameContinue = No;
                break;
            }
        }   
    }

    if(square[1] != '1' && square[2] != '2' && square[3] != '3' && 
       square[4] != '4' && square[5] != '5' && square[6] != '6' && 
       square[7] != '7' && square[8] != '8' && square[9] != '9') {
        board();
        printf("It's a draw\n");
        shouldGameContinue = No;
    }
}