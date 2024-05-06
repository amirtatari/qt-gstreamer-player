#include "stream.hpp"

Stream::Stream() :
    _status(Stream::Status::Idle) 
    {}

void Stream::Play(const QString& description, quintptr wid){
    // TODO
}

void Stream::Stop(){
    //TODO
}

Stream::Status Stream::GetStatus() const {
    return _status;
}

void Stream::CheckStatus(){
    // TODO
}