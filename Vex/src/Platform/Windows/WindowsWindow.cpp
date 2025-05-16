#include "VexPch.h"
#include "WindowsWindow.h"

#include "Vex/Events/ApplicationEvent.h"
#include "Vex/Events/KeyEvent.h"
#include "Vex/Events/MouseEvent.h"
#include "Vex/Log.h"

namespace Vex
{
    static bool s_SDLInitialized = false;

    /**
     * Factory method for creating a platform-specific Window instance.
     */
    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    /**
     * Constructor: Initializes the SDL window with given properties.
     */
    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props);
    }

    /**
     * Destructor: Cleans up window resources.
     */
    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    /**
 * Polls and handles window events (e.g., resize, quit, mouse events, keyboard events).
 */
    void WindowsWindow::OnUpdate()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                // Handle quit event if needed
                VEX_CORE_INFO("Window Closed Event Detected");
                break;

            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    int newWidth = event.window.data1;
                    int newHeight = event.window.data2;

                    WindowResizeEvent e(newWidth, newHeight);
                    m_Data.EventCallback(e);
                }
                break;

            case SDL_KEYDOWN:
            {
                bool isRepeat = event.key.repeat != 0;
                KeyPressedEvent e(static_cast<Vex::KeyCode>(event.key.keysym.sym), isRepeat);
                m_Data.EventCallback(e);
                break;
            }

            case SDL_KEYUP:
            {
                KeyReleasedEvent e(static_cast<Vex::KeyCode>(event.key.keysym.sym));
                m_Data.EventCallback(e);
                break;
            }

            case SDL_TEXTINPUT:
            {
                char inputChar = event.text.text[0];
                KeyTypedEvent e(static_cast<Vex::KeyCode>(inputChar));
                m_Data.EventCallback(e);
                break;
            }

            // ** Mouse Events Handling **
            case SDL_MOUSEMOTION:
            {
                // Mouse movement event
                float x = static_cast<float>(event.motion.x);
                float y = static_cast<float>(event.motion.y);
                MouseMovedEvent e(x, y);
                m_Data.EventCallback(e);
                break;
            }

            case SDL_MOUSEWHEEL:
            {
                // Mouse scroll event
                float xOffset = static_cast<float>(event.wheel.x);
                float yOffset = static_cast<float>(event.wheel.y);
                MouseScrolledEvent e(xOffset, yOffset);
                m_Data.EventCallback(e);
                break;
            }

            case SDL_MOUSEBUTTONDOWN:
            {
                // Mouse button press event
                MouseCode button = static_cast<MouseCode>(event.button.button);
                MouseButtonPressedEvent e(button);
                m_Data.EventCallback(e);
                break;
            }

            case SDL_MOUSEBUTTONUP:
            {
                // Mouse button release event
                MouseCode button = static_cast<MouseCode>(event.button.button);
                MouseButtonReleasedEvent e(button);
                m_Data.EventCallback(e);
                break;
            }
            }
        }
    }



    /**
     * Initializes the SDL window with the provided properties.
     */
    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        VEX_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_SDLInitialized)
        {
            int errorCode = SDL_Init(SDL_INIT_VIDEO);

            if (errorCode != 0)
            {
                VEX_CORE_ERROR("SDL failed to initialize: {0}", SDL_GetError());
                return;
            }

            s_SDLInitialized = true;
        }

        m_Window = SDL_CreateWindow(
            m_Data.Title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            static_cast<int>(m_Data.Width),
            static_cast<int>(m_Data.Height),
            SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE
        );

        if (!m_Window)
        {
            VEX_CORE_ERROR("SDL failed to create window: {0}", SDL_GetError());
            return;
        }

        VEX_CORE_INFO("Window created successfully!");
    }

    /**
     * Destroys the SDL window and releases resources.
     */
    void WindowsWindow::Shutdown()
    {
        SDL_DestroyWindow(m_Window);
        m_Window = nullptr;
    }
}
