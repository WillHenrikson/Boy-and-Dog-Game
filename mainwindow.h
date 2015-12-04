#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 *   \file mainwindow.h
 *   \brief The starting menu
 */


#include <QMainWindow>
#include <map.h>

namespace Ui {
class MainWindow;
}
/**
 *   \class MainWindow
 *   \brief this class overloads QMainWindow and is the interface for the beginning of the game
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     *       \brief connects this to its Ui
     *       \param QWidget *parent explicit nullpointer because this is a top level widget
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     *      \brief deletes the Ui
     */
    ~MainWindow();

public slots:
    /**
     *       \brief resizes the window, sets borders to black, sets the focus to the map
     */
    void create_map();

private:
    Ui::MainWindow *ui; //!< predesigned ui
    Map* map;  //!< pointer to map child
};

#endif // MAINWINDOW_H
