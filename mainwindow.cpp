#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "map.h"
#include <iostream>
#include <QWidget>
#include <QWindow>
#include <QPalette>

/**
 *   \file boy.cpp
 *   \brief Source code for the start menu
 */


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->game_begin, SIGNAL(clicked()), this, SLOT(create_map()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_map()
{
   // ui->Spacebar->clear();  works to clear the text, signal is going through
    QWidget* wig = new QWidget(this);  
    QPalette* borders = new QPalette;
    borders->setColor(QPalette::Background,"Qt::black");
    this->setPalette(*borders);
    map = new Map(wig);
    this->setCentralWidget(wig);
  //  this->setContentsMargins(0,0,0,0);
    this->setFixedSize(815,660);

}

