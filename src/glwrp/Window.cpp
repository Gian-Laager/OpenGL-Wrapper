#include "glwrp/Window.h"

std::shared_ptr<GLFWwindow> glwrp::Window::boundWindow = nullptr;
glwrp::Window glwrp::Window::mainWindow{};

glwrp::Window::Window(int width, int height, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share)
{
    glfwWindow = createWindow(width, height, title, monitor, share);
    if (glfwWindow == nullptr)
        throw GlfwException("Failed to initialize window.");
}

std::shared_ptr<GLFWwindow>
glwrp::Window::createWindow(int width, int height, const std::string& title, GLFWmonitor* monitor,
                            GLFWwindow* share)
{
    return std::shared_ptr<GLFWwindow>(glfwCreateWindow(width, height, title.data(), monitor, share),
                                       glfwDestroyWindow);
}

void glwrp::Window::bind()
{
    if (glwrp::Window::boundWindow != glfwWindow)
    {
        glfwMakeContextCurrent(glfwWindow.get());
        glwrp::Window::boundWindow = glfwWindow;
    }
}

void glwrp::Window::unbind()
{
    if (glwrp::Window::boundWindow == glfwWindow)
    {
        glfwMakeContextCurrent(nullptr);
        glwrp::Window::boundWindow = nullptr;
    }
}

bool glwrp::Window::shouldClose()
{
    return glfwWindowShouldClose(glfwWindow.get());
}

glm::vec<2, int> glwrp::Window::getFramebufferSize()
{
    glm::vec<2, int> size{};
    glfwGetFramebufferSize(glfwWindow.get(), &size.x, &size.y);
    return size;
}

void glwrp::Window::swapBuffers()
{
    glfwSwapBuffers(glfwWindow.get());
}

void glwrp::Window::pollEvents()
{
    glfwPollEvents();
}

