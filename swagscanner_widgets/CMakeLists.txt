add_library(calibration_widget_basic SHARED
        CalibrationDropdownBasic.h CalibrationDropdownBasic.cpp)

add_library(scan_widget_basic SHARED
        ScanDropdownBasic.cpp ScanDropdownBasic.h)

target_link_libraries(calibration_widget_basic qt_collapsible_section)
target_link_libraries(scan_widget_basic qt_collapsible_section)

add_executable(executable mainwindow.h mainwindow.cpp mainwindow.ui main.cpp)



install(TARGETS
        calibration_widget_basic
        scan_widget_basic
        DESTINATION ${QT_INSTALL_PLUGINS}/designer
        )

target_link_libraries(executable calibration_widget_basic)
target_link_libraries(executable scan_widget_basic)