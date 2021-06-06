#include "glw/Window.h"

std::shared_ptr<GLFWwindow> glw::Window::boundWindow = nullptr;
glw::Window glw::Window::mainWindow{};

glw::Window::Window(int width, int height, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share)
{
    glfwWindow = createWindow(width, height, title, monitor, share);
    if (glfwWindow == nullptr)
        throw GlfwException("Failed to initialize window.");
}

std::shared_ptr<GLFWwindow>
glw::Window::createWindow(int width, int height, const std::string& title, GLFWmonitor* monitor,
                          GLFWwindow* share)
{
    return std::shared_ptr<GLFWwindow>(glfwCreateWindow(width, height, title.data(), monitor, share),
                                       glfwDestroyWindow);
}

void glw::Window::bind()
{
    if (glw::Window::boundWindow != glfwWindow)
    {
        glfwMakeContextCurrent(glfwWindow.get());
        glw::Window::boundWindow = glfwWindow;
    }
}

void glw::Window::unbind()
{
    if (glw::Window::boundWindow == glfwWindow)
    {
        glfwMakeContextCurrent(nullptr);
        glw::Window::boundWindow = nullptr;
    }
}

bool glw::Window::shouldClose()
{
    return glfwWindowShouldClose(glfwWindow.get());
}

glm::vec<2, int> glw::Window::getFramebufferSize()
{
    glm::vec<2, int> size{};
    glfwGetFramebufferSize(glfwWindow.get(), &size.x, &size.y);
    return size;
}

void glw::Window::swapBuffers()
{
    glfwSwapBuffers(glfwWindow.get());
}

void glw::Window::pollEvents()
{
    glfwPollEvents();
}

