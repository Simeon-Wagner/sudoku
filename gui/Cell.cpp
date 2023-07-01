//
// Created by wagne on 7/1/2023.
//


#include "Cell.h"

Cell::Cell(int row, int col, QWidget *parent) : QLineEdit(parent), row(row), col(col)
{
    setFixedSize(50, 50);
    setMaxLength(1);
    setAlignment(Qt::AlignCenter);
    setValidator(new QIntValidator(1, 9, this));  // Set validator to accept numbers between 1 and 9
    setFont(QFont("Arial", 16));  // Set font size to 16

    connect(this, &Cell::textChanged, this, &Cell::checkInput);
}

void Cell::checkInput(const QString &text) {
    if(std::equal(text.begin(), text.end(),"0")){
        clear();
    }
}
