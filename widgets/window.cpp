#include "window.hpp"

Window::Window(const QString& iName, QWidget* parent) :
    QWidget(parent), _name(iName)
    {}

void Window::PlayStream(){
    try{
        _stream.Play("",this->winId());
    } catch (...) {
        // TODO add logger
    }
}

void Window::StopStream(){
    try{
        _stream.Stop();
    } catch (...) {
        // TODO add logger
    }   
}
