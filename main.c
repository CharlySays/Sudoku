#include <generator.h>
#include <time.h>
#include <gameManagement.h>

#define clear() printf("\033[H\033[J")

void generateScreen(Field grid[][9],int *X, int *Y, time_t begin,bool *fixed);
void gameManagement(Field grid[][9], FILE *myFile);

int main(void)
{
    Field grid[9][9];
    bool won = false;
    bool fixed = false;
    int X = 10;
    int Y = 10;

    //readGrid(grid);
    FILE *gameFile = NULL;

    gameManagement(grid,gameFile);

    time_t begin = time(NULL);

    while(!won){

        generateScreen(grid,&X, &Y,begin,&fixed);

        won = winCondition(grid);
    }

    system("clear");
    renderInt(grid,X,Y);
    printf("Gratuliere Sie haben das Rätsel in: %.lf:%02d gelöst.\n", floor((double)(time(NULL)-begin)/60),(int)(time(NULL)-begin)%60);

    return 0;
}

void generateScreen(Field grid[][9],int *X, int *Y, time_t begin, bool *fixed){
    // Das aktuelle Rätsel ausgeben
    system("clear");
    //clear();
    renderInt(grid,*X,*Y);

    printf("Zeit: %.lf:%02d\n", floor((double)(time(NULL)-begin)/60),(int)(time(NULL)-begin)%60);

    if(!validNum(*X)){
        if(*fixed){
            printf("Das ausgewählte Feld ist leider ein vorgegebenes. Erneut wählen.\n");
        }
        coordinateRead(X,'X');
        return;
    }

    *fixed = false;
    if(!validNum(*Y)){
        coordinateRead(Y,'Y');
        return;
    }

    if(isfixed(grid,*X,*Y)){
        *fixed = true;
        *X=*Y=10;
        return;
    }

    printf("Neuen Wert für diese Position eingeben: ");
    int value;

    if (readSudokuVal(&value)){
        if (!insertValue(grid,value,*X,*Y)){
            printf("fixed\n");
            return;
        }
        *X=*Y=10;
    }else{
        return;
    }
}

void gameManagement(Field grid[][9], FILE *myFile){
    char name[255];
    printf("Spielname: ");
    scanf("%s",name);

    myFile = fopen(strcat(name,".txt"), "r+");
    if(myFile == NULL) //if file does not exist, create it
    {
       myFile = fopen(name, "wb");
       // genrator here bum bang done
       generateGrid(grid,20,name);
       gridToFile(grid,name);
       myFile = fopen(name, "r+");
    }
    readGridWithFile(grid,myFile);
}
