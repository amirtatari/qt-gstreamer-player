# qt-gstreamer-player
A gstreamer player for rtsp streams.

## Installation
Please install the following libraries:

### GCC & CMake
``` shell
sudo apt install build-essential cmake -y
```

### PkgConfig
``` shell
sudo apt install pkg-config -y
```

### Qt6
``` shell
sudo apt install qt6-base-dev qt6-tools-dev qt6-wayland -y 
```

### Gstreamer
``` shell
sudo apt install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio -y
```

Build the project using the following commands:
``` shell
mkdir -vp build
cmake -S . -B build
cmake --build build
```


## Usage
Please type your rtsp url in the text box and click on `Play Stream` button. To stop the stream, please click on `Stop Stream` button.

rtsp url example:

rtsp://<-CRED->@<-IP->/cam/realmonitor?channel=1&subtype=2