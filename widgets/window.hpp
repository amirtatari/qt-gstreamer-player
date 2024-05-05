#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>
#include <QString>

class Window : public QWidget
{
    Q_OBJECT
    QString _name;
    QString _description;
    WId _id;
public:
    explicit Window(const QString& iName, QWidget* parent=nullptr);

    void SetDescription(const QString& iDescription);

public slots:
    void PlayStream();
    void StopStream();
};

#endif