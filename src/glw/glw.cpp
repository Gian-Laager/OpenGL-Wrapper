#include "glw/glw.h"

bool hello()
{
    glfwInit();
    glw::Window window{720, 480, "Test"};
    window.bind();
    glewInit();
    while (!window.shouldClose())
    {
        glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.5);
        glVertex2d(0.5, -0.5);
        glVertex2d(-0.5, -0.5);
        glEnd();
        glClear(GL_COLOR_BUFFER_BIT);
        window.swapBuffers();
        glw::Window::pollEvents();
    }
    return true;
}
