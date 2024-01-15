#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define playerWin 0
#define botWin 1
#define error -1
#define draw 2
#define true 1
#define rock 1
#define paper 2
#define scissors 3

#define max 10

int gameResult(int);

int main(void){
int scorePlayer =0,scoreBot=0;
int round = 1;
int choise = 0;
int result = 0;//store the last round result
printf("WELCOME TO ROCK PAPERS SCISSORS\n");

while(true){
    printf("\nROUND : %d-score : player = %d - bot = %d\n\n",round,scorePlayer,scoreBot);
    printf("\n1)rocks\n2)paper\n3)scissors\noption: ");
    scanf("%d",&choise);

    result = gameResult(choise);
    if(result == playerWin){
        ++round;
        ++scorePlayer;
    }
    else if(result == botWin){
        ++round;
        ++scoreBot;
    }
    else if(result == error){
        printf("\nwrong input!try again\n");
    }
    else{
        ++round;
    }

    if(scorePlayer == max){
        printf("\n\nPLAYER WINS");
        exit(0);
    }
    else if(scoreBot == max){
        printf("\n\nBOT WINS.BETTER LUCK NEXT TIME...");
        exit(0);
    }

}
    
}

int gameResult(int choise){//calculate the result of the last round
    
    int bot = 1 + rand() % 3;

    if(choise == rock && bot == scissors){
        return playerWin;
    }
    else if (choise == scissors && bot == paper){
        return playerWin;
    }
    else if (choise == paper && bot == rock){
        return playerWin;
    }
    else if (choise == bot){
        return draw;
    }
    else if(choise < 1 || choise > 3){
        return error;
    }

    return botWin;
}