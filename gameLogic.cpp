//
// Created by wagne on 6/29/2023.
//
#include <iostream>
#include <algorithm>
#include <random>
#include "gameLogic.h"


//filling the three blocks of a diagonal with random numbers between 1 and 9
int sudokuField[9][9];
int sudokuGame[9][9];


//Just a helping method for the ambiguity
int reversedSolvedSudoku[9][9];

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


//Debugging only
void printCurrentState(){
    std::cout<<"Current State"<< std::endl;
    // Print the generated Sudoku game
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << sudokuGame[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
bool acceptedEntry( int row, int col, int num)
{
    for (int x = 0; x <= 8; x++) {
        if (sudokuGame[row][x] == num) {
            std::cout<< "Mistake within the Column" << std::endl;
            printCurrentState();
            return false;
        }
    }

    for (int x = 0; x <= 8; x++){
        if (sudokuGame[x][col] == num){
            std::cout<< "Mistake within the Row" << std::endl;
            printCurrentState();
            return false;
        }
    }
    int startRow = row - row % 3,
            startCol = col - col % 3;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (sudokuGame[i + startRow][j + startCol] == num){
                std::cout<< "Mistake within the Block" << std::endl;
                printCurrentState();
                return false;
            }
        }
    }

    return true;
}

bool reverseIsPossible( int row,
                 int col, int num)
{
    for (int x = 0; x <= 8; x++)
        if (reversedSolvedSudoku[row][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (reversedSolvedSudoku[x][col] == num)
            return false;

    int startRow = row - row % 3,
            startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (reversedSolvedSudoku[i + startRow][j +
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


//My Idea behind this implementation is that when the sudoku is created the backtrackings starts
//with one and adds one if the solution is not possible. In this case the reverse thing is done.
//the first number inserted is 9 and if the solution is not accepted the the number gets decremented.
bool reverseSolveSudoku(int row, int col)
{
    if (row == N - 1 && col == N){
        return true;
    }

    if (col == N) {
        row++;
        col = 0;
    }
    if (reversedSolvedSudoku[row][col] > 0)
        return reverseSolveSudoku( row, col + 1);

    for (int num = 9; num > 0; num--)
    {
        if (reverseIsPossible( row, col, num))
        {
            reversedSolvedSudoku[row][col] = num;

            if (reverseSolveSudoku( row, col + 1))
                return true;
        }
        reversedSolvedSudoku[row][col] = 0;
    }
    return false;
}

bool isAmbiguous(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            reversedSolvedSudoku[i][j] = sudokuGame[i][j];
        }
    }

    reverseSolveSudoku(0,0);

    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (reversedSolvedSudoku[i][j] != sudokuField[i][j]) {
                return true;
            }
        }
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
}

void createSudokuGame(int amountBlankSpace) {
    createSudoku();
    // Print the generated Sudoku game
    std::cout<<"RESULT"<< std::endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << sudokuField[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int array[81];
    for (int i = 0; i < 81; i++) {
        array[i] = i;
    }

    do  {
        std::shuffle(array, array + 81, std::default_random_engine(0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sudokuGame[i][j] = sudokuField[i][j];
            }
        }

        for (int i = 0; i < amountBlankSpace; i++) {
            int row = array[i] / N;
            int column = array[i] % N;
            sudokuGame[row][column] = 0;
        }

    }while (isAmbiguous());

}

bool sudokuCompleted(){
    // Print the generated Sudoku game
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
           if(sudokuGame[i][j]!=sudokuField[i][j]){
               return false;
           }
        }
    }
    return true;
}
//If the entry is correct the player receives a point
bool correctEntry(int row, int col, int entry){
    return sudokuGame[row][col]==entry;
}
