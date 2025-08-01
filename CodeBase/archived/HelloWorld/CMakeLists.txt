if (Hello_World)
    message(STATUS "🔨 Hello World :)")

    set(ACTIVE_CLI_TOOL_SRCS
        "${CMAKE_CURRENT_SOURCE_DIR}/Src/Main.cpp"
    )

    set(ACTIVE_CLI_TOOL_HDRS
        "${CMAKE_CURRENT_SOURCE_DIR}/include/HelloWorld.h"
    )

    define_tool(
        Hello_World
        exe
        "${ACTIVE_CLI_TOOL_SRCS}"
        "${ACTIVE_CLI_TOOL_HDRS}"
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "Hello_World"  # 👈 This becomes your sub-folder under Debug/Release
        ""
    )
endif()