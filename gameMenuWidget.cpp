//
// Created by wagne on 6/29/2023.
//
#include "sudokuGridWidget.h"
#include <QGridLayout>
#include <QLineEdit>
#include <QMenuBar>
#include <QMenu>
#include <QPushButton>
#include <QLabel>
#include "gameMenuWidget.h"

GameMenuWidget::GameMenuWidget(QWidget *parent)
        : QMainWindow(parent) {
    setWindowTitle("Sudoku");
    setFixedSize(500, 500);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QLabel *welcomingLabel = new QLabel("Start playing Sudoku!", centralWidget);
    welcomingLabel->setFont(QFont("Arial", 20, QFont::Bold));
    QLabel *instructionLabel = new QLabel("Choose your level:", centralWidget);
    instructionLabel->setFont(QFont("Arial", 16, QFont::Bold)); // Set a larger font size

    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(welcomingLabel);
    mainLayout->addWidget(instructionLabel);

    QPushButton *easyButton = new QPushButton("Easy");
    QPushButton *intermediateButton = new QPushButton("Intermediate");
    QPushButton *hardButton = new QPushButton("Hard");

    QSize buttonSize(200, 90);
    easyButton->setFixedSize(buttonSize);
    intermediateButton->setFixedSize(buttonSize);
    hardButton->setFixedSize(buttonSize);

    // Apply a rounded style to the buttons
    QString buttonStyle = "QPushButton {"
                          "border-radius: 10px;"
                          "background-color: grey;"
                          "margin-top: 10px;"
                          "}";

    easyButton->setStyleSheet(buttonStyle);
    intermediateButton->setStyleSheet(buttonStyle);
    hardButton->setStyleSheet(buttonStyle);

    mainLayout->addWidget(easyButton);
    mainLayout->addWidget(intermediateButton);
    mainLayout->addWidget(hardButton);

    connect(easyButton, &QPushButton::clicked, this, [this]() {
        startGame(0);
    });
    connect(intermediateButton, &QPushButton::clicked, this, [this]() {
        startGame(1);
    });
    connect(hardButton, &QPushButton::clicked, this, [this]() {
        startGame(2);
    });
    show();
}

void GameMenuWidget::startGame(const int level) {
    SudokuGridWidget *sudokuGridWidget = new SudokuGridWidget(parentWidget());
    sudokuGridWidget->show();
    hide();
}
