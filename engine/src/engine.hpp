#pragma once

#include <vulkan/vulkan.h>

#include <iostream>
#include <vector>

struct DescriptorSet;
struct Pipeline;

class Engine {
private:
  struct DescriptorSet {
    std::string name;

    VkDescriptorPool descriptorPoolHandle;
    VkDescriptorSetLayout descriptorSetLayoutHandle;
  };

  struct Pipeline {
    std::string name;

    VkPipelineLayout pipelineLayoutHandle;

    std::vector<std::pair<VkShaderModule, VkShaderStageFlagBits>>
        shaderModuleList;

    VkPipeline pipelineHandle;
  };

  uint32_t windowWidth;
  uint32_t windowHeight;

  VkInstance instanceHandle;
  VkPhysicalDevice physicalDeviceHandle;
  VkDevice deviceHandle;

  VkQueue queueHandle;
  VkCommandPool commandPoolHandle;
  std::vector<VkCommandBuffer> commandBufferHandleList;

  std::vector<DescriptorSet> descriptorSetList;
  std::vector<Pipeline> pipelineList;
public:
  Engine(int windowWidth, int windowHeight);
  ~Engine();

  VkResult initialize();

  VkResult addDescriptorSet();
  DescriptorSet *getDescriptorSet(uint32_t id);
  DescriptorSet *getDescriptorSet(std::string name);

  VkResult addPipeline(std::vector<DescriptorSet*> descriptorSetList,
                       std::vector<std::string> shaderSourcePathList);

  VkResult start();
  VkResult stop();
};
