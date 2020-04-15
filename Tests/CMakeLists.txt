SET( TESTS_TARGET "Taktix_Tests" )

FILE( GLOB_RECURSE TESTS_SOURCES "Tests_*/Tests_*.cpp" )
FILE( GLOB_RECURSE TESTS_HEADERS "Tests_*/Tests_*.hpp" )
FILE( GLOB_RECURSE TESTS_INLINES "Tests_*/Tests_*.inl" )

SET(
        APP_LIBRARIES
        ${SFML_LIBRARIES}
        ${TGUI_LIBRARY}
)

ADD_EXECUTABLE(
        ${TESTS_TARGET}
        main.cpp
        ${TESTS_SOURCES}
        ${TESTS_HEADERS}
        ${TESTS_INLINES}
        ${TAKTIX_SOURCES}
)

TARGET_LINK_LIBRARIES(
        ${TESTS_TARGET}
        ${APP_LIBRARIES}
)
