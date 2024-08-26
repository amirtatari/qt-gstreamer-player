#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include <gst/gst.h>
#include <gst/video/videooverlay.h>
#include <string>
#include <QWidget>
#include <iostream>

class Pipeline {
    GstElement* _player;
    GstBus* _bus;
    GstMessage* _message;
    GError* _error;
    GstStateChangeReturn _ret;
    static bool _inited;

    void CheckGstInit();

public:
    // CTOR
    explicit Pipeline();
    
    // DTOR
    ~Pipeline();

    // Create elements and play pipeline
    void Play(const std::string& description, WId windowId);

};

#endif // PIPELINE_HPP