//
// Created by wagne on 7/1/2023.
//


#include "Cell.h"
#include <iostream>
Cell::Cell(int row, int col, int value, QWidget *parent) : QLineEdit(parent), row(row), col(col)
{
    setFixedSize(50, 50);
    setMaxLength(1);
    setAlignment(Qt::AlignCenter);
    setValidator(new QIntValidator(1, 9, this));  // Set validator to accept numbers between 1 and 9
    setFont(QFont("Arial", 16));  // Set font size to 16

    //In the array if the field is empty the value is zero, but we don't want a zero displayed in the field
    if (value != 0) {
        std::string entry = std::to_string(value);
        QString qtext = QString::fromStdString(entry);
        setText(qtext);
        //the pregiven values should not be changeable
        setReadOnly(true);
    }
    connect(this, &Cell::textChanged, this, &Cell::checkInput);
}

void Cell::checkInput(const QString &text) {
    if(!std::equal(text.begin(), text.end(),"0")){
        int entry = text.toInt();
        if(acceptedEntry(row, col, entry)){
            sudokuGame[row][col] = entry;
            setStyleSheet("color:  #6666ff;");
        }
        else{
            setStyleSheet("color: red;");
        }
    }else{

        clear();
        sudokuGame[row][col] = 0;
    }

}
