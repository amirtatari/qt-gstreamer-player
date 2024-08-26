#include "pipeline.hpp"
#include <stdexcept>


bool Pipeline::_inited = false;

Pipeline::Pipeline() :
    _player{nullptr}, 
    _bus{nullptr},
    _error{nullptr},
    _message{nullptr},
    _ret{GstStateChangeReturn::GST_STATE_CHANGE_NO_PREROLL}
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

    if(_error != nullptr){
        g_object_unref(_error);
        _error = nullptr;
    }

    if(_message != nullptr){
        g_object_unref(_message);
        _message = nullptr;
    }
}


void Pipeline::Play(const std::string& description, WId windowId){
    using std::invalid_argument, std::cout;

    // check if gstreamer is initialized
    if(!_inited){
        throw invalid_argument("Play: ERROR: gstreamer is not initialized!");
    }

    // check the input variables
    if(description.empty()){
        throw invalid_argument("Play: ERROR: description is empty!");    
    }

    if(windowId == static_cast<unsigned long long>(0)){
        throw invalid_argument("Play: ERROR: windowId is null!");
    }

    // intialize the player element using the description
    _player = gst_parse_launch(description.c_str(), &_error);

    if(_player == nullptr){
        throw invalid_argument("Play: ERROR: could not parse the description!");
    }

    // set video overlay
    GstElement* video_sink = gst_bin_get_by_interface(GST_BIN(_player), GST_TYPE_VIDEO_OVERLAY);
    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(video_sink), windowId);

    // change the player state and start playing the player
    _ret = gst_element_set_state(_player, GST_STATE_READY);

    _ret = gst_element_set_state(_player, GST_STATE_PLAYING);
    
    if(_ret == GST_STATE_CHANGE_FAILURE){
        gst_element_set_state(_player, GST_STATE_NULL);
        gst_object_unref(_player);
        throw invalid_argument("Play: ERROR: could not play the pipeline!");
    }
}