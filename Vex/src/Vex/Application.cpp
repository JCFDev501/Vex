#include "VexPch.h"
#include "Application.h"

#include "Log.h"
#include "Window.h"

namespace Vex
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application() 
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::Run()
	{

        // Main loop (just for illustration)
        while (m_Running)
        {
            m_Window->OnUpdate();

        }
	}

    void Application::OnEvent(Event& e)
    {
        VEX_CORE_INFO(e.ToString());
    }
}


