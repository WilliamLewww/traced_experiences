#include "engine.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

static char keyDownIndex[500];

void keyCallback(GLFWwindow *windowPtr, int key, int scancode, int action,
    int mods) {

  if (action == GLFW_PRESS) {
    keyDownIndex[key] = 1;
  }

  if (action == GLFW_RELEASE) {
    keyDownIndex[key] = 0;
  }
}

Engine::Engine(int windowWidth, int windowHeight) :
    windowWidth(windowWidth),
    windowHeight(windowHeight)
{
  VkInstance instanceHandle = VK_NULL_HANDLE;
  VkPhysicalDevice physicalDeviceHandle = VK_NULL_HANDLE;
  VkDevice deviceHandle = VK_NULL_HANDLE;

  VkQueue queueHandle = VK_NULL_HANDLE;
  VkCommandPool commandPoolHandle = VK_NULL_HANDLE;
  std::vector<VkCommandBuffer> commandBufferHandleList = {};

  std::vector<DescriptorSet> descriptorSetList = {};
  std::vector<Pipeline> pipelineList = {};
}

Engine::~Engine() {

}

VkResult Engine::initialize() {
  VkResult result = VK_SUCCESS;

  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  GLFWwindow *windowPtr = glfwCreateWindow(this->windowWidth,
      this->windowHeight, "Vulkan", NULL, NULL);
  glfwSetInputMode(windowPtr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glfwSetKeyCallback(windowPtr, keyCallback);

  return result;
}

VkResult Engine::start() {
  VkResult result = VK_SUCCESS;

  return result;
}

VkResult Engine::stop() {
  VkResult result = VK_SUCCESS;

  return result;
}
