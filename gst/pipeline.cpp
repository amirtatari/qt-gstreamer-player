#include "pipeline.hpp"
#include <stdexcept>


bool Pipeline::_inited = false;

Pipeline::Pipeline(QWidget* parentPtr) :
    QWidget{parentPtr},
    _player{nullptr}, 
    _bus{nullptr},
    _error{nullptr},
    _message{nullptr}
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


void Pipeline::Stop(){
    // top the pipeline from playing
    GstStateChangeReturn ret = gst_element_set_state(_player, GST_STATE_PAUSED);
    ret = gst_element_set_state(_player, GST_STATE_NULL);

    // release memory from all elements
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


Pipeline::~Pipeline(){
    // deintialize the gstreamer
    gst_deinit();

    // cleanup the memory
    Stop();
}


void Pipeline::Play(const QString& description){
    using std::invalid_argument, std::cout;

    // check if gstreamer is initialized
    if(!_inited){
        throw invalid_argument("Play: ERROR: gstreamer is not initialized!");
    }

    // check the input variables
    if(description.isEmpty()){
        throw invalid_argument("Play: ERROR: description is empty!");    
    }

    // intialize the player element using the description
    _player = gst_parse_launch(description.toStdString().c_str(), &_error);
    if(_player == nullptr){
        throw invalid_argument("Play: ERROR: could not parse the description!");
    }

    // get the sink element & set video overlay
    GstElement* video_sink = gst_bin_get_by_interface(GST_BIN(_player), GST_TYPE_VIDEO_OVERLAY);
    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(video_sink), this->winId());

    GstStateChangeReturn ret = gst_element_set_state(_player, GST_STATE_PLAYING);
    
    if(ret == GST_STATE_CHANGE_FAILURE){
        // stop the player and free the memory
        Stop();
        throw invalid_argument("Play: ERROR: could not play the pipeline!");
    }
}