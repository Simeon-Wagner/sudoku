//
// Created by wagne on 7/1/2023.
//

#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H

#include <QLabel>
#include <algorithm>
#include <iterator>
#include <string>

class Cell : public QLabel {

public:
    explicit Cell( int row=0, int col=0, int value = 0, QWidget *parent = nullptr);
    void setCellColor(std::string color);
    static QFont setHintFont();
    static QFont setValueFont();
    void updateBackground();
    int getRow(){return row;}
    int getCol(){return col;}
    int getVal(){return value;}
    void setCorrect(bool value){correct= value;}
    int getCorrect(){return correct;}
    QString getQVal(){return text();}

private:
    int value = 0;
    int row;
    int col;
    bool correct = true;

};
#endif //SUDOKU_CELL_H
