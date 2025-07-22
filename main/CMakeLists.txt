set(SOURCES "main.cc")
set(INCLUDE_DIRS "." "boards" "boards/bread-wifi")

file(GLOB BOARD_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/boards/bread-wifi/*.cc
)

list(APPEND SOURCES ${BOARD_SOURCES})

idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS ${INCLUDE_DIRS}
                    )