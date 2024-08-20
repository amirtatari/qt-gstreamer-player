#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, 
    ui{new Ui::MainWindow},
    _pipeline{}
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

