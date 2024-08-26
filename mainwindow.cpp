#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, 
    ui{new Ui::MainWindow}
{
    ui->setupUi(this);
    _pipeline = new Pipeline{centralWidget()};
    _pipeline->setObjectName(QString("streamWidget").toUtf8());
    _pipeline->setStyleSheet("background-color : black");
    _pipeline->setGeometry(QRect{0, 0, 1080, 720});
    PlayStream();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PlayStream(){
    using std::string, std::exception, std::invalid_argument;
    try{
        QString description = "uridecodebin \
        uri=https://gstreamer.freedesktop.org/data/media/sintel_trailer-480p.webm \
        ! queue ! videoscale ! video/x-raw,width=640,height=480 \
        ! videoconvert ! ximagesink";

        _pipeline->Play(description);
    } catch(const exception& exp){
        throw std::invalid_argument("PlayStream: ERROR" + string(exp.what()));
    }
}

