#include "SDLWindow.h"
#include <FfmpegVideoPlayer/VideoRead.h>
#include <iostream>

int main(int argc, const char *argv[]) {

    VideoRead::PlayerSettings playerSettings = {
            .onVideoInit = [](const VideoRead::VideoInfo& info) {
                SDLWindow::open(info.width, info.height);
            },

            .onVideoFrame = [](const VideoRead::VideoFrameData& data) {
                SDLWindow::displayPixels(data.rgb.data(), data.pitch);

                SDLWindow::update();
            },
    };

    if(argc != 2)
    {
        std::cout << "Usage: SDLPlayerExample <video-file>" << std::endl;
        return -1;
    }

	VideoRead::playVideo(argv[1], playerSettings);

    return 0;
}