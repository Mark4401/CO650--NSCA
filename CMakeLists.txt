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
option(Hello_World "Building Hello World" OFF)
option(Part-1 "Building Hello World" ON)

# Load your custom function
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(define_tool)
# ======================================
# 🟥 Tool Definitions (Using Macro)
# ======================================

add_subdirectory(CodeBase/HelloWorld)
add_subdirectory(CodeBase/CO650-Part-1)

