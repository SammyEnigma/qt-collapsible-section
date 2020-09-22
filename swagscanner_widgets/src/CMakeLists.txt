# build Section as a static library
add_library(section STATIC
        ../include/Section.h Section.cpp)
target_link_libraries(section PUBLIC Qt5::Quick Qt5::Core Qt5::Widgets Qt5::Designer)

# Create new widgets as standalone shared libraries
add_subdirectory(calibration)
add_subdirectory(scanning)

# this executable is for testing the new widgets
add_executable(executable mainwindow.h mainwindow.cpp mainwindow.ui main.cpp)
target_link_libraries(executable calibration_basic_widget)

# install widgets!
install(TARGETS
        calibration_basic_widget
        scan_basic_widget
        DESTINATION ${QT_INSTALL_PLUGINS}/designer
        )