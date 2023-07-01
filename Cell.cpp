//
// Created by wagne on 7/1/2023.
//

#include "Cell.h"

Cell::Cell(int row, int col, QWidget *parent) : QLineEdit(parent), row(row), col(col)
{
    setFixedSize(50,50);
    setMaxLength(1);
    setAlignment(Qt::AlignCenter);

}