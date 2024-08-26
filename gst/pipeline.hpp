#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include <gst/gst.h>
#include <gst/video/videooverlay.h>
#include <string>
#include <QWidget>
#include <iostream>

class Pipeline : public QWidget {
    Q_OBJECT

    GstElement* _player;
    GstBus* _bus;
    GstMessage* _message;
    GError* _error;
    static bool _inited;

    // Initializes gstreamer
    void CheckGstInit();

public:
    // CTOR
    explicit Pipeline(QWidget* parentPtr = nullptr);
    
    // DTOR
    ~Pipeline();

    // Create elements and play pipeline
    void Play(const QString& description);

    // Stops the player and Cleans up the memory
    void Stop();

};

#endif // PIPELINE_HPP