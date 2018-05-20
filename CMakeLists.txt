cmake_minimum_required(VERSION 3.1)
project(ffmpeg_video_player)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(FFmpeg COMPONENTS AVCODEC AVFORMAT AVUTIL AVDEVICE REQUIRED)

if(FFMPEG_FOUND)
    #  FFMPEG_INCLUDE_DIRS  - Include directory necessary for using the required components headers.
    #  FFMPEG_LIBRARIES     - Link these to use the required ffmpeg components.
    #  FFMPEG_DEFINITIONS   - Compiler switches required for using the required ffmpeg components.

    include_directories(${FFMPEG_INCLUDE_DIRS})

    set(FFMPEG_LIBRARIES avformat avcodec swresample swscale avutil)

    # Let the library know
    add_definitions(-DHAS_FFMPEG)
else()
    message(STATUS "FFMPEG not found, continuing without video playback support")
    set(FFMPEG_LIBRARIES "")
endif()



# Main library
add_library(ffmpeg_video_player STATIC
        src/VideoRead.cpp)
target_link_libraries(ffmpeg_video_player ${FFMPEG_LIBRARIES})

include_directories(include)

# Examples
if(FFMPEG_VIDEO_PLAYER_BUILD_EXAMPLES)

    add_executable(player_sdl
            examples/SDLPlayerExample.cpp
            examples/SDLWindow.cpp
            examples/SDLWindow.h )

    target_link_libraries(player_sdl ffmpeg_video_player SDL2)

endif()
