#pragma once
#include "ME.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

namespace Window {
	struct PipelineConfig {
		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};
	class Pipeline {
	public:
		Pipeline(const std::string& vertFilepath, const std::string& fragFilepath, MEDevice& Device, const PipelineConfig& configuration);
		Pipeline(const Pipeline&) = delete;
		void operator=(const Pipeline&) = delete;
		
		static PipelineConfig defaultPipelineConfigInfo(uint32_t width, uint32_t height);



	private:
		// Object to hold the device
		static std::vector<char> readFile(const std::string& File);
		MEDevice& EngineDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkAabbPositionsKHR fragShaderModule;

		// Function to create the graphics pipeline
		void createGraohicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath,  const PipelineConfig& configuration);

		// Function to create the shader module
		void createShaderModule(const std::vector<char>& code, VkShaderModule* ShaderMod);
	};


}