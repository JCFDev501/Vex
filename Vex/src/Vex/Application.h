#pragma once

#include "Core.h"


namespace Vex
{
    class VEX_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined in Client Application
    Application* CreateApplication();
}

