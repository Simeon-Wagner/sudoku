#include <QApplication>
#include <QMainWindow>
#include "gui/sudokuGridWidget.h"
#include "gui/gameMenuWidget.h"
#include "gameLogic.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    GameMenuWidget gameMenuWidget;
    gameMenuWidget.setFixedSize(500,550);
    gameMenuWidget.show();
    return a.exec();


}