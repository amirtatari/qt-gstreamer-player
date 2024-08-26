#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, 
    ui{new Ui::MainWindow},
    _pipeline{}
{
    ui->setupUi(this);
    QWidget* centWidget = new QWidget(centralWidget());
    centWidget->setObjectName(QString("streamWidget").toUtf8());
    centWidget->setStyleSheet("background-color : black");
    centWidget->setGeometry(QRect{0, 0, 1080, 720});
    PlayStream();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PlayStream(){
    using std::string, std::exception, std::invalid_argument;
    try{
        string description = "uridecodebin \
        uri=https://gstreamer.freedesktop.org/data/media/sintel_trailer-480p.webm \
        ! queue ! videoscale ! video/x-raw,width=640,height=480 \
        ! videoconvert ! ximagesink";
        QWidget* streamWidget = centralWidget()->findChild<QWidget*>(QString("streamWidget").toUtf8());
        if(streamWidget == nullptr){
            throw std::invalid_argument("child widget is null ptr!");
        }
        _pipeline.Play(description, streamWidget->winId());
    } catch(const exception& exp){
        throw std::invalid_argument("PlayStream: ERROR" + string(exp.what()));
    }
}

