#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>
#include <QString>
#include "../stream/stream.hpp"

struct SrcParams 
{
    QString _host;
    QString _user;
    QString _password;
};

class Window : public QWidget
{
    Q_OBJECT
    Stream _stream;
    SrcParams _params;
    QString _name;

public:
    explicit Window(const QString& iName, QWidget* parent=nullptr);

public slots:
    void PlayStream();
    void StopStream();
};

#endif