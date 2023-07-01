//
// Created by wagne on 6/29/2023.
//
#include <iostream>
#include <algorithm>
#include <random>
#include "gameLogic.h"

#define N 9
const int TEXTBUFF_SIZE =   81;

//filling the three blocks of a diagonal with random numbers between 1 and 9
int sudokuField[9][9];


bool isPossible( int row,
            int col, int num)
{
    for (int x = 0; x <= 8; x++)
        if (sudokuField[row][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (sudokuField[x][col] == num)
            return false;

    int startRow = row - row % 3,
            startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudokuField[i + startRow][j +
                                   startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int row, int col)
{

    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }
    if (sudokuField[row][col] > 0)
        return solveSudoku( row, col + 1);

    for (int num = 1; num <= N; num++)
    {
        if (isPossible( row, col, num))
        {
            sudokuField[row][col] = num;
            if (solveSudoku( row, col + 1))
                return true;
        }
        sudokuField[row][col] = 0;
    }
    return false;
}



 void createSudoku() {


     //fill the diagonal
     int startBlock = 0;
     int endBlock = 3;

     int index = 0;
     int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
     std::shuffle(array, array + 9, std::default_random_engine(0));

     for (int i = 0; i < 9; ++i) {
         for (int j = 0; j < 9; ++j) {
             sudokuField[i][j] = 0;
         }
     }

     for (int i = 0; i < 9; ++i) {
         if (i == 3 || i == 6) {
             index = 0;
             std::shuffle(array, array + 9, std::default_random_engine(0));
             startBlock += 3;
             endBlock += 3;
         }
         for (int j = startBlock; j < endBlock; ++j) {
             sudokuField[i][j] = array[index];
             ++index;
         }
     }
     solveSudoku(0,0);
     for (int i = 0; i < 9; ++i) {
         for (int j = 0; j < 9; ++j) {
             std::cout << sudokuField[i][j] << " ";
         }
         std::cout << std::endl;
     }
 }

