//
// Created by wagne on 6/29/2023.
//

#ifndef SUDOKU_GAMEMENUWIDGET_H
#define SUDOKU_GAMEMENUWIDGET_H


#include <QMainWindow>
#include "sudokuGridWidget.h"
#include <QGridLayout>
#include <QMenu>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include "../gamelogic.h"


class GameMenuWidget : public QMainWindow {
Q_OBJECT

public:
    GameMenuWidget(QWidget *parent = nullptr);
    bool multiplayer;

private slots:
    void startGame(Level level);
};


#endif //SUDOKU_GAMEMENUWIDGET_H
