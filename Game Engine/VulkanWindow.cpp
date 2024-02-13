#include "VulkanWindow.h"

namespace Window {

	VulkanWindow::VulkanWindow(int height, int width, std::string Window) : WIDTH{ width }, HEIGHT(height), WindowsName{ Window } {
		initializeWindow();
	}

	VulkanWindow::~VulkanWindow() {
		glfwDestroyWindow(Window);
		glfwTerminate(); 
	}

	void VulkanWindow::initializeWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); 
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		Window = glfwCreateWindow(WIDTH, HEIGHT, WindowsName.c_str(), nullptr, nullptr);
	}
	void VulkanWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, Window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface!");
		}
	}
}