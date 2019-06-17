set(apps_sources
    mwFractionOp.cxx
    )

set(apps_headers
    )

add_executable(Fraction ${apps_sources})

target_link_libraries(Fraction operations)

set_target_properties(Fraction PROPERTIES FOLDER "Applications")

install(
    TARGETS
        Fraction

	RUNTIME DESTINATION bin
)


install(DIRECTORY ${CMAKE_SOURCE_DIR}/../bin/
        DESTINATION bin
FILES_MATCHING PATTERN "*.sh"
PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_READ WORLD_EXECUTE
)