#pragma once


#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>
namespace Window {

	class VulkanWindow {

	public:
		VulkanWindow(int height, int width, std::string Window);
		~VulkanWindow();

		VulkanWindow(const VulkanWindow&) = delete;
		VulkanWindow& operator=(const VulkanWindow) = delete; 


		bool ShouldBeClosed() { return glfwWindowShouldClose(Window); } 

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	private:
		void initializeWindow();

		const int WIDTH; 
		const int HEIGHT; 


		std::string WindowsName;
		GLFWwindow* Window;

		
	};
}