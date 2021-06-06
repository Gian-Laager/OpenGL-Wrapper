#ifndef OPENGL_WRAPPER_GLWRP_H
#define OPENGL_WRAPPER_GLWRP_H

#include "pch.h"
#include "Window.h"

namespace glwrp
{
    void init(int windowWidth, int windowHeight,
              const std::string& windowTitle,
              const std::vector<Window::Hint>& windowHints = std::vector<Window::Hint>(),
              GLFWmonitor* windowMonitor = nullptr, GLFWwindow* windowShare = nullptr);

    class GlewException : public std::exception
    {
        std::string message;
    public:
        GlewException(std::string  message) : message(std::move(message))
        {}

        const char* what() const noexcept override
        { return message.c_str(); }
    };
}

#endif //OPENGL_WRAPPER_GLWRP_H
