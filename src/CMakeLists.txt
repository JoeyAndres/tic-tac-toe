include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_FILES "*.cpp")

# Non-Intrinsic Sources.
add_library(tictactoe ${SRC_FILES})
