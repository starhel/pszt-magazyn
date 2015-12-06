cmake_minimum_required(VERSION 3.3)
project(pszt)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES main.cpp src/RandInt.h src/userwindow.cpp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)

# Podstawowa aplikacja
add_executable(app ${SOURCE_FILES})
qt5_use_modules(app Widgets)

# Testy jednostkowe
add_executable(tests tests/test_RandInt.cc)
target_link_libraries(tests boost_unit_test_framework-mt)

# Dokumentacja
find_package(Doxygen) # Doxygen
option(GENERATE_DOC "Wygeneruj dokumentacje" ON)
if(GENERATE_DOC)
    if(DOXYGEN_FOUND)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
        add_custom_target(doc
                ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                COMMENT "Generating API documentation with Doxygen" VERBATIM
                )
    endif(DOXYGEN_FOUND)
endif()