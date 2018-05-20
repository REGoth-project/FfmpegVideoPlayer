//
// Created by andre on 20.05.18.
//

#pragma once

#include <functional>
#include <vector>

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
        /**
         * RGB24 frame data
         */
        std::vector<uint8_t> rgb;

        /**
         * Row size, in bytes
         */
        size_t pitch;
    };

    typedef std::function<void(const VideoInfo&)> VideoInitCallback;
    typedef std::function<void(const VideoFrameData&)> VideoFrameCallback;

    struct PlayerSettings
    {
        VideoInitCallback onVideoInit;
        VideoFrameCallback onVideoFrame;
    };

    void playVideo(const std::string& file, PlayerSettings playerSettings);
    bool isVideoPlaybackAvailable();
};



