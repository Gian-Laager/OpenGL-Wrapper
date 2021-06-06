#pragma once

#include "Buffer.h"

namespace glwrp
{
    class IndexBuffer : public Buffer
    {
    public:
        static unsigned int boundId;
        int numberOfVertices;

        IndexBuffer(int numberOfVertices);

        void bind() const override;

        void unbind() const override;
    };
}