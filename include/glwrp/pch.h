#pragma once

////open gl error handling
#define glCall(x) GLErrorHandling::clearError();\
    x;\
    assert(GLErrorHandling::logCall(#x, __FILE__, __LINE__))

namespace glwrp
{
    namespace GLErrorHandling
    {
        void clearError();

        bool logCall(const char* function, const char* file, int line);
    }

////Destroyer
    struct Destroyer
    {
        ~Destroyer();
    };
}

////macros
#define glAbs_Init() auto destructor = glAbs::init();\


////including dependencies
#include "GL/glew.h"
#include "GLFW/glfw3.h"
//#include "stb_image.h"
//glm
#include "glm/glm.hpp"
#include "glm/gtx/string_cast.hpp"
#include "glm/gtc/type_ptr.hpp"

////including standard library
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstddef>

#define _USE_MATH_DEFINES

#include <math.h>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <array>
#include <future>
#include <memory>
#include <map>
