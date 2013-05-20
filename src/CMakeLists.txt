set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
add_definitions(-std=c++11)

set(SRC_LIST
    "model/InvalidFieldException.hpp"
    "model/InvalidFieldException.cpp"
    "model/RequestPacket.hpp"
    "model/RequestPacket.cpp"
    "model/ResponsePacket.hpp"
    "model/ResponsePacket.cpp"
    "model/FetchRequest.hpp"
    "model/FetchRequest.cpp"
    "model/FetchResponse.hpp"
    "model/FetchResponse.cpp"
    "model/ServerConfig.hpp"
    "model/ServerConfig.cpp"

    "handlers/Thumbnailer.hpp"
    "handlers/Thumbnailer.cpp"
    "handlers/SexpRenderer.hpp"
    "handlers/SexpRenderer.cpp"

    "main.cpp"
)

find_package(Qt5Core)

add_executable(${PROJECT_NAME} ${SRC_LIST})
qt5_use_modules(${PROJECT_NAME} WebKitWidgets Network Gui)
