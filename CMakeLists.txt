cmake_minimum_required(VERSION 3.16...3.28 FATAL_ERROR)
project(NSCA_api VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# 🟨 Global build output directory
set(GLOBAL_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Builds)

# ======================================
# 🟦 Build Toggles (Options)
# ======================================
option(BUILD_TOOL_A "Build Tool A" ON)

# ======================================
# 🟩 Macro: define_tool
# ======================================
# define_tool(name sources headers include_dir sub-folder)
function(define_tool TOOL_NAME SRC_LIST HDR_LIST INCLUDE_DIRS SUBFOLDER)
    add_executable(${TOOL_NAME} ${SRC_LIST} ${HDR_LIST})

    target_include_directories(${TOOL_NAME} PRIVATE ${INCLUDE_DIRS})

    if (WIN32)
        target_compile_definitions(${TOOL_NAME} PRIVATE UNICODE _UNICODE)
    endif()

    target_compile_options(${TOOL_NAME} PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/utf-8>
        $<$<CXX_COMPILER_ID:GNU>:-finput-charset=UTF-8 -fexec-charset=UTF-8>
        $<$<CXX_COMPILER_ID:Clang>:-finput-charset=UTF-8 -fexec-charset=UTF-8>
    )

    set_target_properties(${TOOL_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${GLOBAL_OUTPUT_DIR}/${SUBFOLDER}/$<CONFIG>
        LIBRARY_OUTPUT_DIRECTORY ${GLOBAL_OUTPUT_DIR}/${SUBFOLDER}/$<CONFIG>
        RUNTIME_OUTPUT_DIRECTORY ${GLOBAL_OUTPUT_DIR}/${SUBFOLDER}/$<CONFIG>
    )
endfunction()

# ======================================
# 🟥 Tool Definitions (Using Macro)
# ======================================

