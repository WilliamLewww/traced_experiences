cmake_minimum_required (VERSION 3.21)
project(vulkan_ray_tracing_minimal_abstraction)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_library(engine SHARED src/main.cpp)
include_directories(engine include)
include_directories(engine ${Vulkan_INCLUDE_DIRS})
include_directories(engine ${GLFW_INCLUDE_DIRS})
target_link_libraries(engine ${Vulkan_LIBRARIES})
target_link_libraries(engine glfw)
target_link_libraries(engine m)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/shaders)
foreach(SHADER ${SHADERS})
	get_filename_component(SHADER_NAME ${SHADER} NAME)

	add_custom_command(
		OUTPUT shaders/${SHADER_NAME}.spv
    COMMAND ${Vulkan_GLSLANG_VALIDATOR_EXECUTABLE} --target-env vulkan1.2 -o
        shaders/${SHADER_NAME}.spv ${SHADER}
		DEPENDS ${SHADER}
	)
	target_sources(engine PRIVATE shaders/${SHADER_NAME}.spv)
endforeach()

add_custom_target(copy_resources
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources
)

add_dependencies(engine copy_resources)
