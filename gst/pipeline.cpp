#include "pipeline.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

bool Pipeline::_inited = false;

Pipeline::Pipeline() :
    _player{nullptr},
    _bus{nullptr}
{
    using std::cout, std::exception;
    try{
        // initialize gstreamer
        CheckGstInit();
    } catch(const exception& exp){
        cout << "Pipeline: CTOR: " << exp.what() << '\n';
    }
    
}

void Pipeline::CheckGstInit(){
    using std::runtime_error, std::string, std::cout;
    if (!_inited){
        if (gst_init_check(nullptr, nullptr, &_error)){
            _inited = true;
            cout << "CheckGstInit: LOG: gstreamer intialized.\n";
        } else {
            throw runtime_error("CheckGstInit: ERROR: " + string(_error->message));
        }
    }
}

Pipeline::~Pipeline(){
    // deintialize the gstreamer
    gst_deinit();

    // release other elements
    if(_player != nullptr){
        g_object_unref(_player);
        _player = nullptr;
    }

    if(_bus != nullptr){
        g_object_unref(_bus);
        _bus = nullptr;
    }
}