cmake_minimum_required(VERSION 3.5)

project(BrickGame VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt Widgets package
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Find ncurses library
find_package(Curses REQUIRED)  # Added this line

set(PROJECT_SOURCES
        main.cpp
        game_controller.h
        game_params.cpp
        game_params.h

        brick_game/snake/snake_game.cpp
        brick_game/snake/snake_game.h
        brick_game/tetris/tetris_game.cpp
        brick_game/tetris/tetris_game.h

        gui/cli/cli_view.cpp
        gui/cli/cli_view.h

        gui/desktop/desktop_view.cpp
        gui/desktop/desktop_view.h
        gui/desktop/desktop_view.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BrickGame  # Change desktop_gui to BrickGame
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(BrickGame SHARED  # Change desktop_gui to BrickGame
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(BrickGame  # Change desktop_gui to BrickGame
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link libraries for the project
target_link_libraries(BrickGame PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets 
    ${CURSES_LIBRARIES}  # Link ncurses
)

# Bundle properties for macOS
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.BrickGame)  # Update if necessary
endif()
set_target_properties(BrickGame PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS BrickGame  # Change desktop_gui to BrickGame
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BrickGame)  # Change desktop_gui to BrickGame
endif()