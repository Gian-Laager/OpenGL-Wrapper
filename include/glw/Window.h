#ifndef OPENGL_WRAPPER_WINDOW_H
#define OPENGL_WRAPPER_WINDOW_H

#include "glw/pch.h"

namespace glw
{
    class Window
    {
    public:
        Window(int width, int height, const std::string& title, GLFWmonitor* monitor = nullptr,
               GLFWwindow* share = nullptr);

        void bind();

        void unbind();

        bool shouldClose();

        glm::vec<2, int> getFramebufferSize();

        void swapBuffers();

        static void pollEvents();

    private:
        static std::shared_ptr<GLFWwindow> boundWindow;

        std::shared_ptr<GLFWwindow> glfwWindow;

        static std::shared_ptr<GLFWwindow>
        createWindow(int width, int height, const std::string& title, GLFWmonitor* monitor = nullptr,
                     GLFWwindow* share = nullptr);

        static void errorCallback(int error, const char* message);

    public:
        class GlfwException : public std::exception
        {
            std::string message;
        public:
            GlfwException(std::string message) noexcept: message(std::move(message))
            {}

            const char* what() const noexcept override
            { return message.c_str(); };
        };
    };
}

#endif //OPENGL_WRAPPER_WINDOW_H
