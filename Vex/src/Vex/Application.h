#pragma once

#include "Core.h"
#include <memory>

namespace Vex
{
	class Event;
	class Window;

	class VEX_API Application
    {
        std::unique_ptr<Window> m_Window = nullptr;
        bool m_Running = true;
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);
    };

    // To be defined in Client Application
    Application* CreateApplication();
}

