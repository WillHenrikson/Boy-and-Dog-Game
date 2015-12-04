#ifndef BOY
#define BOY

/**
 *   \file boy.h
 *   \brief Header file for the game logic
 */


#include <QWidget>
#include <QTransform>
#include <QRect>

/**  \class Boy
    \brief contains the code and variables for the actual gameplay: the paint event, the information about the location and direction
    the boy is looking, and handles all the keypresses for movement and sound events.

 */

class Boy : public QWidget
{
    Q_OBJECT


public:
    /**
     *      \param QWidget *parent a pointer to the boy's parent, set to Map in this game
     */
    explicit Boy(QWidget *parent = 0);
    /**
     *       \brief repaints only in a box around current location, uses two transforms, one standard(always true north), one represents roation of boy
     *       \returns void
     */
    void paintEvent(QPaintEvent *e);
    /**
     *       \brief handles up/down/left/right and spacebar for sound
     *       \returns void
     */
    void keyPressEvent(QKeyEvent *event);
    /**
     *       \brief sets focus to this window then shows it
     *       \returns void
     */
    void showEvent(QShowEvent *e);

    /**
    *   \brief trivial
    */
    ~Boy();

private:
    //Ui::Boy *ui;
    double theta;  //!< in radians
    double x, y; //!< boy position in the transform
    QTransform transform;  //!< follows turning
    QTransform standard;  //!< the identity transform
    double std_x,std_y;   //!< the boy location on the standard transform
    int count;            //!< count for recycling sound files


};
void delay();   //!< timer function for not overlapping sound files

#endif // BOY

