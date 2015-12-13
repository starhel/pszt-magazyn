cmake_minimum_required(VERSION 3.3)
project(pszt)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES src/main.cpp src/model/RandInt.h src/view/userwindow.cpp src/model/RandDouble.h src/model/Product.cpp src/model/Product.h src/model/Creature.cpp src/model/Creature.h src/model/algorithm.cpp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)

# Podstawowa aplikacja
add_executable(app ${SOURCE_FILES})
qt5_use_modules(app Widgets)

# Testy jednostkowe
find_package(Boost)
if(Boost_FOUND)
    option(GENERATE_TESTS "Wygeneruj testy" ON)
    if(GENERATE_TESTS)
        add_executable(tests tests/main.cc tests/test_RandInt.cc tests/test_RandDouble.cc
                tests/test_Product.cc src/model/Product.cpp
                tests/test_Creature.cpp src/model/Creature.cpp)
        target_link_libraries(tests boost_unit_test_framework-mt)
    endif(GENERATE_TESTS)
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
                COMMENT "Generating API documentation with Doxygen" VERBATIM
                )
    endif(GENERATE_DOC)
endif(DOXYGEN_FOUND)