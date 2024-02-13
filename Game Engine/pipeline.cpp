#include "pipeline.hpp"


namespace Window {
	Pipeline::Pipeline(const std::string& vertFilepath, const std::string& fragFilepath, MEDevice& Device, const PipelineConfig& configuration) : EngineDevice{Device}  {
		createGraohicsPipeline(vertFilepath, fragFilepath, configuration);
	}
	
	std::vector<char> Pipeline::readFile(const std::string& File) {
		std::ifstream file(File, std::ios::ate | std::ios::binary);
		if (!file.is_open()) {
			std::cerr<<"Failed to open file"<<std::endl;
			throw std::runtime_error("Failed to open file: " + File);
		}

		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);
		file.seekg(0);
		file.read(buffer.data(), fileSize);
		file.close();
		return buffer;
	}
	
	void Pipeline::createGraohicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfig& configuration) {
				auto vertCode = readFile(vertFilepath);
		auto fragCode = readFile(fragFilepath);
			std::cout<< "Vertex Shader: "<<vertCode.size()<<std::endl;
			std::cout<< "Fragment Shader: "<<fragCode.size()<<std::endl;
	}

	void Pipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* ShaderMod) {
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
		if (vkCreateShaderModule(EngineDevice.device(), &createInfo, nullptr, ShaderMod) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create shader module (Refer to 'createShaderModule' in Pipeline.cpp" );
		}
	}

	PipelineConfig Pipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
		PipelineConfig config{};
		config.inputAssemblyInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		config.inputAssemblyInfo.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		config.inputAssemblyInfo.primitiveRestartEnable = VK_FALSE;

		config.viewport.x = 0.0f;
		config.viewport.y = 0.0f;
		config.viewport.width = static_cast<float>(width);
		config.viewport.height = static_cast<float>(height);
		config.viewport.minDepth = 0.0f;
		config.viewport.maxDepth = 1.0f;

		config.scissor.offset = {0, 0};
		config.scissor.extent = {width, height};
		return config;
	}	

}