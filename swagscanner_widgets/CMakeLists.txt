add_library(swag_widget SHARED
        CalibrationDropdownBasic.h CalibrationDropdownBasic.cpp)
target_link_libraries(swag_widget qt_collapsible_section)

add_executable(executable mainwindow.h mainwindow.cpp mainwindow.ui main.cpp)

target_link_libraries(executable swag_widget)

install(TARGETS swag_widget
        DESTINATION ${QT_INSTALL_PLUGINS}/designer
        )