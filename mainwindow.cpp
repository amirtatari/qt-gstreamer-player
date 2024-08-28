#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, 
    ui{new Ui::MainWindow},
    _streamPipeline{new Pipeline{this}}
{
    ui->setupUi(this);
    
    // init ui main page
    SetupMainPageUi();
}

MainWindow::~MainWindow()
{
    gst_deinit();
    delete ui;
}


void MainWindow::SetupMainPageUi(){
    // create a vertical layout as the central widget
    QVBoxLayout* v_layout = new QVBoxLayout(centralWidget());

    // initialize start and stop buttons 
    QHBoxLayout* h_btn_layout = new QHBoxLayout{this};
    QPushButton* start_btn = new QPushButton{"start", this};
    QPushButton* stop_btn = new QPushButton{"stop", this};
    start_btn->setFixedSize(QSize{100, 50});
    stop_btn->setFixedSize(QSize{100, 50});
    h_btn_layout->addWidget(start_btn);
    h_btn_layout->addWidget(stop_btn);

    // set stream pipeline attributes
    _streamPipeline->setObjectName(QString("streamWidget").toUtf8());
    _streamPipeline->setStyleSheet("background-color : black");
    _streamPipeline->setGeometry(QRect{0, 0, 1080, 720});

    // add elemetns to main layout
    v_layout->addWidget(_streamPipeline);
    v_layout->addLayout(h_btn_layout);

    // connect released events of buttons to corresponding slots
    connect(start_btn, &QPushButton::released, this, &MainWindow::SlotStartStream);
    connect(stop_btn, &QPushButton::released, this, &MainWindow::SlotStopStream);
}


void MainWindow::SlotStopStream(){
    _streamPipeline->Stop();
}


void MainWindow::SlotStartStream(){
    using std::string, std::exception, std::invalid_argument;
    try{
        QString description = "uridecodebin \
        uri=https://gstreamer.freedesktop.org/data/media/sintel_trailer-480p.webm \
        ! queue ! videoscale ! video/x-raw,width=640,height=480 \
        ! videoconvert ! ximagesink";

        _streamPipeline->Play(description);
    } catch(const exception& exp){
        throw std::invalid_argument("PlayStream: ERROR" + string(exp.what()));
    }
}

