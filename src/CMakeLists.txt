set(BINARY ${CMAKE_PROJECT_NAME})

set(HEADER_FILES
        XLList.h
        )

set(SOURCE_FILES
        main.cpp
        )

set(INCLUDE_FILES
        ${SOURCE_FILES}
        ${HEADER_FILES}
        )

add_executable(${BINARY}_run ${INCLUDE_FILES})

add_library(${BINARY}_lib STATIC ${INCLUDE_FILES})
