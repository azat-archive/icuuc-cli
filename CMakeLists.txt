project(Icuuc_CLI)
cmake_minimum_required(VERSION 2.8.12)

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(
    icuuc-cli

    "${CMAKE_SOURCE_DIR}/src/icuuc.cpp"
    "${CMAKE_SOURCE_DIR}/src/ops.cpp"
    "${CMAKE_SOURCE_DIR}/src/options.cpp"
)
target_link_libraries(icuuc-cli icuuc ${Boost_LIBRARIES})
