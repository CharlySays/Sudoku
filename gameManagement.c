#include <gameManagement.h>

void gridToFile(Field grid[][9], char* fileName){
    char output[255];
    char temp[255];
    strcpy(temp,"\0");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            itoa(grid[i][j].value,temp,10);
            strcat(output,temp);
        }
    }

    FILE *myFile = fopen(fileName,"w");
    fputs(output,myFile);
    fclose(myFile);
}
