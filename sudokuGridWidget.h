//
// Created by wagne on 7/1/2023.
//

#ifndef SUDOKU_SUDOKUGRIDWIDGET_H
#define SUDOKU_SUDOKUGRIDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include "cell.h"

class SudokuGridWidget : public QWidget
{
Q_OBJECT

public:
    explicit SudokuGridWidget(QWidget *parent = nullptr);

private:
    QGridLayout *layout;
    Cell *cells[9][9];

    void createGrid();
};

#endif //SUDOKU_SUDOKUGRIDWIDGET_H
