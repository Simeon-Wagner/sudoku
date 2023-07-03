//
// Created by wagne on 7/1/2023.
//

#ifndef SUDOKU_SUDOKUGRIDWIDGET_H
#define SUDOKU_SUDOKUGRIDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QMenuBar>
#include <QKeyEvent>
#include <QKeyEvent>

#include "Cell.h"
#include "../gameLogic.h"

class SudokuGridWidget : public QWidget
{
Q_OBJECT

public:
    explicit SudokuGridWidget(bool mulitplayer, QWidget *parent = nullptr);

private:
    QGridLayout *layout;
    Cell *cells[9][9];
    QMenuBar *menuBar;
    QAction *newGameAction;
    QAction *hintAction;
    QAction *undoAction;
    bool multiplayer;
    Cell* pressedCell = nullptr;
    Cell* cellPressedBefore = nullptr;

    void createGrid();
    void createMenuBar();
    void undo();
    void newGame();

    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif //SUDOKU_SUDOKUGRIDWIDGET_H
