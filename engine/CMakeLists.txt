find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_library(engine SHARED
    src/engine.cpp)

include_directories(engine
    include
    ${Vulkan_INCLUDE_DIRS}
    ${Vulkan_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS})

target_link_libraries(engine
    ${Vulkan_LIBRARIES}
    glfw
    m)
