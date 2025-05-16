#pragma once

#include "Vex/Core.h"
#include "Vex/Events/Event.h"

namespace Vex
{
    /**
     * Struct representing properties used to initialize a window.
     */
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Vex Engine",
            unsigned int width = 1280,
            unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {
        }
    };

    /**
     * Abstract interface representing a platform-independent window.
     * All platform-specific windows must implement this interface.
     */
    class VEX_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        /** Called once per frame to process events and perform any per-frame logic. */
        virtual void OnUpdate() = 0;

        /** Returns the width of the window in pixels. */
        virtual unsigned int GetWidth() = 0;

        /** Returns the height of the window in pixels. */
        virtual unsigned int GetHeight() = 0;

        /** Sets the callback function to handle events. */
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

        // Future: Additional attributes such as VSync control, fullscreen toggle, etc.

        /** Factory method to create a platform-specific window instance. */
        static Window* Create(const WindowProps& props = WindowProps());
    };
}
