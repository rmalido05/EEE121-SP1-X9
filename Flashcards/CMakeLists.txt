cmake_minimum_required(VERSION 3.19)
project(Flashcards LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Flashcards
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui





    addflashcardsdialog.h addflashcardsdialog.cpp addflashcardsdialog.ui
    editflashcardsdialog.h editflashcardsdialog.cpp editflashcardsdialog.ui
    deleteflashcardsdialog.h deleteflashcardsdialog.cpp deleteflashcardsdialog.ui
    studymodedialog.h studymodedialog.cpp studymodedialog.ui
    datastructures.h

)

target_link_libraries(Flashcards
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Flashcards
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Flashcards
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
