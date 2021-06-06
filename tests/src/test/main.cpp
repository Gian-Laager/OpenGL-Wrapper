#include <test/pch.h>
#include "glwrp/glwrp.h"

TEST(Window, BasicWindow)
{
    glwrp::init(720, 480, "Test",
                std::vector<glwrp::Window::Hint>{glwrp::Window::Hint{GLFW_CONTEXT_VERSION_MAJOR, 4},
                                                 glwrp::Window::Hint{GLFW_CONTEXT_VERSION_MINOR, 1},
                                                 glwrp::Window::Hint{GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE},
                                                 glwrp::Window::Hint{GLFW_OPENGL_FORWARD_COMPAT, true}});
    while (!glwrp::Window::mainWindow.shouldClose())
    {
        glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.5);
        glVertex2d(0.5, -0.5);
        glVertex2d(-0.5, -0.5);
        glEnd();
        glClear(GL_COLOR_BUFFER_BIT);
        glwrp::Window::mainWindow.swapBuffers();
        glwrp::Window::pollEvents();
    }
}

int main()
{
    testing::InitGoogleTest();
    std::cout << "binding: " << GL_ARRAY_BUFFER_BINDING << ", buffer: " << GL_ARRAY_BUFFER << std::endl;
    return RUN_ALL_TESTS();
}
