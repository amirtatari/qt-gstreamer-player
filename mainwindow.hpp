#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "gst/pipeline.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Ui::MainWindow *ui;
    Pipeline* _streamPipeline;

    // setup Ui components for main ui page
    void SetupMainPageUi();

private slots:
    // connecting start button released signal & play the stream in the widget
    void SlotStartStream();

    // connecting stop button released signal & stop the stream from playing
    void SlotStopStream();
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 

};
#endif // MAINWINDOW_HPP
