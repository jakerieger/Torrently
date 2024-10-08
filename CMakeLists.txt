cmake_minimum_required(VERSION 3.14)
project(Torrently CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SRCDIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)
set(3PDIR ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(
    ${SRCDIR}
    ${3PDIR}
    ${ftxui_SOURCE_DIR}/include
)

add_executable(torrently
    ${SRCDIR}/main.cpp
)

add_subdirectory(ThirdParty/FTXUI)

target_link_libraries(torrently
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
)
