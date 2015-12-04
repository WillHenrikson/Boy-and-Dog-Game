#include "map.h"
#include "mainwindow.h"
//#include "ui_Map.h"
#include <QPushButton>
#include "boy.h"
#include <QPainter>
#include <QVBoxLayout>
#include <iostream>

/**
 *   \file map.cpp
 *   \brief the source code for the window that contains the game
 */


Map::Map(QWidget *parent) :
    QWidget(parent)
{

    // This code Creates the Map and the boy
    boy = new Boy(this);

    QVBoxLayout* layout = new QVBoxLayout(parent);


    layout->addWidget(boy);

}

Map::~Map()
{
      //delete ui;
}

void Map::paintEvent(QPaintEvent *e) {

    boy->paintEvent(e);

    return;
}


void Map::showEvent(QShowEvent *e) {

    this->activateWindow();
    this->setFocus();
    QWidget::showEvent(e);
}


