//
// Created by wagne on 7/1/2023.
//

#include <QMessageBox>
#include <iostream>
#include "sudokuGridWidget.h"
#include "gameMenuWidget.h"

SudokuGridWidget::SudokuGridWidget(int amountPlayers, QWidget *parent) : QWidget()
{
    setFixedSize(550,600);
    mainLayout = new QVBoxLayout(this);
    sudokuWidget = new QWidget();
    sudokuWidget->setFixedSize(500,500);
    gridLayout = new QGridLayout(sudokuWidget);
    playerLayout = new QHBoxLayout;

    this->amountPlayers = amountPlayers;
    this->currentPlayer = 0;
    std::cout<< "Current AmountOfPlayers" << this->amountPlayers << std::endl;

    playerList.resize(amountPlayers, 0);

    createMenuBar();

    sudokuWidget->setLayout(gridLayout);

    // Create labels for each player
    for (int i = 0; i < amountPlayers; i++) {
        QLabel* playerLabel = new QLabel(this);
        playerLabel->setFixedSize(100,40);
        QString styleSheet = "border-radius: 10px; font-size: 14px; padding: 5px; border: 2px solid #607D8B;";
        playerLabel->setStyleSheet(styleSheet);


        playerLabel->setText(QString("Player %1: %2").arg(i+1).arg(playerList[i]));

        // Set different color for the label of the current player
        if (i == currentPlayer) {
            playerLabel->setStyleSheet("border-radius: 10px; font-size: 14px; padding: 5px; border: 2px solid #607D8B; background-color: blue;");
        }
        playerLayout->addWidget(playerLabel, i);
    }

    // Add spacing between menu bar and player labels
    playerLayout->addSpacing(10);

    createGrid();

    mainLayout->addLayout(playerLayout);  // Add playerLayout to mainLayout
    mainLayout->addWidget(sudokuWidget);

    setLayout(mainLayout);
}


void SudokuGridWidget::createGrid()
{
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cells[row][col] = new Cell(row, col, sudokuGame[row][col], this);
            gridLayout->addWidget(cells[row][col], row, col);
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
                //qDebug() << "Pressed Cell:" << row << col;
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
            this->pressedCell->setText("");
        }
            // Handle the digit keys from 1 to 9
        else if (event->text().length() == 1 && event->text().at(0).isDigit()) {
            // Get the pressed digit
            int digit = event->text().toInt();
            if (digit >= 1 && digit <= 9) {
                // Set the content of the field to the pressed digit
                this->cells[row][col]->setText(QString::number(digit));

                if(acceptedEntry(row, col, digit)){
                    this->cells[row][col] ->setCorrect(true);
                    this->cells[row][col]->updateBackground();
                    sudokuGame[row][col] = digit;
                    if(correctEntry(row, col, digit)){
                        this->playerList[currentPlayer] += 1;
                        refreshLabels();
                        std::cout<< "Player " << this->currentPlayer+1 << ": "<< this->playerList[this->currentPlayer] << std::endl;
                    }
                    if(sudokuCompleted()){
                        gameFinished();
                    }
                }
                else{
                    this->cells[row][col] ->setCorrect(false);
                    this->cells[row][col]->updateBackground();
                    if(currentPlayer+1< amountPlayers){
                        this->currentPlayer++;
                    } else{
                        this->currentPlayer = 0;
                    }
                    refreshLabels();
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
    mainLayout->setMenuBar(menuBar);
    setLayout(mainLayout);
}

void SudokuGridWidget::newGame() {
    // Implement the logic for starting a new game
    QMessageBox::information(this, tr("New Game"), tr("Starting a new game..."));
    GameMenuWidget *gameMenuWidget = new GameMenuWidget();
    gameMenuWidget->show();
    hide();
}
void SudokuGridWidget::gameFinished(){

    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cells[row][col]->completedSudoku();
        }
    }
    QMessageBox::information(this, "Sudoku Completed", "Congratulations! You completed the sudoku!");
}
void SudokuGridWidget::undo() {
}

void SudokuGridWidget::refreshLabels() {
    for (int i = 0; i < amountPlayers; i++) {
        QLabel* playerLabel = dynamic_cast<QLabel*>(playerLayout->itemAt(i)->widget());
        QString styleSheet = "border-radius: 10px; font-size: 14px; padding: 5px; border: 2px solid #607D8B;";

        if (playerLabel) {
            playerLabel->setText(QString("Player %1: %2").arg(i+1).arg(playerList[i]));

            // Set different color for the label of the current player
            if (i == currentPlayer) {
                playerLabel->setStyleSheet("border-radius: 10px; font-size: 14px; padding: 5px; border: 2px solid #607D8B; background-color: blue;");
            } else {
                playerLabel->setStyleSheet(styleSheet);
            }
        }
    }
}
