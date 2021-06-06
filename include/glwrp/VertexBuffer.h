#ifndef OPENGL_WRAPPER_VERTEXBUFFER_H
#define OPENGL_WRAPPER_VERTEXBUFFER_H

#include "pch.h"

namespace glwrp
{
    class VertexBuffer
    {
    public:
        VertexBuffer(GLsizeiptr size, GLenum target, GLenum usage);

        template<typename VertexType>
        VertexBuffer(GLsizeiptr size, VertexType* data, GLenum target, GLenum usage);
        template<typename VertexType>
        VertexBuffer(std::vector<VertexType> vertices, GLenum target, GLenum usage);
        VertexBuffer() = default;

        void bind();
        void unbind();

        void attribPointer(unsigned int index, int size, GLenum type, bool normalized, int stride, void* offset);
        template<typename VertexType>
        void setData(std::vector<VertexType> vertices);

    private:
        static bool idBound(GLenum target, unsigned int id);
        GLenum target = 0;
        GLenum usage = 0;
        unsigned int id = 0;
    };
}

#endif //OPENGL_WRAPPER_VERTEXBUFFER_H
