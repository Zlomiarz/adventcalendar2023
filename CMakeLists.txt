cmake_minimum_required(VERSION 3.15)

enable_language(CXX ASM)

project(adventcalendar2023)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler options
add_compile_options(-Wredundant-decls)
add_compile_options(-Wmain)
add_compile_options(-Wundef)
add_compile_options(-Winline)
add_compile_options(-Wswitch-enum)
add_compile_options(-Wmissing-declarations)
add_compile_options(-Wnon-virtual-dtor)
add_compile_options(-Wzero-as-null-pointer-constant)
add_compile_options(-Winit-self)
add_compile_options(-Wshadow)
add_compile_options(-Wswitch-default)
add_compile_options(-Wfloat-equal)
add_compile_options(-Wunreachable-code)
add_compile_options(-m64)
add_compile_options(-O0)
add_compile_options(-gdwarf-2)
add_compile_options(-Wextra)
add_compile_options(-std=c++20)
add_compile_options(-Wall)

set ( TARGET_SRCS
    src/main.cpp
)

set ( COMMON_SRCS
    src/day6.cpp
    src/day5.cpp
    src/day2.cpp
    src/day1.cpp
    src/day3.cpp
    src/base_class.cpp
    src/day4.cpp
    src/day7.cpp
    src/day8.cpp
    src/day9.cpp
    src/day10.cpp
)

set ( TESTS_SRCS
    tests/main.cpp
    tests/day5.cpp
    tests/day7.cpp
    tests/day10.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set_source_files_properties(
    ${COMMON_SRCS} PROPERTIES COMPILE_FLAGS 
    "")


add_executable(adventcalendar2023 ${TARGET_SRCS} ${COMMON_SRCS} )

add_executable(tests ${COMMON_SRCS} ${TESTS_SRCS} )
target_include_directories(tests PRIVATE .)
target_link_libraries(tests GTest::gtest_main )
target_link_libraries(tests GTest::gmock_main )

include(GoogleTest)
gtest_discover_tests(tests)
