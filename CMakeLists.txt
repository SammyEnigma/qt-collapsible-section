cmake_minimum_required(VERSION 3.17)
project(qt_collapsible_section)

option(BUILD_SWAG_SCANNER_WIDGETS "Build swagscanner widgets" ON)

set(CMAKE_CXX_STANDARD 17)
set(Qt5_DIR "/usr/local/opt/qt/lib/cmake/Qt5")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets Quick Designer REQUIRED)
add_definitions(${QT_DEFINITIONS})

get_target_property(QT_QMAKE_EXECUTABLE Qt5::qmake LOCATION)
execute_process(COMMAND ${QT_QMAKE_EXECUTABLE} -query QT_INSTALL_PLUGINS
        OUTPUT_VARIABLE QT_INSTALL_PLUGINS OUTPUT_STRIP_TRAILING_WHITESPACE)


if (BUILD_SWAG_SCANNER_WIDGETS)
    add_subdirectory(swagscanner_widgets)

else ()
    include_directories(include)

    add_subdirectory(src)

endif ()




