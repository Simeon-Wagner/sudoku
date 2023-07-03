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
#include <vector>
#include "Cell.h"
#include "../gameLogic.h"

class SudokuGridWidget : public QWidget
{
Q_OBJECT

public:
    explicit SudokuGridWidget(int amountPlayers, QWidget *parent = nullptr);

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout* playerLayout;
    QWidget *sudokuWidget;
    QGridLayout *gridLayout;
    Cell *cells[9][9];
    QMenuBar *menuBar;
    QAction *newGameAction;
    QAction *hintAction;
    QAction *undoAction;
    int amountPlayers;
    std::vector<int> playerList;
    int currentPlayer = 0;
    Cell* pressedCell = nullptr;
    Cell* cellPressedBefore = nullptr;

    void createGrid();
    void createMenuBar();
    void undo();
    void newGame();
    void gameFinished();
    void refreshLabels();

    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif //SUDOKU_SUDOKUGRIDWIDGET_H
