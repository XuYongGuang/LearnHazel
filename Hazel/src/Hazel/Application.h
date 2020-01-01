#pragma once

#include "Core.h"

namespace Hazel{

    class Application {
    public:
        Application();

        ~Application();

        void Run();
    };

    // to be define in client
    Application* CreateApplication();
}