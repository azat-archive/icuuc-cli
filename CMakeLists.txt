project(Icuuc_CLI)

add_executable(
    icuuc-cli

    "${CMAKE_SOURCE_DIR}/src/icuuc.cpp"
)
target_link_libraries(icuuc-cli icuuc)
