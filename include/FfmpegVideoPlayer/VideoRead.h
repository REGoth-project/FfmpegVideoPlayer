//
// Created by andre on 20.05.18.
//

#pragma once

#include <functional>

namespace VideoRead
{
    int vmain(int argc, const char *argv[]);

    struct VideoInfo
    {
        uint32_t width;
        uint32_t height;
    };

    struct VideoFrameData
    {
        const uint8_t* pYplane;
        size_t Ypitch;

        const uint8_t* pUplane;
        size_t Upitch;

        const uint8_t* pVplane;
        size_t Vpitch;
    };

    typedef std::function<void(VideoInfo)> VideoInitCallback;
    typedef std::function<void(VideoFrameData)> VideoFrameCallback;

    struct PlayerSettings
    {
        VideoInitCallback onVideoInit;
        VideoFrameCallback onVideoFrame;
    };

    void playVideo(const std::string& file, PlayerSettings playerSettings);
    bool isVideoPlaybackAvailable();
};



