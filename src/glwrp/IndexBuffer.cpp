#include "glwrp/IndexBuffer.h"

using namespace glwrp;

unsigned int IndexBuffer::boundId = 0;

IndexBuffer::IndexBuffer(int numberOfVertices) : Buffer(GL_ELEMENT_ARRAY_BUFFER),
                                                 numberOfVertices(numberOfVertices)
{}

void IndexBuffer::bind() const
{
    if (IndexBuffer::boundId != id)
    {
        Buffer::bind();
        IndexBuffer::boundId = id;
    }
}

void IndexBuffer::unbind() const
{
    if (IndexBuffer::boundId == id)
    {
        Buffer::unbind();
        IndexBuffer::boundId = 0;
    }
}

