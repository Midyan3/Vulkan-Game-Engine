#include "Application.h"

namespace Window{

	void Application::run() {
		while (!VulkanWindow.ShouldBeClosed()) {
			glfwPollEvents();
		}

	}
}