/**
 *  \file main.cpp
 *  @author William Henrikson
 *  @date december 3, 2015
 *  \brief This is the source code for the Boy and Dog game.  It is split into 3 classes in header/source pairs.
 *   the MainWindow opens a Ui which gives the user the option to start the game, that opens up the map window
 *   which calls the game, boy.
 *
 */
/*! \mainpage Boy and Dog Game
 *
 * \section The Game
 *
 * This is a simple Qt game where you play as a boy looking for his lost dog at night with a flashlight.
 *
 */
#include <QApplication>
#include <QVBoxLayout>
#include "mainwindow.h"
#include "boy.h"

int main(int argc, char *argv[]) {
QApplication app(argc, argv);

MainWindow window;
window.show();


return app.exec();
}
