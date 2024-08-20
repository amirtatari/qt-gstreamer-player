#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include <gst/gst.h>

class Pipeline
{
    GstElement* _player;
    GstElement* _bus;
    GError* _error;
    static bool _inited;

    void CheckGstInit();

public:
    Pipeline();

    ~Pipeline();
};

#endif // PIPELINE_HPP