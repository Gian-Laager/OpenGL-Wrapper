#include <test/pch.h>
#include "glw/glw.h"

TEST(Window, BasicWindow)
{
    glw::init(720, 480, "Test",
              std::vector<glw::Window::Hint>{glw::Window::Hint{GLFW_CONTEXT_VERSION_MAJOR, 4},
                                             glw::Window::Hint{GLFW_CONTEXT_VERSION_MINOR, 1},
                                             glw::Window::Hint{GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE},
                                             glw::Window::Hint{GLFW_OPENGL_FORWARD_COMPAT, true}});
    while (!glw::Window::mainWindow.shouldClose())
    {
        glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.5);
        glVertex2d(0.5, -0.5);
        glVertex2d(-0.5, -0.5);
        glEnd();
        glClear(GL_COLOR_BUFFER_BIT);
        glw::Window::mainWindow.swapBuffers();
        glw::Window::pollEvents();
    }
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
