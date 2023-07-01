#include <QApplication>
#include <QMainWindow>
#include "sudokuGridWidget.h"
#include "gameMenuWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameMenuWidget gameMenuWidget;
    gameMenuWidget.setFixedSize(500,500);
    gameMenuWidget.show();
    return a.exec();
}