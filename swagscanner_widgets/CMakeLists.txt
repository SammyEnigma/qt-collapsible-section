add_library(section
        Section.h Section.cpp)

target_link_libraries(section PUBLIC Qt5::Quick Qt5::Core Qt5::Widgets Qt5::Designer)

add_library(calibration_basic_widget SHARED
        CalibrationDropdownBasic.h CalibrationDropdownBasic.cpp)

add_library(scan_basic_widget SHARED
        ScanDropdownBasic.h ScanDropdownBasic.cpp)

target_link_libraries(calibration_basic_widget section Qt5::Quick Qt5::Core Qt5::Widgets Qt5::Designer)
target_link_libraries(scan_basic_widget section Qt5::Quick Qt5::Core Qt5::Widgets Qt5::Designer)

add_executable(executable mainwindow.h mainwindow.cpp mainwindow.ui main.cpp)

target_link_libraries(executable calibration_basic_widget)

install(TARGETS
        calibration_basic_widget
        scan_basic_widget
        DESTINATION ${QT_INSTALL_PLUGINS}/designer
        )