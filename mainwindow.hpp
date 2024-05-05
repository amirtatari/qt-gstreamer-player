#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "widgets/window.hpp"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Ui::MainWindow *ui;
    Window _window;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 
};
#endif // MAINWINDOW_HPP
