#ifndef OPENGL_WRAPPER_WINDOW_H
#define OPENGL_WRAPPER_WINDOW_H

#include "glwrp/pch.h"

namespace glwrp
{
    class Window
    {
    public:
        struct Hint
        {
            int hint;
            int value;
        };

        static Window mainWindow;

        Window(int width, int height, const std::string& title, GLFWmonitor* monitor = nullptr,
               GLFWwindow* share = nullptr);

        Window() = default;

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
