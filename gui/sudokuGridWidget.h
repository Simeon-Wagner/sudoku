//
// Created by wagne on 7/1/2023.
//

#ifndef SUDOKU_SUDOKUGRIDWIDGET_H
#define SUDOKU_SUDOKUGRIDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QMenuBar>

#include "Cell.h"

class SudokuGridWidget : public QWidget
{
Q_OBJECT

public:
    explicit SudokuGridWidget(QWidget *parent = nullptr);

private:
    QGridLayout *layout;
    Cell *cells[9][9];
    QMenuBar *menuBar;
    QAction *newGameAction;
    QAction *hintAction;
    QAction *undoAction;

    void createGrid();
    void createMenuBar();
    void undo();
    void newGame();
};

#endif //SUDOKU_SUDOKUGRIDWIDGET_H
