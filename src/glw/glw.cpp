#include "glw/glw.h"

static void errorCallback(int error, const char* message)
{
    std::stringstream exceptionMessage;
    exceptionMessage << "glfw error, code: " << error << ", message: " << message << std::endl;
    throw glw::GlewException{exceptionMessage.str()};
}

void glw::init(int windowWidth, int windowHeight,
               const std::string& windowTitle, const std::vector<Window::Hint>& windowHints, GLFWmonitor* windowMonitor,
               GLFWwindow* windowShare)
{
    glfwSetErrorCallback(errorCallback);
    if (!glfwInit())
        throw glw::Window::GlfwException("Failed to initialize GLFW");
    for (auto& hint : windowHints)
        glfwWindowHint(hint.hint, hint.value);
    glw::Window::mainWindow = glw::Window{windowWidth, windowHeight, windowTitle, windowMonitor, windowShare};
    glw::Window::mainWindow.bind();
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
        throw glw::GlewException("Failed to initialize GLEW");
}
