//
// Created by wagne on 6/29/2023.
//
#include "sudokuGridWidget.h"
#include <QGridLayout>
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
        startGame(Easy);
    });
    connect(intermediateButton, &QPushButton::clicked, this, [this]() {
        startGame(Intermediate);
    });
    connect(hardButton, &QPushButton::clicked, this, [this]() {
        startGame(Expert);
    });
    show();
}

void GameMenuWidget::startGame(const Level level) {
    createSudokuGame(static_cast<int>(level));
    SudokuGridWidget *sudokuGridWidget = new SudokuGridWidget(parentWidget());
    sudokuGridWidget->show();
    hide();
}
