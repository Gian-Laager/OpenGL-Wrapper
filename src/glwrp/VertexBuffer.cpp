#include "glwrp/VertexBuffer.h"

void glwrp::VertexBuffer::bind()
{
    if (!idBound(target, id))
        glBindBuffer(target, id);
}

void glwrp::VertexBuffer::unbind()
{
    if (idBound(target, id))
        glBindBuffer(target, 0);
}

glwrp::VertexBuffer::VertexBuffer(GLsizeiptr size, GLenum target, GLenum usage)
        : target(target),
          usage(usage)
{
    glGenBuffers(1, &id);
    bind();
    glBufferData(target, size, nullptr, usage);
    unbind();
}

template<typename VertexType>
glwrp::VertexBuffer::VertexBuffer(GLsizeiptr size, VertexType* data, GLenum target, GLenum usage)
        : target(target),
          usage(usage)
{
    glGenBuffers(1, &id);
    bind();
    glBufferData(target, size, data, usage);
    unbind();
}

template<typename VertexType>
glwrp::VertexBuffer::VertexBuffer(std::vector<VertexType> vertices, GLenum target, GLenum usage)
        : target(target),
          usage(usage)
{
    glGenBuffers(1, &id);
    bind();
    glBufferData(target, vertices.size(), vertices.data(), usage);
    unbind();
}

bool glwrp::VertexBuffer::idBound(GLenum target, unsigned int id)
{
    int boundId = 0;
    glGetIntegerv(target + 2, &boundId);
    return boundId == id;
}

void
glwrp::VertexBuffer::attribPointer(unsigned int index, int size, GLenum type, bool normalized, int stride, void* offset)
{
    bind();
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, type, normalized, stride, offset);
    unbind();
}

template<typename VertexType>
void glwrp::VertexBuffer::setData(std::vector<VertexType> vertices)
{
    bind();
    glBufferData(target, vertices.size(), vertices.data(), usage);
    unbind();
}
