add_library(qt_collapsible_section STATIC
        Section.cpp
        ../include/Section.h)
target_link_libraries(qt_collapsible_section Qt5::Quick Qt5::Core Qt5::Widgets Qt5::Designer)

add_executable(exe mainwindow.h mainwindow.cpp mainwindow.ui main.cpp)
target_link_libraries(exe qt_collapsible_section)

install(TARGETS qt_collapsible_section
        DESTINATION ${QT_INSTALL_PLUGINS}/designer
        )