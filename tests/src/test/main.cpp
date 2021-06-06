#include <test/pch.h>
#include "glwrp/glwrp.h"
#include <array>

TEST(Window, BasicWindow)
{
    struct Vertex
    {
        glm::vec<2, float> position;
        glm::vec<3, float> color;
    };
    glwrp::init(720, 480, "Test",
                std::vector<glwrp::Window::Hint>{glwrp::Window::Hint{GLFW_CONTEXT_VERSION_MAJOR, 4},
                                                 glwrp::Window::Hint{GLFW_CONTEXT_VERSION_MINOR, 1},
                                                 glwrp::Window::Hint{GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE},
                                                 glwrp::Window::Hint{GLFW_OPENGL_FORWARD_COMPAT, true}});

    std::array<Vertex, 3> vertices = {Vertex{glm::vec<2, double>{0.0, 0.5}, glm::vec<3, double>{1.0, 0.0, 0.0}},
                                      Vertex{glm::vec<2, double>{0.5, -0.5}, glm::vec<3, double>{0.0, 1.0, 0.0}},
                                      Vertex{glm::vec<2, double>{-0.5, -0.5}, glm::vec<3, double>{0.0, 0.0, 1.0}},
    };

    std::array<unsigned int, 3> indices = {0, 1, 2};

    glwrp::VertexBuffer vertexBuffer = {};
    vertexBuffer.data(vertices.data(), vertices.size() * sizeof(Vertex), GL_STATIC_DRAW);
    glwrp::IndexBuffer indexBuffer = {3};
    indexBuffer.data(indices.data(), indices.size() * sizeof(unsigned int), GL_STATIC_DRAW);
    glwrp::VertexArray vertexArray = {};
    glwrp::Shader shader = {
            "../tests/assets/shaders/helloShader.glsl"};
    glwrp::VertexBufferLayout layouts[] = {
            glwrp::VertexBufferLayout{0, 2, GL_FLOAT, false, sizeof(Vertex), nullptr},
            glwrp::VertexBufferLayout{1, 3, GL_FLOAT, false, sizeof(Vertex),
                                      (void*) sizeof(glm::vec<2, float>)}};
    vertexArray.push(&vertexBuffer, layouts, 2);
    vertexArray.push(&indexBuffer);

    glwrp::Renderer renderer = {&vertexArray, &shader};

    while (!glwrp::Window::mainWindow.shouldClose())
    {
        renderer.draw(3);
        glwrp::Window::mainWindow.swapBuffers();
        glwrp::Window::pollEvents();
    }
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
