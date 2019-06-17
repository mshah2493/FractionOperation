set(op_sources
    Fraction.cxx
    )

set(op_headers
    Fraction.h
    )

add_library(operations ${op_sources} ${op_headers})

set(op_DEP_LIBS ${CMAKE_DL_LIBS})

target_link_libraries(operations ${op_DEP_LIBS})