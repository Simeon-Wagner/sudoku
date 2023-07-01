//
// Created by wagne on 6/29/2023.
//

#ifndef SUDOKU_GAMEMENUWIDGET_H
#define SUDOKU_GAMEMENUWIDGET_H


#include <QMainWindow>

class GameMenuWidget : public QMainWindow {
Q_OBJECT

public:
    GameMenuWidget(QWidget *parent = nullptr);

private slots:
    void startGame(const int level);
};


#endif //SUDOKU_GAMEMENUWIDGET_H
