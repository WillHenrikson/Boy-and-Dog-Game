#include "boy.h"
//#include "ui_Boy.h"
#include <QPainter>
#include <QBrush>
#include <QRectF>
#include <QKeyEvent>
#include <cmath>
#include <QRect>
#include <QCoreApplication>
#include <QTransform>
#include <QLabel>
#include <QtMultimedia/QSound>
#include <QPixmap>
#include <QTime>
#include <iostream>
//#include <QSound>


/**
 *   \file boy.cpp
 *   \brief The source file for the game logic
 */

Boy::Boy(QWidget *parent) :
    QWidget(parent)
    //ui(new Ui::Boy)
{
    //ui->setupUi(this);
    x = 545.0;
    y = 480.0;
    std_x=0;std_y=0;
    theta=1.5708;
    count=1;
    //transform.translate(230,150);   want




}


void Boy::showEvent(QShowEvent *e) {

    this->activateWindow();
    this->setFocus();
    QWidget::showEvent(e);
}

//using Ellipse as standin for Boy
//gets called by key press events
void Boy::paintEvent(QPaintEvent *e) {

    QPainter painter(this);

    // This sets the fill color and style.

    // Let’s just draw a simple circular dot. It will be inscribed in a rectangle.
   // double width = 60.0, height = 100.0;
    //QRectF rectangle(x, y, width, height);
   // QRectF rectangle2(100, 100, 30, 30);

   // QPointF boy_location(x,y)
    //QLabel* boy_label = new QLabel();
   // boy_label->setPixmap(boy_pixmap);

    //create stationary paint objects
   // painter.setTransform(standard);
    //painter.setBrush( QBrush(Qt::green));
   // painter.drawRoundedRect(rectangle2,30,50);
   // painter.setFont(QFont("Helvetica", 12));
   // painter.setPen(QPen(Qt::blue, 1));
   // painter.drawText(120, 100, "This green dot and text represent the stationary background");
   // painter.drawText(210, 130, "Press Space");

    painter.setTransform(standard);
    QPixmap* map_pixmap = new QPixmap(":/Map.jpg");
    painter.drawPixmap(0,0,*map_pixmap);

    QPixmap* boy_pixmap = new QPixmap(":/boy_small_cleaned.png");
    painter.setTransform(transform);
    painter.drawPixmap(x,y,150,150,*boy_pixmap);

    QPixmap* flashlight_pixmap = new QPixmap(":/darkest.png");  //don't need large pixmap never update it
    painter.drawPixmap(x-596,y-598,1200,1200,*flashlight_pixmap);
   // QPixmap* large_pixmap = new QPixmap(":/Large and Dark.png");
   // painter.drawPixmap(x-800,y-800,1600,1600,*large_pixmap);

    return;
}

//uses trig functions to calculate x,y changes based on theta
void Boy::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Left:
        transform.translate(x+75,y+75);
        transform.rotateRadians(-.4);
        transform.translate(-x-75,-y-75);
        theta -= 0.4; break;
    case Qt::Key_Right:
        transform.translate(x+75,y+75);
        transform.rotateRadians(.4);
        transform.translate(-x-75,-y-75);
        theta += 0.4; break;
    case Qt::Key_Up:
        transform.rotate(-theta);
        transform.translate(0,-5);
        theta = fmod(theta,6.28318);              //I don't know if this mod is faster than an if statement
        transform.rotate(theta);
        std_x += 5*cos(theta); std_y+=5*sin(theta);
        x+= 0; y -= 5; break;
    case Qt::Key_Down:
        transform.rotate(-theta);
        transform.translate(0, 5);
        theta = fmod(theta,6.28318);              //I don't know if this mod is faster than an if statemen
        transform.rotate(theta);
        std_x -= 5*cos(theta); std_y-=5*sin(theta);
        x -= 0; y += 5; break;
    case Qt::Key_Space:

      if(std_y<230 && std_y>190 && std_x<25 && std_x>-25){
            QSound::play(":/dog_whine.wav");
            delay();
            QSound::play(":/never_letting_you_out_of_my_sight_again.wav");
            delay();
            QSound::play(":/dog bark twice.wav");
            delay();
            delay();
            qApp->exit();
       }
        if(count%3 == 0){
            QSound::play(":/come_here_boy.wav");
        }
        if(count%3 == 2){
            QSound::play(":/rover_rover_rover.wav");
        }
        if(count%3 == 1){
            QSound::play(":/rover_where_are_you.wav");
        }
        count++;
        break;
    default:
        QWidget::keyPressEvent(event);
    }
    //545-50+std_x,480-50+std_y,200,200
    QRect* update_area= new QRect(545-200-2*std_x,480-200-2*std_y,400,400);

    update(*update_area);
   // repaint();
    QCoreApplication::processEvents();

    return;
}
//delay 2 seconds
void delay(){
    QTime dieTime= QTime::currentTime().addSecs(2);
    while (QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

Boy::~Boy()
{
    //delete ui;
}


/*
case Qt::Key_Up:
    transform.rotate(-theta);
    transform.translate(0,-5);
    theta = fmod(theta,6.28318);              //I don't know if this mod is faster than an if statement
    transform.rotate(theta);
    x+= 0; y -= 5; break;
case Qt::Key_Down:
    transform.rotate(-theta);
    transform.translate(0, 5);
    theta = fmod(theta,6.28318);              //I don't know if this mod is faster than an if statemen
    transform.rotate(theta);
    x -= 0; y += 5; break;
*/
