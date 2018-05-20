#include "SDLWindow.h"
#include <FfmpegVideoPlayer/VideoRead.h>
#include <iostream>

int main(int argc, const char *argv[]) {

    VideoRead::PlayerSettings playerSettings = {
            .onVideoInit = [](VideoRead::VideoInfo info) {
                SDLWindow::open(info.width, info.height);
            },

            .onVideoFrame = [](VideoRead::VideoFrameData data) {
                SDLWindow::displayPixels(data.pYplane, data.Ypitch,
                                         data.pUplane, data.Upitch,
                                         data.pVplane, data.Vpitch);

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