#pragma once

#include "Core.h"

namespace Hazel{

    extern "C" {
        class Application {
        public:
            Application();

            ~Application();

            void Run();
        };
    };

    // to be define in client
    Application* CreateApplication();
}