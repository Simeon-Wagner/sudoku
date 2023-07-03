//
// Created by wagne on 7/1/2023.
//

#ifndef SUDOKU_GAMELOGIC_H
#define SUDOKU_GAMELOGIC_H
//filling the three blocks of a diagonal with random numbers between 1 and 9
#define N 9
extern int sudokuField[9][9];
extern int sudokuGame[9][9];


//Just a helping method for the ambiguity
extern int reversedSolvedSudoku[9][9];


void createSudokuGame(int amountBlankSpace);
bool acceptedEntry(int row, int col, int num);
bool correctEntry(int row, int col, int num);
bool sudokuCompleted();
enum Level {
    Easy = 20,
    Intermediate = 30,
    Expert = 50
};

#endif //SUDOKU_GAMELOGIC_H
