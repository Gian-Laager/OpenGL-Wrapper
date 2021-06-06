#include "glwrp/glwrp.h"

static void errorCallback(int error, const char* message)
{
    std::stringstream exceptionMessage;
    exceptionMessage << "glfw error, code: " << error << ", message: " << message << std::endl;
    throw glwrp::GlewException{exceptionMessage.str()};
}

void glwrp::init(int windowWidth, int windowHeight,
                 const std::string& windowTitle, const std::vector<Window::Hint>& windowHints, GLFWmonitor* windowMonitor,
                 GLFWwindow* windowShare)
{
    glfwSetErrorCallback(errorCallback);
    if (!glfwInit())
        throw glwrp::Window::GlfwException("Failed to initialize GLFW");
    for (auto& hint : windowHints)
        glfwWindowHint(hint.hint, hint.value);
    glwrp::Window::mainWindow = glwrp::Window{windowWidth, windowHeight, windowTitle, windowMonitor, windowShare};
    glwrp::Window::mainWindow.bind();
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
        throw glwrp::GlewException("Failed to initialize GLEW");
}
