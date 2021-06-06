#include "glwrp/glwrp.h"

void glwrp::GLErrorHandling::clearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool glwrp::GLErrorHandling::logCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::stringstream errorIdHex;
        errorIdHex << std::hex << error;
        std::cout << "[OpenGL Error] (" << errorIdHex.str() << ") " << "file: " << file << ":" << line << " function: "
                  << function << std::endl;
        return false;
    }
    return true;
}

static void errorCallback(int error, const char* message)
{
    std::stringstream exceptionMessage;
    exceptionMessage << "glfw error, code: " << error << ", message: " << message << std::endl;
    throw glwrp::GlfwException{exceptionMessage.str()};
}

void glwrp::init(int windowWidth, int windowHeight,
                 const std::string& windowTitle, const std::vector<Window::Hint>& windowHints,
                 GLFWmonitor* windowMonitor,
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
