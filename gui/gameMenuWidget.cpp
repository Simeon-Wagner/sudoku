//
// Created by wagne on 6/29/2023.
//

#include <iostream>
#include "gameMenuWidget.h"
#include <QComboBox>


GameMenuWidget::GameMenuWidget(QWidget *parent)
        : QMainWindow(parent) {
    setWindowTitle("Sudoku");
    setFixedSize(500, 600);

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


    QWidget *dropdownWidget = new QWidget(this);

    QHBoxLayout* dropdownLayout = new QHBoxLayout;
    dropdownLayout->setAlignment(Qt::AlignLeft);
    dropdownWidget->setLayout(dropdownLayout);

    QLabel* dropLabel = new QLabel("Amount of Players");


    QComboBox* comboBox = new QComboBox(this);  // Create the QComboBox instance

    // Add items to the dropdown list
    comboBox->addItem("1 Players");
    comboBox->addItem("2 Players");
    comboBox->addItem("3 Players");
    comboBox->addItem("4 Players");

// Set the initial selection (optional)
    comboBox->setCurrentIndex(0);


// Set the position and size of the dropdown list
    comboBox->setGeometry(50, 50, 400, 50);

    dropdownLayout->addWidget(dropLabel);
    dropdownLayout->addWidget(comboBox);
    mainLayout->addWidget(dropdownWidget);



    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [this, comboBox](int index) {
      //  QString selectedItem = comboBox->itemText(index);

      std::cout<< "Current Index " << index << std::endl;
      this-> arraySize = index+1;
      std::cout<< "Current Arraysize " << arraySize << std::endl;

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
    SudokuGridWidget *sudokuGridWidget = new SudokuGridWidget(this->arraySize, parentWidget());
    sudokuGridWidget->show();
    hide();
}

