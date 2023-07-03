//
// Created by wagne on 7/1/2023.
//

#include <QMessageBox>
#include <iostream>
#include "sudokuGridWidget.h"
#include "gameMenuWidget.h"

SudokuGridWidget::SudokuGridWidget(bool multiplayer, QWidget *parent) : QWidget()
{

    setFixedSize(500,500);
    layout = new QGridLayout(this);

    createGrid();
    createMenuBar();
    setLayout(layout);
}

void SudokuGridWidget::createGrid()
{
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cells[row][col] = new Cell(row, col, sudokuGame[row][col], this);
            layout->addWidget(cells[row][col], row, col);
        }
    }
}


void SudokuGridWidget::mousePressEvent(QMouseEvent *event) {
    // Call the base class implementation of the method
    QWidget::mousePressEvent(event);

    // Find the cell that was pressed
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (cells[row][col]->underMouse()) {
                // Save the pressed cell to a variable
                if(cellPressedBefore != nullptr && cellPressedBefore->getCorrect()){
                    cellPressedBefore->updateBackground();
                }
                pressedCell = cells[row][col];
                pressedCell->setStyleSheet("border: 2px solid grey;""background-color: blue;");
                cellPressedBefore = pressedCell;
                qDebug() << "Pressed Cell:" << row << col;
                // Or you can retrieve the text entered in the cell
                QString cellText = pressedCell->text();
                // ... (perform any other desired operations)
                break;
            }
        }
    }
}

void SudokuGridWidget::keyPressEvent(QKeyEvent *event) {
    // Call the base class implementation of the method
    QWidget::keyPressEvent(event);
    int row = pressedCell->getRow();
    int col = pressedCell->getCol();

    // Check if the event occurred in a specific field
    if (pressedCell != nullptr) {
        // Handle the backspace key
        if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete) {
            // Clear the content of the field
            pressedCell->setText("");
        }
            // Handle the digit keys from 1 to 9
        else if (event->text().length() == 1 && event->text().at(0).isDigit()) {
            // Get the pressed digit
            int digit = event->text().toInt();
            if (digit >= 1 && digit <= 9) {
                // Set the content of the field to the pressed digit
                cells[row][col]->setText(QString::number(digit));

                if(acceptedEntry(row, col, digit)){
                    cells[row][col] ->setCorrect(true);
                    cells[row][col]->updateBackground();
                    sudokuGame[row][col] = digit;
                    //isGameFinished();
                }
                else{
                    cells[row][col] ->setCorrect(false);
                    cells[row][col]->updateBackground();
                    sudokuGame[row][col] = digit;
                }
            }
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