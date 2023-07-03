//
// Created by wagne on 7/1/2023.
//


#include "Cell.h"
#include "sudokuGridWidget.h"
#include <iostream>
Cell::Cell(int row, int col, int value, QWidget *parent) : QLabel(parent), row(row), col(col)
{
    setFixedSize(50, 50);
    setAlignment(Qt::AlignCenter);
    setFont(QFont("Arial", 16));  // Set font size to 16



    // Set border style
    QString borderStyle = QString("border: 2px solid grey;");

    //In the array if the field is empty the value is zero, but we don't want a zero displayed in the field
    if (value != 0) {
        std::string entry = std::to_string(value);
        QString qtext = QString::fromStdString(entry);
        setText(qtext);
    }
    setStyleSheet(borderStyle);
}

void Cell::updateBackground() {
    QString qColor = correct ? "border: 2px solid grey;" :"border: 2px solid grey;""background-color: red;";
    setStyleSheet(qColor);
}




