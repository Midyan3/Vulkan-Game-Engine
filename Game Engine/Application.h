#pragma once

#include "VulkanWindow.h"
#include "pipeline.hpp"
#include "ME.hpp"

namespace Window {
	class Application {
	public:
		static constexpr int WIDTH = 1200;
		static constexpr int HEIGHT = 1000;

		void run(); 

	private:
		VulkanWindow VulkanWindow{HEIGHT, WIDTH, "HELLO"};
		MEDevice EngineDevice{ VulkanWindow };
		Pipeline pipeLine{ "Shader/Shader.vert.spv", "Shader/Shader.frag.spv", EngineDevice, Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT) };
	};
} 