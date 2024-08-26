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
    Pipeline* _pipeline;
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 

    // play the stream in the widget
    void PlayStream();
};
#endif // MAINWINDOW_HPP
