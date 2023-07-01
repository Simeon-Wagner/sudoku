//
// Created by wagne on 7/1/2023.
//

#include <QMessageBox>
#include "sudokuGridWidget.h"
#include "gameMenuWidget.h"

SudokuGridWidget::SudokuGridWidget(QWidget *parent) : QWidget()
{
    setFixedSize(500,550);
    layout = new QGridLayout(this);
    createGrid();
    createMenuBar();
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

void SudokuGridWidget::createMenuBar(){
    menuBar = new QMenuBar(this);
    menuBar->addSeparator();
    QMenu* newGameMenu = menuBar->addMenu(tr("New Game"));
    QMenu* undoMenu = menuBar->addMenu(tr("Undo"));

    newGameAction = new QAction(tr("Start New Game"), this);
    newGameMenu->addAction(newGameAction);
    connect(newGameAction, &QAction::triggered, this, &SudokuGridWidget::newGame);

    undoAction = new QAction(tr("Undo Move"), this);
    undoMenu->addAction(undoAction);
    connect(undoAction, &QAction::triggered, this, &SudokuGridWidget::undo);

    hintAction = new QAction(tr("Hint"), this);
    QMenu* hintMenu = menuBar->addMenu(tr("Hint"));
    hintMenu->addAction(hintAction);
    connect(undoAction, &QAction::triggered, this, &SudokuGridWidget::undo);
    layout->setMenuBar(menuBar);
    setLayout(layout);
}

void SudokuGridWidget::newGame() {
    // Implement the logic for starting a new game
    QMessageBox::information(this, tr("New Game"), tr("Starting a new game..."));
    GameMenuWidget *gameMenuWidget = new GameMenuWidget();
    gameMenuWidget->show();
    hide();
}

void SudokuGridWidget::undo() {

}