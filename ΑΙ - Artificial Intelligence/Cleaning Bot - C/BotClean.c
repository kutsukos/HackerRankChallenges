/******************************************************************************
https://www.hackerrank.com/challenges/botclean
by Dheeraj Ravindranath https://www.hackerrank.com/dheeraj
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void updateDistanceMatrix(int posr, int posc, int *DirtPositions[25][3]){
    for(int x=0;x<25;x++){
        DirtPositions[x][2]=6969;
    }
    int k,l;
    for(int x=0;x<25;x++){
        k=DirtPositions[x][0];
        l=DirtPositions[x][1];
        DirtPositions[x][2]=abs(k-posr) + abs(l-posc);
    }
}

int findClosest(int *DirtPositions[25][3]){
    int min=11;
    int closest=99;
    for(int x=0;x<25;x++){
        if(DirtPositions[x][2]<min){
            min=DirtPositions[x][2];
            closest=x;
        }
    }
    return closest;
}

void cleanDirt(int x, int *DirtPositions[25][3],int posr, int posc, char board[5][5]){
    printf("CLEAN\n");
    DirtPositions[x][0]=999;
    DirtPositions[x][1]=999;
    board[posr][posc]='b';
}

void initDirtPositions(char board[5][5], int *DirtPositions[25][3]){
    int i=0;

    for(int x=0;x<25;x++){
        DirtPositions[x][0]=999;
        DirtPositions[x][1]=999;
        
    }
    
    for(int x=0;x<5;x++){
        for(int y=0;y<5;y++){
            if(board[x][y]=='d'){
                DirtPositions[i][0]=x;
                DirtPositions[i][1]=y;
                DirtPositions[i][2]=999;
                i++;
            }
        }
    }
}

void printboard(char board[5][5]){
    printf("\nBoard\n");
    for(int x=0;x<5;x++){
        for(int y=0;y<5;y++){
            printf("| %c ",board[x][y]);
        }
        printf("|\n");
    }
    printf("\n");
}

void next_move(int posr, int posc, char board[5][5], int *DirtPositions[25][3]) {
    updateDistanceMatrix(posr, posc, DirtPositions);
    printboard(board);
    int closest = findClosest(DirtPositions);
    if(closest==99){
        return 0;
    }else{
        if(DirtPositions[closest][2]==0)
            cleanDirt(closest, DirtPositions,posr, posc,board);
        else{   //make move
            board[posr][posc]='-';
            if(posr<DirtPositions[closest][0]){
                printf("DOWN\n");
                posr++;
            }else if(posr>DirtPositions[closest][0]){
                printf("UP\n");
                posr--;
            }else{
                if(posc<DirtPositions[closest][1]){
                    printf("RIGHT\n");
                    posc++;
                }else{
                    printf("LEFT\n");
                    posc--;
                }
            }
            if(board[posr][posc]=='d')
                board[posr][posc]='#';
            else
                board[posr][posc]='b';
        }
    }
    next_move(posr, posc, board, DirtPositions);
}

int main(void) {
    int pos[2], i;
    char board[5][5], line[6];
    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);
    for(i=0; i<5; i++) {
        scanf("%s[^\\n]%*c", line);
        strncpy(board[i], line, 5);
    }
    int *DirtPositions[25][2];
    initDirtPositions(board, DirtPositions);
    
    next_move(pos[0], pos[1], board, DirtPositions);
    return 0;
}