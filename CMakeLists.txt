cmake_minimum_required(VERSION 3.15)

enable_language(CXX ASM)

project(adventcalendar2023)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler options
add_definitions(-Wredundant-decls)
add_definitions(-Wmain)
add_definitions(-Wundef)
add_definitions(-Winline)
add_definitions(-Wswitch-enum)
add_definitions(-Wmissing-declarations)
add_definitions(-Wnon-virtual-dtor)
add_definitions(-Wzero-as-null-pointer-constant)
add_definitions(-Winit-self)
add_definitions(-Wshadow)
add_definitions(-Wswitch-default)
add_definitions(-Wfloat-equal)
add_definitions(-Wunreachable-code)
add_definitions(-m64)
add_definitions(-O0)
add_definitions(-gdwarf-2)
add_definitions(-Wextra)
add_definitions(-std=c++20)
add_definitions(-Wall)

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
)

set ( TESTS_SRCS
    tests/main.cpp
    tests/day5.cpp
    tests/day7.cpp
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
    " -Wredundant-decls -Wmain -Wundef -Winline -Wswitch-enum -Wmissing-declarations -Wnon-virtual-dtor -Wzero-as-null-pointer-constant -Winit-self -Wshadow -Wswitch-default -Wfloat-equal -Wunreachable-code -m64 -O0 -gdwarf-2 -Wextra -std=c++20 -Wall")


add_executable(adventcalendar2023 ${TARGET_SRCS} ${COMMON_SRCS} )

add_executable(tests ${COMMON_SRCS} ${TESTS_SRCS} )
target_include_directories(tests PRIVATE .)
target_link_libraries(tests GTest::gtest_main )
target_link_libraries(tests GTest::gmock_main )

include(GoogleTest)
gtest_discover_tests(tests)
