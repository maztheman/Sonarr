find_package(fmt CONFIG REQUIRED)

add_executable(sonarrcpp)

file(GLOB_RECURSE CPP_FILES *.cpp)

target_sources(sonarrcpp PRIVATE ${CPP_FILES})

target_include_directories(sonarrcpp PRIVATE ".")
target_link_libraries(sonarrcpp PRIVATE fmt::fmt)
target_precompile_headers(sonarrcpp PRIVATE pch.h)