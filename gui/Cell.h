//
// Created by wagne on 7/1/2023.
//

#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H


#include <QIntValidator>
#include <QLineEdit>
#include <QSpinBox>

class Cell : public QLineEdit
{
Q_OBJECT

public:
    explicit Cell(int row, int col, QWidget *parent = nullptr);

private:
    int row;
    int col;

private slots:
    void checkInput(const QString &text);
};


#endif //SUDOKU_CELL_H
