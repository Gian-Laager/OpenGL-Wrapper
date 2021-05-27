#include "glw/glw.h"
#include <iostream>

static int WIDTH = 640;
static int HEIGHT = 480;
double rotateX = 0, rotateY = 0, mouseX = 0, mouseY = 0;
bool dragging = false;
int keyArr[350];

static void Initialize()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

static void Update(GLFWwindow* window, double delta)
{
    if (keyArr[GLFW_KEY_ESCAPE])
        glfwSetWindowShouldClose(window, 1);
    rotateX += keyArr[GLFW_KEY_LEFT] - keyArr[GLFW_KEY_RIGHT];
    rotateY += keyArr[GLFW_KEY_UP] - keyArr[GLFW_KEY_DOWN];
}

static void RenderScene(GLFWwindow* window, double delta)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.25, 0.25);
    glVertex2f(0.75, 0.25);
    glVertex2f(0.75, 0.75);
    glVertex2f(0.25, 0.75);
    glEnd();
    glFlush();
}

static void Resize(GLFWwindow* window, int w, int h)
{
    if (h < 1)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float) w / (float) h, 0.1f, 1000.0f);
    gluLookAt(0.0f, 0.0f, 30, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
}

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    keyArr[key] = action;
}

static void MouseClickCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_1)
    {
        dragging = action;
    }
}

static void MouseMotionCallback(GLFWwindow* window, double x, double y)
{
    if (dragging)
    {
        mouseX += x;
        mouseY += y;
    }
}

bool hello()
{
    GLFWwindow* window;

    glfwInit();
    window = glfwCreateWindow(WIDTH, HEIGHT, "Hello GL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    Initialize();

    glfwSetWindowSizeCallback(window, Resize);
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetMouseButtonCallback(window, MouseClickCallback);
    glfwSetCursorPosCallback(window, MouseMotionCallback);
    while (!glfwWindowShouldClose(window))
    {
        double delta = glfwGetTime();
        Update(window, delta);
        RenderScene(window, delta);
        glfwSetTime(0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    return true;
}
