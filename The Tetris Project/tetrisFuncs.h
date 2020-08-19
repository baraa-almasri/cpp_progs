#ifndef TETRISFUNCS_H
#define TETRISFUNCS_H

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "kbInput.h"
#include "ioFuncs.h"

#define true 1
#define false 0
#define bool int

void initLengths(int *lengths0) {
    int (*lengths)[10] = lengths0;
    for(int i = 0; i < 10; i++) {
        (*lengths)[i] = 19;
    }
}

void initCheckList(bool *checkList0) {
    bool (*checkList)[10] = checkList0;

    for(int row = 0; row < 20; row++) {
        
        for(int col = 0; col < 10; col++){

            checkList[row][col] = 0;

        }
    
    }
}

void initMatrix(char *matrix0, int rows, int columns){

    char (*matrix)[columns] = matrix0;

    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++){
            
            matrix[row][col] = '.';

        }
    
    }
}

void updateTetrisMap(char *matrix0, bool *checkList0, int rows, int columns) {

    char (*matrix)[columns] = matrix0;
    bool (*checkList)[columns] = checkList0;

    for(int row = 0; row < rows; row++) {
        
        for(int col = 0; col < columns; col++){

            // (== 1) because for some reason the "if" fucks with the array and assigns some garbage values
            if( checkList[row][col] == 1 ) {
                matrix[row][col] = '#';
                
            }

        }
    
    }

}

void checkMap(char *matrix0, bool *checkList0, int rows, int columns, int *lengths0) {

    char (*matrix)[columns] = matrix0;
    bool (*checkList)[columns] = checkList0;
    int (*lengths)[columns] = lengths0;

    for(int col = 0; col < columns; col++) {
        
        for(int row = 0; row < rows; row++){

            if( matrix[row][col] == '#' ) {
                checkList[row][col] = 1;
                (*lengths)[col]--;
                break;
                
            }

        }
    
    }
/*
    for(int row = 0; row < rows; row++) {
        
        for(int col = 0; col < columns; col++){

            if( matrix[row][col] == '#' ) {
                checkList[row][col] = 1;
                (*lengths)[col]--;
                break;
                
            }

        }
    
    }
*/
}

void dropOverColumn(char *matrix0, int rows, int columns) {
    // convert the given pointer to matrix
    char (*matrix)[columns] = matrix0;
    // start dropping from the first row
    int droppingRow = -1;
    // dropping starts from the middle
    int col = columns / 2;
    // print current tetris
    printMatrix(*matrix, rows, columns);
    
    while( droppingRow < rows - 1 ) {
        
        // get current character from keyboard
        char chr = getch();
        // replace dropped character with a dot
        matrix[droppingRow++][col] = '.';
        // move left / right
        if(chr == 'A' || chr == 'a'){
        
            col--;
        
        } else if(chr == 'D' || chr == 'd'){
            
            col++;
        
        }

        // setting boundaries
        if( col >= 9 ){
        
            col = 9;
        
        } else if( col <= 0 ) {

            col = 0;

        }


        clear();
        
        // add the dropping chararecter
        matrix[droppingRow][col] = '#';
        // print current tetris map
        printMatrix(*matrix, rows, columns);

        
    }

}

#endif //TETRISFUNCS_H