//
// Created by wagne on 7/1/2023.
//

#include "sudokuGridWidget.h"

SudokuGridWidget::SudokuGridWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(500,500);
    layout = new QGridLayout(this);
    createGrid();
    setLayout(layout);
}

void SudokuGridWidget::createGrid()
{
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cells[row][col] = new Cell(row, col);
            layout->addWidget(cells[row][col], row, col);
        }
    }
}