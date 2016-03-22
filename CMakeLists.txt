cmake_minimum_required(VERSION 3.3)
project(pszt)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES src/main.cpp src/model/RandInt.h src/view/userwindow.cpp src/model/RandDouble.h src/model/Product.cpp src/model/Product.h src/model/Creature.cpp src/model/Creature.h src/model/algorithm.cpp src/model/algorithm.h src/model/Population.cpp src/model/Population.h)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)

find_package(Boost)
if(Boost_FOUND)
    # Podstawowa aplikacja
    add_executable(app ${SOURCE_FILES})
    target_link_libraries(app boost_random-mt)
    target_link_libraries(app boost_system-mt)
    qt5_use_modules(app Widgets)
endif(Boost_FOUND)

# Dokumentacja
find_package(Doxygen) # Doxygen
if(DOXYGEN_FOUND)
    option(GENERATE_DOC "Wygeneruj dokumentacje" ON)
    if(GENERATE_DOC)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
        add_custom_target(doc
                ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                COMMENT "Generowanie dokumentacji" VERBATIM
                )
    endif(GENERATE_DOC)
endif(DOXYGEN_FOUND)
