set(BINARY ${CMAKE_PROJECT_NAME}_tst)

set(SOURCE_FILES
        XLList_test.cpp
        main.cpp
        )

add_executable(${BINARY} ${SOURCE_FILES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)