#ifndef MAP_H
#define MAP_H

/**
 *   \file map.h
 *   \brief the window that contains the game
 */

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include "boy.h"

/**
 *   \brief the window the game is played in, forwards paint events to boy
*/
class Map : public QWidget
{
    Q_OBJECT

public:
    /**
     *       \brief creates the boy(the game) object and adds it to a layout
    */
    explicit Map(QWidget *parent = 0);
    /**
     *   \brief trivial
     */
    ~Map();
    /**
     *   \brief calls boy->paintEvent();
     *       \returns void
    */
    void paintEvent(QPaintEvent *e);
    /**
     *   \brief gives this window active focus
     *       \returns void
    */
    void showEvent(QShowEvent *e);



private:

    Boy* boy; //!< used to connect the window with the the game logic

};

#endif // MAP_H

