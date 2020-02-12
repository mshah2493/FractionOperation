set(op_sources
    Fraction.cxx
	Operators-impl.cxx
    )

set(op_headers
    Fraction.h
    )

add_library(operations INTERFACE) # no sources

set(op_DEP_LIBS ${CMAKE_DL_LIBS})

target_link_libraries(operations INTERFACE ${op_DEP_LIBS})