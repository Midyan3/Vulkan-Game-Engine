#include "Application.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

int main() {
	Window::Application app{};
	bool failed = false; 
	
	try {
		app.run();
		
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
		failed = true; 
	}
	std::cout << "Status: " << failed; 
	return EXIT_SUCCESS; 

}