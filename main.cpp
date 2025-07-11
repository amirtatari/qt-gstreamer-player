#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    } 
    catch(const std::exception& exp)
    {
        std::cerr << "main: ERROR: " << exp.what() << '\n';
        return -1;
    }
    return 0;
}
