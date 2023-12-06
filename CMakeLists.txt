# -*- CMakeLists.txt generated by CodeLite IDE. Do not edit by hand -*-

cmake_minimum_required(VERSION 3.0)


#{{{{ User Code 01
# Place your code here
#}}}}

enable_language(CXX C ASM)
# Project name
project(adventcalendar2023)



#{{{{ User Code 02
# Place your code here
#}}}}

# This setting is useful for providing JSON file used by CodeLite for code completion
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CONFIGURATION_NAME "Debug")

set(CL_WORKSPACE_DIRECTORY .)
# Set default locations
set(CL_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${CL_WORKSPACE_DIRECTORY}/cmake-build-${CONFIGURATION_NAME}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CL_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CL_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CL_OUTPUT_DIRECTORY})

# Projects


# Top project
# Define some variables
set(PROJECT_adventcalendar2023_PATH "${CMAKE_CURRENT_LIST_DIR}")
set(WORKSPACE_PATH "${CMAKE_CURRENT_LIST_DIR}/")



#{{{{ User Code 1
# Place your code here
#}}}}

include_directories(
    .
    .

)


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
add_definitions(-std=c++17)
add_definitions(-Wall)

# Linker options


if(WIN32)
    # Resource options
endif(WIN32)

# Library path
link_directories(
    .
)

# Define the CXX sources
set ( CXX_SRCS
    ${CMAKE_CURRENT_LIST_DIR}/day1.cpp
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

set_source_files_properties(
    ${CXX_SRCS} PROPERTIES COMPILE_FLAGS 
    " -Wredundant-decls -Wmain -Wundef -Winline -Wswitch-enum -Wmissing-declarations -Wnon-virtual-dtor -Wzero-as-null-pointer-constant -Winit-self -Wshadow -Wswitch-default -Wfloat-equal -Wunreachable-code -m64 -O0 -gdwarf-2 -Wextra -std=c++17 -Wall")

if(WIN32)
    enable_language(RC)
    set(CMAKE_RC_COMPILE_OBJECT
        "<CMAKE_RC_COMPILER> ${RC_OPTIONS} -O coff -i <SOURCE> -o <OBJECT>")
endif(WIN32)



#{{{{ User Code 2
# Place your code here
#}}}}

add_executable(adventcalendar2023 ${RC_SRCS} ${CXX_SRCS} ${C_SRCS} ${ASM_SRCS})
target_link_libraries(adventcalendar2023 ${LINK_OPTIONS})



#{{{{ User Code 3
# Place your code here
#}}}}
