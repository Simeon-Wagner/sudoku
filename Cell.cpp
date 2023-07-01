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
    setFont(QFont("Arial", 18));  // Set font size to 16

    connect(this, &QLineEdit::textEdited, this, &Cell::handleTextEdited);
}

void Cell::handleTextEdited(const QString &text)
{
    if (text.size() > 1)
        setText(text.right(1));  // Replace the text with the last character entered
}