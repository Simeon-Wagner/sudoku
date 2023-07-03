//
// Created by wagne on 6/29/2023.
//

#include <iostream>
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


    QWidget *checkboxWidget = new QWidget(this);

    QHBoxLayout* checkBoxLayout = new QHBoxLayout;
    checkBoxLayout->setAlignment(Qt::AlignLeft);
    checkboxWidget->setLayout(checkBoxLayout);


    QLabel* label = new QLabel("Multiplayer");

// Create a QCheckBox instance and set its properties
    multiplayer = true;

    QCheckBox* checkbox = new QCheckBox;

    QString checkBoxStyle = "QCheckBox {"
                            "    spacing: 10px;" // Adjust the spacing between the checkbox and label
                            "}"
                            "QCheckBox::indicator {"
                            "    width: 24px;" // Increase the width of the checkbox
                            "    height: 24px;" // Increase the height of the checkbox
                            "}"
                            "QCheckBox::indicator:unchecked {"
                            "    background-color: grey;" // Set the background color when the checkbox is checked
                            "}";
    checkbox->setStyleSheet(checkBoxStyle);
    checkbox->setChecked(multiplayer);

    checkBoxLayout->addWidget(label);
    checkBoxLayout->addWidget(checkbox);
    mainLayout->addWidget(checkboxWidget);


    QObject::connect(checkbox, &QCheckBox::stateChanged, [this](int state) {
        multiplayer = !multiplayer;
    });

    connect(easyButton, &QPushButton::clicked, this, [this]() {
        startGame(Easy );
    });
    connect(intermediateButton, &QPushButton::clicked, this, [this]() {
        startGame(Intermediate );
    });
    connect(hardButton, &QPushButton::clicked, this, [this]() {
        startGame(Expert );
    });
    show();
}

void GameMenuWidget::startGame(const Level level) {
    createSudokuGame(static_cast<int>(level));
    SudokuGridWidget *sudokuGridWidget = new SudokuGridWidget(multiplayer, parentWidget());
    sudokuGridWidget->show();
    hide();
}

