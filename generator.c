#include <generator.h>

void generateGrid(Field grid[][9], int numFields, char *gameName){
    unsigned int hash=0;
    for(unsigned int i=0;i<strlen(gameName);i++){
        hash += gameName[i];
    }
    srand(hash);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            grid[i][j].value = 0;
        }
    }

    int filled = 0;
    int x,y;
    while(filled < numFields){
        x = rand() % 9;
        y = rand() % 9;

        //printf("%d:%d",y+1,x+1);
        if(grid[y][x].value == 0){
            insertValue(grid,rand()%9+1,x+1,y+1);

            if(rowCheckField(grid,x,y) && culCheckField(grid,x,y) && squareCheckField(grid,x,y)){
                filled++;
            }else{
                printf("kicked\n");
                grid[y][x].value = 0;
            }
        }
    }
}
