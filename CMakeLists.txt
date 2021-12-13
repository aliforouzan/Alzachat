#[[
/*
* CmakeList file.
* Copyright (c) 2021 Alzachat. All rights reserved.
*                  Ali Forouzan
*/
]]

cmake_minimum_required(VERSION 3.19)
project(Alzachat)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "/home/forouzan_a/Qt/6.2.2/gcc_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Network)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Network)

add_executable(${PROJECT_NAME}
        src/server/main.cpp
        src/server/main.cpp
        src/server/User.cpp
        src/server/User.h
        src/server/SMS.cpp
        src/server/SMS.h
        src/lib/Message.cpp
        src/lib/Message.h
        src/lib/TextMessage.cpp
        src/lib/TextMessage.h
        src/lib/VoiceMessage.cpp
        src/lib/VoiceMessage.h
        src/lib/MediaMessage.cpp
        src/lib/MediaMessage.h
        src/lib/ImageMessage.cpp
        src/lib/ImageMessage.h
        src/lib/VideoMessage.cpp
        src/lib/VideoMessage.h
        src/server/ServerConfig.h
        src/server/AlzaServer.cpp
        src/server/AlzaServer.h
        src/server/AlzaRunnable.cpp
        src/lib/AlzaRunnable.h
        src/server/ServerConfig.cpp
        src/lib/Alzachat.h
        src/lib/Logging.cpp
        src/lib/Logging.h
        src/client/main.cpp
        src/client/AlzaClient.cpp
        src/client/AlzaClient.h
        src/client/AlzaRunnable.cpp)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
