#include "window.hpp"
#include <iostream>

Window::Window(const QString& iName, QWidget* parent) :
    QWidget(parent), _name(iName), _description(""), _id(this->winId()) 
    {}

void Window::SetDescription(const QString& iDescription){
    _description = iDescription;
}

void Window::PlayStream(){
    std::cout << "Stream started ..." << std::endl;
}

void Window::StopStream(){
    std::cout << "Stream stopped ..." << std::endl;
}
