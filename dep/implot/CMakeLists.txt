#=================== IMPLOT ===================

set(IMPLOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_library(IMPLOT STATIC)

target_sources( IMPLOT
                PRIVATE
                    ${IMPLOT_DIR}/implot_items.cpp
                    ${IMPLOT_DIR}/implot.cpp
                )

target_include_directories( IMPLOT
                            PUBLIC
                                ${IMPLOT_DIR}
                                ${CMAKE_SOURCE_DIR}/dep/imgui
                            )


target_link_libraries(IMPLOT PUBLIC ${CMAKE_DL_LIBS})


